//
// Created by 24563 on 2023/1/4.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l_Count = index, r_Count = n - 1 - index;//index左侧元素个数：l_Count，index右侧元素个数：r_Count
        long l = 1, r = maxSum;//nums[index]的值应在[l, r] : [1, maxSum]中取到

        while (l <= r) {
            long mid = (l + r) / 2;
            long sum = mid + getSum(mid, l_Count) + getSum(mid, r_Count);
            if (sum > maxSum) r = --mid;
            else l = ++mid;//sum <= maxSum
        }
        return l - 1;
    }

private:
    long getSum(int max, int count) {
        if (max > count) {//山峰高度max大于该侧元素个数count-->sum = (m-1) + (m-2) + ...... + (m - count) = (2m - 1 - count) * count / 2;
            return (long) (2 * max - 1 - count) * count / 2;
        } else {//山峰高度max小于该测元素个数count--> sum = (m - 1) + (m - 2) + ... + (m - m) +  (count - m - 1)
            return (long)(max - 3) * max / 2 + count + 1;
        }
    }
};


