#include <iostream>
#include <bitset>

using namespace std;

int main (){
    long long int n, m, num, s;
    cin >> n >> m;

    for(long long int i=0; i<m; ++i){
        cin >> num >> s;
        s = s%n;
        //cout << s << endl;
        //cout << "Num: ";
        //cout<<bitset<50>(num)<<endl;
        
        for(long long int j=0; j<s; ++j){
            if(num >= ((long long int)1 << (n-1))){
                num-= ((long long int)1 << (n-1));
                num = num << 1;
                num++;
            }else{
                num = num << 1;
            }
            //cout<<bitset<50>(num)<<endl;
        }
        cout << num << endl;

    }

    return 0;
}
