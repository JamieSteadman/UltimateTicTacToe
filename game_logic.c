#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <gtk/gtk.h>
#include "functions.h"

void enable_buttons(GtkWidget *board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            GtkWidget *button = board[i][j];
            const char *label_text = gtk_button_get_label(GTK_BUTTON(button));
            if (label_text == NULL || (strcmp(label_text, " ")) == 0) {
                gtk_widget_set_sensitive(button, TRUE);
                
                // Add bold border style for enabled buttons
                GtkStyleContext *context = gtk_widget_get_style_context(button);
                gtk_style_context_remove_class(context, "thick-left-2");
                gtk_style_context_add_class(context, "bold-border");
            }
        }
    }
}

void disable_buttons(GtkWidget *board[3][3]) {
    puts("Disabled");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            GtkWidget *button = board[i][j];
            gtk_widget_set_sensitive(button, FALSE);

            GtkStyleContext *context = gtk_widget_get_style_context(button);
            gtk_style_context_remove_class(context, "bold-border");
            gtk_style_context_add_class(context, "thick-left-2");
        }
    }
}

bool isFull(GtkWidget *board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            GtkWidget *button = board[i][j];
            const char *label_text = gtk_button_get_label(GTK_BUTTON(button));
            if (label_text == NULL || (strcmp(label_text, " ")) == 0) {
                return false;
            }
        }
    }
    return true;
}
