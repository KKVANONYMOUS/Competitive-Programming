#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        bool terminal;
        int freq;
        unordered_map<char,Node *> children;

        Node(char d){
            data=d;
            terminal=false;
            freq=0;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root=new Node('\0');
        }

        void insert(string word){
            Node *temp=root;

            for(int i=0;i<word.size();i++){
                char ch=word[i];
                if(temp->children.find(ch)==temp->children.end()){
                    Node *new_node=new Node(ch);
                    temp->children[ch]=new_node;
                }
                temp->children[ch]->freq++;
                temp=temp->children[ch];
            }

            temp->terminal=true;
        }

        string findPrefix(string word){
            Node *temp=root;

            string prefix;
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                prefix+=ch;
                if(temp->children[ch]->freq==1){
                    break;
                }
                else{
                    temp=temp->children[ch];
                }
            }
            return prefix;
        }
};
int main(){
    Trie t;
    vector <string> words={"apple", "dog", "duck", "dove"};
    for(auto x:words){
        t.insert(x);
    }
    
    vector <string> ans;
    
    for(auto x:words){
        string pref=t.findPrefix(x);
        ans.push_back(pref);
    }
    for(auto x:ans) cout<<x<<" ";
    return 0;
}