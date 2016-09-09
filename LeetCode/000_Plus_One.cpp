#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500 + 10;
const int INF = 1000000000 + 7;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
		vector<int> ans;
		for (int i = digits.size() - 1; i >= 0; --i) {
			ans.push_back(digits[i]); 
		}

		for (int i = 0; i < ans.size(); ++i) {
			if (!i) {
				int d = (ans[i] + 1) % 10;
				carry = (ans[i] + 1) / 10;
				ans[i] = d;
			} else {
				int d = (ans[i] + carry) % 10;
				carry = (ans[i] + carry) / 10;
				ans[i] = d;				
			}
		} 
		if (carry) {
			ans.push_back(carry);
		}

		vector<int> ret;
		for (int i = ans.size() - 1; i >= 0; --i) {
			ret.push_back(ans[i]);
		}

		return ret;
    }
};

int main() {
	
	vector<int> num;
	num.push_back(8);
	for (int i = 1; i < 4; ++i) {
		num.push_back(9);
	}

	Solution t;
	vector<int> ans = t.plusOne(num);

	for (int i = 0; i < ans.size(); ++ i) {
		cout << ans[i] << endl;
	}
	return 0;
}