int isRepeat(char *s,int st, int ed){
    char table[256] = {0};
    while(st <= ed){
        if(++table[s[st]] == 2) return 1;
        st++;
    }
    return 0;
}
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int max = len ? 1 : 0;
    int l, st, ed;
    for(l = 2; l<=len; l++){
        for(st=0, ed=l-1; ed<=len-1;st++,ed++){
            if(isRepeat(s, st, ed))
                continue;
            max = l;
        }
    }
    return max;
}
