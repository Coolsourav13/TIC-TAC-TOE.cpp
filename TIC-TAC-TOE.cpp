#include <iostream>
#include <vector>

// Function to initialize the game board
void InitializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        std::vector<char> row(3, ' ');
        board.push_back(row);
    }
}

// Function to display the game board
void DisplayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "  -+-+-" << std::endl;
    }
}

// Function to check if a player has won
bool CheckWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        // Check columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the game is a draw
bool CheckDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    bool playAgain;
    do {
        std::vector<std::vector<char>> board;
        InitializeBoard(board);

        char currentPlayer = 'X';
        bool gameIsOver = false;

        std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

        do {
            // Display the current state of the board
            DisplayBoard(board);

            // Get the current player's move
            int row, col;
            do {
                std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                std::cin >> row >> col;
                row--; // Adjust for 0-based indexing
                col--; // Adjust for 0-based indexing
            } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ');

            // Update the board with the player's move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (CheckWin(board, currentPlayer)) {
                DisplayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameIsOver = true;
            }
            // Check if the game is a draw
            else if (CheckDraw(board)) {
                DisplayBoard(board);
                std::cout << "It's a draw!" << std::endl;
                gameIsOver = true;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        } while (!gameIsOver);

        std::cout << "Do you want to play again? (1 for Yes, 0 for No): ";
        std::cin >> playAgain;

    } while (playAgain);

    std::cout << "Thank you for playing Tic-Tac-Toe!" << std::endl;

    return 0;
}
