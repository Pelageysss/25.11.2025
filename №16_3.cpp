#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
int main() {
    int n, amount;
    cout << "Введите количество номиналов монет: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Введите номиналы монет: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Введите сумму: ";
    cin >> amount;
    int result = coinChange(coins, amount);
    cout << "Минимальное количество монет: " << result << endl;
    return 0;
}
