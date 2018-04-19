bool isPalindrome(int x) {
    int str[32];
    int i,j;
    if(x < 0){return false;}
    for(i=0; x!=0; ++i){
        str[i] = x % 10;
        x /= 10;
    }
    j=i;
    for(;i >0 ; --i){
        if(str[i-1] != str[j-i]){
            return false;
        }
    }
    return true;
}