#include <bitset>
#include<vector>
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {

    int M;
    string blank;
    unsigned short int N, K, P, coin;
    char result;

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        if (i>0)
        {
            cout<<endl;
        }
        
        getline(cin, blank);
        cin >> N >> K;
        bool coins_state[N];
        memset( coins_state, 1, (N)*sizeof(bool) );
        
        while(K--) {
            cin >> P;

            vector<int> w_coins;
            for (unsigned short int j = 0; j < P*2; j++)
            {
                cin >> coin;
                w_coins.push_back(coin);

            }
            cin >> result;

            if (result == '=') {
                for (unsigned short int k = 0; k < w_coins.size(); k++)
                {
                    coins_state[w_coins.at(k)-1] = false;
                }
            }
        }

        int num = 0;
        int count = 0;
        for (unsigned short int l = 0; l < N; l++)
        {
            if (coins_state[l] == 1)
            {
                num = l+1;
                count++;
              
            }
        }
        
        if (count > 1)
        {
            cout<<"0"<<endl;
        }
        else {
            cout<<num<<endl;
        }

    }
}
