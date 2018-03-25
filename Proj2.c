#include <stdio.h>
#include "Editor.h"

int main()
{

	// Creates the Ncurses Editor
	Editor editor;
	Editor *eptr = &editor;
	init(eptr);
}
