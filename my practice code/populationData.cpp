// wangdiedang is a good guy! =v=
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Wddsolution {
public:
	string Warshall(vector<vector<int>>& myGraph, int num = 0) {
		int i, j, k;
		for (k = 0; k < num; k++) {
			for (j = 0; j < num; j++) {
				for (i = 0; i < num; i++) {
					if (myGraph[i][k] == 1 && myGraph[k][j] == 1) {
						//当两人生命周期相通时，则不允许其位置出现生命周期相接的情况
						if (myGraph[i][j] == 0)
							myGraph[i][j] = 1;
						else 
							return "inconsistent";
					}
				}
			}
			//出现回路，直接return
			if (myGraph[k][k] == 1)
				return "inconsistent";
		}
		return "consistent";
	}
};

int main() {
	Wddsolution wdd;
	string reSign = "consistent";
	int sum, sumrecord, people1, people2, sign, i = 0;
	cin >> sum >> sumrecord;
	vector<vector<int>> graph(sum, vector<int>(sum));
	while (i < sumrecord) {
		cin >> people1 >> people2 >> sign;
		if (sign == 2) {
			//当sign为2的时候，则people1和people2不能相通，
			//但允许people1和people2相同的情况，和冗余
			if (graph[people1 - 1][people2 - 1] != 1 && graph[people2 - 1][people1 - 1] != 1)
				graph[people1 - 1][people2 - 1] = sign;
			else 
				reSign = "inconsistent";
		}
		//当sign为1的时候，则people1和people2是属于相通状态，
		//则不可出现生命周期相接和颠倒生命周期情况，
		//也不允许同一个人死于自己出生之前的矛盾情况
		else {
			if (graph[people1 - 1][people2 - 1] == 0 && graph[people2 - 1][people1 - 1] == 0 && people1 != people2)
				graph[people1 - 1][people2 - 1] = sign;
			else 
				reSign = "inconsistent";
		}
		i++;
	}

	if (reSign != "inconsistent")
		reSign = wdd.Warshall(graph, sum);
	cout << reSign;
	return 0;
}