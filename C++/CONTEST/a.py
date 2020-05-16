n,m = input().split(' ')
n = int(n)
m = int(m)
arr = [str(i) for i in range(n)]
def gn(cur):
	if arr[(cur+2)%n] !='-1':
		arr[(cur+2)%n] ='-1'
		return (cur+2)%n
	else:
		return gn((cur+1)%n)

s = 0
for j in range(m):
	s = gn(s)
