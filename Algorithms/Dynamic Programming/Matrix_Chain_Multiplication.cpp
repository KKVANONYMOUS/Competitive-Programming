#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector <vector <int>> m(n,vector <int> (n,0));

    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){
            int j=i+d;
            int min=INT_MAX;
            int q=0;
            for(int k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<min){
                    min=q;
                }
            }
            m[i][j]=min;
        }
    }

    cout<<m[1][n-1];
}