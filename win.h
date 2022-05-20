#ifndef WIN_H
	#define WIN_H
	#include <stdbool.h>
	bool someone_won(char** board, int num_rows, int num_cols, int col_heights[], int col_input, int pieces_to_win, char blank_char, int cur_player_turn);
	char get_cur_player_piece(int cur_player_turn);
	bool someone_won_horizontally(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn);
	bool someone_won_vertically(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn);
	bool someone_won_diagonally_left(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn);
	bool someone_won_diagonally_right(char** board, int num_rows, int num_cols, int row, int col, int pieces_to_win, char blank_char, int cur_player_turn);
	bool tie_game(char** board,  int num_rows, int num_cols, int blank_char);
#endif
