//
// Created by Orange on 2022/4/13.
//
using  namespace  std;
#ifndef INTERVIEWS_DP_H
#define INTERVIEWS_DP_H

int maxProfit(vector<int>& prices);
vector<double> dicesProbability(int n);
int nthUglyNumber(int n);
int maxValue(vector<vector<int>>& grid);
int translateNum(int num);
int maxSubArray(vector<int>& nums);
int cuttingRope(int n);
int dfs_movingCount(int i, int j, int si, int sj, vector<vector<bool>>& visited, int m, int n, int k);
int movingCount(int m, int n, int k);
int fib(int n);
int numWays(int n);
int lengthOfLongestSubstring(string s);
#endif //INTERVIEWS_DP_H
