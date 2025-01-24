// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <gtk/gtk.h>
#include <stdbool.h>  // For bool, true, false

// External variable declarations
extern GtkWidget *buttons[3][3][3][3];
extern bool x;             // If used across multiple files
extern bool forTesting;

// Function declarations
void on_button_clicked(GtkWidget *button, gpointer user_data);
void activate(GtkApplication *app, gpointer user_data);
void help();
bool check_win(char board[3][3], char label);

void disable_grids(int row, int column);
void enable_buttons(GtkWidget *board[3][3]);
void disable_buttons(GtkWidget *board[3][3]);
bool isFull(GtkWidget *board[3][3]);

gboolean quit_application(gpointer app);

#endif // FUNCTIONS_H
