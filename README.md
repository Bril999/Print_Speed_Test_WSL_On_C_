Print_Speed_Test_WSL_On_C
The text or set of words that the user must enter is hardcoded in the program.
When the program starts, the text appears completely in the terminal. If it doesn't fit, then only part of it appears.
At startup, the cursor appears at the very beginning of the text, and when typing each character, it moves to the next character
When you enter the correct character, the symbol is highlighted in green. When entering the wrong red. At the same time, if a character is entered incorrectly, the cursor still moves to the next character. That is, if the user made a mistake in entering a character, he cannot correct his mistake.
There are 3 difficulty levels of the game. The difficulty level is passed as the first argument, and can take the values easy, medium, and hard. There are 3 different texts or sets of words for each difficulty level, which are output depending on the level selected by the user.
A time limit in seconds is passed to the program for the second argument. That is, a limited time is given for text input, which the user will enter with the second argument. If the user has not typed the text, and the time has run out, then the game ends.
The third argument passes the number of errors that the user can make. If the user entered incorrectly more characters than specified in the third argument, the game ends.
At the end of the game, regardless of how it ended (the user typed everything correctly, or lost due to time or errors), statistics about the game should be displayed:
The number of correctly entered characters
The number of incorrectly entered characters
Total number of characters entered (correct + incorrect)
The average speed of typing characters in the game, measured in the number of characters per minute
The average word typing speed in the game, measured in the number of words per minute
The "ncurses" library is required for the program to work You need to run the program through the terminal WSL The input must be of the form - ./ncurses_example.elf medium 50 10
