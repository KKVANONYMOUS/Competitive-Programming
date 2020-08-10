#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int no,x[5001],a[5001],b[5001],c[5001],m=0,n=0,p=0,o,nTeams;
    cin>>no;
    fl(i,0,no){
        cin>>x[i];
    }
    fl(i,0,no){
     if (x[i]==1){
         a[m]=i+1;
         m++;
     }
     if(x[i]==2){
         b[n]=i+1;
         n++;
     }
     if (x[i]==3){
         c[p]=i+1;
         p++;
     }
    }
    o=min(m,n);
    nTeams=min(o,p);
    cout<<nTeams<<"\n";
    fl(i,0,nTeams){
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<"\n";
    }
     
    return 0;
}