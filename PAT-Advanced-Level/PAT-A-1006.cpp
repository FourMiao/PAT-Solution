#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

const int MAXN = 1000 + 10;
const int INF = 1000000000 + 7;

int main() {
	int n;
	char str[22], time1[22], time2[22];
	char maxStr[] = {"00:00:00"}, minStr[] = {"24:59:59"};
	char minID[22], maxID[22];

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%s%s%s", str, time1, time2);
		if (strcmp(time1, minStr) < 0) {
			strcpy(minStr, time1);
			strcpy(minID, str);
		}
		if (strcmp(time2, maxStr) > 0) {
			strcpy(maxStr, time2);
			strcpy(maxID, str);
		}
	}
	printf("%s %s\n", minID, maxID);

	return 0;
}