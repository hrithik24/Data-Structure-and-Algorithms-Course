#include<iostream>
using namespace std;
class abc{
    mutable int x;
    int *y;
    int z;
    public:
    // old type of constructor
    //   abc(int _x,int _y,int _z = 0){
    //     x = _x;
    //     y = new int(_y);
    //     z = _z;
    //   }

    // initialization list
    abc(int _x, int _y, int _z=0) : x(_x), y(new int(_y)), z(_z) {
        cout << "in initializaion list" << endl;
    }

      int getX() const{
        x = 10;  // we can override const keyword using mutable variable 
        return x;
      }

      int setX(int _val){
        x = _val;
      }

      int getY() const{
        return *y;
      }

      int setY(int _val){
        *y = _val;
      }

      int getZ() const{
        return z;
      }
};
void printABC(const abc &a){
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}
int main(){
    const int x = 5; // x is constant
    // initialization can be done here but we can't re-assign a value.
    // x = 10;
    cout << x << endl;

    // const with pointers
    const int *a = new int(2); // constant data and non-constant pointer
    cout << *a << endl;
    // *a = 20; Can't change the content of pointer.
    int b = 30;
    a = &b; // pointer itself can be reassigned
    cout << *a << endl;

    // constant pointer and non-constant data
    int *const c = new int(2);
    cout << *c << endl;
    *c = 20; // data is not constant so we can re-assign it
    cout << *c << endl;
    // int d = 50;
    // c = &d; // pointer is constant here
    // cout << *c << endl;

    // constant pointer and constant data
    const int *const e = new int(10);
    cout << *e << endl;
    // *e = 50; data is constant here so we cannot re-assign it.
    // cout << *e << endl;
    // int f = 100;
    // e = &f;  pointer is also constant here so we cannot re-assign it as well.
    // cout << *e << endl;

    abc ae(1,2,3);
    printABC(ae);
}