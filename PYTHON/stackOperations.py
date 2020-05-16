[n,k] = list(map(int,input().split()))
arr = list(map(int,input().split()))

if n==1:
	if k%2==0:
		print(arr[0])
	else:
		print(-1)

elif k==1:
	print(arr[1])

elif k<n:
	print(max(max(arr[:k-1]),arr[k]))
elif k==n:
	print(max(arr[:k-1]))
elif k > n:
	print(max(arr))
