#include <iostream>
#include <vector>

using namespace std;

int main (){
    long int x, y, l, u, blank;
    int n, tTot;
    long double coef=0, aux, fac;
    cout.precision(10);
    cout << fixed;

    cin >> x >> y;
    tTot= y;

    cin >> n;
    blank = y;

    for(int i=0; i<n; ++i){
        cin >> l >> u >> fac;
        coef+= fac*(u-l);
        blank-= (u-l);
    }
    coef+=blank;

    long double r = x/coef;
    cout << r << endl;


    return 0;
}
