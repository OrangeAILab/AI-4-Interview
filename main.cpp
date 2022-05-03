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
#include "array/array.h"
using namespace std;


int main(){
//    vector<int> pushed = {1, 2, 3, 4, 5};
//    vector<int> popped = {4, 5 ,1 ,2 ,3};
//    std::cout << validateStackSequences(pushed, popped) << endl;

//    double  x = 2.00000;
//    int n = 10;
//    std::cout<< "pow(x,n)="<<myPow(x,n)<<endl;


//    MaxQueue* obj1 = new MaxQueue();
//    obj1->push_back(6);
//    cout<< "obj1 max_value: " << obj1->max_value() << " front_value:"<< obj1->pop_front() << endl;
//    MaxQueue obj2;
//    obj2.push_back(8);
//    cout<< "obj2 max_value: " << obj2.max_value() << " front_value:"<< obj2.pop_front() << endl;


//    vector<int> array = {49 , 38, 65, 97, 76, 12, 27, 50};
//    quick_sort(array,0, array.size() - 1);
//    for(int i = 0; i < array.size(); ++i){
//        cout << array[i] << ' ';
//    }
//    cout<< endl;


//    vector<int> nums = {8, 1, 14, 3, 21, 5, 7, 10};
//    heap_sort(nums);
//    std::cout<<"heap sort:"<<endl;
//    for(auto& num : nums){
//        std::cout<<num<<' ';
//    }
//    std::cout<<endl;
//
//    std::cout<<"bucket sort:"<<endl;
//    bucket_sort(nums);
//    for(int i=0;i<nums.size();i++)
//    {
//        cout<<nums[i]<<' ';
//    }

//    int n = 10;
//    cout<<"ugly number:"<<nthUglyNumber(10);

//    vector<int> nums1 = {1,2};
//    vector<int> nums2 = {3};
//    int k = 3;
//    vector<vector<int>> res;
//    res =  kSmallestPairs(nums1,  nums2, k);
//
//    for(int i = 0; i < res.size(); ++i){
//        for(auto& num : res[i]){
//            std::cout<<num<<' ';
//        }
//        std::cout<<endl;
//    }

//    * Trie* obj = new Trie();
//    * obj->insert(word);
//    * bool param_2 = obj->search(word);
//    * bool param_3 = obj->startsWith(prefix);

//    Trie* trie = new Trie();//在堆中实例化对象
//
//    trie->insert("apple");
//    std::cout<<trie->search("apple")<<endl;   // 返回 True
//    std::cout<<trie->search("app")<<endl;     // 返回 False
//    std::cout<< trie->startsWith("app")<<endl; // 返回 True
//    trie->insert("app");
//    std::cout<<trie->search("app")<<endl;     // 返回 True

    //Trie2* trie = new Trie2();

    //std::cout<<"encoding length:"<<trie->insert("time");
    vector<string> words{"time","me","bell"};
    std::cout<<"Tire encoding :" <<minimumLengthEncoding(words);
    return 0;

}


