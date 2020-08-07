#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,a[101],max=0,min=101,maxIndex=0,minIndex=0;
    cin>>n;
    fl(i,0,n){
        cin>>a[i];
        if (a[i]>max){
            max=a[i];
            maxIndex=i;
        }
        if(a[i]<=min){
            min=a[i];
            minIndex=i;
        }
    }
    if (minIndex<maxIndex){
        cout<<maxIndex+n-2-minIndex;//awesome logic
    }
    else{
        cout<<maxIndex+n-1-minIndex;
    }
    return 0;
}