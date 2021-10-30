#include<iostream>
#include<vector>
#include<string>
using namespace std;

class wddsolution {
public:
	void getPathtoleaf(vector<string> tdarrary, string temp="") {
		if (tdarrary.size() == 1) { //�ж���������Ϊ1��ֻ��һ�ֽṹ�����
			cout << temp + tdarrary[0][tdarrary[0].length() - 1] + ";";
			return;
		}
			
		int i;
		for (i = 0; i < tdarrary.size() - 1; i++) //���������ȫ��ͬ�����
			if (tdarrary[i][tdarrary[i].size() - 1] != tdarrary[i + 1][tdarrary[i + 1].size() - 1])
				break;
		if (i == tdarrary.size() - 1) {
			cout << temp + tdarrary[0][tdarrary[0].length() - 1] + ";";
			return;
		}
		else {  //����ֱ��������ֱ��������
			vector<string> tdarrary_h, tdarrary_l;
			for (i = 0; i < tdarrary.size(); i++) {
				if (tdarrary[i][0] == 'H')
					tdarrary_h.push_back(tdarrary[i].erase(0,1));
				else
					tdarrary_l.push_back(tdarrary[i].erase(0,1));
			}

			if(tdarrary_h.size() != 0) //��������Ԫ��ʱ��ʼ�ݹ顣
				getPathtoleaf(tdarrary_h, temp+'H');
			if(tdarrary_l.size() != 0)
				getPathtoleaf(tdarrary_l, temp+'L');                                  
		}
	}
};

int main() {
	wddsolution wdd;
	vector<string> tdarrary;
	int rownum, colnum, tempnum, tempcol, i = 0;
	cin >> rownum;
	char bspace, each_choose;
	string temp;
	if (rownum && ((bspace = getchar()) != '/n')) 
		cin >> colnum;

	while (rownum--) {
		tempcol = colnum+1;
		cin >> tempnum;
		temp = "";
		while (tempcol-- && ((bspace = getchar()) != '/n')) {
			cin >> each_choose;
			temp += each_choose;
		}
		tdarrary.push_back(temp);
	}

	if (tdarrary.size() == 1)
		cout << tdarrary[0] + tdarrary[tdarrary[0].size() - 1];
	else
		wdd.getPathtoleaf(tdarrary);

	return 0;
}
