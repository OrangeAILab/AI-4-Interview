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

//二分查找
int binary_search(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (high - low ) / 2 + low;
        int mid_num = nums[mid];
        if ( target == mid_num){
            return mid;
        }else if(target < mid_num){
            high = mid - 1;
        }else if(target > mid_num){
            low = mid + 1;
        }
    }
    return -1;
}


//快速排序
void quick_sort(vector<int>& array, int start, int end){
    /*
     * 49 , 38, 65, 97, 76, 12, 27, 50
     *
     */
    if ( start < end){
        int i = start;
        int j = end;
        int temp = array[i];

        while(i < j){
            while(i < j && array[j] > temp){
                --j;
            }
            array[i] = array[j];
            while(i < j && array[i] <= temp){
                ++i;
            }
            array[j] = array[i];
        }
        //a quick sort has done!
        array[i] = temp;
        //sub
        quick_sort(array, start, i - 1);
        quick_sort(array, i + 1, end);

    }else{
        return;
    }
}


