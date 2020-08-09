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
    int s, n, arr[1001][2], min = 10000, flag = 0;
    cin >> s >> n;
    fl(i, 0, n)
    {
        fl(j, 0, 2)
        {
            cin >> arr[i][j];
        }
    }
    fl(i, 0, n)
    {
        fl(j, i + 1, n)
        {
            if (arr[j][0] < arr[i][0])
            {
                int temp = arr[i][0]; // should have used swap here...but didn't knew about it at that time
                arr[i][0] = arr[j][0];
                arr[j][0] = temp;
                int temp2=arr[i][1];
                arr[i][1]=arr[j][1];
                arr[j][1]=temp2;
            }
        }
    }
    if (s < arr[0][0])
    {   
        cout << "NO";
    }
    else
    {
        fl(i, 0, n)
        {
            if (s > arr[i][0])
            {  
                s = s + arr[i][1];
               
                flag++;
            }
        }
         if (flag == n)
    {
        cout << "YES";
    }
    else {
       
        cout<<"NO";
    }
    }
   

    return 0;
}