#include <stdbool.h>
#include "win.h"
#include "board.h"
#include "game.h"

bool someone_won(char** board, int num_rows, int num_cols, int col_heights[], int col_input, int pieces_to_win, char blank_char, int cur_player_turn) {
	int row = col_heights[col_input];
	int col = col_input;
	return someone_won_horizontally(board, num_rows, num_cols, row, col, pieces_to_win, blank_char, cur_player_turn) ||
				 someone_won_vertically(board, num_rows, num_cols, row, col, pieces_to_win, blank_char, cur_player_turn) ||
				 someone_won_diagonally_left(board, num_rows, num_cols, row, col, pieces_to_win, blank_char, cur_player_turn);
				 someone_won_diagonally_right(board, num_rows, num_cols, row, col, pieces_to_win, blank_char, cur_player_turn);
}

char get_cur_player_piece(int cur_player_turn) {
	if(cur_player_turn % 2 == 0) {  // it's player 1's turn
		return 'X';
	} else {
		return 'O';  // it's player 2's turn
	}
}

bool someone_won_horizontally(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn) {  // need to check to the left and to the right
	int num_your_pieces = 1;
	for(int cur_col = col - 1; cur_col >= 0; --cur_col) { // iterates the amount of times of pieces you need
		if(is_inside_board(&row, cur_col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[row][cur_col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
	}
	for(int cur_col = col + 1; cur_col < num_cols; ++cur_col) {
		if(is_inside_board(&row, cur_col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[row][cur_col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
	}
	return false;
}

bool someone_won_vertically(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn) {
	int num_your_pieces = 1;
	for(int cur_row = row - 1; cur_row >= 0; --cur_row) { // iterates the amount of times of pieces you need
		if(is_inside_board(&cur_row, col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[cur_row][col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
	}
	for(int cur_row = row + 1; cur_row < num_rows; ++cur_row) {
		if(is_inside_board(&cur_row, col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[cur_row][col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
	}
	return false;
}

bool someone_won_diagonally_left(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn) {
	/*Look for this type of win
	  0 1 2
	0	X
	1	  X
	2     X
	*/
	int num_your_pieces = 1;
	for(int cur_col = col - 1; cur_col >= 0; --cur_col) { // iterates the amount of times of pieces you need
		int cur_row = row - 1;
		if(is_inside_board(&cur_row, cur_col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[cur_row][cur_col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
		cur_row -= 1;
	}
	for(int cur_col = col + 1; cur_col < num_cols; ++cur_col) {
		int cur_row = row + 1;
		if(is_inside_board(&cur_row, cur_col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[cur_row][cur_col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
		cur_row += 1;
	}
	return false;
}

bool someone_won_diagonally_right(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn) {
	/*Look for this type of win
	  0 1 2
	0	    X
	1	  X
	2 X
	*/
	int num_your_pieces = 1;
	for(int cur_col = col - 1; cur_col >= 0; --cur_col) { // iterates the amount of times of pieces you need
		int cur_row = row + 1;
		if(is_inside_board(&cur_row, cur_col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[cur_row][cur_col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
		cur_row += 1;
	}
	for(int cur_col = col + 1; cur_col < num_cols; ++cur_col) {
		int cur_row = row - 1;
		if(is_inside_board(&cur_row, cur_col, num_rows, num_cols) == false) { // end of board
			break;
		}
		else if(board[cur_row][cur_col] == get_cur_player_piece(cur_player_turn)) {
			num_your_pieces += 1;
			if(num_your_pieces == pieces_to_win) { // you have the amount of pieces to win
				return true;
			}
		} else {
		break;
		}
		cur_row -= 1;
	}
	return false;
}

bool tie_game(char** board,  int num_rows, int num_cols, int blank_char) {
	//only call this function after checking for a win
	return is_board_full(board, num_rows, num_cols, blank_char);
}
