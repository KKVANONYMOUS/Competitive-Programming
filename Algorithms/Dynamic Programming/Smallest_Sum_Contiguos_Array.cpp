#include <bits/stdc++.h>
using namespace std;


int main(){

    vector <int> a={2, 6, 8, 1, 4};
    int sum=0,ans=INT_MAX;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum<ans) ans=sum;
        if(sum>0) sum=0;
    }

    cout<<ans;
    return 0;
}