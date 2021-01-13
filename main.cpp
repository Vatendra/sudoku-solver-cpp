#include <iostream>
using namespace std;
#define BLANK 0
#define N 9 // rows or columns in a sudoku
#define NN 3 // rows or columns of sudoku sub-grid

// Function definitions
bool inRow(int mat[N][N], int row, int key); // checks for the presence of a key number in a given row
bool inCol(int mat[N][N], int col, int key); // // checks for the presence of a key number in a given column
bool inSubGrid(int mat[N][N], int row, int col, int key); // checks for the presence of a key number in a given sub grid
bool isValid(int mat[N][N], int row, int col, int key); // checks whether it is valid to insert a number
bool emptyCells(int mat[N][N], int& row, int& col); // finds available empty cells
bool solve(int mat[N][N]); // recursive function to solve sudoku
void display(int mat[N][N]); // displays sudoku in a formatted manner.

int main() {
    int mat[N][N];
    cout << "----------Sudoku Solver----------" << endl;
    cout << "Input Problem Sudoku row wise.\nInput numbers separated by whitespace and 0 for blanks.\n " <<endl ;
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Entered Problem Sudoku : \n");
    display(mat);
    solve(mat);
    printf("Sudoku Solved : \n");
    display(mat);
    return 0;
}
bool inRow(int mat[N][N], int row, int key)
{
    for (int col = 0; col < N; col++)
        if (mat[row][col] == key)
            return true;
    return false;
}

bool inCol(int mat[N][N], int col, int key)
{
    for (int row = 0; row < N; row++)
        if (mat[row][col] == key)
            return true;
    return false;
}

bool inSubGrid(int mat[N][N], int row, int col, int key)
{
    for (int i = 0; row < NN; row++)
        for (int j = 0; col < NN; col++)
            if (mat[i + row]
                [j + col] == key)
                return true;
    return false;
}
bool solve(int mat[N][N])
{
    int row, col;

    // If no more empty cells, than sudoku is solved.
    if (!emptyCells(mat, row, col))
        // success!
        return true;

    // Trying digit from 1 to 9
    for (int num = 1; num <= N; num++)
    {

        // Check for validity
        if (isValid(mat, row, col, num))
        {

            // then pass value to matrix at current index
            mat[row][col] = num;

            // if this solves problem, return true
            if (solve(mat))
                return true;

            // Otherwise, make it blank
            mat[row][col] = BLANK;
        }
    }

    // This triggers backtracking
    return false;
}

bool emptyCells(int mat[N][N],
                int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (mat[row][col] == BLANK)
                return true;
    return false;
}



bool isValid(int mat[N][N], int row,
             int col, int key)
{
    return !inRow(mat, row, key)
           && !inCol(mat, col, key)
           && !inSubGrid(mat, row - row % NN,col - col % NN, key)
           && mat[row][col] == BLANK;
}
void display(int mat[N][N]){
    int i, j;
    for(i=0;i<N;i++){
        if(i%NN==0 && i>0){ // inserting extra line break to distinguish sub-grids
            cout << "\n";
        }
        for(j=0;j<N;j++){
            if(j%NN ==0 && j>0){
                printf(" %d ",mat[i][j]); // inserting space before to distinguish sub-grids
            }
            else{
                printf("%d ",mat[i][j]);
            }
        }
        cout << "\n";
    }
}
