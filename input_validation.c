#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"

bool isValidFormat(const int num_args_read, int col_input, int num_cols) {
  const int num_args_needed = 1;
  if(num_args_read == num_args_needed) {
    do {
      //scanf("%d", &col_input);
  		if(col_input > 0 && col_input < num_cols - 1){ //found a non positive integer on the way to the end of the line
  			return true;
  		}
  	} while(col_input != '\n'); //read characters until the end of the line
  }
  return false;
}
