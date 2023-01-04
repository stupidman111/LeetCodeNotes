//
// Created by 24563 on 2023/1/3.
//
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool areNumbersAscending(string s) {
        int now = 0;
        int old = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] > '0' && s[i] <= '9') {//取最高位
                now = s[i] - '0';//
                for (int j = i + 1; j < s.size(); j++) {//当前token可能不止一位数字，往后遍历的同时i++
                    if (s[j] >= '0' && s[j] <= '9') {//当前token不止一位数，每次x10将其扩展开来
                        now = now * 10 + (s[j] - '0');
                        i++;
                    } else {
                        break;
                    }
                }
                if (now > old) {
                    old = now;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};