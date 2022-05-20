#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "input_validation.h"
#include "win.h"
#include "board.h"

// gets the board and who goes first
void setup_game(int num_rows, int num_cols, char blank_char, char*** board, int* cur_player_turn) {
	*board = setup_board(num_rows, num_cols, blank_char);
	*cur_player_turn = choose_who_goes_first();
}

// play the game
void play_game(char** board, int num_rows, int num_cols, int num_args_read, char blank_char, int cur_player_turn, char* player_pieces, int pieces_to_win) {
	const int num_players = 2;
	int col_heights[num_cols];
	for(int i = 0; i < num_cols; i++) {
		col_heights[i] = num_rows;
	}
	while(false) {
		display_game_state(board, num_rows, num_cols);
		get_valid_move_from_player(board, num_rows, num_cols, blank_char, col_heights);
		do_move(board, num_args_read, col_heights, num_rows, num_cols, blank_char);
		if(is_game_over(board, num_rows, num_cols, pieces_to_win, cur_player_turn, blank_char, col_heights) == true) {
			break;
		}
		change_turn(&cur_player_turn, num_players);
	}
	declare_results(board, num_rows, num_cols, blank_char, cur_player_turn, pieces_to_win, col_heights);
}

// sets the first player's value to 0 so the second player is 1
int choose_who_goes_first() {
	return 0;
}

// this prints the board after the game has started
void display_game_state(char** board, int num_rows, int num_cols) {
	print_board(board, num_rows, num_cols);
}

// when the user enters invalid input, you prompt them again
int get_valid_move_from_player(char** board, int num_rows, int num_cols, char blank_char, int col_heights[]) {
	int num_args_read;
	int col_input;
	do {
		printf("Enter what column between 0 and %d to play in: ", num_cols - 1);
		num_args_read = scanf(" %d", &col_input);
	} while(!is_valid_move(num_args_read, col_heights, col_input, board, num_rows, num_cols, blank_char));
	return col_input;
}

// checks if the input from the user for what column they want is valid
bool is_valid_move(int num_args_read, int col_heights[], int col_input, char** board, int num_rows, int num_cols, char blank_char) {
	return isValidFormat(num_args_read, col_input, num_cols) &&
				 is_inside_board(col_heights, col_input, num_rows, num_cols) &&
				 spot_is_empty(board, col_heights, col_input, blank_char);
}

// stores the location of the piece in board[row][col]
void do_move(char** board, int num_args_read, int col_heights[], int num_rows, int num_cols, int blank_char) {
	int col_input = get_valid_move_from_player(board, num_rows, num_cols, blank_char, col_heights);
	while(!is_valid_move(num_args_read, col_heights, col_input, board, num_rows, num_cols, blank_char)){
		get_valid_move_from_player(board, num_rows, num_cols, blank_char, col_heights);
	}
	col_heights[col_input] = col_heights[col_input] - 1;
}

// changes whose turn it is to play
void change_turn(int* cur_turn, int num_players) {
	*cur_turn = (*cur_turn + 1) % num_players;
}

// this calls win.c to figure out if someone won or there is a tie or if the game should continue
bool is_game_over(char** board, int num_rows, int num_cols, int pieces_to_win, int cur_player_turn, char blank_char, int col_heights[]) {
	int col_input = get_valid_move_from_player(board, num_rows, num_cols, blank_char, col_heights);
	return someone_won(board, num_rows, num_cols, col_heights, col_input, pieces_to_win, blank_char, cur_player_turn) ||
	       tie_game(board, num_rows, num_cols, blank_char);
}

// prints out who won
void declare_results(char** board, int num_rows, int num_cols, char blank_char, int cur_player_turn, int pieces_to_win, int col_heights[]) {
	print_board(board, num_rows, num_cols);
	int col_input = get_valid_move_from_player(board, num_rows, num_cols, blank_char, col_heights);
	if(someone_won(board, num_rows, num_cols, col_heights, col_input, pieces_to_win, blank_char, cur_player_turn)) {
		printf("Player %d  won the game!\n", cur_player_turn + 1);
	} else {
		printf("Tie Game.\n");
	}
}

// cleans up the memory
void clean_up_game(char*** board, int num_rows, int num_cols) {
	for(int i = 0; i < num_rows; ++i) {
		free((*board)[i]);
		for(int j = 0; j < num_cols; ++j) {
			free((*board)[i]);
		}
	}
	free(*board);
	*board = NULL;
}
