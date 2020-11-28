#include <bits/stdc++.h>
using namespace std;

int main(){
   vector <int> a = { 12, 11, 13, 5, 6 };
   for(int i=0;i<a.size();i++){
       cout<<a[i]<<" ";
   }
   cout<<"\n";
   for(int i=1;i<a.size();i++){
       int key=a[i];
       int j=i-1;
       while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
       }
        a[j+1]=key;
   }
   for(int i=0;i<a.size();i++){
       cout<<a[i]<<" ";
   }
    
    return 0;
}