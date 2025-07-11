#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize the game board with numbers 1–9
void initializeBoard() {
    char cell = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = cell++;
}

// Display the current board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

// Switch between players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Make a move on the board
bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

// Check if the current player has won
bool checkWin() {
    // Rows, Columns, Diagonals
    for (int i = 0; i < 3; i++) {
        if (
            (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
        )
            return true;
    }

    if (
        (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    )
        return true;

    return false;
}

// Check if the board is full (draw)
bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameEnded = false;

        cout << "===========================\n";
        cout << "   Welcome to Tic-Tac-Toe\n";
        cout << "===========================\n";

        while (!gameEnded) {
            displayBoard();
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (makeMove(move)) {
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameEnded = true;
                } else if (isDraw()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    gameEnded = true;
                } else {
                    switchPlayer();
                }
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}
