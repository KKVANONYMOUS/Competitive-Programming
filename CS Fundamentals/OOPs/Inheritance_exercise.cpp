#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

class SimpleCalculator{
    protected:
    float a,b;
    public:
    void set_input(float x,float y){
        a=x;
        b=y;
    }
    void compute_Calc(){
        cout<<a+b<<"\n";
    }
};
class ScientificCalculator{
    protected:
    int c;
    public:
    void set_number(int z){
        c=z;
    }
    void compute_SciCalc(){
        cout<<sqrt(c)<<"\n";
    }
};

class HybridCalculator: public SimpleCalculator,public ScientificCalculator{
    public:
    void display(){
        compute_Calc();
        compute_SciCalc();
    }
};
int main(){
    kkvanonymous();
    HybridCalculator o;
    o.set_input(2.3,4);
    o.set_number(16);
    o.display();
    return 0;
}