def kmp(p):
    """ compute KMP map"""
    m=len(p)
    f=[-1]*(m+1)
    i=1
    f[1]=0
    j=0
    while i<m:
        if p[i]==p[j]: f[i]=f[j]
        else:
            f[i]=j
            while j>=0 and p[i]!=p[j]: j=f[j]
        i+=1
        j+=1
    f[m]=j
    return f

def match(t,p):
    f=kmp(p)
    i=0
    j=0
    for i in range(len(t)):
        if t[i]!=p[j]:
            j=f[j]
        while j>=0 and t[i]!=p[j]:
            j=f[j]
        j+=1
        if j==len(p):
            print i
            j=f[j]
