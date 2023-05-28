#include <iostream>
#include <vector>
using namespace std;
class Matrix{
int a,b,c,d;
  public:
 Matrix(){
   a=b=c=d=0;
 }
 Matrix(int aM,int bM,int cM, int dM){
   a=aM;
   b=bM;
   c=cM;
   d=dM;
 }
  void input(){
  cin>>a>>b>>c>>d;
  }
  void Matrix_transp(){
  int oA,oB,oC,oD;
  oA=a;oB=c;oC=b;oD=d;
  cout<<"( "<<oA<<" "<<oB<<" )"<<endl;
  cout<<"( "<<oC<<" "<<oD<<" )"<<endl;
}
  void print(){
  cout<<"( "<<a<<" "<<b<<" )"<<endl;
  cout<<"( "<<c<<" "<<d<<" )"<<endl;
}
  void Matrix_opr(){
  cout<<"Определитель = "<<a*d-b*c<<endl;
  }
  void Summ(Matrix A, Matrix B){
  a=A.a+B.a;
  b=A.b+B.b;
  c=A.c+B.c;
  d=A.d+B.d;
  }
  void Multiple(){
  int k;
  cout<<"k=";cin>>k;
  a=a*k;
  b=b*k;
  c=c*k;
  d=d*k;
  }
  void MM(Matrix A, Matrix B){
  a=A.a*B.a+A.b*B.c;
  b=A.a*B.b+A.b*B.d;
  c=A.c*B.a+A.d*B.c;
  d=A.c*B.b+A.d*B.d;
  }

  void power(Matrix A,int k){
  int x,y,z,v; x=a;y=b;z=c;v=d;
  Matrix P; P.a=a;P.b=b;P.c=c;P.d=d;
  for (int i=0;i<k-1;k++){
  MM(P,A);
  }
  }
};
int main(){
  Matrix M,G,F;
  M.input();
  //G.input();
  //F.Summ(M,G);
  //F.MM(M,G);
  //F.print();
  //M.Multiple();
  //M.print();
  int k; cin>>k;
  M.print();
  M.power(M,k);
  M.print();
  //F.print();
}
