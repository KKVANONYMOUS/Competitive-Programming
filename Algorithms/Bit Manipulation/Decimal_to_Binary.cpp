#include<bits/stdc++.h>
using namespace std;

int decimal_to_binary(int n){
    int p=1;
    int ans=0;
    while(n>0){
        int x=(n&1);
        ans+=(p*x);
        p*=10;
        n=n>>1;
    }
    return ans;
}

int main(){
    int n=10;
    cout<<decimal_to_binary(n);
    return 0;
}
