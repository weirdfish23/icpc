#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#define MAX 1005

using namespace std;
string strs[MAX];
vector<int> adj[MAX];
vector<int> adjI[MAX];
bool visited[MAX];
stack<int> TS;
stack<int> comp;

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
    visited[u]= true;
    for(int i=0; i<adjI[u].size(); ++i){
        int v = adjI[u][i];
        if(!visited[v])
            dfsSCC(v);
    }
    comp.push(u);
}

int main (){
    int P, T;

    while(true){
        cin >> P >> T;
        if(P==0 && T==0)
            break;
        
        string name;
        map<string, int> names;
        for(int i=1;i<=P ; ++i){
            cin >> ws;
            getline(cin, name);
            names[name] = i;
            strs[i] = name;
            adj[i].clear();
            adjI[i].clear();
            visited[i]= false;
        }

        string s1, s2;
        int u, v;
        for(int i=0; i<T; ++i){
            cin >> ws;
            getline(cin, s1);
            cin >> ws;
            getline(cin, s2);
            u= names[s1];
            v= names[s2];
            adj[u].push_back(v);
            adjI[v].push_back(u);
        }

        for(int i=1; i<=P; ++i){
            if(!visited[i])
                dfsTS(i);
        }
        for(int i=1; i<=P; ++i)
            visited[i]= false;

        int count=0;
        for(int i=1; i<=P; ++i){
            u= TS.top();
            TS.pop();
            if(!visited[u]){
                dfsSCC(u);
                count++;                
                while(!comp.empty())
                    comp.pop();
            }
        }
        cout << count << endl;

    }
    

    return 0;
}
