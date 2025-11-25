#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(N, vector<int>(M, 0));
    vector<vector<pair<int, int>>> prev(N, vector<pair<int, int>>(M, {-1, -1}));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) continue;
            if (i > 0 && j > 0) {
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                    prev[i][j] = {i-1, j};
                } else {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                    prev[i][j] = {i, j-1};
                }
            } else if (i > 0) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
                prev[i][j] = {i-1, j};
            } else if (j > 0) {
                dp[i][j] = dp[i][j-1] + grid[i][j];
                prev[i][j] = {i, j-1};
            }
        }
    }
    vector<pair<int, int>> path;
    int i = N-1, j = M-1;
    while (i != -1 && j != -1) {
        path.push_back({i, j});
        pair<int, int> p = prev[i][j];
        i = p.first;
        j = p.second;
    }
    reverse(path.begin(), path.end());
    for (auto p : path) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
