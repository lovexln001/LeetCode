#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "solution.h"

void main(){
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";
    char s3[] = "pwwkew";
    char s4[] = "au";
    int max1 = lengthOfLongestSubstring(s1);
    int max2 = lengthOfLongestSubstring(s2);
    int max3 = lengthOfLongestSubstring(s3);
    int max4 = lengthOfLongestSubstring(s4);
    printf("s1: %s, st:3, longest: %d\n", s1, max1);
    printf("s2: %s, st:1  longest: %d\n", s2, max2);
    printf("s3: %s, st:3  longest: %d\n", s3, max3);
    printf("s4: %s, st:2  longest: %d\n", s4, max4);
}
