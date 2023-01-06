//
// Created by 24563 on 2023/1/6.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = num; i > 0; i--) {
            if (getEachOfBitSum(i) % 2 == 0) {
                res++;
            }
        }
        return res;
    }

    int getEachOfBitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};