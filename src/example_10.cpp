/* Example 10 */
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int startx{};
int starty{};

const char *choices[] = {
  "Choice 1",
  "Choice 2",
  "Choice 3",
  "Choice 4",
  "Exit"
};

int n_choices = sizeof(choices) / sizeof(char *);

void print_menu (WINDOW *menu_win, int highlight) {
  int x {2};
  int y {2};
  box(menu_win, 0, 0);
  for (int i = 0 ; i < n_choices ; ++i) {
    if (highlight == i + 1) { /* Highlight the present choice */
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, y, x, "%s", choices[i]);
      wattroff(menu_win, A_REVERSE);
    } else {
      mvwprintw(menu_win, y, x, "%s", choices[i]);
    }
    ++y;
  }
  wrefresh(menu_win);
}

int main () {
  WINDOW *menu_win;
  int highlight {1};
  int choice {};

  initscr();
  clear();
  noecho();
  cbreak();
  startx = (80 - WIDTH) / 2;
  starty = (24 - HEIGHT) / 2;

  menu_win = newwin(HEIGHT, WIDTH, starty, startx);
  keypad(menu_win, TRUE);
  mvprintw(0, 0, "Use arrow keys to go up and down, press enter to select a choice.");
  refresh();
  print_menu(menu_win, highlight);
  while (1) {
    int c = wgetch(menu_win);
    switch(c) {
    case KEY_UP:
      if(highlight == 1)
        highlight = n_choices;
      else
        --highlight;
      break;
    case KEY_DOWN:
      if(highlight == n_choices)
        highlight = 1;
      else
        ++highlight;
      break;
    case 10: /* Enter */
      choice = highlight;
      break;
    default:
      mvprintw(24, 0, "Character pressed: %d", c);
      refresh();
      break;
    }
    print_menu(menu_win, highlight);
    if (choice != 0) /* Break out of while loop. */
      break;
  }
  mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
  clrtoeol();
  getch();
  refresh();
  endwin();
}
