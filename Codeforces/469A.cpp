#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
bool findInxArr(int a[],int m,int x){
    fl(i,0,x){
        if (a[i]==m){
            return true;
        }
    }
    return false;
}
bool findInyArr(int a[],int m, int y){
      fl(i,0,y){
        if (a[i]==m){
            return true;
        }
    }
    return false;
}
int main(){
    kkvanonymous();
    int nLevels,x,y,xArr[101],yArr[101],c=1,flag;
    cin>>nLevels;
    cin>>x;
    fl(i,0,x){
        cin>>xArr[i];
    }
    cin>>y;
    fl(i,0,y){
        cin>>yArr[i];
    }
    while(c<(nLevels+1)){
        if (findInxArr(xArr,c,x)||findInyArr(yArr,c,y)){
            c++;
        }
        else{
            break;
        }
    }
    c=c-1;
    if (c==nLevels){
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }
    return 0;
}