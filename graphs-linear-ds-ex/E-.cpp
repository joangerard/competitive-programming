/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/
#include <bits/stdc++.h>
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define punteria(a) cout<<setprecision(a)<<endl
#define print(a) cout<<a<<endl;
#define input(a) cin.ignore();getline(cin,a);

using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string primero; 
    int segundo, tercero;
    int k;
    map<int, int> retornos; 
    vector<pair<int, int>> joselito;
    vector<int> incremento;
    while(true){
        cin>>primero; 
        if(primero == "Register"){
            cin>>segundo>>tercero;
            joselito.push_back({tercero, segundo}); 
            incremento.push_back(tercero);
        }
        else if(primero == "#"){
            cin>>segundo;
            break;
        }
    }


    k = segundo;
     
    pair<int, int> minimo; 
    while(k--){
        minimo = {INT_MAX, INT_MAX};
        for(auto i: joselito) minimo = min(minimo, i); 
        for(int i=0; i<joselito.size(); i++){
            if(joselito[i] == minimo) joselito[i].first += incremento[i]; 
        }
        print(minimo.second); 
    }

    return 0;
}