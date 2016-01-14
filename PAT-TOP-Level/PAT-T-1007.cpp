#include <cstdio>
#include <cstring>

const int MAXN = 500 + 10;
const int MAXH = 10 + 2;
const int MOD = 1000000007;

typedef long long LL;

LL dp[MAXN][MAXNH][2];

int dfs(int n, int H, bool color) {
    if (H == 1) {
        return n == 1 ? 1 : 0;
    }
    if (dp[n][H][color]) {
        return dp[n][H][color];
    }
    for (int x = 1; x < n; ++ x) {
        if (!color) {
            dp[x][H - 1][~color] = dfs(x, H - 1, ~color);
            dp[n - x][H - 1][~color] = dfs(n - x, H - 1, ~color);
            dp[n][H][color] = dp[x][H - 1][~color] * dp[n - x][H - 1][~color] % MOD;
        } else {
            dp[x][H - 1][color] = dfs(x, H - 1, color);
            dp[n - x][H - 1][color] = dfs(n - x, H - 1, color);
            dp[n - x][H][~color] = dfs(n - x, H, ~color);
            dp[x][H][~color] = dfs(x, H, ~color);
            dp[n][H][color] = (dp[n][H][color] + dp[x][H - 1][color] * dp[n - x][H - 1][color] % MOD) % MOD;
            dp[n][H][color] = (dp[n][H][color] + dp[x][H - 1][color] * dp[n - x][H][~color] * 2 % MOD) % MOD;
            dp[n][H][color] = (dp[n][H][color] + dp[x][H][~color] * dp[n - x][H][~color] % MOD) % MOD;
        }
    }
    return dp[n][H][color];
}

void work(int n) {
    LL ans = 0;
    for (int H = 1; H < MAXH; ++ H) {
        if (((1 << H) - 1) > n) {
            break;
        }
        ans = (ans + dfs(n, H, 1)) % MOD;
    } 
    printf("%lld\n", ans);
    return ;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        work(n);
    }
    return 0;
}