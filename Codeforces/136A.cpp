#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,arr[101],output[101];
    cin>>n;
    fl(i,0,n){
        cin>>arr[i];
    }
    fl(i,0,n){
        output[arr[i]-1]=i+1;
    }
    cout<<output[0];
    fl(i,1,n){
        cout<<" "<<output[i];
    }
    return 0;
}