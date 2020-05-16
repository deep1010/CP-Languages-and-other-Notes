n,x,y = input().split(' ')
given = str(input())
n,x,y = int(n),int(x),int(y)
a = given[-x:]
b = '0'*x
idx = x-y-1
b = b[:idx] + '1' + b[idx+1:]
# print(a,b)
ans = 0
for i in range(x):
	if a[i]!=b[i]:
		ans+=1
print(ans)
