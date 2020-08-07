#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int matrix[6][6];
    fl(i,0,5){
        fl(j,0,5){
            cin>>matrix[i][j];
            
        }
    }
    fl(i,0,5){
        fl(j,0,5){
            if (matrix[i][j]==1){
                cout<<abs(2-i)+abs(2-j);
                break;
            }
            
        }
    }
    return 0;
}