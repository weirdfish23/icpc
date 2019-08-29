#include <iostream>
#include <string>

using namespace std;

int main (){
    string bin;

    cin >> ws;
    getline(cin, bin);
    int pos1 = bin.find("1");
    int r = ((double)(bin.size() - pos1 -1))/2 +0.5;

    if(r<0 || pos1==-1){
        cout << 0 << endl;
    }else{
        if((bin.size()-pos1-1)%2 == 0 && pos1 < bin.size() -1 && bin.find("1", pos1+1) != -1){
            r++;
        }
        cout << r << endl;
    }

    return 0;
}
