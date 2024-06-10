// 4.7 example 2 Initialization function usage

#include <ncurses.h>

int main () {
  initscr();
  raw();
  keypad(stdscr, true);
  noecho();

  printw("Type any character to see it in bold\n");
  auto ch = getch();
  if (ch == KEY_F(1))
    printw("F1 pressed.");
  else {
    printw("The pressed key is ");
    attron(A_BOLD);
    printw("%c", ch);
    attroff(A_BOLD);
  }
  refresh();
  getch();
  endwin();
}
