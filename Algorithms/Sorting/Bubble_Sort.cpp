#include <bits/stdc++.h>
using namespace std;


void printArr(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void bubbleSort(vector <int> &input){
 for(int i=0;i<input.size();i++){
     for (int j=0;j<input.size()-1;j++){
         if (input[j]>input[j+1]) swap(input[j],input[j+1]);
     }
 }
}
int main(){
    vector <int> input={12,89,55,63,11,24,12};
    printArr(input);
    bubbleSort(input); 
    printArr(input);
    return 0;
}