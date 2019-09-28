#include <iostream>
#define MAX 12

using namespace std;

int main(){
    int N, M, u, v;

    bool dpH[MAX][1<<MAX];
    bool graf[MAX][MAX];

    for(int i=0; i<(1<<MAX); ++i)
        for(int j=0; j<MAX; ++j)
            dpH[j][i]=false;
    
    for(int i=0; i<MAX; ++i)
        for(int j=0; j<N; ++j)
            graf[i][j] = false;

    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> u >> v;
        graf[u][v] = graf[v][u] = true;
    }
    
    for(int i=0; i<N; ++i)
        dpH[i][1<<i]=true;

    for(int i=1; i<(1<<N); ++i){
        for(int j=0; j<N; ++j){
            if(i & (1<<j))
                for(int k=0; k<N; ++k){
                    if(i & (1<<k)){
                        if(graf[j][k] && j!=k && dpH[k][i^(1<<j)]){
                            dpH[j][i] = true;
                            break;
                        }
                    }
                }
        }
    }
    bool r = false;
    for(int i=0; i<N; ++i){
        if(dpH[i][(1<<N)-1])
            r = true;
    }
    if(r)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}
