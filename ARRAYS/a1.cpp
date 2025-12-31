#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 3, 4, 5, 6};

    int bytes = sizeof(arr);
    int elementSize = sizeof(arr[0]);
    int len = bytes / elementSize;

    int ans = arr[0]; // assume first element is smallest

    for (int i = 1; i < len; i++) {
        if (arr[i] < ans) {
            ans = arr[i]; // update smallest
        }
    }

    cout << "Smallest number is: " << ans << endl;

    return 0;
}
