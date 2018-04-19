int searchInsert(int* nums, int numsSize, int target) {
    int index = 0;
    int i;
    for(i=0; i < numsSize; i++){
        index = i;
        if(nums[i] >= target) break;
    }
    return i == index?index:i;
}