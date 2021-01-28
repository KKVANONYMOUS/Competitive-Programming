#include <bits/stdc++.h>
using namespace std;
 
int isPowerOfTwo(int n)
{   
    if(n and (!(n&(n-1)))) return true;
    return false;
}
 

int main()
{
    int i;
    cin>>i;
    cout << (isPowerOfTwo(i) ? "YES":"NO");
    return 0;
}