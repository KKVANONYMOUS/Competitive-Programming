#include <bits/stdc++.h>
using namespace std;

const int n=5;

void printSolution(int board[n][n]){
    for(int i=0;i<n;i++){
        for(int j=.0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row,int col,int board[n][n]){

    //For same col
    for(int j=0;j<n;j++){
        if(board[j][col]) return false;
    }
 
    //For upper left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]) return false;
    }

    //For upper right diagonal
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]) return false;
    }
    return true;
}

bool solveNQueen(int row,int board[n][n]){
    if(row==n){
        printSolution(board);
        return true;
    }

    bool res=false;
    for(int col=0;col<n;col++){
        if(isSafe(row,col,board)){

            board[row][col]=1;
            res=solveNQueen(row+1,board);
            board[row][col]=0;
            
        }
    }

    return res;

}
int main(){
    int board[n][n];
    memset(board, 0, sizeof(board[0][0]) * n * n);
    if(!solveNQueen(0,board)){
        cout<<"No solution\n";
    }
}