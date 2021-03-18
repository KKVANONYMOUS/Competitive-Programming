#include <bits/stdc++.h>
using namespace std;


class SRD{
    public:
        int block_size;
        vector <int> blocks;//stores blocks sum

        //Precomputing 
        SRD(int n,vector <int> a){
            block_size=ceil(sqrt(n));
            blocks.resize(block_size,0);
            for(int i=0;i<n;i++){
                blocks[i/block_size]+=a[i];
            }
            //for(auto x:blocks) cout<<x<<' ';
        }

        //For updating values
        void update(int index,int new_val,vector <int> &a){
            int old_val=a[index];
            blocks[index/block_size]+=new_val-old_val;
            a[index]=new_val;
        }

        //For computing sum in the given range
        int sum(int left,int right,vector <int> &a){
            int sum=0;

            //Calculating the start and end block
            int start_block=left/block_size;
            int end_block=right/block_size;

            //when both left and right lie in same block
            if(start_block==end_block){
                for(int i=left;i<=right;i++){
                    sum+=a[i];
                }
            }
            else{

                //elements from left postion to the end of start block
                for(int i=left;i<=((start_block+1)*block_size)-1;i++) sum+=a[i];

                //elements from start of end block to the right position
                for(int i=(end_block*block_size);i<=right;i++) sum+=a[i];

                //elements between start and end block
                for(int i=start_block + 1;i<=end_block-1;i++) sum+=blocks[i];
            }

            

            return sum;
        }
};
int main(){
    vector <int> a= {1, 1, 2, 1, 3, 4, 5, 2, 8};
    SRD obj(a.size(),a);
    int q;
    cin>>q;
    int b,c;
    obj.update(0,2,a);
    while(q--){
        cin>>b>>c;
        cout<<obj.sum(b,c,a)<<endl;
    }
    return 0;
}