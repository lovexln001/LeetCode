char* addBinary(char* a, char* b) {
    int i,j;
    int c = 0;
    for(i=0; *a; a++, i++);
    for(j=0; *b; b++, j++);
    char *p = (char *)calloc(i>j ? i+2: j+2, sizeof(char)), *last=p;
    while(i || j || c != 0){
        int s = c;
        if(i){
            s += *(--a)-'0';
            i--;
        }
        if(j){
            s += *(--b)-'0';
            j--;
        }
        *last++ = (s&1)+'0';
        c = s>>1;
    }
    *last = 0;
    char *start=p,t;
    while(start+1 < last){
        t = *(--last);
        *last = *start;
        *start++ = t;
    }
    return p;
}