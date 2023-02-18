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
bool validate(int c3,int contpq,int contq,int conts) {
    return (2 * c3 == contpq + contq) || (2 * c3 == contpq + conts)|| (2 * c3 == contq + conts);
}
void solve(int n) {
    stack<unsigned short int> sk;
    queue<unsigned short int>q;
    priority_queue<unsigned short int> pq;
    int conts = 0, contq = 0, contpq = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
        unsigned short int a, x; cin >> a >> x;
        if (a == 1) {
            sk.push(x);
            q.push(x);
            pq.push(x);
        }
        else {
            if (!sk.empty() && x == sk.top()) {
                conts++;
                sk.pop();
            }
            if (!q.empty() && x == q.front()) {
                contq++;
                q.pop();
            }
            if (!pq.empty() && x == pq.top()) {
                contpq++;
                pq.pop();
            }
            c3++;
        }
    }

    if (validate(c3,contpq,contq,conts))print("not sure")
   else if (contq ==c3) {
        print("queue")
    }
    else if (conts ==c3) {
        print("stack")
    }
    else if (contpq==c3) {
        print("priority queue")
    }
    else {
        print("impossible")
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (cin>>s) {
        istringstream ss(s);
        int n;
        ss >> n;
        solve(n);
        s.clear();
        ss.clear();
    }
    return 0;
}