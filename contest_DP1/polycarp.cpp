#include <iostream>
#include <string>
#define MAX 200005
using namespace std;
//int cache[MAX][MAX] = {-1};
string s;

//int maxNums(int l, int r){
//    if(l>r)
//        return 0;
//    if(l==r)
//        return ((s[l]-'0') %3 ==0)? 1 : 0;
//
//    int max=0, maxP;
//    for(int p =l; p<r; ++p){
//
//        if(cache[l][p] == -1)
//            cache[l][p] = maxNums(l, p);
//        
//        if(cache[p+1][r] == -1)
//            cache[p+1][r] = maxNums(p+1, r);
//        
//        if (cache[l][p] + cache[p+1][r] > max)
//            max = cache[l][p] + cache[p+1][r], maxP = p;
//    }
//    return max;
//}

int main(){

    getline(cin, s);
    //int sum[MAX]={0};

    //sum[0] = (s[0]-'0')%3;
    //for(int i=1; i<s.size(); ++i){
    //    sum[i] = (sum[i-1] + s[i] - '0')%3;
    //}

    //int DP[MAX][MAX];
    //DP[0][0] = (sum[0]%3 == 0)? 1:0;
    //cout << maxNums(0, s.size()-1) << endl;

    long long ant = 0, tot=0, aux=0;
    for(long long i=0; i<s.size(); ++i){
        if((s[i]-'0')%3==0){
            tot++;
            aux = 0;
        }else{
            aux += (s[i]-'0');
            aux=aux%3;
            if(aux==0)
                tot++;
        }
    }
    cout << tot << endl;

    return 0;
}
