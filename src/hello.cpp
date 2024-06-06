
#include <iostream>
#include <ncurses.h>

int main () {
  std::cout << "Hello" << std::endl;

  initscr();

  printw("Hello World!");
  refresh();
  getch();
  endwin();
}
