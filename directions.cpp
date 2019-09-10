#include <iostream>
#include <vector>
#include <stack>
#define MAX 1005
#define INF 9999

using namespace std;
vector<int> graf[MAX];
vector<int> grafD[MAX];
bool mtrB[MAX][MAX], visited[MAX], done[MAX][MAX];
int disc[MAX], low[MAX], parent[MAX];

void dfsB(int u, int time){
    visited[u] = true;
    int childs = 0;
    disc[u] = low[u] = time+1;
    for(int i=0; i<graf[u].size(); ++i){
        int v = graf[u][i];
        if(!done[u][v] && !done[v][u]){
            grafD[u].push_back(v);
            done[u][v] = done[v][u] = true;
        }
        if(!visited[v]){
            childs++;
            parent[v]= u;
            dfsB(v, time+1);
            low[u] = min(low[v], low[u]);
            if(low[v] > disc[u])
                mtrB[u][v]= mtrB[v][u]= true;
        }else if(parent[u] != v){
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main (){
    int N, M, T=0, u, v;

    while(true){
        ++T;
        cin >> N >> M;
        if(N==0 && M==0)
            break;
        for(int i=1; i<=N; ++i){
            graf[i].clear();
            grafD[i].clear();
            visited[i]= false;
            disc[i]= 0;
            low[i] = INF;
            parent[i]= -1;
            for(int j=1; j<=N; ++j){
                mtrB[i][j]= false;
                done[i][j]= false;
            }
        }
        for(int i=0; i<M; ++i){
            cin >> u >> v;
            graf[u].push_back(v);
            graf[v].push_back(u);
        }
        for(int i=1; i<=N; ++i){
            if(!visited[i])
                dfsB(i, 0);
        }
        cout << T << endl << endl;
        for(int i=1; i<=N; ++i){
            for(int j=0; j<grafD[i].size(); ++j){
                int v = grafD[i][j];
                cout << i << " " << v << endl;
                if(mtrB[i][v])
                    cout << v << " " << i << endl;
            }
        }
        cout << "#" << endl;

    }
    
    return 0;
}
