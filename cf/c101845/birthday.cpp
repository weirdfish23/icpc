#include <iostream>
#include <string>

using namespace std;

bool bisiesto(int ano){
    if(ano%4 == 0){
        if(ano%100 == 0){
            return (ano%400 == 0);
        }else{
            return true;
        }
    }else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    string days [7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int c=0;
    int ano = 1867;
    int dia = 0;
    for(int i=1; i<=n; ++i){
        dia++;
        ano++;
        if(bisiesto(ano))
            dia++;
        dia = dia % 7;
    }

    cout << days[dia] << endl;

    return 0;
}
