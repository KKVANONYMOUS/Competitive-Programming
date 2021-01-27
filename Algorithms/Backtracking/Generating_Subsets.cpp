#include <bits/stdc++.h>
using namespace std;

void printSubSet(vector <int> a){

    vector <vector <int>> ans;
    
    for(int i=0;i<(1<<a.size());i++){

        vector <int> subset;

        for(int j=0;j<a.size();j++){
            if(i & (1<<j)) subset.push_back(a[j]);
        }

        //To check for repeated subsets
        if(find(ans.begin(),ans.end(),subset)==ans.end()) ans.push_back(subset);
    }

    for(int i=0;i<ans.size();i++){
        cout<<"{ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"}\n";
    }
}
int main(){
    vector <int> a={10,12,12};
    printSubSet(a);
    return 0;
}