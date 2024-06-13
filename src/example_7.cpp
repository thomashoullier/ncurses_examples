#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx) {
  WINDOW *local_win;
  local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0);
  wrefresh(local_win);
  return local_win;
}

void destroy_win(WINDOW *local_win) {
  wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(local_win);
  delwin(local_win);
}

int main () {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);

  auto height = 3;
  auto width = 10;
  auto starty = (LINES - height) / 2;
  auto startx = (COLS - width) / 2;
  printw("Press F1 to exit.");
  refresh();
  auto my_win = create_newwin(height, width, starty, startx);

  int ch;
  while ((ch = getch()) != KEY_F(1)) {
    switch(ch) {
    case KEY_LEFT:
      destroy_win(my_win);
      my_win = create_newwin(height, width, starty, --startx);
      break;
    case KEY_RIGHT:
      destroy_win(my_win);
      my_win = create_newwin(height, width, starty, ++startx);
      break;
    case KEY_UP:
      destroy_win(my_win);
      my_win = create_newwin(height, width, --starty, startx);
      break;
    case KEY_DOWN:
      destroy_win(my_win);
      my_win = create_newwin(height, width, ++starty, startx);
      break;
    }
  }

  endwin();
}
