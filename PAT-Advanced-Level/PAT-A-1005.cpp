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


char *numStr[] = {"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"};
int num[MAXN];

void num2str(int n, int &len) {
	do {
		num[len ++] = n % 10;
		n /= 10;
	} while(n);
}

void work(char *str) {
	int sum = 0;
	for (int i = 0; str[i] != '\0'; ++ i) {
		sum += str[i] - '0';
	}
	int len = 0;
	num2str(sum, len);

	for (int i = len - 1; i > 0; -- i) {
		printf("%s ", numStr[num[i]]);
	}
	printf("%s\n", numStr[num[0]]);
}

int main() {
	char str[MAXN];
	scanf("%s", str);
	work(str);

	return 0;
}