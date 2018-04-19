/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *p;
    int a, b, i, j;
    p = (int*)malloc(sizeof(int)*2);
    for(i=0; i<numsSize; i++){
        for(j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j] == target){
                a=i;
                b=j;
                break;
            }
        }
    }
    p[0] = a;
    p[1] = b;
    return p;
}