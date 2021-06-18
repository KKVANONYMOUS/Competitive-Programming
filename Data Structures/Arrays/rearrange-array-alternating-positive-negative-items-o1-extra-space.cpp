#include<bits/stdc++.h>
using namespace std;

int getSign(int n){
    return n<0?-1:1;
}
int main(){
    vector <int> a={1,2,-8,-9,4,-6,-8,-2,7,3,1,5,8};
    int i=a[0]<0?1:0;
    int n=a.size();
    while(i<n){
        if(i>0 and getSign(a[i])==getSign(a[i-1])){
            int j=i+1;
            while(getSign(a[j])==getSign(a[i]) and j<n) j++;
            if(j>=n) break;
            
            int num=a[j];
            while(j>i){
                a[j]=a[j-1];
                j--;
            }

            a[i]=num;
        }
        i++;
    }

    for(auto x:a) cout<<x<<" ";
    return 0;
}