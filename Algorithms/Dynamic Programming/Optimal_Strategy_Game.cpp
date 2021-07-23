#include <bits/stdc++.h>
using namespace std;

int maxPoints(int l,int r,vector <int> a){
    if(l>r) return 0;
        
    return max(maxPoints(l,r-1,a)+a[r],maxPoints(l+1,r,a)+a[l]);
}
int main(){
    vector <int> a={5,3,7,10};
    cout<<maxPoints(0,a.size()-1,a);
    return 0;
}