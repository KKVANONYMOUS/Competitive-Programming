#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// CSES: Range Update Queries Problem
ll constructTree(ll start,ll end, ll treeIndex, vector <ll> &a,vector <ll> &tree){
    if(start==end){
        return tree[treeIndex]=a[start];
    }

    ll mid=(start+end)>>1;
    return tree[treeIndex]=constructTree(start,mid,2*treeIndex+1,a,tree)+constructTree(mid+1,end,2*treeIndex+2,a,tree);
}

// With Lazy Propagation
ll getSum(ll qs,ll qe, ll start, ll end, ll treeIndex, vector <ll> &tree,vector <ll> &lazy){
    if(lazy[treeIndex]!=0){
        tree[treeIndex]+=(end-start+1)*lazy[treeIndex];
        if(start!=end){
            lazy[2*treeIndex+1]+=lazy[treeIndex];
            lazy[2*treeIndex+2]+=lazy[treeIndex];
        }
        lazy[treeIndex]=0;
    }

    if(start>end || qe<start || qs>end) return 0;

    if(qs<=start and qe>=end){
        return tree[treeIndex];
    }

    ll mid=(start+end)>>1;
    return getSum(qs,qe,start,mid,2*treeIndex+1,tree,lazy)+getSum(qs,qe,mid+1,end,2*treeIndex+2,tree,lazy);
}

// With Lazy Propagation
void updateVal(ll qs, ll qe, ll start, ll end, ll treeIndex, ll diff,vector <ll> &tree,vector <ll> &lazy){
    
    if(lazy[treeIndex]!=0){
        tree[treeIndex]+=(end-start+1)*lazy[treeIndex];
        if(start!=end){
            lazy[2*treeIndex+1]+=lazy[treeIndex];
            lazy[2*treeIndex+2]+=lazy[treeIndex];
        }
        lazy[treeIndex]=0;
    }

    if(start>end || qe<start || qs>end) return;

    if(qs<=start and qe>=end){
        tree[treeIndex]+=(end-start+1)*diff;
        if(start!=end){
            lazy[2*treeIndex+1]+=diff;
            lazy[2*treeIndex+2]+=diff;
        }
        return;
    }

    ll mid=(start+end)>>1;
    updateVal(qs,qe,start,mid,2*treeIndex+1,diff,tree,lazy);
    updateVal(qs,qe,mid+1,end,2*treeIndex+2,diff,tree,lazy);
    tree[treeIndex]=tree[2*treeIndex+1]+tree[2*treeIndex+2];
}

int main(){
    ll n,q;
    cin>>n>>q;

    vector <ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];

    ll sz=pow(2,ceil(log2(n))+1)-1;
    vector <ll> tree(sz,0);
    constructTree(0,n-1,0,a,tree);
    vector <ll> lazy(sz,0);

    while(q--){
       ll type;
       cin>>type;

       if(type==1){
            ll a,b,val;
            cin>>a>>b>>val;
            a--;b--;
            updateVal(a,b,0,n-1,0,val,tree,lazy);
       }
       else{
            ll k;
            cin>>k;
            k--;
            if(k) cout<<getSum(0,k,0,n-1,0,tree,lazy)-getSum(0,k-1,0,n-1,0,tree,lazy)<<"\n";
            else cout<<getSum(0,k,0,n-1,0,tree,lazy)<<"\n";
       }
    }   
    return 0;
}