/* Example 5 */
#include <cstdio>
#include <ncurses.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  auto prev = EOF;

  /* Catching misuse/errors */
  if (argc != 2) {
    printf("Usage: %s <a c file name>\n", argv[0]);
    exit(1);
  }

  auto fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("Cannot open input file");
    exit(1);
  }

  /* Init */
  initscr();
  int row, col;
  getmaxyx(stdscr, row, col);

  int ch;
  while((ch = fgetc(fp)) != EOF) {
    int y, x;
    getyx(stdscr, y, x); /* Get current cursor */

    if (y == (row -1)) { /* Are we at the end of the screen? */
      printw("<-Press any key->");
      getch();
      clear();
      move(0, 0); /* Start on new page. */
    }

    if (prev == '/' && ch == '*') {
      attron(A_BOLD);
      getyx(stdscr, y, x);
      move(y, x-1); /* Back up one space. */
      printw("%c%c", '/', ch); /* Print in bold. */
    } else {
      printw("%c", ch); /* Running printing using current attribute. */
    }
    refresh();
    if (prev == '*' && ch == '/') {
      attroff(A_BOLD);
    }
    prev = ch;
  }

  getch();
  endwin();
  fclose(fp);
}
