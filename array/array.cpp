//
// Created by heyue on 2022/4/22.
//

#include <vector>
#include <unordered_map>
#include <algorithm>

using  namespace  std;


//剑指 Offer II 009. 乘积小于 K 的子数组 [滑动窗口]
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    //edge
    if (k <= 1 ) return 0;

    int res = 0;
    int product = 1;
    int n = nums.size();
    //init slide window
    int start = 0;
    int end = 0;

    while(end < n){
        product *= nums[end];

        while(product >= k){
                product /= nums[start];
                ++start;
        }

        res += (end - start + 1);
        ++end;
    }

    return res;

}


//剑指 Offer II 008. 和大于等于 target 的最短子数组 [滑动窗口]
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int res = INT_MAX;
    int sum = 0;
    int start = 0;
    int end = 0;

    while(end < n){
        sum += nums[end];
        while(sum >= target){
            res = min(res, end - start + 1);
            sum -= nums[start];
            ++start;
        }
        ++end;
    }

    return res == INT_MAX ? 0 : res;

}


//剑指 Offer II 007. 数组中和为 0 的三个数  [双指针] T=O(N^2) S=O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    std::sort(nums.begin(), nums.end());

    for(int k = 0; k < n - 2; ++k){
        if (nums[k] > 0) break;
        if (k > 0 && nums[k] == nums[k - 1]) continue;

        int i = k + 1;
        int j = n - 1;

        while(i < j){
            int  sum = nums[k] + nums[i] + nums[j];
            if (sum < 0){
                while(i < j && nums[i] == nums[++i]);
            }else if(sum > 0){
                while(i < j && nums[j] == nums[--j]);
            }else{
                res.push_back({nums[k], nums[i], nums[j]});
                while(i < j && nums[i] == nums[++i]);
                while(i < j && nums[j] == nums[--j]);
            }
        }
    }

    return res;
}


//剑指 Offer II 004. 只出现一次的数字
int singleNumber(vector<int>& nums) {
    //T = O(n), S = O(n)
    unordered_map<int, int> map;

    for(auto num : nums){
        ++map[num];
    }

    int res = 0;
    for(int i = 0; i < nums.size(); ++i){
        if (map[nums[i]] == 1) {
            res = nums[i];
            break;
        }else{
            continue;
        }
    }

    return res;
}


