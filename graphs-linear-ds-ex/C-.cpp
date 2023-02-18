/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/
#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a). end()
#define endl '\n'
#define int long long int

int32_t main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
	
    int n;
    cin >> n;
    while (n){

        set<int> bills;
        map<int, int> remain;
        int k, e, sol = 0;

        while(n--){

            cin >> k;

            while(k--){
                cin >> e;
                remain[e]++;
                bills.insert(e);
            }

            


            sol+= (*bills.rbegin() - *bills.begin() );
            remain[*bills.rbegin()]--;
            remain[*bills.begin()]--;

            if(!remain[*bills.rbegin()]) bills.erase(*bills.rbegin());
            if(!remain[*bills.begin()]) bills.erase(*bills.begin());
        }

        cout << sol << endl;
        cin >> n;
    }
    return 0;
}