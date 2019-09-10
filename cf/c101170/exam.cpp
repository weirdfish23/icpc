#include <iostream>
#include <vecto>
#include <algorithm>
#include <queue>
using namespace std;

int main (){
    int n;
    vector<int> order;
    cin >> n;
    int aux;

    for(int i=0; i<n; ++i){
        cin >> aux;
        order.push_back(aux);
    }
    sort(order.begin(), order.end());
    queue<pair<int, int> > exams;
    exams.push(make_pair(0, order[0]);
    bool possible= true;

    for(int i=1; i<n; ++i){
        while(exams.front().second< order[i]){
            order[i]-=exams.front().second;
            if(exams.first == i)
                possible= false, break;
            exams.pop();
        }
        if(order[i]
    }

    return 0;
}
