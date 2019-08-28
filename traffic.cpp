// la suma de los nodos que tienen solo grado de entrada 0 y los nodos que 
// tienen solo grado de salida 0 y el numero de componentes - 1 por 2 si hay
// mas de un componente
#include <cstdio>
#include <vector>
#define MAX 20005

using namespace std;

int gi[MAX];
int go[MAX];

int main (){
    int T, N, M, u, v;

    scanf("%d", &T);

    for(int t=1; t<=T; ++t){
        scanf("%d %d", &N, &M);
        for(int i=1;i<=N;++i){
            gi[i] = go[i] = 0;
        }

        for(int i=0; i<m; ++u){
            cin >> u >> v;
            go[u]++;
            gi[v]++;
        }

        int count = 0;
        for(int i=1; i<=N; ++i){
            if(gi[i] == 0 || go[i] == 0){
                count ++;
            }
        }
        if(count 

    }

    return 0;
}
