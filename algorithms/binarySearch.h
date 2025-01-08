#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& arr, int target, bool firstOccurrence = true) {
    sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            if (firstOccurrence) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}