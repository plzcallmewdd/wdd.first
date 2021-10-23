#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0,ListNode *ne=NULL){
        val = x;
        next = ne;
    }
};

class Solution {
public:
    int getMaxbonus(vector<int> price) {
        int* themin = new int[price.size()];
        int i, reMax = 0;
        themin[0] = INT_MAX;
        for (int i = 1; i < price.size(); i++) {
            themin[i] = themin[i - 1] <= price[i - 1] ? themin[i - 1] : price[i - 1];
            reMax = reMax < price[i] - themin[i] ? price[i] - themin[i] : reMax;
        }
        return reMax;
    }
};

int main() {
    int num, temp;
    vector<int> targetpricenum;
    cin >> num;
    char c;
    while (num && ((c=getchar())!='/n')) {
        cin >> temp;
        targetpricenum.push_back(temp);
        num--;
    }
    Solution a;
    cout << a.getMaxbonus(targetpricenum);
    
    return 0;
}
