#include <bits/stdc++.h>
using namespace std;

void printArr(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void merge(vector <int> &a,int l,int m, int r){
    int n1=m-l+1;
    int n2=r-m;

    vector <int> L(n1); // make temp vector L
    vector <int> R(n2); // make temp vector R

    for(int i=0;i<n1;i++)  L[i]=a[l+i]; // copy data to L
    for(int j=0;j<n2;j++)  R[j]=a[m+1+j]; // copy data to R

    int i=0; // initial index of first subvector
    int j=0; // initial index of second subvector
    int k=l; // initial index of merged subvector

    while(i<n1 && j<n2){
        if (L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }

    // include all elements left in L
    while(i < n1){
        a[k]=L[i];
        i++;
        k++;
    }

    // include all elements left in R
    while(j < n2){
        a[k]=R[j];
        j++;
        k++;
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

int main(){
    vector <int> a = { 12, 11, 13, 5, 6, 7 };
    printArr(a); 
    mergeSort(a,0,a.size()-1);
    printArr(a);
    return 0;
}