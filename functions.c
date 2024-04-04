#include "functions.h"
void input_func(int i, char str[], int *right, int *wrong, int *word_count, int max_time, int mistakes) {
    time_t end_time = time(NULL) + max_time;
    while (i < strlen(str)) {
        move(0, i);
        if (isspace(str[i])) {
            (*word_count)++;
        }
        int ch = getch();
        if (ch == str[i]) {
            attron(COLOR_PAIR(1));
            mvprintw(0, i, "%c", ch);
            attroff(COLOR_PAIR(1));
            i++;
            (*right)++;
        } else {
            attron(COLOR_PAIR(2));
            mvprintw(0, i, "%c", ch);
            attroff(COLOR_PAIR(2));
            i++;
            (*wrong)++;
        }
        if (*wrong >= mistakes){
            break;
        }
        if (time(NULL) >= end_time) {
            break;
        }
    }
    output_();
}
char output_() {
    refresh();
    getch();
    endwin();
    return 0;
}
int statistic(int right, int wrong, int sum, int symbol_speed, int words_speed) {
    printw("\nThe number of characters entered correctly : %d", right);
    printw("\nThe number of incorrectly entered characters : %d", wrong);
    printw("\nTotal number of characters entered : %d", sum);
    printw("\nAverage character printing speed : %d", symbol_speed);
    printw("\nAverage words printing speed : %d", words_speed);
}
void result(int argc, char *argv[], int max_time) {
    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    char easy[] = "Meet my family. There are five of us, my parents, my elder brother, my baby sister and me. First, meet my mum and dad, Jane and Michael.My mum enjoys reading and my dad enjoys playing chess with my brother Ken.";
    char medium[] = "Let me introduce myself. My name is Mariya I am a 20-year-old student from Donetsk.I study at the university in my native town and my future profession is bookkeeping.I live with my parents and my elder sister Lena. We are a friendly family. Lena is 2 years older than me.We share our room and tell all our secrets to each other.";
    char hard[] = "Unfortunately, these conditions are also perfect for the spread of the fungus Fusarium oxysporum f. sp. cubense, which attacks the plants roots and prevents it from transporting water to the stem and leaves. The TR-1 strain of the fungus was resistant to crop sprays and travelled around on boots or the tyres of trucks, slowly infecting plantations across the region. In an attempt to escape the fungus, farmers abandoned infected fields, flooded them and then replanted crops somewhere else, often cutting down rainforest to do so.";
    char *choice = argv[1];
    int i = 0, right = 0, wrong = 0, word_count = 1, mistakes = atoi(argv[3]);
    if (mistakes < 0 || mistakes > 15) {
        addstr("Mistakes input error!\n The third argument should be bigger than 0 and less than 15.\n "
               "Example of correct input: './ncurses_example.elf medium 10 5'");
        output_();
    }
    if (max_time < 0 || max_time > 60) {
        addstr("Maximal time input error!\n The second argument should be bigger than 0 and less than 60.\n "
               "Example of correct input: './ncurses_example.elf medium 10 5'");
        output_();
    }
    if (strcmp(choice, "easy") == 0){
        addstr(easy);
        input_func(i, easy, &right, &wrong, &word_count, max_time, mistakes);
    }
    else if (strcmp(choice, "medium") == 0){
        addstr(medium);
        input_func(i, medium, &right, &wrong, &word_count, max_time, mistakes);
    }
    else if (strcmp(choice, "hard") == 0){
        addstr(hard);
        input_func(i, hard, &right, &wrong, &word_count, max_time, mistakes);
    }
    else {
        addstr("Difficulty input error!\n The first argument should be 'easy' or 'medium' or 'hard'.\n "
               "Example of correct input: './ncurses_example.elf medium 10 5'");
        output_();
    }
    int sum = right + wrong;
    int symbol_speed = (sum * 60 / max_time);
    int words_speed = (word_count * 60 / max_time);
    statistic(right, wrong, sum, symbol_speed, words_speed);
    output_();
}