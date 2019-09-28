#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#define MAX 30

using namespace std;
vector<int> adj[MAX];
vector<int> adjI[MAX];
bool mtr[MAX][MAX];
bool visited[MAX];
vector<int> TS;
vector<char> component;

void dfsTS(int u){
    visited[u] = true;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v])
            dfsTS(v);
    }
    TS.push_back(u);
}

void dfsSCC(int u, string strs[]){
    visited[u]= true;
    for(int i=0; i<adjI[u].size(); ++i){
        int v = adjI[u][i];
        if(!visited[v])
            dfsSCC(v, strs);
    }
    component.push_back(strs[u][0]);
}

int main (){
    int N;
    bool first= true;

    while(true){
        cin >> N;
        if(N == 0)
            break;

        map<char, int> names;
        string strs[MAX];
        int max= 0;

        for(int i=1; i<=MAX; ++i){
            for(int j=1; j<=MAX; ++j){
                mtr[i][j]= false;
            }
            visited[i]= false;
            adj[i].clear();
            adjI[i].clear();
        }
        TS.clear();
        for(int i=0; i<N; ++i){
            cin >> ws;
            stack<char> st;
            char aux;
            int u, v;
            while(true){
                cin >> aux;
                if(cin.peek() == ' '){
                    st.push(aux);
                    cin >> ws;
                }else{
                    if(names[aux] == 0){
                        u= ++max;
                        names[aux]=u;
                        strs[u]=aux;
                        //cout << u << " es: " << strs[u] << endl;
                    }else{
                        u= names[aux];
                    }
                    break;
                }
            }
            while(!st.empty()){
                if(names[st.top()] == 0){
                    names[st.top()]= ++max;
                    strs[max]= st.top();
                    //cout << max << " es: " << strs[max] << endl;
                }
                int v= names[st.top()];
                st.pop();
                if(u!=v && !mtr[u][v]){
                    mtr[u][v]= true;
                    adj[u].push_back(v);
                    adjI[v].push_back(u);
                    if(u>max) max= u;
                    if(v>max) max = v;
                }
            }
        }
        for(int i=1; i<=max; ++i){
            if(!visited[i]){
                dfsTS(i);
            }
        }
        reverse(TS.begin(), TS.end());
        for(int i=1; i<=max; ++i){
            visited[i]= false;
        }
        map<char, vector<char> > cs;
        for(int i=0; i<max; ++i){
            if(!visited[TS[i]]){
                dfsSCC(TS[i], strs);
                sort(component.begin(), component.end());
                cs[component[0]] = component;
                component.clear();
            }
        }
        if(first)
            first= false;
        else
            cout << endl;
        for(map<char, vector<char> >::iterator it= cs.begin(); it!=cs.end(); ++it){
            for(int i=0; i<it->second.size(); ++i){
                if(i>0) cout << " ";
                cout << char(it->second[i]);
                //cout << char('A'+it->second[i]);
            }
            cout << endl;
        }
    }

    return 0;
}
