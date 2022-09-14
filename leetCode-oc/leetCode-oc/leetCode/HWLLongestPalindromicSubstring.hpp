//
//  HWLLongestPalindromicSubstring.hpp
//  leetCode-oc
//
//  Created by jipengfei on 2022/9/14.
//

#ifndef HWLLongestPalindromicSubstring_hpp
#define HWLLongestPalindromicSubstring_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace::std;

class LongestPalindromicSubstring {
public:
    
    //** 动态规划 */
    string longestPalindrome1(string s) {
        int n = (int)s.size();
        if (n < 2) {
            return s;
        }
        
        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }
                
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        // dp[i + 1][j - 1], 比dp[i][j]短, 所以之前已经循环并判定过其bool值
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                
                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    };
    
    //** 中心扩展法 */
    
    // 这里使用const string&修饰形参, 可以节约时间和空间的开销.(直接引用地址, 不需要拷贝一份s)(并且const保证了实参不会被修改)
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return {left+1, right-1};
    };
    
    string longestPalindrome2(string s) {
        int start = 0, end = 0;
        
        for (int i=0;i<s.size();i++) {
            pair<int, int> a = expandAroundCenter(s, i, i);
            pair<int, int> b = expandAroundCenter(s, i, i+1);

            if (a.second-a.first > end-start) {
                start = a.first;
                end = a.second;
            }
            if (b.second-b.first > end-start) {
                start = b.first;
                end = b.second;
            }
        }
        
        return s.substr(start, end-start+1);
    }
    
    //** Manacher */
    //** 当在位置 i 开始进行中心拓展时，我们可以先找到 i 关于 j 的对称点 2 * j - i。那么如果点 2 * j - i 的臂长等于 n，我们就可以知道，点 i 的臂长至少为 min(j + length - i, n)。那么我们就可以直接跳过 i 到 i + min(j + length - i, n) 这部分，从 i + min(j + length - i, n) + 1 开始拓展。 */
    
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        
        // 根据(2 * length + 1)、 字符串长度 = (right-1) - (left+1) + 1, 那么length = ((right-1) - (left+1) + 1 - 1)/2;
        return (right - left - 2) / 2; //(返回臂长)
    }
    
    string longestPalindrome(string s) {
        int start = 0, end = -1;
        
        string t = "#";
        for (char c: s) {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;
        
        vector<int> arm_len;
        int right = -1, j = -1;
        
        for (int i = 0; i < s.size(); ++i) {
            int cur_arm_len;
            if (right >= i) {
                int i_sym = j * 2 - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            } else {
                cur_arm_len = expand(s, i, i);
            }
            
            //** 每次for循环都记录每个i的臂长cur_arm_len */
            arm_len.push_back(cur_arm_len);
            
            if (i + cur_arm_len > right) {
                
                //** 记录右臂在最右侧的回文字符串的中心点 */
                j = i;
                
                //** 记录右臂在最右侧的回文字符串的最右侧边界点 */
                right = i + cur_arm_len;
                
                //** 注意: 后续的i一定在j的右侧, 所以right只需要保证在最右侧即可(即满足最大限度的避免重复计算) */
            }
            
            //** 记录当前最大回文子串起始位置 */
            if (cur_arm_len * 2 + 1 > end - start) {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }
        
        string ans;
        for (int i = start; i <= end; ++i) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }
        
        return ans;
    }

};
#endif /* HWLLongestPalindromicSubstring_hpp */
