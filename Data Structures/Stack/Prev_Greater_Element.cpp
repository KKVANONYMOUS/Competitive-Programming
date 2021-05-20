#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> arr={11, 13, 21, 3};
	stack <int> st;
    vector <int> ans(4);
    for(int i=0;i<4;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:arr[st.top()];
        st.push(i);
    }
    
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" --> "<<ans[i]<<"\n";
    }
    return 0;
}