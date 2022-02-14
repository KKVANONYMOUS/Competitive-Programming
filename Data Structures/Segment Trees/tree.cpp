#include <bits/stdc++.h>
using namespace std;

int constructSTree(vector <int> &tree,int si,int se,int i,int arr[6]){
    if(si==se){
        tree[i]=arr[si];
        return tree[i];
    }
    int mid=(si+se)>>1;
    tree[i]=constructSTree(tree,si,mid,2*i+1,arr) + constructSTree(tree,mid+1,se,2*i+2,arr);
    return tree[i];
}

int main(){
    int arr[]={10,20,30,40,50,60};

    int size=pow(2,ceil(log2(6)+1))-1;

    vector <int> tree(size,-1);

    constructSTree(tree,0,5,0,arr);

    for(auto x:tree){
        cout<<x<<" ";
    }
}