// uva 11450 - Wedding Shopping
#include <iostream>

using namespace std;

int main() {
    int g, money, k, TC, M, C;
    int price[25][25]; // price[g (<= 20)][model (<= 20)]
    bool reachable[25][210]; // reachable table[g (<= 20)][money (<= 200)]
    
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &M, &C);
        for (g = 0; g < C; g++) {
            scanf("%d", &price[g][0]); // we store K in price[g][0]
            for (money = 1; money <= price[g][0]; money++)
                scanf("%d", &price[g][money]);
        }
        memset(reachable, false, sizeof reachable); // clear everything
        for (g = 1; g <= price[0][0]; g++) // initial values (base cases)
            if (M - price[0][g] >= 0) // to prevent array index out of bound
                reachable[0][M - price[0][g]] = true; // using first garment g = 0

        for (g = 1; g < C; g++) {// for each remaining garment
            for (money = 0; money < M; money++) {
                if (reachable[g-1][money]) {
                    for (k = 1; k <= price[g][0]; k++) {
                        if (money - price[g][k] >= 0) {
                            reachable[g][money - price[g][k]] = true; // also reachable now
                        }
                    }   
                }
            }
        }

        for (money = 0; money <= M && !reachable[C - 1][money]; money++);

        if (money == M + 1) printf("no solution\n"); // last row has no on bit
        else printf("%d\n", M - money);
    }
}
