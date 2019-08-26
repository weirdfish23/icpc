#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi adj[20];
vi topo;
int visited[20];

void dfsTopo(int u){
    visited[u] = 1;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(visited[v] == -1){
            dfsTopo(v);
        }
    }
    topo.push_back(u);
}

int main (){
    adj[1].push_back(5);
    adj[1].push_back(6);
    adj[1].push_back(5);
    adj[2].push_back(5);
    adj[2].push_back(9);
    adj[2].push_back(5);
    adj[3].push_back(5);
    adj[3].push_back(5);
    adj[3].push_back(5);
    adj[4].push_back(5);
    adj[4].push_back(5);
    adj[4].push_back(5);
    adj[5].push_back(5);
    adj[6].push_back(5);
    adj[6].push_back(5);
    adj[7].push_back(5);
    adj[9].push_back(5);
    adj[10].push_back(5);
    adj[10]push_back(5);
    adj[11].push_back(5);
    adj[13].push_back(5);

    return 0;
}
