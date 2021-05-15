#include <bits/stdc++.h>
using namespace std;
 
//Time complexity(log(N)) - because a number N can have atmost log(N) set bits
int countSetBits(int n)
{   
    int count = 0;
    while (n) {
        count += n & 1; // check if the last bit is 1 or 0 and update the count accordingly
        n >>= 1; // right shift the bit by one place
    }
    return count;
}

//Time Complexity:O(no of set bits)
int countSetBitsFast(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1); //removes set bit one at a time...so the number of times this line works is our ans
        ans++;
    }
    return ans;
}
 

int main()
{
    int i = 15;
    cout << countSetBits(i);
    cout<<"\n";
    cout << countSetBitsFast(i);
    cout<<"\n";
    cout<<__builtin_popcount(i);
    return 0;
}