#include <bits/stdc++.h>
using namespace std;

bool isOdd(int n){
    return (1&n);
}
int getBit(int n,int i){
    int mask=(n>>i);
    return (1&mask)>0 ? 1:0;
}
void setBit(int &n,int i){
    int mask=(1<<i);
    n=n^mask;
}
void clearBit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
}
void updateBit(int &n,int i,int v){
    int mask=(v<<i);
    int cleared_n=n&(~(1<<i));
    n=cleared_n|mask;
}
int main(){
    cout<<isOdd(3)<<"\n";
    cout<<isOdd(4)<<"\n";
    for(int i=0;i<4;i++){
        cout<<i<<"-->"<<getBit(14,i)<<"\n";
    }
    int n=10;
    setBit(n,2);
    cout<<n<<"\n";
    clearBit(n,2);
    cout<<n<<"\n";
    updateBit(n,0,1);
    cout<<n<<"\n";
    
}