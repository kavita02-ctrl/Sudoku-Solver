#include <iostream>
using namespace std;

#define N 9

void getUserInput(int board[N][N]) {
    cout <<"Enter the Sudoku grid (use 0 for empty cells):\n";
    cout <<"You can skip any entry by pressing 'Enter' \n";

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int input;
            cout <<"Enter value for cell [" << row + 1 << "][" << col + 1 << "] (Current: " << board[row][col] << "): ";
            cin >> input;

            
            if (input >= 0 && input <= 9) {
                if (input != 0) {
                    board[row][col] = input;
                }
            } else {
                cout <<"Invalid input! Please enter a number between 0 and 9.\n";
                col--; 
            }
        }
    }
}

bool isValid(int board[N][N], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            return false;

    // Check the column
    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    // Check the 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool findEmptyLocation(int board[N][N], int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (board[row][col] == 0)
                return true;
    return false;
}

bool solveSudoku(int board[N][N]) {
    int row, col;

    // If there is no empty cell left, return true
    if (!findEmptyLocation(board, row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board))
                return true;
            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << board[row][col] << " ";
        cout << endl;
    }
}

bool isBoardValid(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        bool rowCheck[N + 1] = {false};
        for (int col = 0; col < N; col++) {
            if (board[row][col] != 0) {
                if (rowCheck[board[row][col]])
                    return false;
                rowCheck[board[row][col]] = true;
            }
        }
    }

    for (int col = 0; col < N; col++) {
        bool colCheck[N + 1] = {false};
        for (int row = 0; row < N; row++) {
            if (board[row][col] != 0) {
                if (colCheck[board[row][col]])
                    return false;
                colCheck[board[row][col]] = true;
            }
        }
    }

    for (int startRow = 0; startRow < N; startRow += 3) {
        for (int startCol = 0; startCol < N; startCol += 3) {
            bool subgridCheck[N + 1] = {false};
            for (int row = startRow; row < startRow + 3; row++) {
                for (int col = startCol; col < startCol + 3; col++) {
                    if (board[row][col] != 0) {
                        if (subgridCheck[board[row][col]])
                            return false;
                        subgridCheck[board[row][col]] = true;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    getUserInput(board);

    if (isBoardValid(board)) {
        if (solveSudoku(board))
            printBoard(board);
        else
            cout <<"No solution exists"<< endl;
    } else {
        cout <<"Your Sudoku is not correctly formed, It is incorrect."<< endl;
    }

    return 0;
}
