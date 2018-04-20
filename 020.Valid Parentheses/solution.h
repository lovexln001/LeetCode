bool isValid(char* s) {
    char *p = (char*)calloc(strlen(s),sizeof(char));
    char *m;
    m = p;
    while(*s){
        if(*s == '(' || *s =='[' || *s == '{'){
            if(*s == '(') *p =')';
            if(*s == '[') *p =']';
            if(*s == '{') *p ='}';
            ++p;
        }else if(*s == ')' || *s ==']' || *s == '}'){
            if(*(--p) != *s) return false;
        }else{
            return false;    
        }
        s++;
    }
    if(m != p)return false;
    return true;
}