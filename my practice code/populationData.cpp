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
						//����������������ͨʱ����������λ�ó�������������ӵ����
						if (myGraph[i][j] == 0)
							myGraph[i][j] = 1;
						else 
							return "inconsistent";
					}
				}
			}
			//���ֻ�·��ֱ��return
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
			//��signΪ2��ʱ����people1��people2������ͨ��
			//������people1��people2��ͬ�������������
			if (graph[people1 - 1][people2 - 1] != 1 && graph[people2 - 1][people1 - 1] != 1)
				graph[people1 - 1][people2 - 1] = sign;
			else 
				reSign = "inconsistent";
		}
		//��signΪ1��ʱ����people1��people2��������ͨ״̬��
		//�򲻿ɳ�������������Ӻ͵ߵ��������������
		//Ҳ������ͬһ���������Լ�����֮ǰ��ì�����
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