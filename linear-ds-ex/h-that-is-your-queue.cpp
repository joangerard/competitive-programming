#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <map>
#include <list>
using namespace std;

int main() {
    int p,c,k;
    char v;
    int cases = 1;

    while(scanf("%d %d",&p,&c),p){
        list<int> q;

        for(int i=1; i<=min(min(p,1000),c); i++) {
            q.push_back(i);
        }

        cout << "Case " << cases++ << ":\n";
        
        for(int i=0; i<c; i++){
            cin >> v;
            if(v == 'N') {
                cout << q.front() << endl;
                q.push_back(q.front());
                q.pop_front();
            } else {
                cin >> k;
                q.remove(k); //O(n)
                q.push_front(k);
            }
        }
    }
}

// 4 2 1 5 3
