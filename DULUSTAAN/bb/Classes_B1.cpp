#include <iostream>
#include <string>
using namespace std;
class Vector{
int oX;
int oY;
public:
Vector(){
oX=0;
oY=0;
  }
Vector(int x, int y){
oX=x;
oY=y;
}
void find_coordinatex(){
cout<<endl<<"Введите x: "; cin>>oX;
  }
void find_coordinatey(){
cout<<endl<<"Введите y: "; cin>>oY;
}
void print(){
cout<<endl<<"x = "<<oX;
cout<<endl<<"y = "<<oY;
cout<<endl<<"vector("<<oX<<","<<oY<<")";
}
void new_coordinate(){
cout<<endl<<"Введите новый x: "; cin>>oX;
cout<<endl<<"Введите новый y: "; cin>>oY;  
}
Vector vectorsum( Vector C,Vector A,Vector B){
C.oX=A.oX+B.oX;
C.oY=A.oY+B.oY;
return C;
}
void skaly(double k){
oX=oX*k;
oY=oY*k;
}
void skaly(Vector B){
oX=oX+B.oX;
oY=oY+B.oY;
}

};
int main(){
Vector A;
A.find_coordinatex();
A.find_coordinatey();
A.print();
Vector B;
B.find_coordinatex();
B.find_coordinatey();
//B.print();
//Vector C;
//C.vectorsum(C,A,B).print();
double k;
cout<<endl<<"k=";cin>>k;
A.skaly(k);
A.print();
A.skaly(B);
A.print();


  

}