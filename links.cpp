#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 10005
#define INF 999999

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vi adjList [MAX];

int low[MAX], disc[MAX], parent[MAX];
int visited[MAX];
vii bridges;

void dfsBridges(int u, int time){
    visited[u] = 1;
    low[u] = disc[u] = time +1;

    for(int i=0; i<adjList[u].size(); ++i){
        int v = adjList[u][i];
        if(visited[v] == -1){
            parent[v] = u;
            dfsBridges(v, time+1);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]){
                bridges.push_back(make_pair(u, v));
            }
        }else if(parent[u] != v){
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main (){
    int T, N, u, v, k;

    //scanf("%d", &T);

    //for(int t=0; t<T; ++t){
    while(true){

        if(scanf("%d", &N) == EOF)
            break;

        for(int i=0; i<N; ++i){
            low[i] = INF;
            disc[i] = 0;
            parent[i] = -1;
            visited[i] = -1;
            adjList[i].clear();
        }
        bridges.clear();

        for(int n=0; n<N; ++n){
           scanf("%d (%d)", &u, &k);

           for(int i=0; i<k; ++i){
               scanf("%d", &v);
               adjList[u].push_back(v);
           }
        }

        for(int i=0; i<N; ++i){
            if(visited[i] == -1){
                dfsBridges(i, 0);
            }
        } 

        sort(bridges.begin(), bridges.end());
        //printf("Case %d:\n", t+1);
        printf("%d critical links\n", bridges.size());
        for(int i=0; i<bridges.size(); ++i){
            u = bridges[i].first;
            v = bridges[i].second;
            if(v<u){
                int temp = u;
                u=v;
                v=temp;
            }
            printf("%d - %d\n", u, v);
        }
        printf("\n");

    }

    return 0;
}
