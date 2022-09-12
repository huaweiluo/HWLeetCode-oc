//
//  HWLAddTwoNumByRecursion.hpp
//  leetCode-oc
//
//  Created by jipengfei on 2022/9/12.
//

#ifndef HWLAddTwoNumByRecursion_hpp
#define HWLAddTwoNumByRecursion_hpp

#include <stdio.h>
#include "HWLSomeDefines.h"
#include <string>
#include <unordered_map>
#include <iostream>

using namespace::std;

class HWLAddTwoNumByRecursion {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
    
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_map<char, int> occ;
        unsigned long n = s.size();
        
        // 最终结果记录
        int rt = 0;
        
        // 最长子串起点index
        int rs = -1;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int>::iterator itFind = occ.find(s[i]);
            char charKey = s[i];
            
            if (occ.end() != itFind && itFind->second>rs) {
                rs = itFind->second;
                
                // 同一value, 更新index
                occ.erase(charKey);
                occ.insert(pair<char, int>(charKey, i));
            } else {
                rt = max(rt, i-rs);
                
                if (occ.end() != itFind) {
                    // 存在相同value, 先erase再insert(因为无法覆盖)
                    occ.erase(charKey);
                }
                occ.insert(pair<char, int>(charKey, i));
            }
        }
        
        return rt;
    }
    
//    int lengthOfLongestSubstring(string s) {
//        // 哈希集合，记录每个字符是否出现过
//        unordered_map<char, int> occ;
//        unsigned long n = s.size();
//
//        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
//        int rk = -1, ans = 0;
//
//        // 枚举左指针的位置，初始值隐性地表示为 -1
//        int rs = -1;
//
//        for (int i = 0; i < n; ++i) {
//
//            while (rk + 1 < n && occ.find(s[rk + 1])==occ.end()) {
//                // 不断地移动右指针
//                occ.insert(pair<char, int>(s[rk + 1], rk+1));
//
//                unordered_map<char, int>::iterator it = occ.find(s[rk + 1]);
//                cout << "index:" << it->first << "\nvalue:" << it->second << endl;
//
//                ++rk;
//            }
//
//            // 第 i 到 rk 个字符是一个极长的无重复字符子串
//            ans = max(ans, rk - i + 1);
//
//            // 跳跃到重复字符后一位
//            if (rk+1 < n) {
//                i = occ.find(s[rk + 1])->second;
//            }
//
//            // 删除重复字符以及前面的所有字符
//            for (int d=i;d>rs;d--) {
//                occ.erase(s[d]);
//            }
//
//            // 更新存储记录起点位置
//            rs = i;
//        }
//        return ans;
//    }
    
};

#endif /* HWLAddTwoNumByRecursion_hpp */
