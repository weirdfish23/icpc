#include <iostream>
#include <string>
using namespace std;

int main (){
    int n;
    string s1, s2;
    cin >> n;
    cin >> ws;

    getline(cin, s1, ' ');
    cin >> ws;
    getline(cin, s2);
    
    long long int n1=0, n2=0;
    long long int ant;

    if(s1[0] == '1')
        ant=1;
    else
        ant = 0;
    n1+= ant;
    for(int i=1; i<s1.size(); ++i){
        if(s1[i] == '1'){
            ant = ant? 0:1;
        }
        n1 = n1 << 1;
        n1+=ant;
            
    }

    if(s2[0] == '1')
        ant=1;
    else
        ant = 0;
    n2+= ant;
    for(int i=1; i<s2.size(); ++i){
        if(s2[i] == '1'){
            ant = ant? 0:1;
        }
        n2 = n2 << 1;
        n2+=ant;
            
    }
    long long int r = (n1 > n2)? (n1-n2):(n2-n1);
    r--;
    cout << r << endl;

    return 0;
}
