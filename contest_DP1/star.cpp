#include <iostream>
#define MAX_POS 105
using namespace std;

int main (){
    int N, Q, C;
    int stars[MAX_POS][MAX_POS][11]={0}, tot[MAX_POS][MAX_POS][11] ={0};
    int aux[11];

    cin >> N >> Q >> C;

    int x, y, s;

    for(int i=0; i<N; ++i){
        cin >> x >> y >> s;
        stars[x][y][s]++;
    }
    //cout << "Antes:" << endl;
    //for(int i=1; i<=3; ++i){
    //    for(int j=1; j<=3; ++j){
    //        cout << stars[i][j][0] << ' ';
    //    }
    //    cout << endl;
    //}
    for(int i=0; i<11; ++i)
        tot[1][1][i] = stars[1][1][i];

    for(int i=2; i<MAX_POS; ++i){
        for(int j=0; j<11; ++j){
            tot[i][1][j] = stars[i][1][j] + tot[i-1][1][j];
            tot[1][i][j] = stars[1][i][j] + tot[1][i-1][j];
        }
    }

    for(int i=2; i<MAX_POS; ++i){
        for(int j=2;j<MAX_POS; ++j){
            for(int k=0; k<11; ++k){
                tot[i][j][k] = tot[i-1][j][k] + tot[i][j-1][k] - tot[i-1][j-1][k] + stars[i][j][k];
                //debug
                //if (k==0){
                //    cout << "i j: " << tot[i][j][k] << "i j-1: " << tot[i][j-1][k] << " i-1 j: " << tot[i-1][j][k] << endl;
                //    cout << "i-1 j-1: " << tot[i-1][j-1] << endl;
                //}
            }
        }
    }

    long long t, total;
    int x1, x2, y1, y2;

    for(int q=0; q<Q; ++q){
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t = t % (C+1);
        total=0;

        for(int i=0; i<11; ++i){
            aux[i] = tot[x2][y2][i];
            if(x1>1){
                aux[i] -= tot[x1-1][y2][i];
            }
            if(y1>1){
                aux[i] -= tot[x2][y1-1][i];
            }
            if(x1>1 && y1 >1){
                aux[i] += tot[x1-1][y1-1][i];
            }
            total += ((i+t)%(C+1))*aux[i];
        }
        cout << total << endl;
    }
    
    //cout << "Debug: " << endl;
    //for(int i=1; i<=3; ++i){
    //    for(int j=1; j<=3; ++j){
    //        cout << tot[i][j][1] << ' ';
    //    }
    //    cout << endl;
    //}

    return 0;
}
