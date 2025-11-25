#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L;
    vector<int> values(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }
    sort(values.begin(), values.end(), greater<int>());
    vector<vector<int>> dp(K + 1, vector<int>(L + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int k = K; k >= 1; k--) {
            for (int l = L; l >= 1; l--) {
                dp[k][l] = max(dp[k][l], dp[k - 1][l - 1] + values[i]);
            }
        }
    }
    cout << dp[K][L] << endl;
    return 0;
}
