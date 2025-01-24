#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
#include <unistd.h>
#include "functions.h"

GtkWidget *buttons[3][3][3][3];
bool x;
bool forTesting = false;
int OneWins = 0;
int TwoWins = 0;

void resetBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}
int main() {
    bool win = false;
    bool failed = false;
    char board[3][3];

    puts("Testing check_win():");

    //Diagonal win case
    board[0][0] = 'x';
    board[1][1] = 'x';
    board[2][2] = 'x';
    win = check_win(board, 'x');
    if (win == true) {
        puts("Test case 1 Passed");
    }
    else {
        puts("Test case 1 Failed");
        failed = true;
    }

    //Diagonal netural case
    board[0][0] = 'x';
    board[1][1] = 'o';
    board[2][2] = 'x';
    win = check_win(board, 'x');
    if (win == false) {
        puts("Test case 2 Passed");
    }
    else {
        puts("Test case 2 Failed");
        failed = true;
    }
    resetBoard(board);

    //Row win case
    board[2][0] = 'o';
    board[2][1] = 'o';
    board[2][2] = 'o';
    win = check_win(board, 'o');
    if (win == true) {
        puts("Test case 3 Passed");
    }
    else {
        puts("Test case 3 Failed");
        failed = true;
    }
    
    //Row netural case
    board[2][2] = 'x';
    win = check_win(board, 'o');
    if (win == false) {
        puts("Test case 4 Passed");
    }
    else {
        puts("Test case 4 Failed");
        failed = true;
    }
    resetBoard(board);
    
    //Column win case
    board[0][2] = 'x';
    board[1][2] = 'x';
    board[2][2] = 'x';
    win = check_win(board, 'x');
    if (win == true) {
        puts("Test case 5 Passed");
    }
    else {
        puts("Test case 5 Failed");
        failed = true;
    }

    //Column neutral case
    board[2][2] = ' ';
    win = check_win(board, 'x');
    if (win == false) {
        puts("Test case 6 Passed");
    }
    else {
        puts("Test case 6 Failed");
        failed = true;
    }
    resetBoard(board);
}