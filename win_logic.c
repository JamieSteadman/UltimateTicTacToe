#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
#include <unistd.h>
#include "functions.h"

bool check_win(char board[3][3], char label) {
    // Check diagonals
    if (board[0][0] == label && board[1][1] == label && board[2][2] == label) {
        return true;
    }
    if (board[0][2] == label && board[1][1] == label && board[2][0] == label) {
        return true;
    }
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == label && board[i][1] == label && board[i][2] == label) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == label && board[1][j] == label && board[2][j] == label) {
            return true;
        }
    }
    return false;
}
