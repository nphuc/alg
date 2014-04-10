#define printNumber(n) do{\
        char __p[21];\
        register char __plen=0;\
        register unsigned long long __n=(n);\
        while(__n||!__plen){ __p[__plen++]=__n%10; __n/=10;}\
        while(__plen--){putchar_unlocked('0'+__p[__plen]);}\
    }while(0)
