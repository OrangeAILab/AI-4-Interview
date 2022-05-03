//
// Created by Orange on 2022/4/22.
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using  namespace  std;


//剑指 Offer II 061. 和最小的 k 个数对 [堆/优先队列]
vector<vector<int>> kSmallestPairs_(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> res;
    int n = nums1.size();
    int m = nums2.size();
    bool flag = true;

    if (n > m){
        std::swap(nums1, nums2);
        std::swap(m, n);
        flag = false;
    }

    auto compare = [&] (const pair<int,int>& a, const pair<int,int>& b){
        return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> queue(compare);

    //输出构造长度为K的小顶堆
    for(int i = 0; i < min(n, k); ++i){
        queue.push({i, 0});
    }

    while(res.size() < k && queue.size()){
        //pair<int,int> heap_top = queue.top();
        auto [a, b] = queue.top();
        queue.pop();

        flag ? res.push_back({nums1[a], nums2[b]}): res.push_back({nums2[b], nums1[a]});

        if (b + 1 < m){
            queue.push({a, b + 1});
        }

    }
    return res;
}


//264. 丑数 II    [堆/优先队列]   T = nlogn
int nthUglyNumber_(int n) {
    vector<int> ugly_factors{2, 3, 5};
    long heap_top;
    priority_queue<long, vector<long>, greater<long>> queue;
    set<long> set;

    queue.push(1L);
    set.insert(1L);

    for(int i = 1; i <= n; ++i){

        if(n == 1) return 1;

        //堆顶元素
        heap_top = queue.top();
        queue.pop();
        for(auto& ugly_factor: ugly_factors){
            long num = ugly_factor * heap_top;
            if(set.find(num) == set.end()){
                queue.push(num);
                set.insert(num);
            }
        }
    }

    return heap_top;

}


//剑指 Offer II 060. 出现频率最高的 k 个数字  [堆/优先队列]  T=nlogk
struct compare{
    bool operator()(pair<int, int> p, pair<int, int> q){
        return p.second > q.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {

    //1.遍历数组，使用字典统计词频 T = O(N)
    unordered_map<int, int> map;
    for(auto& num : nums){
        map[num] ++;
    }

    //存入长度为K的小顶堆进行排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
    for(auto& key_value : map){
        que.push(key_value);
        if(que.size() > k){
            que.pop();
        }
    }

    //输出
    vector<int> res;
    while(!que.empty()){
        res.push_back(que.top().first);
        que.pop();
    }

    return res;
}


//剑指 Offer II 057. 值和下标之差都在给定的范围内





//剑指 Offer II 038. 每日温度 [单调栈]
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);

    stack<int> stack;

    for(int i = 0; i < n; ++i){
        while(!stack.empty() && temperatures[i] > temperatures[stack.top()]){
            int pre_index = stack.top();
            res[pre_index] = i - pre_index;
            stack.pop();
        }
        stack.push(i);
    }

    return res;
}


//剑指 Offer II 037. 小行星碰撞 [栈模拟]
vector<int> asteroidCollision(vector<int>& asteroids) {

    stack<int> stack;
    stack.push(INT_MIN);//先存一个最小的负数，默认正数的正方向，负数为负方向。

    for(auto num : asteroids){
        if (num >= 0) {
            stack.push(num);
        }else{
            //栈中始终存在最小的负数，因此不需要判断栈空
            while(stack.top() > 0 && stack.top() < -num){
                stack.pop();
            }
            if (stack.top() < 0){
                stack.push(num);
            }
            if (stack.top() == -num){
                stack.pop();
                continue;
            }
            if (stack.top() > - num){
                continue;
            }
        }
    }

    int res_size = stack.size() - 1;
    vector<int> res(res_size, 0);

    for(int i = res_size - 1; i > 0; --i){
        res[i] = stack.top();
        stack.pop();
    }

    return res;
}


//剑指 Offer II 036. 后缀表达式 [栈 + 逆波兰序列]
bool is_number(string& token){
    return !(token == "+" || token == "-" || token == "*" || token == "/");
}

int evalRPN(vector<string>& tokens) {
    //tokens已经是一个逆波兰序列

    int n = tokens.size();
    stack<int> express_stack;

    for(int i = 0; i < n; ++i){
        if (is_number(tokens[i])){
            //convert into integer
            express_stack.push(atoi(tokens[i].c_str()));
        }else{
            int num1 = express_stack.top(); express_stack.pop();
            int num2 = express_stack.top(); express_stack.pop();
            //expression
            switch (tokens[i][0]) {
                case '+' :
                    express_stack.push(num2 + num1);
                    break;
                case '-' :
                    express_stack.push(num2 - num1);
                    break;
                case '*' :
                    express_stack.push(num2 * num1);
                    break;
                case '/' :
                    express_stack.push(num2 / num1);
                    break;
            }
        }
    }

    return express_stack.top();

}


//剑指 Offer II 035. 最小时间差
int parse_time(string& timeString){
    return  ((timeString[0] - '0') * 10 + (timeString[1] - '0')) * 60 + ((timeString[3] - '0') * 10) + (timeString[4] - '0');
}

int findMinDifference(vector<string>& timePoints) {
    int ans = INT_MAX;
    int n = timePoints.size();
    if ( n > (24 * 60)) return 0;//必有重复

    sort(timePoints.begin(), timePoints.end());

    int pre_minutes = parse_time(timePoints[0]);

    for(int i = 1; i < n; ++i){
        int cur_minutes = parse_time(timePoints[i]);
        ans = min(ans, cur_minutes - pre_minutes);
        pre_minutes = cur_minutes;
    }

    ans = min(ans, parse_time(timePoints[0]) + 24 * 60 - pre_minutes);
    return ans;
}


//剑指 Offer II 030. 插入、删除和随机访问都是 O(1) 的容器 [变长数组 + 哈希表]
class RandomizedSet {

private:
    unordered_map<int,int> map;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned) time_t(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val)) return false;

        nums.push_back(val);
        map[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!map.count(val)) return false;

        int tail = nums.back();
        int index = map[val];
        nums[index] = tail;
        nums.pop_back();
        map[tail] = index;
        map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int rand_index = rand() % nums.size();
        return nums[rand_index];
    }
};


//剑指 Offer II 011. 0 和 1 个数相同的子数组 [前缀和]
int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> map;
    vector<int> pre_sum(n+1, 0);
    int res = 0;

    for(int i = 1; i <= n; ++i){
        pre_sum[i] = pre_sum[i - 1] + (nums[i - 1] == 0 ? -1 : 1);
    }

    for(int i = 0; i <= n; ++i){
        if (map.count(pre_sum[i])){
            res = max(res, i - map[pre_sum[i]]);
        }

        if (!map.count(pre_sum[i])){
            map[pre_sum[i]] = i;
        }
    }
    return res;

}


//剑指 Offer II 010. 和为 k 的子数组  [前缀和]
int subarraySum(vector<int>& nums, int k) {
    int pre_sum = 0;
    int count = 0;
    unordered_map<int, int> map;
    map[0] = 1;

    for(auto& num : nums){
        pre_sum += num;
        if (map.find(pre_sum - k) != map.end()){
            count += map[pre_sum - k];
        }

        ++map[pre_sum];
    }
    return count;

}



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


