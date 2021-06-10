#include <bits/stdc++.h>
using namespace std;

int maxSizeSubArray(vector <int> temp,int n){
        unordered_map <int,int> mp;
        int sum=0,maxLen=0;
        for(int i=0;i<n;i++){
            sum+=temp[i];

            if(temp[i]==0 and maxLen==0){
                maxLen=1;
            }
            if(sum==0) maxLen=i+1;

            if(mp.find(sum)!=mp.end()){ 
                maxLen=max(maxLen,abs(mp[sum]-i));
            }
            else{
                mp[sum]=i;
            }
        }
        return maxLen;
}

//Time Complexity:O(R*R*(C+C))
int main(){
    vector <vector <int>> M={ { 9, 7, 16, 5 }, { 1, -6, -7, 3 },
                      { 1, 8, 7, 9 }, { 7, -2, 0, 10 } };

    int R=M.size();
    int C=M[0].size();
    int ans=INT_MIN;
    for(int i=0;i<R;i++){
        vector <int> temp(C,0);
        for(int j=i;j<R;j++){
            for(int k=0;k<C;k++){
                temp[k]+=M[j][k];
            }
            int row=j==0?j+1:j;
            ans=max(ans,maxSizeSubArray(temp,C)*row);
        }
        
    }
    cout<<ans;
    return 0;
}