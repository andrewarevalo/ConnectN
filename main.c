#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "input_validation.h"
#include "win.h"

int main(int argc, char** argv) {
	if(argc == 4) {
		char** board;
		int cur_player_turn;
		char blank_char = '*';
		int num_rows;
    int num_cols;
    int pieces_to_win;
		int num_args_read = 3;
    num_rows = atoi(argv[1]);
    num_cols = atoi(argv[2]);
    pieces_to_win = atoi(argv[3]);
		char player_pieces[] = "XO";
		sscanf(argv[1], "%d", &num_rows);
		sscanf(argv[2], "%d", &num_cols);
		sscanf(argv[3], "%d", &pieces_to_win);
		// blank_char = argv[2][0];
		setup_game(num_rows, num_cols, blank_char, &board, &cur_player_turn);
		play_game(board, num_rows, num_cols, num_args_read, blank_char, cur_player_turn, player_pieces, pieces_to_win);
		clean_up_game(&board, num_rows, num_cols);
	} else {
		initial_input_error(argc);
	}
	return 0;
}
