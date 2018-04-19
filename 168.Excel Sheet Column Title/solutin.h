char* convertToTitle(int n) {
    char s[10] = {0};
    int i = 0, j = 0;
    while(n > 0){
        s[i++] = --n % 26 + 'A';
        n /= 26;
    }
    char *p = (char*)malloc((i+1)*sizeof(char));
    while(i > 0){
        p[j++] = s[--i];
    }
    p[j] = '\0';
    return p;
}