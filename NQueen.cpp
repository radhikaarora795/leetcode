#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;      // Stores all valid solutions
    vector<string> board;               // To build chessboard configuration
    vector<bool> col, diag1, diag2;     // Column, Main diagonal, Anti-diagonal trackers
    int n;

    void solveNQueensUtil(int row) {
        // If all queens are placed successfully
        if (row == n) {
            result.push_back(board);
            return;
        }

        // Try placing queen in each column of current row
        for (int c = 0; c < n; c++) {
            /*
                Conditions to check if we can place a queen at (row, c):
                1. col[c]     → column must be free
                2. diag1[row - c + n - 1] → main diagonal (\) must be free
                3. diag2[row + c] → anti diagonal (/) must be free
            */
            if (!col[c] && !diag1[row - c + n - 1] && !diag2[row + c]) {

                // Place the queen
                board[row][c] = 'Q';
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;

                // Recurse to next row
                solveNQueensUtil(row + 1);

                // Backtrack (undo the move)
                board[row][c] = '.';
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string>(n, string(n, '.'));
        /*
        Create an array (vector) of size n, where each element is a string of length n filled with '.'
        Example: If n = 4, it creates:
        {
        "....",
        "....",
        "....",
        "...."
        }
        */
        col = vector<bool>(n, false);
        /*
        We use arrays of size 2*n - 1 because:
        A chessboard of size n × n has exactly 2n − 1 diagonals in each direction 
        (main and anti-diagonal). To check attacks in O(1) time, we map each 
        diagonal to an index in a boolean array of size 2n−1.
        */
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        solveNQueensUtil(0);
        return result;
    }
};

int main() {
     int n;
    cout << "Enter number of queens: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> solutions = obj.solveNQueens(n);

    cout << "\nTotal Solutions: " << solutions.size() << "\n\n";

    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (auto &row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}