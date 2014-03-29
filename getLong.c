long getLong(){
    long res=0;
    char c;
    for(;;){
        c=getchar_unlocked();
        if(isdigit(c)) break;
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res;
}
