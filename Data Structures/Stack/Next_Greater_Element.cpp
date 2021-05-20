#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> arr={11, 13, 21, 3};
	stack <int> st;
    for(int i=0;i<4;i++){
        while(!st.empty() && st.top()<arr[i]){
            cout<<st.top()<<" --> "<<arr[i]<<"\n";
            st.pop();
        }
        st.push(arr[i]);
    }
    
    while(!st.empty()){
        cout<<st.top()<<" --> "<<-1<<"\n";
        st.pop();
    }
    return 0;
}