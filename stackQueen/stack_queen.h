//
// Created by heyue on 2022/4/13.
//
using  namespace  std;
#ifndef INTERVIEWS_STACK_QUEEN_H
#define INTERVIEWS_STACK_QUEEN_H

bool validateStackSequences(vector<int>& pushed, vector<int>& popped);

//class MaxQueue {
//private:
//    queue<int> que;
//    deque<int> deq;
//public:
//    MaxQueue();
//
//    int max_value();
//
//    void push_back(int value);
//
//    int pop_front();
//};

class MaxQueue {
private:
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() {

    }

    int max_value() {
        return deq.empty() ? -1 : deq.front();
    }

    void push_back(int value) {
        que.push(value);
        while(!deq.empty() && deq.back() < value){
            deq.pop_back();
        }
        deq.push_back(value);
    }

    int pop_front() {
        if (que.empty()) return -1;
        int val = que.front();
        if (val == deq.front()){
            deq.pop_front();
        }
        que.pop();
        return val;
    }
};
#endif //INTERVIEWS_STACK_QUEEN_H
