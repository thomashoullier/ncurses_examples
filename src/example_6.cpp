/* Example 6 */

#include <ncurses.h>

int main() {
  initscr();
  start_color();

  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  printw("A Big string which i didn't care to type fully\n");
  printw("Another Big string which i didn't care to type fully\n");
  printw("Another Big string which i didn't care to type fully\n");

  mvchgat(1, 0, -1, A_BLINK, 1, NULL);

  refresh();
  getch();
  endwin();
}
