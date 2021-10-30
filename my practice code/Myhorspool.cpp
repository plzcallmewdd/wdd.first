#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
private:
	map<char, int> getshifttable(string targetstr) {
		map<char, int> shifttable;
		for (int i = targetstr.length() - 2; i >= 0; i--)
			shifttable.insert({ targetstr[i], targetstr.length() - 1 - i });
		return shifttable;
	}
public:

	int myhorspool(string mainstr, string targetstr) {
		map<char, int> shifttable = getshifttable(targetstr);
		int i, j;
		i = targetstr.length() - 1; j = targetstr.length() - 1;
		while (i < mainstr.length()) {
			char finalchar = mainstr[i];
			for (j = targetstr.length() - 1; j >= 0; j--, i--)
				if (targetstr[j] != mainstr[i]) {
					if (shifttable.count(finalchar)) //���Ӷ�Ϊn*m?
						i += shifttable.find(finalchar)->second;
					else
						i += targetstr.length();
					break;
				}
			if (j == -1)
				return i+2;
		}
		return 0;
	}
};

int main() {
	Solution wdd;
	string mainstr;
	string targetstr;
	cin >> mainstr;
	cin >> targetstr;
	if (wdd.myhorspool(mainstr, targetstr))
		cout << "�ҵ��ˣ���������" << wdd.myhorspool(mainstr, targetstr) << "��λ�ÿ�ʼ";
	else
		cout << "δ�ҵ���";
		return 0;
}