// uva 11450 - Wedding Shopping
#include <iostream>

using namespace std;

int M, C, price [25] [25];
int memo [210] [25];

int shop_backtrack(int money, int g) {
    if (money < 0) return -1000000000;
    if (g == C) return M - money;

    int ans = -1;
    for (int model = 1; model <= price [g] [0]; model++)
        ans = max (ans, shop_backtrack(money - price [g][model], g + 1));
    
    return ans;
}

int shop_top_down(int money, int g) {
    if (money < 0) return -1000000000;
    if (g == C) return M - money;

    if (memo[money][g] != -1) return memo[money][g]; // TOP-DOWN: memoization

    int ans = -1;
    for (int model = 1; model <= price [g] [0]; model++)
        ans = max (ans, shop_top_down(money - price [g][model], g + 1));
    
    return memo[money][g] = ans;
}

void print_shop(int money, int g) { // this function returns void
    if (money < 0 || g == C) return; // similar base cases
    for (int model = 1; model <= price[g][0]; model++) {
        if (shop_top_down(money - price[g][model], g + 1) == memo[money][g]) {
                printf("%d%c", price[g][model], g == C-1 ? '\n' : '-');
                print_shop(money - price[g][model], g + 1);
        }
    }
}

int main() {

    int i, j, TC, score; 
    scanf ("%d", &TC) ;

    while (TC--) {
        scanf ("%d %d", &M, &C);

        for (i = 0; i < C; i++) {
            scanf ("%d", &price[i][0]); // number of garments
    
            for (j = 1; j <= price[i][0]; j++) scanf ("%d", &price[i][j]);
        }
    
        memset (memo, -1, sizeof memo);
        score = shop_top_down (M, 0);
        if (score < 0)  printf ("no solution \n");
        else            printf ("%d\n", score);

        print_shop(M,0);
    }
}