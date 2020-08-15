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
    string o="";
    cin>>s;
    fl(i,0,s.length()){
        if (s[i]=='a' || s[i]=='e' ||  s[i]=='i' ||  s[i]=='o' ||  s[i]=='u' ||  s[i]=='y'|| s[i]=='A' || s[i]=='E' ||  s[i]=='I' ||  s[i]=='O' ||  s[i]=='U' ||  s[i]=='Y'){
            continue;
        }
        else if((int)s[i]>=65 && (int)s[i]<=90){
            o=o+"."+(char)((int)s[i]+32);
        }
        else{
            o=o+"."+s[i];
        }
    };
    cout<<o;
    return 0;
}