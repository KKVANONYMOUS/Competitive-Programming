#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> a={1, 2, 2, 1};
    int n=a.size();
    int i=0,j=n-1;
    int cnt=0;
    while(i<=j){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else if(a[i]>a[j]){
            int sum=0;
            int t=j;
            while(sum!=a[i] and j>=i) sum+=a[j--];
            cnt+=(t-j-1);
            i++;
        }
        else{
            int sum=0;
            int t=i;
            while(sum!=a[j] and i<=j) sum+=a[i++];
            cnt+=(i-t-1);
            j--;
        }
    }
    cout<<cnt;
    return 0;
}