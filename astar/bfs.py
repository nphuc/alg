from sys import *
s=stdin.readline().split(" ")
n=int(s[0])
k=int(s[1])

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
class Node:
    def __init__(self,x,y):
        self.x=x
        self.y=y
        self.parent=None
    def __eq__(self,o):
        return self.x==o.x and self.y==o.y
    def __str__(self):
        return str(self.x)+":"+str(self.y)

tx=[0,1,0,-1]
ty=[1,0,-1,0]
count=0
def bfs(list_from,end):
    global visited,count
    new_list=[]
    for node in list_from:
        if node==end:
            return node
        for i in range(len(tx)):
            count+=1
            x=node.x+tx[i]
            y=node.y+ty[i]
            if x>=0 and y>=0 and x<len(m[0]) and y<len(m) and not visited[y][x] and m[y][x]==0:
                n=Node(x,y)
                n.parent=node
                visited[y][x]=True
                new_list.append(n)
    if len(new_list)==0:
        return None
    return bfs(new_list,end)
visited[0][0]=True
t=bfs([Node(2,2)],Node(5,5))
print("loop=",count)
while t.parent is not None:
    print(t)
    t=t.parent
