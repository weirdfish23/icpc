#include <iostream>
#include <vector>
#include <stack>
#define MAX 100005
using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
stack<int> TS;

void dfs(int u){
    visited[u] = true;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
    TS.push(u);
}
void dfs2(int u){
    visited[u] = true;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v]){
            dfs2(v);
        }
    }
}

int main (){

    int T, N, M;

    cin >> T;

    for(int t=0; t<T; ++t){
        cin >> N >> M;

        for(int i=1; i<=N; ++i){
           adj[i].clear();
           visited[i]= false;
        }

        int x, y;
        for(int i=0; i<M; ++i){
            cin >> x >> y;
            adj[x].push_back(y);
        }

        int count=0;
        for(int i=1; i<=N; ++i){
            if(!visited[i]){
                dfs(i);
            }
        }

        for(int i=1; i<=N; ++i)
            visited[i]=false;

        int aux;
        while(!TS.empty()){
            aux=TS.top();
            if(!visited[aux])
                dfs2(aux), count++;
            TS.pop();
        }
        cout << count << endl;
    }

    return 0;
}
