#include <bits/stdc++.h>
using namespace std;

void printArr(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void shellSort(vector <int> &a){
    int n=a.size();
    // log(n) gaps
    for(int gap=n/2;gap>0;gap/=2){

        // insertion sort like approach applied at particular gaps
        for(int i=gap;i<n;i++){
            int temp=a[i];
            int j=i-gap;
            while(j>=0 and a[j]>temp){
                a[j+gap]=a[j];
                j-=gap;
            }
            a[j+gap]=temp;
        }
    }
}

int main(){
    vector <int> a={12,89,55,63,11,24,12};
    printArr(a);
    shellSort(a);
    printArr(a);
    return 0;
}