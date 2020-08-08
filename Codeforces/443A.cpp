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
    string a;
    int  j = 0;
    char b[1001];
    cin>>a;
    cout<<a;
    fl(i, 1, a.size()-1)
    {
        if (a[i] != ',' || a[i]!='\t')
        {
            b[j] = a[i];
            j++;
            cout<<"called"<<endl;
        }
    }
    fl(i,0,a.size()){
        cout<<b[i]<<endl;
    }

    return 0;
}