#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    string a,b;
    int scorea,scoreb;
    cin>>a>>b;
    fl(i,0,a.length())
    {
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
    }
    fl(i,0,a.length()){
        if (a[i]>b[i]){
            scorea++;
        }
        else if(a[i]<b[i]){
            scoreb++;
        }
    }
    if (a>b){
        cout<<1;
    }
    else if(a<b){
        cout<<-1;
    }
    else if(a==b){
        cout<<0;
    }
    return 0;
}