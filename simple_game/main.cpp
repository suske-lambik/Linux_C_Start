//~ #include <iostream>
//~ #include <chrono>
//~ #include <thread>
#include <ncurses.h>

void erase (int y, int x) {
	mvaddch(y, x, ' ');
}

void screen_init() {
	// Initialize ncurses
 	initscr();
 	clear();
 	noecho();
 	cbreak();
 	keypad(stdscr, TRUE);
 	curs_set(0);
}

void game_loop(char main_char, int row, int col, int input) {
	// Check if the user wishes to play the game
	if(input == 'q' || input =='Q') return;

	// Show the main character on the screen
	mvaddch(row, col, main_char);
	refresh();

	for(;;) {
		input = getch();

		if(input == KEY_LEFT) {
			erase(row, col);
			col = col - 1;
			mvaddch(row, col, main_char);
			refresh();
		}
		else if(input == KEY_RIGHT) {
			erase(row, col);
			col = col + 1;
			mvaddch(row, col, main_char);
			refresh();
		}
		else if(input == KEY_UP) {
			erase(row, col);
			row = row - 1;
			mvaddch(row, col, main_char);
			refresh();
		}
		else if(input == KEY_DOWN) {
			erase(row, col);
			row = row + 1;
			mvaddch(row, col, main_char);
			refresh();
		}
		else if(ch == 'q' || ch == 'Q') {
			break;
		}
	}
}

int main()
{
	//~ std::cout << "Hello";//<< std::endl;
	//~ std::cout.flush();
	//~ std::this_thread::sleep_for(std::chrono::milliseconds(500));
	//~ std::cout << "\r" << "Hello again" << std::endl;
	
    screen_init()
 	// Define the main character initial position and symbol:
 	int row = 10, col = 10;
 	char main_char = '@';
 
 	// Print a welcome message on screen
 	printw("Welcome to the RR game.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");
 
 	// Wait until the user press a key
 	int ch = getch();
 
 	// Clear the screen
 	clear();
 	
 	// Start the game loop
 	game_loop(main_char, row, col, ch);
 	
 	//Clear ncurses data structures
 	endwin();
 	
	return 0;
}
