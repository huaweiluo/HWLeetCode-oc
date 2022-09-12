//
//  HWLSomeDefines.h
//  leetCode-oc
//
//  Created by jipengfei on 2022/9/12.
//

#ifndef HWLSomeDefines_h
#define HWLSomeDefines_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct IntValNode {
    int val;
    int index;
    IntValNode(int x, int y) : val(x), index(y) {}
};

#endif /* HWLSomeDefines_h */
