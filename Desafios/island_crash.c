#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char **island, int row, int col, int gridSize, int* gridColSize){
    if(island[row][col] == '0') return;
    island[row][col] = '0';

    if(row - 1 >= 0 && island[row - 1][col] != '0') search(island, row - 1, col, gridSize, gridColSize);
    if(row + 1 < gridSize && island[row + 1][col] != '0') search(island, row + 1, col, gridSize, gridColSize);
    if(col - 1 >= 0 && island[row][col - 1] != '0') search(island, row, col - 1, gridSize, gridColSize); 
    if(col + 1 < *gridColSize && island[row][col + 1] != '0') search(island, row, col + 1, gridSize, gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int cont = 0;
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == '1'){
                search(grid,i,j, gridSize, gridColSize);
                cont++;
            }
        }
    }
    return cont;
}

void printGrid(char **grid, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    int rows = 4;
    int cols = 5;
    int gridColSize = cols;

    char data[4][5] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    char **grid = malloc(rows * sizeof(char *));
    if(grid == NULL){
        printf("Erro de alocacao.\n");
        return 1;
    }

    for(int i = 0; i < rows; i++){
        grid[i] = malloc(cols * sizeof(char));
        if(grid[i] == NULL){
            printf("Erro de alocacao.\n");
            return 1;
        }
        for(int j = 0; j < cols; j++){
            grid[i][j] = data[i][j];
        }
    }

    printf("Matriz antes:\n");
    printGrid(grid, rows, cols);

    int result = numIslands(grid, rows, &gridColSize);

    printf("Numero de ilhas: %d\n\n", result);

    printf("Matriz depois:\n");
    printGrid(grid, rows, cols);

    for(int i = 0; i < rows; i++){
        free(grid[i]);
    }
    free(grid);

    return 0;
}