/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/
#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a). end()
#define endl '\n'
#define TAM 100

int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};
int limH, limW;
bool check[TAM][TAM];

int paint(char l, vector<string> coso, int i, int j){

    if(l != coso[i][j] || check[i][j] ) return 0;

    int holi = 1;
    check[i][j]=true;

    for(int k = 0; k < 4; k++){
        if(i+x[k]>= 0 && i+x[k]< limH && j+y[k]>=0 && j+y[k]<limW){
            holi+=paint(l, coso, i+x[k], j+y[k]);
        }
    }

    return holi;
}

void solve(){

    string e1, e2; cin >> e1 >> e2;

    int g =  stoi(e1)-1, h = stoi(e2)-1;

    vector<string> mapita;


    string s, blank;
    getline(cin, blank);
    
    while (getline(cin, s) && !s.empty() ) {
        mapita.push_back(s);        
    }

    limW = mapita[0].size();
    limH = (int)mapita.size();

    for(int i =0; i < limH; i++){
        for(int j =0; j < limW;j++) check[i][j]=false;
    }

    int sol;

    sol = paint('0', mapita, g, h );
    cout << sol << endl;
}

int main(){

    int t; cin >> t;

    while(t--){
        solve();
        if(t) cout << endl;
    }
}