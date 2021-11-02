// wangdiedang is a good guy! =v=
#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
#include<algorithm>
using namespace std;

class Wddsolution {
private:

public:
	int getmaxprofit(vector<int> values, vector<int> weights, int allweight) {
		vector<vector<int>> profitary(values.size() + 1, vector<int>(allweight + 1));
		int i, j;
		for (i = 1; i <= values.size(); i++)
			for (j = 1; j <= allweight; j++)
				profitary[i][j] = j - weights[i-1] >= 0 ? max(profitary[i - 1][j], values[i - 1] + profitary[i - 1][j - weights[i - 1]]) : profitary[i - 1][j];
		return profitary[values.size()][allweight];
	}
};

int main() {
	Wddsolution wdd;
	/*vector<int> values = { 12, 10, 20, 15 };
	vector<int> weights = { 2, 1, 3, 2 };
	cout << wdd.getmaxprofit(values, weights, 5);*/
	return 0;
}