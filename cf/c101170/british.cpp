#include <iostream>
#include <vector>
#include <stack>
#define MAX 100005

using namespace std;
vector<int> graf[MAX];
bool visited[MAX];
stack<int> TS;

void dfsTS(int u){
    visited[u]= true;
    for(int i=0;i<graf[u].size(); ++i){
        int v = graf[u][i];
        if(!visited[v])
            dfsTS(v);
    }
    TS.push(u);
}
int dfsDeep(int u){
    visited[u]= true;
    int max= 0;
    for(int i=0; i<graf[u].size(); ++i){
        int v = graf[u][i];
        if(!visited[v]){
            int aux= dfsDeep(v);  
            if(aux>max) max = aux;
        }
    }
    return max + 1;
}

int main (){
    int n, m, u, v;
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        visited[i]= false;
        graf[i].clear();
    }

    for(int i=0; i<m; ++i){
        cin >> u >> v;
        graf[u].push_back(v);
    }
    int max = 0;

    for(int i=1; i<=n; ++i){
        if(!visited[i])
            dfsTS(i);
    }
    for(int i=1; i<=n; ++i){
        visited[i]= false;
    }

    while(!TS.empty()){
        int t= TS.top();
        TS.pop();
        if(!visited[t]){
            int aux = dfsDeep(t);
            if(aux> max)
                max = aux;
        }
    }
    cout << max << endl;


    return 0;
}
