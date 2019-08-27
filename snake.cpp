#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;
typedef vector<int> vi;

vi adj[MAX+5];
vi topo;
int visited[MAX+5];

int dfsCuenta(int u){

}

int main (){
    int T, N, K, u, v;
    cin >> T;

    for(int t=0; t<T; ++t){
        cin >> N;
        
        for(int i=0; i<=MAX; ++i){
            visited[i] = -1;
            adj[i].clear();
        }
        topo.clear()
        int nW = 0; 

        for(int n=0; n<N; ++n){
            cin >> K;
            nW+=K;
            for(int k=0; k<K; ++k){
                cin >> u >> v;
                adj[u].push_back(v);
            }
        }
        
        //for(int i=1; i<=MAX; ++i){
        //    if(visited[i] == -1){
        //        dfsTopo(i);
        //    }
        //}
        
        //reverse(topo.begin(), topo.end());  

        bool posible = dfsCuenta(0) == nW;

        if(posible)
            cout << "Case " << t+1 << ": YES" << endl;
        else
            cout << "Case " << t+1 << ": NO" << endl;


    }

    return 0;
}
