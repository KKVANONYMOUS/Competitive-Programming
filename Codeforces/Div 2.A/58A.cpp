#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    string s;
    string target="hello";
    int c=0;
    cin>>s;
    fl(i,0,s.size()){
        if (s[i]==target[c]){
            c++;
        }
    }
    if (c==5){
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}