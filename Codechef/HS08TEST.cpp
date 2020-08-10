#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int w;
    double b;
    cin>>w>>b;
    cout << setprecision(2) << fixed;
    if (w>=(b-0.50) || w%5!=0){
        cout<<b;
    }
    else{
        float leftBalance=b-(double(w)+0.50);
        cout<<leftBalance;
    }
    return 0;
}
