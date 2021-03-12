#include <bits/stdc++.h>
using namespace std;

//Checking if the current value is holds true or not
bool isCorrect(int row,int col, int curr,int grid[9][9]){

    //For same col
    for(int i=0;i<9;i++){
        if(grid[i][col]==curr) return false;
    }

    //For same row
    for(int i=0;i<9;i++){
        if(grid[row][i]==curr) return false;
    }

    //For same 3x3 box
    for(int i=0;i<9;i++){
        if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==curr) return false;
    }

    return true;
}

//Searching for empty cells
bool findEmptyCell(int &row,int &col,int grid[9][9]){
    for(row=0;row<9;row++){
        for(col=0;col<9;col++){
            if(grid[row][col]==0) return true;
        }
    }

    return false;
}

//Printing grid
void printGrid(int grid[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

//TIME COMPLEXITY: O(9*(N^2))
//SPACE COMPLEXITY: O(N^2)
bool solveSudoku(int (&grid)[9][9]){
    int row,col;

    //Checking for any empty cells...if no empty cells found that means we have traversed every cell of the grid and thus we have got our ans
    if(!findEmptyCell(row,col,grid)){
        return true;
    }

    for(int curr=1;curr<=9;curr++){

        //Checking if the value is apt or not
        if(isCorrect(row,col,curr,grid)){

            grid[row][col]=curr;
            if(solveSudoku(grid)) return true;
            grid[row][col]=0;
        }
    }

    return false;
}

int main(){
    int grid[9][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                     {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                     {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                     {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                     {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                     {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                     {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                     {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                     {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    
    if(solveSudoku(grid)){
        printGrid(grid);
    }
    else{
        cout<<"No solution exists";
    }
    return 0;
}