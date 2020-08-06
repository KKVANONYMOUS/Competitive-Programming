#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    string s;
    cin>>x;
    string words[x]={};
    string display[x]={};
    for (int i=0;i<x;i++){
        cin>>s;
        words[i]=s;
    }
    for (int i = 0; i < x; i++)
    {
        if (words[i].length()>10){
            string element=words[i];
            int n=(words[i].length())-2;
            display[i]=element[0]+to_string(n)+element[n+1];
        }
        else
        {
            display[i]=words[i];
        }
        
    }
     for (int i=0;i<x;i++){
        cout<<display[i]<<endl;
    }
    
    return 0;
}