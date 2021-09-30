#include<bits/stdc++.h>
using namespace std;


/*
Abstract Base Class
- No object is instantiated
- Must contain atleast one pure virtual function
*/
class Media{
    protected:
        string title;
        float rating;

    public:
        Media(string t,float r){
            title=t;
            rating=r;
        }
    
        virtual void display()=0; //pure virtual function
};

class Video:public Media{
    protected:
        float length;
    public:
        Video(string t,float r,float l):Media(t,r){
            length=l;
        }
    
        void display(){
            cout<<"Video Media title is "<<title<<" and length is "<<length<<"\n";
        }
};

class Text:public Media{
    protected:
        float pages;
    public:
        Text(string t,float r,float p):Media(t,r){
            pages=p;
        }

        void display(){
            cout<<"Text Media title is "<<title<<" and pages is "<<pages<<"\n";
        }
};

int main(){
    Video video_obj("Avenger Movies",4.9,135);
    Text text_obj("Avenger Comics",4.5,50);

    Media* media_obj_pointers[2];
    media_obj_pointers[0]=&video_obj;
    media_obj_pointers[1]=&text_obj;

    media_obj_pointers[0]->display();
    media_obj_pointers[1]->display();
    return 0;
}