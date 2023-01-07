//
// Created by 24563 on 2023/1/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();//数组总长度
        int sum = accumulate(nums.begin(), nums.end(), 0);//数组元素总和

        if (sum < x) {//剪枝
            return -1;
        }

        /**
         * 由于可以对nums最左端、最右端进行操作--因此可以称数组左端被移除的部分为前缀，数组右端被移除的部分为后缀
         * left指向前缀的最右端，right指向后缀的最左端
         * 初始时，前缀为空，后缀为整个数组，因此left = -1，right = 0
         */
        int left = -1, right = 0;
        int l_sum = 0, r_sum = sum;

        /**
         * 记录最小操作数，实际为 前缀长度 + 后缀长度，初始时为n+1
         * 设置为n+1的另一点是在最后一条语句return时，有一个对比
         */
        int res = n + 1;

        for (; left < n; ++left) {
            if (left != -1) {
                l_sum += nums[left];
            }
            while (right < n && l_sum + r_sum > x) {
                r_sum -= nums[right];
                ++right;
            }
            if (l_sum + r_sum == x) {
                res = min(res, (left + 1) + (n - right));
            }
        }

        return res > n ? -1 : res;
    };
};
