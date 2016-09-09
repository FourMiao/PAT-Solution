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
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++ i) {
			for (int j = i + 1; j < nums.size(); ++ j) {
				if (nums[i] + nums[j] == target) {
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}
		}
    }
};

int main() {
	int n, b;
	vector<int> num;
	int target = 9;

	for (int i = 0; i < 10; ++ i) {
		num.push_back(i);
	}

	Solution s;
	vector<int> t = s.twoSum(num, target);
	for (int i = 0; i < t.size(); ++ i) {
		printf("%d\n", t[i]);
	}

	return 0;
}