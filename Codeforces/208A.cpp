#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fl(i, a, n) for (int i = a; i < n; i++)

void kkvanonymous()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    kkvanonymous();
    string s;
    cin >> s;
    int flag=1;
    fl(i,0,s.size()){
	    if(s[i]=='W'&& s[i+1]=='U' && s[i+2]=='B'){
	        i+=2;
	        if(!flag){
	            cout<<" ";
	        }
	        continue;
	    }else {
	        flag=0;
	        cout<<s[i];
	    }
	}
    return 0;
}