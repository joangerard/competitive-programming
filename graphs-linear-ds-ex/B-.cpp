/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a). end()
#define endl '\n'
#define int long long int

class comp {
    public:
       bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first==b.first){
                if(a.second>b.second) return true;
                else return false;
            }else if(a.first < b.first) return false;
            else return true;
        }
};

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    

    int t;
    cin >> t;

    while(t--){

        string binder, igr, recipe;
        int m, n, b, p, ned, c;
        map<string, int> prices;
        priority_queue<pair<int,string>, vector<pair<int,string>>, comp > sol;
        getline(cin >> ws, binder);
        cin >> m >> n >> b;

        transform(binder.begin(), binder.end(), binder.begin(), ::toupper);

        while(m--){
            cin >> igr >> p;
            prices[igr] = p;
        }

        while(n--){
            int total = 0;
            getline(cin >> ws, recipe);
            cin >> ned;
            while(ned--){
                cin >> igr >> c;
                total += prices[igr] * c;
            }
            if(total<=b) sol.push({total,recipe});

        }

        cout <<binder<<endl;

        if(sol.empty()) cout << "Too expensive!" <<endl;
        else{

            while(!sol.empty()){
                cout << sol.top().second << endl;
                sol.pop();
            }

        }
        cout << endl;

    }

    return 0;
}