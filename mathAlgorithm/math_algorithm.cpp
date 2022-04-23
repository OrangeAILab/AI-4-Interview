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


//剑指 Offer 64. 求1+2+…+n
int res_ = 0;
int sumNums(int n) {
    /*
     * 剑指 Offer 64. 求1+2+…+n
     */
    bool  x = (n > 1 && sumNums(n-1) > 0);
    res_ += n;
    return res_;
}


//剑指 Offer 16. 数值的整数次方
double myPow(double x, int n){
    /*
     * 剑指 Offer 16. 数值的整数次方
     */
    if (x == 0) return 0;
    double res = 1.0;
    long n_ = n;
    //convert
    if(n_ < 0){
        x = 1 / x;
        n_ = -1 * n_;
    }

    while(n_ > 0){
        if((n_ & 1) == 1) res *= x;
        x *= x;
        n_ = n_ >> 1;
    }
    return res;
}