#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define vi          vector<int>
#define vll         vector<ll>
#define pb          push_back
#define mod         1000000007

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main(){
    kkvanonymous();
    int n,sum,c=0;
    char a[101][101];
    cin>>n;
    fl(i,0,n){
        fl(j,0,n){
            cin>>a[i][j];
        }
    }
      fl(i,0,n){
        fl(j,0,n){
            sum=0;
            if ((i-1)>=0 && a[i-1][j]=='o'){
                sum++;
            }
            if((i+1)<n && a[i+1][j]=='o'){
               sum++;
            }
            if((j+1)<n && a[i][j+1]=='o' ){
                sum++;
            }
            if((j-1)>=0 && a[i][j-1]=='o'){
                sum++;
            }
            
            if (sum%2==0){
                c++;
            }
        }   
    }
    if(c==(n*n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}