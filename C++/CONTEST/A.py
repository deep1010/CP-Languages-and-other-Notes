n = int(input())
arr = input()
arr = arr.split(' ')
if len(set(arr)) == 1:
	print(-1)
else:
	print(' '.join(sorted(arr)))