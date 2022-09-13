//
//  HWLMedianFinding.hpp
//  leetCode-oc
//
//  Created by jipengfei on 2022/9/13.
//

#ifndef HWLMedianFinding_hpp
#define HWLMedianFinding_hpp

#include <stdio.h>
#include <vector>

using namespace::std;

class HWLMedianFinding {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, unsigned long k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        unsigned long m = nums1.size();
        unsigned long n = nums2.size();
        unsigned long index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            unsigned long newIndex1 = min(index1 + k / 2 - 1, m - 1);
            unsigned long newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned long totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
    
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays2(nums2, nums1);
        }
        
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int left = 0, right = m;
        double median1 = 0, median2 = 0;
        
        while (left <= right) {
            int i = (left+right)/2;
            int j = (m+n+1)/2 - i;
            
            int nums_im1 = (0==i) ? INT_MIN : nums1[i-1];
            int nums_i = (m==i) ? INT_MAX : nums1[i];
            int nums_jm1 = (0==j) ? INT_MIN : nums2[j-1];
            int nums_j = (n==j) ? INT_MAX : nums2[j];
            
            if (nums_im1 <= nums_j) {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i+1;
            } else {
                right = i-1;
            }
        }
        
        return (0 == (m+n) % 2 ? (median1+median2)/2: median1);
    }
};

#endif /* HWLMedianFinding_hpp */
