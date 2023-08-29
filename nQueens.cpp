#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check to see if there exists a queen in the same column
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 1)
            return false;

    // Checking upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1)
            return false;

    // Checking upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 1)
            return false;

    return true;
}

//backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueensUtil(board, row + 1, n)) // recursive call
                return true;
            board[row][col] = 0; //backtrack
        }
    }

    return false;
}

void nqueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0)); //this is the board
    if (solveNQueensUtil(board, 0, n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << (board[i][j] ? "Q" : ".") << " "; // printing the board
            cout << "\n";
        }
    }
    else {
        cout << "No solution exists.\n";
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    nqueens(n);
    return 0;
}
