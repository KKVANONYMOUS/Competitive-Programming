#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
    return (a.second > b.second); 
} 

double Knapsack(vector <double> weights,vector <double> profits,double n,double m){
    vector <pair<int,double>> c(n);
    for(int i=0;i<n;i++){
        c[i].first=i;
        c[i].second=profits[i]/weights[i];
    }
    sort(c.begin(),c.end(),sortbysec);

    double ans=0;
    int i=0;
    double currWeight=0;
    while(true){
        int j=c[i].first;
        if(currWeight+weights[j]<=m){
            ans+=profits[j];
            currWeight+=weights[j];
        }
        else{
            double remain=m-currWeight;
            ans+=profits[j]*(remain/weights[j]);
            break;
        }
        
        i++;
    }
    return ans;
}

int main(){
    double n,m;
    cin>>n>>m;
    vector <double> weights(n);
    vector <double> profits(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    for(int i=0;i<n;i++) cin>>profits[i];
    cout<<Knapsack(weights,profits,n,m);
    return 0;
}