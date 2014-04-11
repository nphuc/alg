from sys import *
import heapq
s=stdin.readline().split(" ")
n=int(s[0])
k=int(s[1])
"""
test.inp
 matrix 6x6 block=10 
......
..##.#
##.#..
...#..
.##...
....#.

"""
m=[]
for j in range(n):
    m.append([])
    for i in range(n):
        m[j].append(0)
for i in range(k):
    s=stdin.readline().split(" ")
    y=int(s[0])
    x=int(s[1])
    m[y][x]=1
visited=[]
def init():
    global visited
    for j in range(len(m)):
        visited.append([])
        for i in range(len(m[0])):
            visited[j].append(False)
init()
inf=99999999
class Node:
    def __init__(self,x,y):
        self.x=x
        self.y=y
        self.parent=None
        self.g=inf
        self.f=inf
    def __eq__(self,o):
        return self.x==o.x and self.y==o.y
    def __str__(self):
        """ 
        note: write [x,y]
        """
        return str(self.x)+":"+str(self.y)
    def __lt__(self,o):
        return self.f<o.f
    def __gt__(self,o):
        return self.f>o.f
tx=[0,1,0,-1]
ty=[1,0,-1,0]
def heur(curr,goal):
    return abs(curr.x-goal.x)+abs(curr.y-goal.y)
def astar(start,goal):
    count=0
    openset=[]
    heapq.heappush(openset,start)
    global visited
    start.g=0
    start.f=start.g+heur(start,goal)
    while len(openset):
        curr=heapq.heappop(openset)
        if curr==goal:
            print("loop=",count)
            return curr
        visited[curr.y][curr.x]=True
        for i in range(len(tx)):
            count+=1
            x=tx[i]+curr.x
            y=ty[i]+curr.y
            if x>=0 and y>=0 and x<len(m[0]) and y<len(m) and (not visited[y][x])  and (not m[y][x]) :
                t=Node(x,y)
                #tmp=curr.g+distance(curr,t)
                tmp=curr.g+1
                t.parent=curr
                if t.g> tmp:
                    t.g=tmp
                    t.f=t.g+heur(t,goal)
                    heapq.heappush(openset,t)

t=astar(Node(2,2),Node(5,5))
out=[]
for j in range(len(m)):
    out.append([0 for i in range(len(m[0]))])
print(t.g)
while t.parent is not None:
    print(t)
    t=t.parent
    out[t.y][t.x]=1
for j in range(len(m)):
    for i in range(len(m[0])):
        stdout.write(str(out[j][i]))
    stdout.write("\n")
