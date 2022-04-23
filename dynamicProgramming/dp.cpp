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

//接雨水
int trap(vector<int>& height){
    int n = height.size();
    vector<int> leftmax(n);
    vector<int> rightmax(n);

    leftmax[0] = height[0];
    for(int i = 1; i < n; ++i){
        leftmax[i] = max(leftmax[i - 1], height[i]);
    }

    rightmax[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 0; --i){
        rightmax[i] = max(rightmax[i + 1], height[i]);
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        res += min(leftmax[i], rightmax[i]) - height[i];
    }

    return res;
}



//剑指 Offer II 085. 生成匹配的括号
void back_tracing_generateParenthesis(vector<string>& res, string& cur, int left, int right,int n){

    //when back
    if (cur.size() == n * 2){
        res.push_back(cur);
        return;
    }

    //when trace
    if (left < n){
        cur.push_back('(');
        back_tracing_generateParenthesis(res, cur, left + 1, right, n);
        cur.pop_back();
    }

    if (right < left){
        cur.push_back(')');
        back_tracing_generateParenthesis(res, cur, left, right + 1, n);
        cur.pop_back();
    }

}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    back_tracing_generateParenthesis(res, cur, 0, 0, n);
    return res;

}


//剑指 Offer II 020. 回文子字符串的个数
int countSubstrings(string s){
    int n = s.size();
    vector<vector<bool>> dp_matrix(n, vector<bool>(n, true));

    for(int i = n - 1; i >= 0; --i){
        for(int j = i + 1; j < n; ++j){
            dp_matrix[i][j] = (s[i] == s[j]) && dp_matrix[i + 1][j - 1];
        }
    }
    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if (dp_matrix[i][j]){
                ++count;
            }
        }
    }
    return count;
}


//剑指 Offer 63. 股票的最大利润
int maxProfit(vector<int>& prices){
    //edge
    int n = prices.size();
    if (n < 2) return 0;
    //init dp
    vector<int> dp(n, 0);
    dp[0] = 0;
    int low_price = prices[0];
    //dp
    for(int i = 1; i < n; ++i){
        dp[i] = max(dp[i - 1], prices[i] - low_price);
        low_price = min(low_price, prices[i]);
    }
    return dp[n - 1];
}


//剑指 Offer 60. n个骰子的点数
vector<double> dicesProbability(int n){
    vector<vector<int>> dp(20, vector<int>(100, 0));
    //init first row
    for(int j = 1; j <= 6; ++j){
        dp[1][j] = 1;
    }

    for(int i = 2; i <= n; ++i){
        for(int j = i; j <= i * 6; ++j){
            for(int k = 1; k <= 6; ++k){
                if (j - k <= 0) break;//**
                dp[i][j] += dp[i- 1][j- k];
            }
        }
    }

    double sum = pow(6, n);
    vector<double> res;
    for(int j = n; j <= n*6; ++j){
        res.push_back(dp[n][j] * 1.0 / sum);
    }
    return res;
}


//剑指 Offer 49. 丑数
int nthUglyNumber(int n){
    vector<int> dp(n, 0);
    dp[0] = 1;
    int a = 0, b = 0 , c = 0;
    for(int i = 1; i < n; ++i){
        int num_a = dp[a] * 2;
        int num_b = dp[b] * 3;
        int num_c = dp[c] * 5;
        dp[i] =  min(min(num_a, num_b), num_c);
        if(dp[i] == num_a) ++a;
        if(dp[i] == num_b) ++b;
        if(dp[i] == num_c) ++c;
    }
    return dp[n - 1];
}


//剑指 Offer 47. 礼物的最大价值 动态规划 DP
int maxValue(vector<vector<int>>& grid){
    int row = grid.size();
    int col = grid[0].size();

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if (i == 0 && j == 0) {
                continue;//no reward;
            }else if (i == 0){
                grid[i][j] += grid[i][j - 1];
            }else if (j == 0){
                grid[i][j] += grid[i - 1][j];
            }else{
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
    }
    return grid[row - 1][col - 1];
}


//剑指 Offer 46. 把数字翻译成字符串 动态规划 DP
int translateNum(int num){
    string str = to_string(num);
    int n = str.size();
    vector<int> dp(n + 1, 0);
    //init dp
    dp[0] = 1;//infer
    dp[1] = 1;
    for(int i = 2; i <= n ; ++i){
        string sub_str = str.substr(i - 2, 2);
        if (sub_str >= "10" && sub_str <="25"){
            dp[i] = dp[i - 1] + dp[i - 2];
        }else{
            dp[i] = dp[i - 1];
        }
    }
    return dp[n];
}


//剑指 Offer 42. 连续子数组的最大和 动态规划 DP
int maxSubArray(vector<int>& nums){
    //edge
    if (nums.size() == 0) return 0;
    int max_sum = nums[0];

    for(int i = 1; i < nums.size(); ++i){
        nums[i] += max(nums[i - 1], 0);
        max_sum = max(max_sum, nums[i]);
    }
    return max_sum;
}


//剑指 Offer 14- I. 剪绳子 动态规划 DP
int cuttingRope(int n){
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for(int i = 3; i <=n; ++i){
        for(int j = 1; j < i; ++j){
            dp[i] = max(dp[i], max((j * (i - j)), (j * (dp[i - j]))));
        }
    }
    return dp[n];
}


//剑指 Offer 13. 机器人的运动范围 回溯
int dfs_movingCount(int i, int j, int si, int sj, vector<vector<bool>>& visited, int m, int n, int k){
    //dfs traceback edge
    if(i >= m || j >= n || visited[i][j] == true || (si + sj) > k) return 0;
    visited[i][j] = true;

    return 1 + dfs_movingCount(i + 1, j, (i + 1) % 10 == 0 ? si - 8 : si + 1, sj, visited, m, n, k) +
           dfs_movingCount(i, j + 1,si, (j + 1) % 10 == 0 ? sj -8 : sj + 1, visited, m, n ,k);

}

int movingCount(int m, int n, int k){
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    return dfs_movingCount(0, 0, 0, 0, visited, m, n, k);
}


//剑指 Offer 10- I. 斐波那契数列 动态规划 DP
int fib(int n){
    vector<int> dp(n + 1, 0);
    if (n == 0 || n == 1) return n;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    return dp[n];
}


//剑指 Offer 10- II. 青蛙跳台阶问题 动态规划 DP
int numWays(int n){
    //edge
    if (n ==0 || n == 1) return  1;
    //init
    vector<int> dp(n + 1, 1);

    for(int i = 2; i <= n; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    return dp[n];
}


//剑指 Offer 48. 最长不含重复字符的子字符串 动态规划 DP
int lengthOfLongestSubstring(string s){
    if (s.size() == 0) return 0;

    unordered_map<char, int> map;
    int res = 0;
    int temp = 0;
    // vector<int> dp(s.size(), 0);

    for(int j = 0; j < s.size(); ++j){
        int i = map[s[j]];
        map[s[j]] = j;
        temp = temp < j - i ? temp + 1 : j - i;

        res = max(res, temp);
    }
    return res;
}
