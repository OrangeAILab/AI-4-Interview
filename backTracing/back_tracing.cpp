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


//剑指 Offer II 084. 含有重复元素集合的全排列
vector<vector<int>> res6;
vector<int> path6;
vector<bool> visited6;

void backtracing_permuteUique(vector<int>nums, int n){
    //when back
    if (path6.size() == n){
        res6.push_back(path6);
        return;
    }

    //when trace
    for (int i = 0; i < n; ++i){
        if (!visited6[i]){
            //cut branches
            if (i > 0 && nums[i] == nums[i - 1] && !visited6[i - 1]){
                continue;
            }
            visited6[i] = true;
            path6.push_back(nums[i]);
            backtracing_permuteUique(nums, n);
            path6.pop_back();
            visited6[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    res6.clear();
    path6.clear();
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    visited6.resize(n, false);
    backtracing_permuteUique(nums, n);
    return res6;
}

//剑指 Offer II 083. 没有重复元素集合的全排列
vector<vector<int>> res5;
vector<int> path5;
vector<bool> visited;

void backtracing_permute(vector<int>& nums, int n){
    //when back
    if (path5.size() == n){
        res5.push_back(path5);
        return;
    }

    //when trace
    for(int i = 0; i < n; ++i){
        if (!visited[i]){
            visited[i] = true;
            path5.push_back(nums[i]);
            backtracing_permute(nums, n);
            path5.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    visited.resize(n, false);
    res5.clear();
    path5.clear();
    backtracing_permute(nums, n);
    return res5;
}


//剑指 Offer II 082. 含有重复元素集合的组合 回溯
vector<vector<int>> res4;
vector<int> path4;

void backtracing_combinationSum2(int startIndex, vector<int>& candidates, int target){
    //when back
    if (target < 0){
        return;
    }

    if (target == 0){
        res4.push_back(path4);
        return;
    }

    //when trace
    for(int i = startIndex; i < candidates.size(); ++i){
        if (candidates[i] <= target){
            //cut branches
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path4.push_back(candidates[i]);
            backtracing_combinationSum2(i + 1, candidates, target - candidates[i]);
            path4.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    res4.clear();
    path4.clear();
    std::sort(candidates.begin(), candidates.end());
    backtracing_combinationSum2(0, candidates, target);
    return res4;
}


//剑指 Offer II 081. 允许重复选择元素的组合 回溯
vector<vector<int>> res3;
vector<int> path3;

void backtracing_combinationSum(int startIndex, vector<int>& candidates, int target){
    //when back
    if (target < 0){
        return;
    }

    if(target == 0){
        res3.push_back(path3);
        return;
    }

    //when trace
    for(int i = startIndex; i < candidates.size(); ++i){
        if (candidates[i] <= target){
            //剪枝
            path3.push_back(candidates[i]);
            backtracing_combinationSum(i, candidates, target - candidates[i]);
            path3.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    res3.clear();
    path3.clear();
    backtracing_combinationSum(0, candidates, target);
    return res3;
}


//剑指 Offer II 079. 所有子集 回溯 子集
vector<vector<int>> res2;
vector<int> path2;

void backtracing_subsets(int startIndex, vector<int>& nums){
    res2.push_back(path2);

    if (startIndex == nums.size()){
        return;
    }

    for(int i = startIndex; i < nums.size(); ++i){
        path2.push_back(nums[i]);
        backtracing_subsets(i + 1, nums);
        path2.pop_back();
    }

}

vector<vector<int>> subsets(vector<int>& nums){
    res2.clear();
    path2.clear();
    backtracing_subsets(0, nums);
    return res2;
}


//剑指 Offer II 080. 含有 k 个元素的组合  数组回溯 method 1
vector<vector<int>> res1;
vector<int> path1;

void backtracing(int startIndex, int n, int k){
    if (path1.size() == k){
        res1.push_back(path1);
        return;
    }

    for(int i = startIndex; i <= n; ++i){
        path1.push_back(i);
        backtracing(i + 1, n, k);
        path1.pop_back();
    }
}

//剑指 Offer II 080. 含有 k 个元素的组合  数组回溯 method 2
vector<vector<int>> res;
vector<int> temp;

void back_trace(int cur, int n, int k){
    //cut tree branch
    //if (temp.size() + (n - cur + 1) < k) return;
    //edge
    if (temp.size() == k){
        res.push_back(temp);
        return;
    }
    //backtrack
    //check this node
    temp.push_back(cur);
    back_trace(cur + 1, n , k);
    temp.pop_back();
    //back_trace(cur + 1, n, k);
}

vector<vector<int>> combine(int n, int k){
    back_trace(1, n, k);
    return res;
}

