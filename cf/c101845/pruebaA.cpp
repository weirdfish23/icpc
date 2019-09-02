#include <iostream>

using namespace std;
int foo(int a,int b,int c,int d,int e){
  b = a*16;
  c= a*9+b*16;
  d = a*4+b*9+c*16;
  e = a + b * 4 +c * 9 + d * 16;
  return 0;
}
int main(){
  int n;
  cin>>n;
  int sum;
  int a, b, c, d, e=0;
  a = 1;
  if(n<10){
    sum=a;
  }
  b = a*16;
  if(n<=10){
    sum=a+b;
  }
  c= a*9+b*16;
  if(n<=20){
    sum=a+b+c;
  }
  cout<<sum<<endl;
  return 0;

  d = a*4+b*9+c*16;
  if(n<=30){
    sum=a+b+c+d;
  }
  cout<<sum<<endl;
  return 0;

  e = a + b * 4 +c * 9 + d * 16;
  if(n<=40){
    sum=a+b+c+d+e;
  }
  cout<<sum<<endl;
  return 0;

  if((n/10)<5){
    sum=a+b+c+d+e;
  }
  cout<<sum<<endl;
  return 0;

  for(int i=5; i<n/10; i++){
    a=b;
    foo(a,b,c,d,e);
  }
   sum=a+b+c+d+e;

   cout<<sum<<endl;
    
  return 0;
}
