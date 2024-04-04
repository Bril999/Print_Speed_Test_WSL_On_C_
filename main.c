#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        addstr("Input error!\n The first argument should be 'easy' or 'medium' or 'hard'.\n "
               "Example of correct input: './ncurses_example.elf medium 10 5'");
        output_();
    }
    int max_time = atoi(argv[2]);
    result(argc, argv, max_time);
}