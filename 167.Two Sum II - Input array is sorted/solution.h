/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    * returnSize = 2;
    int *p = (int*)calloc(*returnSize, sizeof(int));
    int i=0;
    int j=0;
    int index1=0;
    int index2=0;
    for(i=0; i<numbersSize; i++){
        for(j=i+1; j<numbersSize; j++)
            if(target == numbers[i]+numbers[j]){
                *p = i + 1;
                *(p+1) = j + 1;
                return p;
            }
    }
    *p = i + 1;
    *(p+1) = j + 1;
    return p;
}