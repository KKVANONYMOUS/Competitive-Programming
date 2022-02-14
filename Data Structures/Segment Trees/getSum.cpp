#include <bits/stdc++.h>
using namespace std;

//Construct Tree
int constructSTree(vector <int> &tree,int si,int se,int i,int arr[6]){
    if(si==se){
        tree[i]=arr[si];
        return tree[i];
    }
    int mid=(si+se)>>1;
    tree[i]=constructSTree(tree,si,mid,2*i+1,arr) + constructSTree(tree,mid+1,se,2*i+2,arr);
    return tree[i];
}

//Get Sum function
int getSum(int qs,int qe,int ss,int se,int i,vector <int> &tree){
    if(qe<ss || qs>se) return 0;

    if(qs<=ss and qe>=se) return tree[i];

    int mid=(ss+se)>>1;
    return getSum(qs,qe,ss,mid,2*i+1,tree) + getSum(qs,qe,mid+1,se,2*i+2,tree);
}

int main(){
    int arr[]={10,20,30,40,50,60};

    int size=pow(2,ceil(log2(6)+1))-1;

    vector <int> tree(size,-1);

    constructSTree(tree,0,5,0,arr);

    for(auto x:tree){
        cout<<x<<" ";
    }
    cout<<"\n";
    int sum=getSum(1,3,0,5,0,tree);
    cout<<"Sum: "<<sum<<"\n";
}