//
// Created by heyue on 2022/4/13.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>


using namespace std;





//
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

    if (pushed.size() == 0) return true;

    stack<int> my_stack;
    int j = 0;
    for (size_t i = 0; i < pushed.size(); ++i) {
        my_stack.push(pushed[i]);
        while (!my_stack.empty() && my_stack.top() == popped[j]) {
            my_stack.pop();
            j++;
        }
    }
    if (my_stack.empty()) {
        return true;
    }
    else {
        return false;
    }

}
