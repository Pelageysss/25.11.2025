#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int max_len = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}
int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Введите элементы последовательности: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Длина самой длинной возрастающей подпоследовательности: " << lengthOfLIS(nums) << endl;
    return 0;
}
