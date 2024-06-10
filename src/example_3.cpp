// Example 3
#include <ncurses.h>
#include <string.h>

int main() {
  char mesg[]="Just a string";

  int row, col;
  initscr();
  getmaxyx(stdscr, row, col); /*Get the current number of rows and cols.*/
  mvprintw(row/2, (col-strlen(mesg)), "%s", mesg);
  mvprintw(row-2,0,"This screen has %d rows and %d columns\n", row, col);
  printw("Try resizing your window and run this program again.");
  refresh();
  getch();
  endwin();
}
