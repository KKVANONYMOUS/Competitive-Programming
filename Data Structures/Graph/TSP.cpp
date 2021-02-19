#include <bits/stdc++.h>
using namespace std;


int TSP(vector <int> a[]){
    int start=0;
    vector <int> vec(4);
    for(int i=0;i<4;i++){
        if(i!=start) vec.push_back(i);
    }

    int minDist=INT_MAX;
    
    do{ 
        int sum=0;
        int temp=start;
        for(int i:vec){
            sum+=a[temp][i];
            temp=i;
        }
        sum+=a[vec.back()][start];
        minDist=min(minDist,sum);
    }while(next_permutation(vec.begin(),vec.end()));

    return minDist;
}
int main(){

    vector <int> a[]={ { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    cout<<TSP(a);
    return 0;
}
