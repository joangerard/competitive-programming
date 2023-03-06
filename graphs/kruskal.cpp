#include <vector>
#include <iostream>

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
    vector<pair<int, pair<int, int>>> EdgeList; // weight, (u,v)
    int V = 5, E = 7;


    // create list of edges
    EdgeList.push_back(make_pair(2,make_pair(1,2))); 
    EdgeList.push_back(make_pair(4,make_pair(1,0))); 
    EdgeList.push_back(make_pair(4,make_pair(0,2))); 
    EdgeList.push_back(make_pair(8,make_pair(2,3))); 
    EdgeList.push_back(make_pair(6,make_pair(0,3))); 
    EdgeList.push_back(make_pair(9,make_pair(3,4))); 
    EdgeList.push_back(make_pair(6,make_pair(0,4))); 

    //kruskal algo
    sort(EdgeList.begin(), EdgeList.end());

    int mst_cost = 0;
    UnionFind uf(V);

    for (int i =0; i< E; i++) {
        pair<int, pair<int,int>> front = EdgeList[i];
        int u = front.second.first; //vertex u
        int v = front.second.second; //vertex v
        int w = front.first; //weight

        if (!uf.sameSet(u, v)) { // there is no  cycle
            mst_cost += w; // weight
            uf.unionSet(u,v);
        }
    }

    cout<<"MST cost:"<<mst_cost<<endl;
}
