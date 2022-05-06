//
//  HWLAddTwoNumbers.cpp
//  leetCode-oc
//
//  Created by jipengfei on 2022/5/5.
//

#include "HWLAddTwoNumbers.hpp"

ListNode* AddTwoNumbersSolution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = 1;
    int len2 = 1;
    
    ListNode *p = l1;
    ListNode *q = l2;
    
    while (NULL!=p->next) {
        len1++;
        p=p->next;
    }
    while (NULL!=q->next) {
        len2++;
        q=q->next;
    }
    
    if (len1>len2) {
        for (int i=1; i<=len1-len2; i++) {
            q->next = new ListNode(0);
            q=q->next;
        }
    } else {
        for (int i=1; i<=len2-len1; i++) {
            p->next = new ListNode(0);
            p=p->next;
        }
    }
    
    p = l1;
    q = l2;
    bool carryFlag = false;
    int tempSum = 0;
    ListNode *result = new ListNode(-1);
    ListNode *r = result;
    while (p!=NULL && q!=NULL) {
        tempSum = (carryFlag?1:0) + p->val + q->val;
        r->next = new ListNode(tempSum % 10);
        carryFlag = (tempSum > 10)?true:false;
        p = p->next;
        q = q->next;
        r = r->next;
    }
    
    if (carryFlag) {
        r->next = new ListNode(1);
        r = r->next;
        carryFlag = false;
    }
    
    return result->next;
}
