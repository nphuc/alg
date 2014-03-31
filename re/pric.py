from sys import *
k=2
for i in range(k):
    stdout.write("{")
    for j in range(k-2):
        stdout.write(str((i**j)%k)+",")
    j=k-1
    stdout.write(str((i**j)%k))
    stdout.write("},\n")
        
