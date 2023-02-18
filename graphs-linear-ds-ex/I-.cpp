/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/
#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a). end()
#define endl '\n'
#define TAM 10000

int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};
int limH, limW;
bool check[TAM][TAM];

void paint(char l, vector<string> coso, int i, int j){

    if(l != coso[i][j] || check[i][j]) return;

    check[i][j]=true;

    for(int k = 0; k < 4; k++){

        if(i+x[k]>= 0 && i+x[k]< limH && j+y[k]>=0 && j+y[k]<limW){
            paint(l, coso, i+x[k], j+y[k]);
        }

    }

}

class comp {
    public:
       bool operator()(pair<int,char> a, pair<int,char> b){
            if(a.first==b.first){

                if(a.second > b.second) return true;
                else return false;

            }else if(a.first > b.first) return false;
            else return true;
        }
};

void solve(){

    cin >> limH >> limW;
    char letter;
    vector<string> coso(limH);
    map<char, int> sol;
    priority_queue<pair<int,char>, vector<pair<int,char>>, comp> paraP;

    for(auto &i: coso) cin >> i;

    for(int i =0; i < limH; i++){
        for(int j = 0; j < limW;j++) check[i][j] = 0;
    }


    for(int i =0; i < limH; i++){
        for(int j = 0; j < limW;j++){
            letter = coso[i][j];
            if(!check[i][j]){
                paint(letter, coso, i, j);
                sol[letter]++;
            } 

        }
    }
    
    for(auto s: sol){
        paraP.push({s.second, s.first});
    }

    while(!paraP.empty()){
        cout << paraP.top().second << ": " << paraP.top().first << endl;
        paraP.pop(); 
    }

}

int main(){

    int t; cin >> t;

    for(int i = 1; i <= t;i++){
        cout << "World #" << i << endl;
        solve();
    }
}