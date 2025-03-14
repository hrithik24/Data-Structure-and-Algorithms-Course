#include<iostream>
using namespace std;
class Bird{
    public: 
    int age,weight,nol;
    string color;

    void eat(){ 
        cout << "Bird is eating" << endl;
    }

    void fly(){ 
        cout << "Bird is flying" << endl;
    }
};

class Sparrow : public Bird{
    public: 
        Sparrow(int age,int weight,string color,int nol){
            this->age = age;
            this->weight = weight;
            this->color = color;
            this->nol = nol;
        }

        void grassing(){
            cout << "Sparrow is grassing" << endl;
        }
};

class Pigeon : public Bird{
    public: 
        void guttering(){
            cout << "Pigeon is guttering" << endl;
        }
};
int main(){
    Sparrow s(1,1,"brown",2);
    cout << s.color << endl;
    s.eat();
    s.grassing();

    Pigeon p;
    p.eat(); 
    p.guttering();

}