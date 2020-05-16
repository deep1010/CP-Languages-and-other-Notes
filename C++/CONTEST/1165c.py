n = int(input())
s = str(input())
ans = s[0]
i = 0
while i < n:
	if(len(ans)%2==1):
		if s[i] == ans[-1]:
			i+=1
		else:
			ans += s[i]
			i+=1
	else:
		ans+=s[i]
		i+=1
# print(ans)
if len(ans)%2==1:
	ans = ans[:-1]
print(n - len(ans))
print(ans)