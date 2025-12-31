#include <iostream>
#include <vector>
using namespace std;

void getPermutation(string str, int idx, vector<string> &ans) {
    if (idx == str.size()) {
        ans.push_back(str);
        return;
    }

    for (int i = idx; i < str.length(); i++) {
        swap(str[idx], str[i]);          // include
        getPermutation(str, idx + 1, ans); // recursive call

        swap(str[idx], str[i]);          // exclude → backtracking
    }
}

int main() {
    string str = "abc";
    vector<string> ans;

    getPermutation(str, 0, ans);

    // PRINT ALL PERMUTATIONS
    cout << "All permutations:\n";
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}
