#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int MAXN = 2000 + 10;
const int MOD = 1000000007;
const double eps = 1e-6;

int cmp(string str, LL num, LL base) {
	LL tmp = 1, cnt = 0;
	for (int i = str.size() - 1; i >= 0; -- i) {
		LL n = 0;
		if (str[i] >= '0' && str[i] <= '9') {
			n = str[i] - '0';
		} else {
			n = str[i] - 'a' + 10;
		}
		cnt += tmp * n;
		if (cnt > num) {
			return -1;
		}
		tmp = tmp * base;
		if (tmp < 0 || cnt < 0) {
			return -1;
		}
	}
	if (cnt < num) {
		return 1;
	}
	return 0;
}

LL change(string str, LL base) {
	LL ret = 0;
	for (int i = 0; i < str.size(); ++ i) {
		if (str[i] >= '0' && str[i] <= '9') {
			ret = ret * base + str[i] - '0';
		} else {
			ret = ret * base + str[i] - 'a' + 10;
		}
	}
	return ret;
}

LL findBase(LL num, string str) {
	LL best = -1, L = 0, R = num + 1;

	for (int i = 0; i < str.size(); ++ i) {
		int tmp = 0;
		if (str[i] >= '0' && str[i] <= '9') {
			tmp = str[i] - '0';
		} else {
			tmp = str[i] - 'a' + 10;
		}
		L = tmp > L ? tmp : L;
	}
	L ++;

	while (L <= R) {
		LL mid = (L + R) >> 1;
		LL tmp = change(str, mid);
		int flag = cmp(str, num, mid);
		if (flag == -1) {
			R = mid - 1;
		} else if (flag == 1) {
			L = mid + 1;
		} else {
			best = mid;
			R = mid - 1;
		}
	}
	return best;
}

LL gao(string s1, string s2, int tag, LL radix) {
	LL num;
	string str;
	if (tag == 1) {
		num = change(s1, radix);
		str = s2;
	} else {
		num = change(s2, radix);
		str = s1;
	}
	
	return findBase(num, str);
}

int main() {
	string s1, s2;
	int tag;
	LL radix;
	cin >> s1 >> s2 >> tag >> radix;
	LL ans = gao(s1, s2, tag, radix);
	if (ans == -1) {
		puts("Impossible");
	} else {
		cout << ans << endl;
	}
	return 0;
}