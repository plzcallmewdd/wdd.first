// wangdiedang is a good guy! =v=
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Wddsolution {
private:

public:
	int findsolution(string text1, string text2) {
		int i, j;
		/*int** p = new int* [text1.length() + 1];    使用int **p
		for (i = 0; i <= text1.length(); i++) {
			p[i] = new int[text2.length() + 1];
			p[i][0] = 0;
		}
		for (i = 1; i <= text2.length(); i++)
			p[0][i] = 0;*/
		vector<vector<int>> p(text1.length()+1, vector<int>(text2.length()+1));  // 使用vector, c++尽量还是用vector。
		for (i = 0; i < text1.length(); i++) {
			for (j = 0; j < text2.length(); j++) {
				if (text1[i] == text2[j])
					p[i + 1][j + 1] = p[i][j] + 1;
				else
					p[i + 1][j + 1] = max(p[i + 1][j], p[i][j + 1]);
			}
		}
		return p[text1.length()][text2.length()];
	}
};

int main() {
	Wddsolution wdd;
	/*string a = "shdakjahsdkjahdk";
	string b = "shdakadhjxbczmcbyeuuwiqtyuihducbxmbutierteuhkcbaknx,_";
	cout << wdd.findsolution(a, b);*/
	return 0;
}