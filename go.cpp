#include <iostream>
#include <vector>
#include <stack>
#define MAX 2005

using namespace std;
vector<int> adj[MAX], adjI[MAX];
bool visited[MAX];
stack<int> TS;

void dfsTS(int u){
    visited[u]= true;
    for(int i=0; i<adj[u].size(); ++i){
        int v= adj[u][i];
        if(!visited[v])
            dfsTS(v);
    }
    TS.push(u);
}

void dfsSCC(int u){
    visited[u] = true;
    for( int i=0; i<adjI[u].size(); ++i){
        int v= adjI[u][i];
        if(!visited[v])
            dfsSCC(v);
    }
}

int main(){
    int N, M;

    while(true){
        cin >> N >> M;
        if(N==0 && M==0)
            break;
        for(int i=1; i<=N; ++i){
            adj[i].clear();
            adjI[i].clear();
            visited[i]= false;
        }
        int u, v, aux;
        for(int i=0; i<M; ++i){
            cin >> u >> v >> aux;
            adj[u].push_back(v);
            adjI[v].push_back(u);
            if(aux==2){
                adj[v].push_back(u);
                adjI[u].push_back(v);
            }
        }
        for(int i=1; i<=N; ++i){
            if(!visited[i])
                dfsTS(i);
        }
        for(int i=1; i<=N; ++i)
            visited[i]= false;

        int count=0;
        while(!TS.empty()){
            u= TS.top();
            TS.pop();
            if(!visited[u]){
                dfsSCC(u);
                count++;
            }
        }
        if(count==1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
