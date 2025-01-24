#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
#include "functions.h"

// External declarations of global variables
extern GtkWidget *buttons[3][3][3][3];
extern bool x;
extern int OneWins;
extern int TwoWins;

typedef struct {
    int row;
    int col;
    int subRow;
    int subCol;
    GtkApplication *app;
    GtkWidget *window;
} ButtonData;


gboolean delayed_quit(gpointer user_data) {
    ButtonData *data = (ButtonData *)user_data;
    gtk_widget_destroy(data->window); // Destroy the window
    g_application_quit(G_APPLICATION(data->app));
    free(data); // Free the allocated memory for the data struct
    return FALSE; // Stop the timeout
}


/* Signal handler for button clicks */
void on_button_clicked(GtkWidget *button, gpointer user_data) {
    ButtonData *data = (ButtonData *)user_data;
    

    // Disable the clicked button
    gtk_widget_set_sensitive(button, FALSE);

    // Set the button label based on the current value of `x`
    char current_label = x ? 'X' : 'O';
    gtk_button_set_label(GTK_BUTTON(button), &current_label);

    // Toggle `x` to switch between "X" and "O"
    x = !x;

    // Log the pressed button's coordinates
    printf("Button pressed at [%d][%d][%d][%d]\n", data->row, data->col, data->subRow, data->subCol);

    // Create a 3x3 char array representing the current state of the sub-board
    char subBoard[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            const char *label = gtk_button_get_label(GTK_BUTTON(buttons[data->row][data->col][i][j]));
            subBoard[i][j] = (label != NULL && label[0] != '\0') ? label[0] : ' ';  // Use ' ' for unclicked buttons
        }
    }

    // Check if the current sub-board has a winner
    bool subBoardWinner = check_win(subBoard, current_label);

    if (subBoardWinner == true) {
        printf("Sub game finished. Closing application.\n");

        // Update win counts
        if (current_label == 'X') {
            OneWins += 1;
        } else {
            TwoWins += 1;
        }

        printf("Player 1 with X has %d win(s)\nPlayer 2 with O has %d win(s)\n\n", OneWins, TwoWins);

        // Schedule the application to quit after 100 milliseconds
        g_timeout_add(100, delayed_quit, data);

        return; // Exit the function to prevent freeing 'data' prematurely
    }
    else {
        disable_grids(data->subRow, data->subCol);
    }

    // Free the allocated memory for the data struct
    free(data);
}


/* Activate the application window */
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;

    /* Create a new window */
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "9x9 Grid Click to 'X'");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    /* Create a new grid layout */
    grid = gtk_grid_new();

    /* Add the grid to the window */
    gtk_container_add(GTK_CONTAINER(window), grid);

    /* Create a CSS provider for styling */
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider,
        "button { "
        "   border: 1px solid black; "

        "   font-size: 16px; "
        "} "
        ".bold-border { "
        "   border-width: 3px; background-color : green; "
        "} "
        ".thick-left { border-left-width: 3px; } "
        ".thick-left-2 { border-left-width: 1px; background-color : white; } "
        ".thick-right { border-right-width: 3px; } "
        ".thick-top { border-top-width: 3px; } "
        ".yes {background-color : green; border-left-width: 1px; }"
        ".no { background-color: white }"
        ".thick-bottom { border-bottom-width: 3px; } ",
        -1, NULL);

    /* Create a 9x9 grid of buttons */
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            for (int subRow = 0; subRow < 3; subRow++) {
                for (int subCol = 0; subCol < 3; subCol++) {
                    // Create a button for the specific grid location
                    buttons[row][col][subRow][subCol] = gtk_button_new();

                    /* Set the size of each button to make it square */
                    gtk_widget_set_size_request(buttons[row][col][subRow][subCol], 60, 60);

                    /* Remove the focus outline */
                    gtk_widget_set_can_focus(buttons[row][col][subRow][subCol], FALSE);
                    
                    ButtonData *data = malloc(sizeof(ButtonData));
                    data->row = row;
                    data->col = col;
                    data->subRow = subRow;
                    data->subCol = subCol;
                    data->app = app;
                    data->window = window; // Add this line

                    /* Connect the "clicked" signal */
                    g_signal_connect(buttons[row][col][subRow][subCol], "clicked", G_CALLBACK(on_button_clicked), data);

                    /* Get the style context of the button */
                    GtkStyleContext *context = gtk_widget_get_style_context(buttons[row][col][subRow][subCol]);

                    /* Add CSS classes based on position to create thicker borders */
                    if (subCol == 2)
                        gtk_style_context_add_class(context, "thick-right");
                    if (subRow == 2)
                        gtk_style_context_add_class(context, "thick-bottom");

                    // Attach the button to the grid at (col, row)
                    gtk_grid_attach(GTK_GRID(grid), buttons[row][col][subRow][subCol], col * 3 + subCol, row * 3 + subRow, 1, 1);
                }
            }
        }
    }

    /* Add the CSS provider to the screen */
    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);
    
    /* Show all widgets within the window */
    gtk_widget_show_all(window);
}

void disable_grids(int subRow, int subCol) {
    bool fullGrid = false;
    if (isFull(buttons[subRow][subCol])) {
        fullGrid = true;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == subRow && j == subCol || fullGrid == true) {
                enable_buttons(buttons[i][j]);
            }
            else {
                disable_buttons(buttons[i][j]); 
            }
        }
    }
}
