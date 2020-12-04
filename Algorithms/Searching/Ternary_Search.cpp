#include <bits/stdc++.h>
using namespace std;


int ternary_search(vector <int> a,int n,int left,int right){
    if(left<=right){
            int mid1=left+(right-left)/3;
            int mid2=right-(right-left)/3;
            
            if (a[mid1]==n) return mid1;
            if (a[mid2]==n) return mid2;
            if (a[mid1]>n) return ternary_search(a,n,left,mid1-1);
            else if(a[mid2]<n) return ternary_search(a,n,mid2+1,right);
            else return ternary_search(a,n,mid1+1,mid2-1);
            
        }
    return -1;
}
int main(){
    vector <int> a={22,35,85,45,1,22,15,96,63,17};
    int n;
    cout<<"Enter target element\n";
    cin>>n;
    int left=0,right=a.size()-1;
    sort(a.begin(),a.end());
    int found=ternary_search(a,n,left,right);
    if (found>=0){
        cout<<"Element found at index: "<<found<<" in the sorted version of array";
    }
    else {
        cout<<"Element not found";
    }
    return 0;
}