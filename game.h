#ifndef GAME_H
  #define GAME_H
	#include <stdbool.h>
	void setup_game(int num_rows, int num_cols, char blank_char, char*** board, int* cur_player_turn);
	void play_game(char** board, int num_rows, int num_cols, int num_args_read, char blank_char, int cur_player_turn, char* player_pieces, int pieces_to_win);
	int choose_who_goes_first();
	void display_game_state(char** board, int num_rows, int num_cols);
  int get_valid_move_from_player(char** board, int num_rows, int num_cols, char blank_char, int col_heights[]);
  bool is_valid_move(int num_args_read, int col_heights[], int col_input, char** board, int num_rows, int num_cols, char blank_char);
	void do_move(char** board, int num_args_read, int col_heights[], int num_rows, int num_cols, int blank_char);
	void change_turn(int* cur_turn, int num_players);
	bool is_game_over(char** board, int num_rows, int num_cols, int pieces_to_win, int cur_player_turn, char blank_char, int col_heights[]);
  void declare_results(char** board, int num_rows, int num_cols, char blank_char, int cur_player_turn, int pieces_to_win, int col_heights[]);
  void clean_up_game(char*** board, int num_rows, int num_cols);
#endif
