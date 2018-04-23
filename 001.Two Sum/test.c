#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "solution.h"

int main(){
    int nums[] = {1,3,5};
    int target[] = {0, 2};
    int *p = twoSum(nums, 3, 6);
    int len = sizeof(nums)/sizeof(int);
    printf("len: %d\n", len);
    int i;
    for(i=0; i < len; i++){
    	printf("target: %d, result: %d\n", target[i], p[i]);
        assert(target[i] == p[i]);
    }
}
