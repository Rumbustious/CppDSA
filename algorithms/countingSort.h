#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int>& inputArray) {
    int n = inputArray.size();

    int minValue = inputArray[0];
    int maxValue = inputArray[0];

    for (int i = 1; i < n; i++) {
        minValue = min(minValue, inputArray[i]);
        maxValue = max(maxValue, inputArray[i]);
    }

    int range = maxValue - minValue + 1;
    vector<int> countArray(range, 0);

    for (int i = 0; i < n; i++) {
        countArray[inputArray[i] - minValue]++;
    }

    for (int i = 1; i < range; i++) {
        countArray[i] += countArray[i - 1];
    }

    vector<int> outputArray(n);

    for (int i = n - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i] - minValue] - 1] = inputArray[i];
        countArray[inputArray[i] - minValue]--;
    }
    inputArray = outputArray;
}