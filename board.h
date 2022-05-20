// from google drive > lecture > tictactoe > fall 2021 > board.c
#ifndef BOARD_H
  #define BOARD_H
	#include <stdbool.h>
  void initial_input_error(int argc);
  char** setup_board(int num_rows, int num_cols, char blank_char);
	void print_board(char** board, int num_rows, int num_cols);
  bool is_inside_board(int col_heights[], int col_input, int num_rows, int num_cols);
	bool is_between(int val, int min_val, int max_val);
  bool spot_is_empty(char** board, int col_heights[], int col_input, char blank_char);;
	bool is_board_full(char** board,  int num_rows, int num_cols, int blank_char);
#endif
