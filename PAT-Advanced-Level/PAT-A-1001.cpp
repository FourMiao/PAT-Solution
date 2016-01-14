#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

void int2char (char *s, int n) {
	int len = 0;
	bool flag = 1;
	if (n < 0) {
		n = -1 * n;
		flag = 0;
	}
	int cnt = 0;
	do {
		s[len++] = (n % 10) + '0';
		n /= 10;
		++cnt;
		if (cnt % 3 == 0 && n) {
			s[len++] = ',';
		}
	} while(n);
	if (!flag) {
		s[len++] = '-';
	}
	s[len] = '\0';
}

int main () {
	int a, b;
	char str[12];

	while (scanf("%d%d", &a, &b) != EOF) {
		int2char(str, a + b);
		int len = strlen(str);
		for (int i = len - 1; i >= 0; --i) {
			putchar(str[i]);
		}
		putchar('\n');
	}
	return 0;
}