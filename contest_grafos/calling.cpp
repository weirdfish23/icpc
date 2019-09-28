#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#define MAX 30

using namespace std;

bool mtr[MAX][MAX], visited[MAX];
vector<int> adj[MAX];
vector<int> adjI[MAX];
vector<int> comp;
stack<int> topo;

void dfsTS(int u){
    visited[u]= true;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v])
            dfsTS(v);
    }
    topo.push(u);
}

void dfsSCC(int u){
    visited[u]= true;
    for(int i=0; i<adjI[u].size(); ++i){
        int v= adjI[u][i];
        if(!visited[v])
            dfsSCC(v);
    }
    comp.push_back(u);
}

int main (){
    int N, M, t=0;
    string s1, s2;

    while(true){
        cin >> N >> M;

        if(N==0 && M==0)
            break;
        ++t;
        string names[MAX];
        names[0] = string(" ");
        map<string, int> person;
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=N; ++j)
                mtr[i][j]= false;
            adj[i].clear();
            adjI[i].clear();
            visited[i]= false;
        }
        //topo.clear();
        comp.clear();

        int aux=1;
        for(int i=0; i<M; ++i){
            cin >> ws;
            getline(cin, s1, ' ');
            cin >> ws;
            getline(cin, s2);
            cin >> ws;
            if(person[s1] == 0){
                names[aux]=s1;
                person[s1] = aux++;
            }
            if(person[s2] == 0){
                names[aux]=s2;
                person[s2] = aux++;
            }
            if(s1.compare(s2)!=0 && !mtr[person[s1]][person[s2]]){
                mtr[person[s1]][person[s2]]= true;
                adj[person[s1]].push_back(person[s2]);
                adjI[person[s2]].push_back(person[s1]);
            }
        }
        
        for(int i=1; i<=N; ++i){
            if(!visited[i])
                dfsTS(i);
        }

        for(int i=1; i<=N; ++i){
            visited[i]= false;
        }

        if(t>1)
            cout << endl;
        cout << "Calling circles for data set " << t << ":" << endl;

        for(int i=1; i<=N; ++i){
            if(!visited[topo.top()]){
                dfsSCC(topo.top());
                topo.pop();
                bool first=true;
                sort(comp.begin(), comp.end());
                for(int j=0; j<comp.size(); ++j){
                   if(!first)
                       cout << ", ";
                   else 
                       first= false;
                   cout << names[comp[j]];
                }
                comp.clear();
                if(M>=1)
                    cout << endl;
            }else{
                topo.pop();
            }
        }

    }

    return 0;
}
