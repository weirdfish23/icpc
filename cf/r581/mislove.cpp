#include <iostream>
using namespace std;

int main (){
    int n, l, r;

    cin >> n >> l >> r;
    int min = 1 << (l-1), max = r;
    int minimo = l;
    if (n<l)
        minimo = n;

    int rMin = 0;
    int n1=n;
    while(minimo!=1){
        rMin+= min;
        min = min >> 1;
        n1--;
        minimo--;
    }
    
    while(n1){
        rMin++;
        n1--;
    }

    int rMax= 0;
    if(r>n){
        max = n;
    }

    int aux = 1;
    int n2 = n;
    while(max!=1){
        rMax+=aux;
        aux = aux << 1;
        max--;
        --n2;
    }
    while(n2!=0){

        rMax+=aux;
        --n2;
    }

    cout << rMin << " " << rMax << endl;



    return 0;
}
