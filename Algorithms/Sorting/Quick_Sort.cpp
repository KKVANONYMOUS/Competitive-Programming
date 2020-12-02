#include <bits/stdc++.h>
using namespace std;


void printArr(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int Partition(vector <int> &input,int s, int e){
    int pivot=e; // in this approach we take last element of array as pivot
    int pIndex=s; // initializing pivot index to starting index of sub array

    for(int i=s;i<e;i++){
        // to bring all elements smaller than pivot to left and greater one to right
        if (input[i]<=input[pivot]){
            swap(input[i],input[pIndex]);
            pIndex++;
        }
    }

    swap(input[pivot],input[pIndex]); //placing the pivot in center of the array

    return pIndex; //returning the postion of pivot
}
void quickSort(vector <int> &input,int s,int e){
    if (s<e){ // runs only when start index is less than the end index
        int p=Partition(input,s,e);
        quickSort(input,s,p-1); // recursive quickSort call for left partition
        quickSort(input,p+1,e); // recursive quickSort call for left partition
    }
}


int main(){
    vector <int> input={12,89,55,63,11,24,12};
    printArr(input);
    quickSort(input,0,input.size()-1); // calling quickSort function 
    printArr(input);
    return 0;
}