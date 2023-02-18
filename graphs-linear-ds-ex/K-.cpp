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

    int n; 

    while(true){
        cin>>n; 

        if(n == 0) break; 

        bitset<32> original(n), a, b; 
        bool turno = true; 
        for(int i=0; i<32; i++){
            if(turno and original[i] == 1){
                a[i] = original[i]; 
                b[i] = 0; 
                turno = false;
            }else if(original[i] == 1){
                a[i] = 0; 
                b[i] = original[i];
                turno = true;
            }
        }

        print(a.to_ulong()<<" "<<b.to_ulong())
        
    }
    //
    return 0;
}