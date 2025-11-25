#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool canDistribute(const vector<int>& calories, int D, int maxDiff) {
    int daysUsed = 1;
    int minCal = calories[0];
    int maxCal = calories[0];
    for (int i = 1; i < calories.size(); i++) {
        int newMin = min(minCal, calories[i]);
        int newMax = max(maxCal, calories[i]);
        if (newMax - newMin > maxDiff) {
            daysUsed++;
            minCal = calories[i];
            maxCal = calories[i];
        } else {
            minCal = newMin;
            maxCal = newMax;
        }
    }
    return daysUsed <= D;
}
int main() {
    int N, D;
    cin >> N >> D;
    vector<int> calories(N);
    for (int i = 0; i < N; i++) {
        cin >> calories[i];
    }
    sort(calories.begin(), calories.end());
    int left = 0;
    int right = calories[N-1] - calories[0];
    int answer = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDistribute(calories, D, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}
