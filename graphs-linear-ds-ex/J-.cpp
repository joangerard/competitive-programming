/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/
#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a). end()
#define endl '\n'
#define TAM 1000

int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};
int limH, limW;
bool check[TAM][TAM];

int paint(char l, vector<string> coso, int i, int j){

    if(l != coso[i][j] || check[i][j] || coso[i][j]=='.') return 0;

    int holi = 1;
    check[i][j]=true;

    for(int k = 0; k < 4; k++){

        if(i+x[k]>= 0 && i+x[k]< limH && j+y[k]>=0 && j+y[k]<limW){
            holi+=paint(l, coso, i+x[k], j+y[k]);
        }

    }

    return holi;

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

void solve(int h, int w){
    limH = h, limW = w;
    char letter;
    vector<string> coso(limH);

    priority_queue<pair<int,char>, vector<pair<int,char>>, comp> sol;

    for(auto &i:coso) cin >> i;

    for(int i =0; i < limH; i++){
        for(int j = 0; j < limW;j++) check[i][j] = 0;
    }


    for(int i =0; i < limH; i++){
        for(int j = 0; j < limW;j++){
            letter = coso[i][j];
            if(!check[i][j] && letter!='.'){
                sol.push({paint(letter, coso, i, j), letter});
          
            } 
        }
    }

    while(!sol.empty()){
        cout << sol.top().second << " " << sol.top().first << endl;
        sol.pop(); 
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    

    int h, w, c =1;
    cin >> h >> w;

    while(h&&w){
        cout << "Problem " << c<< ":" << endl;
        solve(h, w);
        cin >> h >> w;
        c++;
    }
}