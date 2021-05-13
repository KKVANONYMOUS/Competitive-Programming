#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        bool terminal;
        unordered_map<char,Node *> children;

        Node(char d){
            data=d;
            terminal=false;
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
                if(temp->children.find(ch)!=temp->children.end()){
                    temp=temp->children[ch];
                }
                else{
                    Node *new_node=new Node(ch);
                    temp->children[ch]=new_node;
                    temp=new_node;
                }
            }
            temp->terminal=true;
        }

        bool find(string word){
            Node *temp=root;

            for(int i=0;i<word.size();i++){
                char ch=word[i];

                if(temp->children.find(ch)==temp->children.end()){
                    return false;
                }
                else{
                    temp=temp->children[ch];
                }
            }

            return temp->terminal;
        }
};
int main(){
    Trie t;
    vector <string> words={"apple","app","ape","not","news"};

    for(auto x:words){
        t.insert(x);
    }
    string target;
    cin>>target;
    if(t.find(target)){
        cout<<"Present";
    }
    else cout<<"Absent";
    return 0;
}