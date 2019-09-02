#include <iostream>
using namespace std;

int suma(int i){
    if(i==1)
        return 0;
    if(i==2)
        return 0;
    i--;
    return (i*(i-1)/2);
}

int main (){
    int n;
    int c= 0;
    cin >> n;

    for(int i=1; i<=(n+1); ++i){
        c = c + suma(i);
    }
    cout << c*3 << endl;

    return 0;
}
