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
    string addBinary(string a, string b) {
		int p1 = a.length() - 1;
		int p2 = b.length() - 1;
		int val = 0, carry = 0;
		string ans = "";
		while (p1 >= 0 || p2 >= 0) {
			int val1 = 0, val2 = 0;
			if (p1 >= 0) {
				val1 = a[p1] - '0';
				p1--;
			}
			if (p2 >= 0) {
				val2 = b[p2] - '0';
				p2--;
			}
			val = (val1 + val2 + carry) % 2;
			carry = (val1 + val2 + carry) / 2;
			ans.append(1, val + '0');
		}
		if (carry) {
			ans.append(1, carry + '0');
		}

		string ret = "";
		for (int i = ans.length() - 1; i >= 0; --i) {
			ret.append(1, ans[i]);
		}

		return ret;
    }
};

int main() {
	
	string a = "11";
	string b = "1";

	Solution t;
	string ans = t.addBinary(a, b);

	cout << ans << endl;
	return 0;
}