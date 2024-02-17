#include <iostream>
#include <vector>

using namespace std;

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

vector<pair<int, int>> checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player)) {
            return {{i, 0}, {i, 1}, {i, 2}};
        }
        if ((board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return {{0, i}, {1, i}, {2, i}};
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player)) {
        return {{0, 0}, {1, 1}, {2, 2}};
    }
    if ((board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return {{0, 2}, {1, 1}, {2, 0}};
    }
    return {};
}

// Fame Draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; 
        }
    }
    return true; 
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X';

    cout << "Welcome to the Classic Tic-Tac-Toe Game!" << endl;

    do {
        displayBoard(board);

        int position;
        cout << "Player " << currentPlayer << ", enter the position number where you want to place your mark: ";
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid position! Please enter a number between 1 and 9." << endl;
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] != ' ') {
            cout << "Position already occupied! Please choose a different position." << endl;
            continue;
        }
        board[row][col] = currentPlayer;

        vector<pair<int, int>> winLine = checkWin(board, currentPlayer);
        if (!winLine.empty()) {
            displayBoard(board, winLine);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    cout << "Thanks for playing! Do you want to play again? (Y/N): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
        main();
    } else {
        cout << "Goodbye!" << endl;
    }

    return 0;
}
