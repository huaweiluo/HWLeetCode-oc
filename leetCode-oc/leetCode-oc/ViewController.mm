//
//  ViewController.m
//  leetCode-oc
//
//  Created by jipengfei on 2022/1/9.
//

#import "ViewController.h"
#import "lcSumOfTwoNumbers.h"
#import "lcPalindromeNumber.h"

#import "HWLAddTwoNumByRecursion.hpp"
#include "HWLAddTwoNumbers.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
#ifdef COMMENT_CODE
    int nums[] = {2, 7, 11, 13};
    int target = 18;
    int returnSize = 0;
    
    int *result = twoSumByHashTable(nums, ARRAY_SIZE(nums), target, &returnSize);
    if (result && returnSize>=2) {
        printf("result is:[%d, %d]\n", result[0], result[1]);
    }
    
    returnSize = 0;
    int target2 = 9;
    int *result2 = twoSum(nums, ARRAY_SIZE(nums), target2, &returnSize);
    if (result2 && returnSize>=2) {
        printf("result2 is:[%d, %d]\n", result2[0], result2[1]);
    }
    
    int x = 122232221;
    bool bRet = isPalindrome(x);
    printf("%d is %spalindrome number.", x, bRet?"":"not ");
    
    [self testAddTwoNumbers];
    
    [self testAddTwoNumbersByRecursion];
    
#endif
    
    [self testMaxLengthOfString];
}

- (void)testAddTwoNumbers {
    AddTwoNumbersSolution *solution = new AddTwoNumbersSolution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(1);
    
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(2);
    
    ListNode *result = solution->addTwoNumbers(l1, l2);
    ListNode *p = result;
    
    NSInteger r = 0;
    NSInteger i = 1;
    while (p!=NULL) {
        r += (p->val * 1*i);
        p = p->next;
        i = i*10;
    }
    
    NSLog(@"testAddTwoNumbers - r is:%ld", r);
}

- (void)testAddTwoNumbersByRecursion {
    HWLAddTwoNumByRecursion *solution = new HWLAddTwoNumByRecursion();
    
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(1);
    
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(3);
    
    ListNode *result = solution->addTwoNumbers(l1, l2);
    ListNode *p = result;
    
    NSInteger r = 0;
    NSInteger i = 1;
    while (p!=NULL) {
        r += (p->val * 1*i);
        p = p->next;
        i = i*10;
    }
    
    NSLog(@"testAddTwoNumbers - r is:%ld", r);
}

- (void)testMaxLengthOfString {
    HWLAddTwoNumByRecursion *solution = new HWLAddTwoNumByRecursion();
    int result = solution->lengthOfLongestSubstring("aabaab!bb");
    
    NSLog(@"testMaxLengthOfString - result:%d", result);
}

@end
