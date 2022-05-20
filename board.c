// from google drive > lecture > tictactoe > fall 2021 > board.c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"

// initial input error messages
void initial_input_error(int argc) {
	if(argc > 4) {
		printf("Too many arguments entered\n");
	} else {
		printf("Not enough arguments entered\n");
	}
	printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
}

// allocates memory for 2D board
char** setup_board(int num_rows, int num_cols, char blank_char) {
	char** board = (char**)calloc(num_rows, sizeof(*board));
	for(int i = 0; i < num_rows; ++i) {
		board[i] = (char*)calloc(num_cols, sizeof(*board[i]));
		for(int j = 0; j < num_cols; ++j) {
			board[i][j] = blank_char;
		}
	}
	return board;
}

// prints the board from the memory that we created above
void print_board(char** board, int num_rows, int num_cols) {
	printf("  ");
	for(int i = 0; i < num_cols; ++i) {  // print column headers
		printf("%d ", i);
	}
	printf("\n");
	for(int i = 0; i < num_rows; ++i) {
		printf("%d ", i);  // print the row header
		for(int j = 0; j < num_cols; ++j) {
			printf("%c ", board[i][j]);  // print the contents
		}
		printf("\n");
	}
}

// if the row and col are inside the board
bool is_inside_board(int col_heights[], int col_input, int num_rows, int num_cols) {
	return is_between(col_heights[col_input], 0, num_rows - 1) &&
				 is_between(col_input, 0, num_cols - 1);
}

bool is_between(int val, int min_val, int max_val) {
	return val >= min_val && val <= max_val;
}

// checks if it is empty (there is no piece), returns true if it is a blank char
bool spot_is_empty(char** board, int col_heights[], int col_input, char blank_char) {
	return board[col_heights[col_input]][col_input] == blank_char;
}

// checks if the entire board is full and therefore there is a tie, if no one won
bool is_board_full(char** board,  int num_rows, int num_cols, int blank_char) {
	for(int i = 0; i < num_rows; ++i) {
		for (int j = 0; j < num_cols; j++) {
			if(board[i][j] == blank_char) {
				return false;
			}
		}
	}
	return true;
}
