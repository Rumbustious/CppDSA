#include <vector>

using namespace std;

int linearSearch(vector<int>& arr, int target, bool firstOccurrence = true) {
    if (firstOccurrence) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
    } else {
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] == target) {
                return i;
            }
        }
    }
}