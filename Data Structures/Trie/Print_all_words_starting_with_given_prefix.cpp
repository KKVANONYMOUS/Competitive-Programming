#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        bool terminal;

        unordered_map <char,Node*> mp;

        Node(char ch){
            data=ch;
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
                if(temp->mp.find(ch)!=temp->mp.end()){
                    temp=temp->mp[ch];
                }
                else{
                    Node *new_node=new Node(ch);
                    temp->mp[ch]=new_node;
                    temp=new_node;
                }
            }
            temp->terminal=true;
        }

        Node* isPresent(string word){
            Node *temp=root;
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                if(temp->mp.find(ch)==temp->mp.end()) return NULL;
                temp=temp->mp[ch];
            }
            return temp;
        }

        void printWords(Node *root,string temp){
            if(root==NULL) return;
            if(root->terminal){
                cout<<temp<<"\n";
            }
            for(auto child:root->mp){
                temp+=child.first;
                printWords(child.second,temp);
                temp.pop_back();
            }
        }
        void printAllSuugestions(string word){
            Node *pos=isPresent(word);
            if(pos){
                string temp=word;
                printWords(pos,temp);
            }
            else cout<<"No match found\n";
        }

};


int main(){
    Trie *t=new Trie();
    vector <string> words={"abc","abcda","affd","ffs"};

    for(auto x:words){
        t->insert(x);
    }

    string prefix="a";
    t->printAllSuugestions(prefix);
    return 0;
}