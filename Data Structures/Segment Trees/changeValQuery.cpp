#include <bits/stdc++.h>
using namespace std;

//Construct Tree
int constructSTree(vector <int> &tree,int ss,int se,int i,int arr[6]){
    if(ss==se){
        tree[i]=arr[ss];
        return tree[i];
    }
    int mid=(ss+se)>>1;
    tree[i]=constructSTree(tree,ss,mid,2*i+1,arr) + constructSTree(tree,mid+1,se,2*i+2,arr);
    return tree[i];
}

//Update Value
void updateVal(int index,int diff,int ss,int se,int i,vector <int> &tree){
    if(index<ss || index>se) return;
    
    tree[i]+=diff;

    if(se>ss){
        int mid=(ss+se)>>1;
        updateVal(index,diff,ss,mid,2*i+1,tree);
        updateVal(index,diff,mid+1,se,2*i+2,tree);
    }
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
    int index=1;
    int new_val=25;
    updateVal(index,new_val-arr[index],0,5,0,tree);
    for(auto x:tree){
        cout<<x<<" ";
    }
}