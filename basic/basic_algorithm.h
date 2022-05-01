//
// Created by heyue on 2022/4/13.
//
using  namespace  std;
#ifndef INTERVIEWS_BASIC_ALGORITHM_H
#define INTERVIEWS_BASIC_ALGORITHM_H

void quick_sort(vector<int>& array, int start, int end);
int binary_search(vector<int>& nums, int target);

void heap_adjust(vector<int>& nums, int len, int index);
void heap_sort(vector<int>& nums);


#endif //INTERVIEWS_BASIC_ALGORITHM_H
