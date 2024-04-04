#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void input_func(int i, char str[], int *right, int *wrong, int *word_count, int max_time, int mistakes);
char output_();
int statistic(int right, int wrong, int sum, int symbol_speed, int words_speed);
void result(int argc, char *argv[], int max_time);