bool isHappy(int n) {
    int m,j=0;
    while(j++<6){
        m=0;
        while( n){m += (n%10)*(n%10);n /=10;}
        if(m == 1 ) return true;
        n = m;
    }
    return false;
}