#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//board = 9x9

int isValid(char** board, int row, int col, char num){
    for (int i = 0; i < 9; i++){
        if (board[row][i] == num) return 1;
        if(board[i][col] == num) return 1;

        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if(board[boxRow][boxCol] == num) return 1;
    }
    return 0;
}
int solve(char** board, int boardSize, int* boardColSize) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.'){
                for(char k = '1'; k <= '9'; k++){
                    int boolean = isValid(board, i, j, k);

                    if(boolean == 0){
                        board[i][j] = k;

                        int sudoku = solve(board, boardSize, boardColSize);

                        if(sudoku == 0) return 0;

                        board[i][j] = '.';
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board,boardSize,boardColSize); 
}

void printBoard(char** board) {
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0 && i != 0){
            printf("------+-------+------\n");
        }

        for(int j = 0; j < 9; j++){
            if(j % 3 == 0 && j != 0){
                printf("| ");
            }
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char row0[] = {'5','3','.','.','7','.','.','.','.'};
    char row1[] = {'6','.','.','1','9','5','.','.','.'};
    char row2[] = {'.','9','8','.','.','.','.','6','.'};
    char row3[] = {'8','.','.','.','6','.','.','.','3'};
    char row4[] = {'4','.','.','8','.','3','.','.','1'};
    char row5[] = {'7','.','.','.','2','.','.','.','6'};
    char row6[] = {'.','6','.','.','.','.','2','8','.'};
    char row7[] = {'.','.','.','4','1','9','.','.','5'};
    char row8[] = {'.','.','.','.','8','.','.','7','9'};

    char* board[] = {
        row0, row1, row2,
        row3, row4, row5,
        row6, row7, row8
    };

    int boardSize = 9;
    int boardColSize[9] = {9,9,9,9,9,9,9,9,9};

    printf("Sudoku inicial:\n\n");
    printBoard(board);

    solveSudoku(board, boardSize, boardColSize);

    printf("\nSudoku resolvido:\n\n");
    printBoard(board);

    return 0;
}