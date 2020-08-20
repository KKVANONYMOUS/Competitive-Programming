#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define all(c)      c.begin(), c.end()
#define vi          vector<int>
#define vll         vector<ll>
#define pii         pair<int,int>
#define pb          push_back
#define mp          make_pair
#define f           first
#define s           second
#define mod         1000000007

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}

int main(){
    kkvanonymous();
    string s;
    cin>>s;
    int pivot;
    fl(i,0,s.size()){
        if (s[i]=='^'){
            pivot=i;
        }
    }
    ll left=0;
    fl(i,0,pivot){
        if (s[i]!='='){
            left+=(s[i]-'0')*(pivot-i);
        }
    }
    ll right=0;
    fl(i,pivot+1,s.size()){
        if (s[i]!='='){
            right+=(s[i]-'0')*(i-pivot);
        }
    }
    if (left==right){
        cout<<"balance";
    }
    else if(left<right){
        cout<<"right";
    }
    else{
        cout<<"left";
    }
    return 0;
}