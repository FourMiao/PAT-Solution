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
	string reverse(string ans) {
		string tmp;
		for (int i = ans.length() - 1; i >= 0; --i) {
			tmp.append(1, ans[i]);
		}
		ans = tmp;
		return ans;
	}

	string removeZero(string str) {
		string ret;
		int index = -1;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] != '0') {
				index = i;
				break;
			}
		}

		for (int i = index; i < str.length(); ++i) {
			ret.append(1, str[i]);
		}

		if (index == -1) {
			ret = "0";
		}
		return ret;
	}

	string add(string num1, string num2) {
		string ans;
		int p1 = num1.length() - 1;
		int p2 = num2.length() - 1;
		int carry = 0, val = 0;

		while (p1 >= 0 || p2 >= 0) {
			int val1 = 0, val2 = 0;
			if (p1 >= 0) {
				val1 = num1[p1] - '0';
				p1--;
			}
			if (p2 >= 0) {
				val2 = num2[p2] - '0';
				p2--;
			}
			val = (val1 + val2 + carry) % 10;
			carry = (val1 + val2 + carry) / 10;
			ans.append(1, val + '0');
		}

		if (carry) {
			ans.append(1, carry + '0');
		}

		ans = reverse(ans);

		return ans;
	}

    string multiply(string num1, string num2) {
		string ans = "0";
		
		for (int i = num1.length() - 1; i >= 0; --i) {
			int carry = 0, val = 0;
			string num = "";
			for (int j = num2.length() - 1; j >= 0; --j) {
				val = ((num1[i] - '0') * (num2[j] - '0') + carry) % 10;
				carry = ((num1[i] - '0') * (num2[j] - '0') + carry) / 10;
				num.append(1, val + '0');
			}
			if (carry) {
				num.append(1, carry + '0');
			}
			num = reverse(num);
			num.append(num1.length() - i - 1, '0');
			ans = add(ans, num);
		}

		return removeZero(ans);
    }
};

int main() {
	
	string s1 = "9133";
	string s2 = "0";

	Solution t;

	cout << t.multiply(s1, s2) << endl;
	return 0;
}