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
    cin>>s;
    int num[102];
    int n=0;
    for(int i=0;i<s.size();i+=2){
        num[n]=s[i]-48;
        n++;
    }
    sort(num,num+s.size()/2+1);
    cout<<num[0];
    fl(i,1,s.size()/2+1){
        cout<<"+"<<num[i];
    }

    return 0;
}