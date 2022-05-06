//
//  HWLAddTwoNumbers.hpp
//  leetCode-oc
//
//  Created by jipengfei on 2022/5/5.
//

#ifndef HWLAddTwoNumbers_hpp
#define HWLAddTwoNumbers_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 */
class AddTwoNumbersSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};


#endif /* HWLAddTwoNumbers_hpp */
