/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/
#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a). end()
#define endl '\n'

int cont = 0;

void dfs(int u, vector<bool> &vst, vector<int> adj[]){

    if(vst[u]) return;

    vst[u]=true;
    cont++;
    for(auto v: adj[u]) dfs(v, vst, adj);
}

class comp {
    public:
       bool operator()(tuple<double, complex<double>, int> a, tuple<double, complex<double>, int> b){
            if(get<0>(a) ==  get<0>(b)){
                
                if(get<1>(a).real() == get<1>(b).real()){

                    if(get<1>(a).imag() > get<1>(b).imag()) return true;
                    else return false;

                }else if(get<1>(a).real() > get<1>(b).real()) return true;
                else return false;

            }else if(get<0>(a) > get<0>(b)) return true;
            else return false;
    
        }
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    

    int n;
    cin >> n;

    while(n){

        vector<int> adj[n];
        vector<bool> vst(n, 0);

        int e, g;
        cont = 0;

        vector<complex<double>> points(n);

        vector< priority_queue< tuple<double, complex<double>, int>, vector<tuple<double, complex<double>, int> >, comp  >  > check(n);

        for(int i =0; i < n; i++){
            cin >> e >> g;
            points[i] = {(double)e, (double)g};
        }

        double d;

        for(int i =0; i < n;i++){
            for(int j = i+1; j < n; j++){
                d = abs(points[i]-points[j]);

                check[i].push({d, points[j], j});
                check[j].push({d, points[i], i});

            }
        }

        for(int i =0; i < n; i++){
            //cout << i << "-> " ; 
            for(int j =0; j < 2; j++){
                adj[i].push_back(get<2>(check[i].top()));
                //cout << get<2>(check[i].top())<< " ";
                check[i].pop();
            }
            //cout << endl;
        }


        dfs(0, vst, adj);

        if(cont == n) cout << "All stations are reachable." << endl;
        else cout << "There are stations that are unreachable." << endl;

        cin >> n;
    }


    return 0;
}