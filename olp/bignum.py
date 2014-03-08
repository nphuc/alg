f=open("BIGNUM.INP")
a=f.readline()[:-1]
b=f.readline()[:-1]
add=eval(a+'+'+b)
mul=eval(a+'*'+b)
sub=eval(a+'-'+b)

print(add)
print(sub)
print(mul)
