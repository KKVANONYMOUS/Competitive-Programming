#include <bits/stdc++.h>
using namespace std;

void printArr(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void merge(vector <int> &a,int l,int mid,int r){
    int i=l,j=mid+1;
    vector <int> temp(a.size(),0); //temp vector to store the merged arrays
    int k=l;
    while(i<=mid and j<=r){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }

    // include all elements left in LHS
    while(i<=mid){
        temp[k++]=a[i++];
    }

    // include all elements left in RHS
    while(j<=r){
        temp[k++]=a[j++];
    }

    for(int i=l;i<=r;i++){
        a[i]=temp[i];
    }
}
void mergeSort(vector <int> &a,int l,int r){
    if (r>l){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r); // merge two subvectors
    }
   
}

//Two Way Merge Sort
void mergeSortIterative(vector <int> &a,int n){
    int p;
    for(p=2;p<=n;p*=2){ //no of passes == log(n)
        int i;
        for(i=0;i+p-1<n;i+=p){
            int l=i;
            int r=i+p-1;
            int mid=(l+r)/2;
            merge(a,l,mid,r);
        }

        // for some leftover elements eg.{2, 5, 8, 12, 3, 6, 7, 10, 11, 10, 2}
        if(n-i>p/2)
        {
            int l=i;
            int r=i+p-1;
            int mid=(l+r)/2;
            merge(a,l,mid,n-1);
        }
    }

    //for odd no. of elements 
    if(p/2<n){
        merge(a,0,p/2-1,n-1);
    }
}
int main(){
    vector <int> a = { 12, 11, 13, 5, 6, 7, 6 };
    printArr(a); 
    //mergeSort(a,0,a.size()-1);
    mergeSortIterative(a,a.size());
    printArr(a);
    return 0;
}