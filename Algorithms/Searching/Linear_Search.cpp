#include <bits/stdc++.h>
using namespace std;


int linear_search(vector <int> a,int t){
    for(int i=0;i<a.size();i++){
        if (a[i]==t) return i;
    }
    return -1;
}
int main(){
    vector <int> a={2, 3, 4, 10, 40 };
    int target;
    cout<<"Enter target element\n";
    cin>>target;
    int found=linear_search(a,target);
    if(found>=0) cout<<"Element Found at index: "<<found<<"\n";
    else cout<<"Element not found\n";
    return 0;
}