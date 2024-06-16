/* Example 12 */
#include <ncurses.h>

int main()
{
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!\n");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
  getch();
	def_prog_mode();		/* Save the tty modes		  */
	endwin();			/* End curses mode temporarily	  */

  /* Do whatever you like in cooked mode */

	reset_prog_mode();		/* Return to the previous tty mode*/
					/* stored by def_prog_mode() 	  */
	refresh();			/* Do refresh() to restore the	  */
					/* Screen contents		  */
	printw("Another String\n");	/* Back to curses use the full    */
	refresh();			/* capabilities of curses	  */
  getch();
	endwin();			/* End curses mode		  */

}
