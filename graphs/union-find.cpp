#include <vector>
#include<iostream>

using namespace std;

class UnionFind {
    private: vector<int> p, rank;
    public: 
        UnionFind(int N) {
            rank.assign(N, 0);
            p.assign(N,0);
            for (int i=0; i < N; i++) {
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (p[i] == i? i: (p[i]=findSet(p[i])));
        }

        bool sameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if(!sameSet(i,j)) {
                int s1 = findSet(i);
                int s2 = findSet(j);

                if(rank[s1] > rank[s2]) {
                    p[s2] = s1;
                }
                else {
                    p[s1] = s2;
                    if(rank[s1] == rank[s2]) rank[s2]++;
                }
            }
        }
};

int main() {
    UnionFind *uf = new UnionFind(8);
    uf->unionSet(1,2);
    uf->unionSet(3,4);
    uf->unionSet(5,6);
    uf->unionSet(6,1);
    uf->unionSet(3,5);

    cout<<uf->findSet(1)<<endl;
    cout<<uf->findSet(2)<<endl;
    cout<<uf->findSet(3)<<endl;
    cout<<uf->findSet(4)<<endl;
    cout<<uf->findSet(5)<<endl;
    cout<<uf->findSet(6)<<endl;
}