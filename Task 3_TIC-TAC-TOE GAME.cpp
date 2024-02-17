#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board with classic graphics
void displayBoard(const vector<vector<char>>& board, const vector<pair<int, int>>& winLine = {}) {
    cout << "  1 | 2 | 3 " << endl;
    cout << " -----------" << endl;
    cout << "  4 | 5 | 6 " << endl;
    cout << " -----------" << endl;
    cout << "  7 | 8 | 9 " << endl;

    cout << "Current Board:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            if (!winLine.empty() && make_pair(i, j) == winLine[0]) {
                cout << "\033[1m" << board[i][j] << "\033[0m";
            } else if (!winLine.empty() && make_pair(i, j) == winLine[1]) {
                cout << "\033[1m" << board[i][j] << "\033[0m";
            } else if (!winLine.empty() && make_pair(i, j) == winLine[2]) {
                cout << "\033[1m" << board[i][j] << "\033[0m";
            } else {
                cout << board[i][j];
            }
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "-----------" << endl;
    }
}

// Function to check if the current player has won and return the winning line
vector<pair<int, int>> checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player)) {
            return {{i, 0}, {i, 1}, {i, 2}};
        }
        if ((board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return {{0, i}, {1, i}, {2, i}};
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player)) {
        return {{0, 0}, {1, 1}, {2, 2}};
    }
    if ((board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return {{0, 2}, {1, 1}, {2, 0}};
    }
    return {};
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // Empty cell found, game not draw
        }
    }
    return true; // All cells filled, game is draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X';

    cout << "Welcome to the Classic Tic-Tac-Toe Game!" << endl;

    do {
        // Display the current state of the board with classic graphics
        displayBoard(board);

        // Player input
        int position;
        cout << "Player " << currentPlayer << ", enter the position number where you want to place your mark: ";
        cin >> position;

        // Check if the chosen position is valid
        if (position < 1 || position > 9) {
            cout << "Invalid position! Please enter a number between 1 and 9." << endl;
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        // Check if the chosen cell is already occupied
        if (board[row][col] != ' ') {
            cout << "Position already occupied! Please choose a different position." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check for a win
        vector<pair<int, int>> winLine = checkWin(board, currentPlayer);
        if (!winLine.empty()) {
            displayBoard(board, winLine);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    cout << "Thanks for playing! Do you want to play again? (Y/N): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
        main(); // Restart the game
    } else {
        cout << "Goodbye!" << endl;
    }

    return 0;
}
