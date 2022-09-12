//
//  HWLAddTwoNumByRecursion.cpp
//  leetCode-oc
//
//  Created by jipengfei on 2022/9/12.
//

#include "HWLAddTwoNumByRecursion.hpp"

ListNode* add(ListNode* l1, ListNode* l2, int carryBit);

ListNode* HWLAddTwoNumByRecursion::addTwoNumbers(ListNode *l1, ListNode *l2) {
    return add(l1, l2, 0);
}

ListNode* add(ListNode* l1, ListNode* l2, int carryBit) {
    if (NULL==l1 && NULL==l2 && 0==carryBit) {
        return NULL;
    }
    
    int val = carryBit;
    if (NULL!=l1) {
        val += l1->val;
        l1 = l1->next;
    }
    
    if (NULL!=l2) {
        val += l2->val;
        l2 = l2->next;
    }
    
    ListNode *node = new ListNode(val % 10);
    node->next = add(l1, l2, val/10);
    return node;
}

