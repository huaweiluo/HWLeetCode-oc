//
//  lcSumOfTwoNumbers.h
//  leetCode-oc
//
//  Created by jipengfei on 2022/1/9.
//

#ifndef lcSumOfTwoNumbers_h
#define lcSumOfTwoNumbers_h

#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))

int *twoSumByHashTable(int *nums, int numsSize, int target, int* returnSize);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

#endif /* lcSumOfTwoNumbers_h */
