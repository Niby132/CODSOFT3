// Task 3: Tic-Tac-Toe

#include <iostream>
using namespace std;

// Function to check for a horizontal win
bool checkHorizontalWin(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        if (board[row][0] != '-' && 
            board[row][0] == board[row][1] && 
            board[row][1] == board[row][2]) {
            return true;
        }
    }
    return false;
}

// Function to check for a vertical win
bool checkVerticalWin(char board[3][3]) {
    for (int col = 0; col < 3; col++) {
        if (board[0][col] != '-' && 
            board[0][col] == board[1][col] && 
            board[1][col] == board[2][col]) {
            return true;
        }
    }
    return false;
}

// Function to check for diagonal wins
bool checkDiagonalWins(char board[3][3]) {
    // Check top-left to bottom-right
    if (board[0][0] != '-' && 
        board[0][0] == board[1][1] && 
        board[1][1] == board[2][2]) {
        return true;
    }
    // Check top-right to bottom-left
    if (board[0][2] != '-' && 
        board[0][2] == board[1][1] && 
        board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

// Function to display the game board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == '-') {
                return false;
            }
        }
    }
    return true;
}

// Function to place a player's mark on the board
void placeMark(char board[3][3], int row, int col, int currentPlayer) {
    if (currentPlayer == 1) {
        board[row][col] = 'X';
    } 
    else {
        board[row][col] = 'O';
    }
}

// Function to check if a cell is occupied
bool isCellOccupied(char board[3][3], int row, int col) {
    return (board[row][col] == 'X' || board[row][col] == 'O');
}

int main() {
start:
    char board[3][3];
    fill_n(&board[0][0], 9, '-'); // Initialize the game board with '-'

    int currentPlayer = 1; // Player 1 starts with 'X'
    
    cout << "Welcome to Tic-Tac-Toe!\n";
    
    while (true) {
        int startingPlayer;
        cout << "Choose who goes first (1 or 2): ";
        cin >> startingPlayer;

        if (startingPlayer == 1 || startingPlayer == 2) {
            currentPlayer = startingPlayer;
            break;
        } else {
            cout << "Invalid input! Please enter 1 or 2.\n";
        }
    }

    while (true) {
        displayBoard(board);
        
        int row, col;
        
        while (true) { // Input loop for valid moves
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Adjust for zero-based indexing
            row--;
            col--;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && !isCellOccupied(board, row, col)) {
                placeMark(board, row, col, currentPlayer);
                break;
            } else {
                cout << "Invalid move! Try again.\n";
            }
        }

        // Check for a win or tie
        if (checkHorizontalWin(board) || checkVerticalWin(board) || checkDiagonalWins(board)) {
            displayBoard(board);
            cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a tie! The board is full.\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1; 
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        goto start; // Restart the game
    }

    return 0;
}