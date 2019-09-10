#include <vector>
#include <stack>
#include <cstdio>
#define MAX 10005
#define INF 99999

using namespace std;

vector<int> graf[MAX];
bool visited[MAX], AP[MAX];
stack< pair<int, int> > bridges;
int low[MAX], disc[MAX], parent[MAX];
int totBC;

void dfsBC(int u, int time){
    visited[u]= true;
    disc[u] = low[u] = time+1;
    int childs=0;

    for(int i=0; i<graf[u].size(); ++i){
        int v = graf[u][i];
        if(!visited[v]){
            childs++;
            parent[v] = u;
            dfsBC(v, time+1);
            bridges.push(make_pair(u, v));
            low[u] = min(low[u], low[v]);
            if(parent[u]==-1 && childs>1){
                AP[u]= true;
                totBC++;
                while((bridges.top().first != u || bridges.top().second != v)
                   && (bridges.top().first != v || bridges.top().second != u)){
                    bridges.pop();
                }
                bridges.pop();
            }
            if(parent[u]!=-1 && low[v] >= disc[u]){
                AP[u]= true;
                totBC++;
                while((bridges.top().first != u || bridges.top().second != v)
                   && (bridges.top().first != v || bridges.top().second != u)){
                    bridges.pop();
                }
                bridges.pop();
            }
        }else if(parent[u] != v && low[u] > disc[v]){
            low[u] = disc[v];
            bridges.push(make_pair(u, v));
        }
    }
 
}

int main (){
    int T, N, M, u, v;
    scanf("%d", &T);

    for(int t=0; t<T; ++t){
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; ++i){
            visited[i]= false;
            graf[i].clear();
            low[i] = INF;
            disc[i] = 0;
            parent[i] = -1;
        }
        totBC=0;
        for(int m=0; m<M; ++m){
            scanf("%d %d", &u, &v);
            graf[u].push_back(v);
            graf[v].push_back(u);
        }
        for(int i=0; i<N; ++i){
            if(!visited[i]){
                dfsBC(i, 0);
                if(!bridges.empty()){
                    totBC++;
                    while(!bridges.empty())
                        bridges.pop();
                }
            }
        }
        printf("Case %d: %d\n", t+1, totBC-1);
    }

    return 0;
}

