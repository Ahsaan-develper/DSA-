#include<iostream>
#include<vector>
using namespace std;

void NotRepeatSubSet(vector<int>& vec, vector<int>& ans, int i, vector<vector<int>>& allSubs){
    if (i == vec.size()){
        allSubs.push_back(ans);
        return;
    }

    // include
    ans.push_back(vec[i]);
    NotRepeatSubSet(vec, ans, i+1, allSubs);

    // exclude
    ans.pop_back();

    int idx = i + 1;
    while (idx < vec.size() && vec[idx] == vec[idx - 1]) {
        idx++;
    }

    NotRepeatSubSet(vec, ans, idx, allSubs);
}

int main(){
    vector<int> vec = {1, 2, 2, 3};
    vector<int> ans;
    vector<vector<int>> allSubs;

    NotRepeatSubSet(vec, ans, 0, allSubs);

    // PRINT RESULT
    for (auto &sub : allSubs){
        cout << "{ ";
        for (int x : sub){
            cout << x << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
