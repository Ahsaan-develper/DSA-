#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &mainStack) {
    stack<int> tempStack;

    while (!mainStack.empty()) {
        int temp = mainStack.top();
        mainStack.pop();

        // Move elements from tempStack to mainStack if they are greater than temp
        while (!tempStack.empty() && tempStack.top() > temp) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    // Copy sorted elements back to mainStack (optional)
    while (!tempStack.empty()) {
        mainStack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> mainStack;

    mainStack.push(34);
    mainStack.push(3);
    mainStack.push(31);
    mainStack.push(98);
    mainStack.push(92);
    mainStack.push(23);

    cout << "Original Stack: Top -> Bottom" << endl;
    stack<int> temp = mainStack;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(mainStack);

    cout << "\nSorted Stack: Top -> Bottom" << endl;
    while (!mainStack.empty()) {
        cout << mainStack.top() << " ";
        mainStack.pop();
    }

    return 0;
}
