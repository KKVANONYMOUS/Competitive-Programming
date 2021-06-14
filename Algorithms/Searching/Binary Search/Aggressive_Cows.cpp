#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		vector <int> stall(n);
		for(int i=0;i<n;i++) cin>>stall[i];
		sort(stall.begin(),stall.end());
		
		int l=1,r=stall.back();
		int ans=0;
		while(l<=r){
			int mid=l+(r-l)/2;
			int cow=1;
			int prev=stall[0];
			for(int i=1;i<n;i++){
				if(stall[i]-prev>=mid){
					cow++;
					prev=stall[i];
				}
				if(cow==c) break;
			}
			
			if(cow==c){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}