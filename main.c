#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
#include <unistd.h>
#include "functions.h"
// Global 2D array to store button references and state variable

// Function declarations
GtkWidget *buttons[3][3][3][3];
bool x;
bool forTesting = false;
int OneWins = 0;
int TwoWins = 0;

void help();
void activate(GtkApplication *app, gpointer user_data);

gboolean quit_application(gpointer app) {
    g_application_quit(G_APPLICATION(app));
    return FALSE; // Stop the timeout from repeating
}

// Global variables (should be declared in a header file if used across multiple files)


int main(int argc, char *argv[]) {
    // Managing help output
    if (argc == 2) {
        if (strcmp(argv[1], "--HELP") == 0) {
            help();
            return EXIT_SUCCESS;
        }
    }

    int status;
    char restart_choice[10];

    do {
        x = true; // Reset the global variable before starting the game

        GtkApplication *app;

        // Create a new application
        app = gtk_application_new("org.example.grid9x9click", G_APPLICATION_FLAGS_NONE);

        // Connect the activate signal
        g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

        puts("Ultimate Tic Tac Toe has been successfully launched");

        if (forTesting) {
            g_timeout_add(2000, quit_application, app);
        }

        // Run the application
        status = g_application_run(G_APPLICATION(app), argc, argv);

        // Clean up
        g_object_unref(app);

        // Prompt the user for a restart
        printf("Do you want to restart the game? (yes/no): ");
        scanf("%9s", restart_choice);
    } while (strcmp(restart_choice, "yes") == 0);

    return status;
}