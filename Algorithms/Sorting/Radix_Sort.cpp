#include <bits/stdc++.h>
using namespace std;


void printArr(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void countingSort(vector <int> &input,int div){
    vector <int> count(10); //make count array
    vector <int> output(input.size()); //make output array

    //taking count of all elements in input array
    for(int i=0;i<input.size();i++){
        count[(input[i]/div)%10]++;
    }

    //cumulative count of count array to get the positions of elements to be stored in the output array
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }

    // placing input array elements into output array in proper positions such that the result is a sorted array in ASC order
    for(int i=input.size();i>=0;i--){ //iterated backward so that the concept of queue can be implemented
        output[--count[(input[i]/div)%10]]=input[i];
    }

    //copy output array elements to input array
    input=output;
}

int getMax(vector <int> input){
    int max=-1e8;
    for(int i=0;i<input.size();i++){
        if (input[i]>max) max=input[i];
    }
    return max;
}
void radixSort(vector <int> &input){
    int max=getMax(input);
    for(int div=1;max/div>0;div*=10){
        countingSort(input,div);
    }

}
int main(){
    vector <int> input={12,89,55,63,11,24,12};
    printArr(input);
    radixSort(input); 
    printArr(input);
    return 0;
}