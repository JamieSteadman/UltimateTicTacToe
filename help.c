#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
#include "functions.h"
void help() {
    printf("Usage: ./grid \n\n"
           "This program creates a 9x9 grid GTK application with a grid of buttons.\n"
           "Each button represents a cell in a 9x9 grid, organized into nine 3x3 subgrids.\n\n"
           "When you click on a button, it alternates between 'X' and 'O', simulating a game turn.\n"
           "The buttons are indexed such that buttons[i][j], where:\n"
           "    - 'i' (0-8) represents the subgrid index (one of the nine 3x3 grids).\n"
           "    - 'j' (0-8) represents the box index within that subgrid.\n\n"
           "Run the program:\n"
           "    ./grid\n\n"
           "Optional Flags:\n"
           "    --help\n"
           "Example Usage:\n"
           "    ./grid\n"
           "    (Launches the GTK application with the 9x9 grid interface)\n\n"
           "Note:\n"
           "    - Ensure that GTK 3 development libraries are installed on your system.\n"
           "    - The application window displays a 9x9 grid with thicker borders outlining the nine 3x3 subgrids.\n"
           "    - Clicking on a button will place an 'X' or 'O', alternating each turn.\n"
           "    - The buttons become disabled after being clicked to prevent multiple selections.\n");
}
