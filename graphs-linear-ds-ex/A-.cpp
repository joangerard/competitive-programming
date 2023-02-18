/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a). end()
#define endl '\n'


map<string, bool> tGen;
map<string, string> people;
map<string, vector<string> > graph;

string chickbear(string child){
    
    if(tGen[child]) return people[child];;

    string rp1 =  chickbear(*graph[child].begin());
    string rp2 =  chickbear(*graph[child].rbegin());

    if((rp1 == "dominant" && rp2 == "dominant") || (rp1 == "dominant" && rp2 == "recessive") || (rp2 == "dominant" && rp1 == "recessive") ) people[child] = "dominant";
    else if( (rp1 == "recessive" && rp2 == "recessive") || (rp1 == "dominant" && rp2 == "non-existent") || (rp2 == "dominant" && rp1 == "non-existent") ) people[child] =  "recessive";
    else people[child] =  "non-existent";

    tGen[child] = true;

    return people[child];
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    

    int n; cin >> n;
    
    string s, p;

    while(n--){
        cin >> s >> p;
        if(p=="dominant"||p=="recessive"||p=="non-existent"){
            people[s] = p;
            tGen[s]=1;
        }else{
            graph[p].push_back(s);
            if(!tGen[p]) tGen[p] = 0;
            if(!tGen[s]) tGen[s] = 0;  
        }
    }

    for(auto x: tGen){
        if(!x.second) chickbear(x.first);
    }

    for(auto x: people){
        cout << x.first << " " << x.second << endl;
    }


    return 0;
}