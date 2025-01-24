Ultimate Tic Tac Toe


Purpose

This application implements an Ultimate Tic Tac Toe game with a graphical user interface (GUI) built using GTK. The game is played on a 9x9 grid subdivided into nine 3x3 subgrids, each representing a standard Tic Tac Toe board. This project expands the classic Tic Tac Toe mechanics, offering a more strategic and challenging experience.

How It Works

The game window presents a 9x9 grid, composed of nine 3x3 subgrids.
Players alternate turns by clicking on empty cells. 'X' always goes first.
Each clicked button is immediately disabled to prevent re-selection.
Once a move is made in a subgrid, the next player must play in the corresponding subgrid that matches the position of the last played cell. For example, if a player selects the middle-right cell of a subgrid, the opponent’s next move must be made in the subgrid at the middle-right position of the 3x3 overall layout.
If the targeted subgrid is fully occupied (no empty cells), the player can make a move in any other available subgrid.

Winning Conditions

Each 3x3 subgrid can be “won” by getting three of the same symbol (X or O) in a row (horizontally, vertically, or diagonally).
Once a subgrid is won, it is effectively “closed” for strategic purposes.
A sub-board victory is detected as soon as a player completes a winning line in that 3x3 subgrid.
When a sub-board is won, the application announces the winner of that sub-board, closes the current game window, and prints out updated win counts for both X and O in the terminal.

Restarting the Game

After a sub-board victory and the game window closes, the terminal will ask:
bash
Do you want to restart the game? (yes/no):
If you enter "yes", the game restarts with a fresh 9x9 grid, retaining the accumulated win counts for X and O across multiple plays.
If you enter "no", the application exits.

Run the Program
Ensure GTK 3 development libraries are installed on your system.

Compile the program using:

"make main" command

Run the application:

./grid

Command Line Options:

--HELP: Displays usage instructions and a brief overview of how to play.

Example:
./grid --HELP

Example Usage

./grid
This launches the GTK application with the 9x9 Ultimate Tic Tac Toe board.

Notes
The interface visually distinguishes the nine 3x3 subgrids with thicker borders and optional styling changes.
Clicking a button places an 'X' or 'O', alternating turns.
Once clicked, buttons are disabled to prevent multiple selections.
The game keeps track of cumulative wins across multiple sessions if you choose to restart after each sub-board victory.

Enjoy strategizing and challenging yourself or others in Ultimate Tic Tac Toe!