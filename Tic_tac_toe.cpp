#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char currentPlayer, int row, int col);
bool checkWin(const vector<vector<char>>& board, char currentPlayer);
bool checkDraw(const vector<vector<char>>& board);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        initializeBoard(board);
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, currentPlayer, row, col)) {
                gameWon = checkWin(board, currentPlayer);
                gameDraw = checkDraw(board);
                currentPlayer = switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        }

        displayBoard(board);

        if (gameWon) {
            cout << "Player " << switchPlayer(currentPlayer) << " wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

    } while (playAgain());

    return 0;
}

void initializeBoard(vector<vector<char>>& board) {
    for (auto& row : board) {
        for (char& cell : row) {
            cell = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool makeMove(vector<vector<char>>& board, char currentPlayer, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char>>& board, char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;  // Horizontal win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;  // Vertical win
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;  // Diagonal win (top-right to bottom-left)
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  // If there's an empty space, the game is not a draw yet
            }
        }
    }
    return true;  // All spaces are filled, and no player has won
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}
