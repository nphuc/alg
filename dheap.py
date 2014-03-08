import math
import random
ARITY=3
def xrange(a,b,c):
    return iter(range(a,b,c))
class HeapItem(object):
    def __init__(s,k,i):
        s.key=k
        s.item=i
        s.pos=None
    def __str__(s):
        return str(s.key)+" " +str(s.item)+" "+str(s.pos)
def children(pos,heap):
    return xrange(ARITY*pos+1,min(ARITY*(pos+1)+1,len(heap)),1)
def minchild(pos,heap):
    minpos=minkey=None
    for c in children(pos,heap):
        if minkey==None or heap[c].key<minkey:
            minkey,minpos=heap[c].key,c
    return minpos
def parent(pos):
    if pos==0: return None
    return int(math.ceil(pos/ARITY)-1)

def siftup(hi,pos,heap):
    p=parent(pos)
    while p is not None and heap[p].key>hi.key:
        heap[pos]=heap[p]
        heap[pos].pos=pos
        pos=p
        p=parent(p)
    heap[pos]=hi
    hi.pos=pos
######################################################################
def siftdown(hi,pos,heap):
    c=minchild(pos,heap)
    while c!=None and heap[c].key<hi.key:
        heap[pos]=heap[c]
        heap[pos].pos=pos
        pos=c
        c=minchild(c,heap)
    heap[pos]=hi
    hi.pos=pos
def makeheap(s):
    heap=list(HeapItem(k,i) for k,i in s)
    for pos in xrange(len(heap)-1,-1,-1):
        siftdown(heap[pos],pos,heap)
    return heap

def findmin(heap):
    return heap[0] if len(heap)>0 else None
def deletemin(heap):
    if len(heap)==0: return None
    i=heap[0]
    last=heap[-1]
    del heap[-1]
    if len(heap)>0:
        siftdown(last,0,heap)
    return i
def heapinsert(key,item,heap):
    heap.append(None)
    hi=HeapItem(key,item)
    siftup(hi,len(heap)-1,heap)
    return hi
def heap_decreasekey(hi,newkey,heap):
    hi.key=newkey
    siftup(hi,hi.pos,heap)



    
    
    
