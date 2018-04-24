#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "solution.h"

struct ListNode *createList(int *array,int len){
    struct ListNode *hd = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = NULL;
    hd->val = 0;
    int i;
    for(i=0; i<len; i++){
        if(p == NULL){
            p = hd;
        }else{
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p->next->val = 0;
            p = p->next;
        }
        p->val = array[i];
    }
    return hd;
}

int *getInt(struct ListNode *l){
    int *num = (int*)malloc(sizeof(int));
    int index = 1;
    num[index - 1] = 0;
    while(l){
        num = realloc(num, index + 1);
        num[index - 1] = l->val;
        l = l->next;
        index++;
    }
    return num;
}

void main(){
    /* 342 + 465 = 807 */
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    int array1[] = {2, 4, 3};
    int array2[] = {5, 6, 4};
    int check[] = {7, 0, 8};
    l1 = createList(array1, 3);
    l2 = createList(array2, 3);
    struct ListNode *sump = addTwoNumbers(l1, l2);
    int *sum = NULL;
    sum = getInt(sump);
    int len = 3;
    int i;
    for(i=0; i<len; i++){
        //assert(check[i] == sum[i]);
        printf("check: %d, get: %d\n", check[i], sum[i]);
    }
}
