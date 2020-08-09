#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int x1,y1,x2,y2,dist;
    cin>>x1>>y1>>x2>>y2;
    if (x1==x2){
        dist=abs(y2-y1);
        cout<<x1+dist<<" "<<y1<<" "<<x1+dist<<" "<<y2;
    }
    else if(y1==y2){
        dist=abs(x2-x1);
        cout<<x1<<" "<<y1+dist<<" "<<x2<<" "<<y1+dist;
    }
    else{
            if(abs(x2-x1)!=abs(y2-y1)){
                cout<<-1;
            }
            else{
                cout<<x2<<" "<<y1<<" "<<x1<<" "<<y2;
            }
    }
    return 0;
}