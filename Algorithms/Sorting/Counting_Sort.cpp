#include <bits/stdc++.h>
using namespace std;


void printArr(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void countingSort(vector <int> &input){
    vector <int> count(100); //make count array
    vector <int> output(input.size()); //make output array

    //taking count of all elements in input array
    for(int i=0;i<input.size();i++){
        count[input[i]]++;
    }

    //cumulative count of count array to get the positions of elements to be stored in the output array
    for(int i=1;i<100;i++){
        count[i]=count[i]+count[i-1];
    }

    // placing input array elements into output array in proper positions such that the result is a sorted array in ASC order
    for(int i=0;i<input.size();i++){
        output[--count[input[i]]]=input[i];
    }

    //copy output array elements to input array
    input=output;
}
int main(){
    vector <int> input={12,89,55,63,11,24,12};
    printArr(input);
    countingSort(input); // works for range 0-99
    printArr(input);
    return 0;
}