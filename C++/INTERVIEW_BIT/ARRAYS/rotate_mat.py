from pprint import pprint
def solve(A):
	# pprint(A)
	# print("\n\n-----------After------------\n\n")
	n = len(A)
	for i in range(0,n):
		for j in range(i+1,n):
			A[i][j] , A[j][i] = A[j][i], A[i][j]
	for i in range(0,n):
		for j in range(0,n//2):
			A[i][j] , A[i][n-j-1] = A[i][n-j-1], A[i][j] 
	# pprint(A)

arr = [
		[1,2,3],
		[4,5,6],
		[7,8,9],
		]
solve(arr)