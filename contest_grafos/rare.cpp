#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#define MAX 50

using namespace std;
vector<int> adj[MAX];
stack<int> TS;
bool visited[MAX];

void dfsTS(int u){
    visited[u]= false;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v])
            dfsTS(v);
    }
    TS.push(u);
}

int main(){
    string line;
    vector<string> word;

    char strs[MAX];
    map<char, int> names;

    while(true){
        getline(cin, line);
        if(line[0] == '#')
            break;
        word.push_back(line);
        //cout << "w: " << line << endl;
    }
    names.clear();
    int count=0;

    for(int i=1; i<=word.size(); ++i){
        adj[i].clear();
        visited[i]= false;
    }

    string aux= word[0];
    names[aux[0]] = ++count;
    strs[count] = aux[0];

    string ant;
    int u, v;

    for(int i=1; i<word.size(); ++i){
        ant= aux;
        aux= word[i];
        //cout << "ant: " << ant << endl;
        //cout << "aux: " << aux << endl;

        int j=0;
        while(j<ant.size() && j<aux.size()){
            if(ant[j]==aux[j]){
                ++j;
            }else{
                if( names[ant[j]] == 0){
                    names[ant[j]]= ++count;
                    strs[count]=ant[j];
                }
                if( names[aux[j]] == 0){
                    names[aux[j]]= ++count;
                    strs[count]= aux[j];
                }
                u= names[ant[j]];
                v = names[aux[j]];
                adj[u].push_back(v);
                break;
            }
        }

    }
   // cout << "Letraas: " << endl;
    for(int i=1; i<=count; ++i){
        char cc = strs[i];
        cout << cc;
    }
    cout << endl;

    for(int i=1; i<=count; ++i){
        if(!visited[i])
            dfsTS(i);
    }

    while(!TS.empty()){
        char c = strs[TS.top()];
        //cout << c;
        TS.pop();
    }

    //cout << endl;

    return 0;
}

