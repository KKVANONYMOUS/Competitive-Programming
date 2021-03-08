#include <bits/stdc++.h>
using namespace std;

const int n=4;

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
    for(int j=0;j<n;j++){
        if(board[j][col]) return false;
    }
    if(row>0){
        if(col>0 and board[row-1][col-1]) return false;
        if(col<n-1 and board[row-1][col+1]) return false;
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
            
            res=solveNQueen(row+1,board) || res;

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