//
// Created by Orange on 2022/4/13.
//
/*
 * In this section, we will write the most useful and basic algorithms with cpp,such as
 * sort, find
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>

#include "basic/basic_algorithm.h"
#include "dynamicProgramming/dp.h"
#include "backTracing/back_tracing.h"
#include "linkList/link_list.h"
#include "stackQueen/stack_queen.h"

using namespace std;


int main(){
//    vector<int> pushed = {1, 2, 3, 4, 5};
//    vector<int> popped = {4, 5 ,1 ,2 ,3};
//    std::cout << validateStackSequences(pushed, popped) << endl;

//    double  x = 2.00000;
//    int n = 10;
//    std::cout<< "pow(x,n)="<<myPow(x,n)<<endl;


    MaxQueue* obj1 = new MaxQueue();
    obj1->push_back(6);
    cout<< "obj1 max_value: " << obj1->max_value() << " front_value:"<< obj1->pop_front() << endl;
    MaxQueue obj2;
    obj2.push_back(8);
    cout<< "obj2 max_value: " << obj2.max_value() << " front_value:"<< obj2.pop_front() << endl;


//    vector<int> array = {49 , 38, 65, 97, 76, 12, 27, 50};
//    quick_sort(array,0, array.size() - 1);
//    for(int i = 0; i < array.size(); ++i){
//        cout << array[i] << ' ';
//    }
//    cout<< endl;


    return 0;
}


}