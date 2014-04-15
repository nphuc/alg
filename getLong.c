long getLong(){
    long res=0;
    char c;
    int flag=1;
    for(;;){
        c=getchar_unlocked();
        if(isdigit(c)) break;
        else if(c=='-') flag=-1;
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res*flag;
}
