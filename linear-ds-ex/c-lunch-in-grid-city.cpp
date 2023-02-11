#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
	int T, s, a, f;
;
	cin >> T;
	while(T--)
	{
		cin >> s >> a >> f;
		
		vector<int> streetPoints(f);
		vector<int> avenuePoints(f);

		for(int i = 0; i < f; ++i) {
            cin >> streetPoints[i] >> avenuePoints[i];  
        }
        
		sort(streetPoints.begin(), streetPoints.end());
		sort(avenuePoints.begin(), avenuePoints.end());

		int mitad = f/2 - 1;
        
        if (f%2 == 1) mitad++;

		cout << "(Street: " << streetPoints[mitad] << ", Avenue: " << avenuePoints[mitad] << ")\n";
	}
}