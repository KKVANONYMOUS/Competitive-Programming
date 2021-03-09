#include <bits/stdc++.h>
using namespace std;

//TO COMPUTE LONGEST PREFIX SUFFIX ARRAY
void computeLPSArray(vector <int> &lps,string pat){
    int m=pat.size();
    int len=0,i=1;
    lps[0]=0;
    while(i<m){
        if(pat[i]==pat[len]){ //when equal prefix and suffix is found
            lps[i]=len+1;
            len++;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

/*
- Knuth-Morris-Pratt (KMP) Algorithm->used for checking if a particular pattern exists in the given string or not
- TIME COMPLEXITY:O(N+M)
- Unlike naive solution, no backtracking of i pointer takes place
- O(M) time is required to generate the LPS array
*/
void KMP_Algo(string s,string pat){
    vector <int> lps(pat.size());
    computeLPSArray(lps,pat);
    int n=s.size(),m=pat.size();
    int i=0,j=0;
    while(i<n){
        if(s[i]==pat[j]){//when character matches increment both i and j pointer by one
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            //when j==0 we need to increment i pointer by one
            else i++;
        }
        if(j==m){
            cout<<i-j<<endl; //Print the starting index of the found instance
            j=lps[j-1];
        }
    }
}

int main(){
    string s="onionionspl";
    string pat="onion";
    KMP_Algo(s,pat);
}