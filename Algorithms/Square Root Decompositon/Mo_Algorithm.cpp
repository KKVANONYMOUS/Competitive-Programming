#include <bits/stdc++.h>
using namespace std;

/*This program shows the implementation of Mo's Algo for SPoJ DQUERY question*/
class query{
    public:
        int l;
        int r;
        int i;
};

query Q[100001];
int block_size=400;
vector <int> ans(100001);
vector <int> arr(100001);
vector <int> freq(1e7);
int cnt=0;

//for sorting the queries
/*first sort according to the block
then if they are in same block sort according to their r value
*/
bool comp(query a,query b){
    if(a.l/block_size!=b.l/block_size){
        return a.l/block_size<b.l/block_size;
    }
    else return a.r<b.r;
}

//adding element in freq array and changing the cnt accordingly
void add(int idx){
    freq[arr[idx]]++;
    if(freq[arr[idx]]==1) cnt++;
}

//removing element in freq array and changing the cnt accordingly
void remove(int idx){
    freq[arr[idx]]--;
    if(freq[arr[idx]]==0) cnt--;
}
int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i;
    }

    sort(Q,Q+m,comp);

    int L=0,R=-1;
    for(int i=0;i<m;i++){
        int left=Q[i].l;
        int right=Q[i].r;

        while(left<L){
            L--;
            add(L);
        }

        while(right>R){
            R++;
            add(R);
        }

        while(left>L){
            L++;
            remove(L);
        }
        
        while(right<R){
            R--;
            remove(R);
        }
        ans[Q[i].i]=cnt;

    }
    for(int i=0;i<m;i++) cout<<ans[i]<<" ";

    return 0;
}