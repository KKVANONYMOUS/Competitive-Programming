#include <bits/stdc++.h>
using namespace std;


int binary_search(vector <int> a,int n){
    sort(a.begin(),a.end());
    int left=0,right=a.size()-1;
    while(left<=right){
            int mid=left+(right-left)/2;
            if (a[mid]==n){
                return mid;
            }
            else if(a[mid]<n){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    return -1;
}
int main(){
    vector <int> a={22,35,85,45,1,22,15,96,63,17};
    int n;
    cout<<"Enter target element\n";
    cin>>n;
    int found=binary_search(a,n);
    if (found>=0){
        cout<<"Element found at index: "<<found<<" in the sorted version of array";
    }
    else {
        cout<<"Element not found";
    }
    return 0;
}