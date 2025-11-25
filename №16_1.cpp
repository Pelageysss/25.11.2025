#include <iostream>
#include <vector>
using namespace std;

int countPartitions(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    cout << countPartitions(n) << endl;
    return 0;
}
