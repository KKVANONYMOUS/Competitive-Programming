#include <bits/stdc++.h>
using namespace std;

int findPosition(int N)
{
    if(!(N && (!(N & (N - 1))))) return -1;
        
    int pos = 1,i=1;
    while (!(i&N))
    {   
        i<<=1;
        pos++;
    }
    
    return pos;
}

int main()
{
    int i;
    cin>>i;
    cout << findPosition(i);
    return 0;
}