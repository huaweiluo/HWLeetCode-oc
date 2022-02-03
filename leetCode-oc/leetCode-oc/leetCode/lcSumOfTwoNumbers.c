//
//  lcSumOfTwoNumbers.c
//  leetCode-oc
//
//  Created by jipengfei on 2022/1/9.
//

#include "lcSumOfTwoNumbers.h"
#include "uthash.h"

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable *hashtable;
struct hashTable* find(int ikey) {
    struct hashTable* tmp = NULL;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (NULL == it) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey;
        tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        it->val = ival;
    }
}

/*
 复杂度分析

 时间复杂度：O(N)，其中 N 是数组中的元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x。
 空间复杂度：O(N)，其中 N 是数组中的元素数量。主要为哈希表的开销。
 */
int *twoSumByHashTable(int *nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i=0; i<numsSize; ++i) {
        struct hashTable* it = find(target-nums[i]);
        if (NULL != it) {
            int* ret = malloc(sizeof(int)*2);
            ret[0] = it->val;
            ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    
    *returnSize = 0;
    return NULL;
}

/*
 复杂度分析

 时间复杂度：O(N²)，其中 N 是数组中的元素数量。最坏情况下数组中任意两个数都要被匹配一次。
 空间复杂度：O(1)。
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
