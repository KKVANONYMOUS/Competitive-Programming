#include <bits/stdc++.h>
using namespace std;

#define ll long long

void prime_sieve(vector <ll> &prime,int n){

    // Marking all odd numbers as prime
    for(ll i=3;i<=n;i+=2) prime[i]=1;

    for(ll i=3;i<=n;i+=2){
        // if the current number is not marked as prime
        if(prime[i]){
            //mark all its multiples as not prime
            for(ll j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
        
    }

    // Handling corner cases
    prime[2]=1;
    prime[0]=prime[1]=0;
}


int main(){
    ll n;
    cin>>n;

    vector <ll> prime(n,0);// this will, by default, mark all numbers as not prime so that we do not have to explicitly mark all even numbers as not prime

    prime_sieve(prime,n);

    for(ll i=0;i<=n;i++){
        if (prime[i]) cout<<i<<" ";
    }
    return 0;
}