//
//  ViewController.m
//  leetCode-oc
//
//  Created by jipengfei on 2022/1/9.
//

#import "ViewController.h"
#import "lcSumOfTwoNumbers.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
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
}

@end
