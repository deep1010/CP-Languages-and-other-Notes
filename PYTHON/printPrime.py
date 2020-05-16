def isPrime(a):
	for i in range(2,a):
		if a % i == 0:
			return False
	return True

n = int(input())

for i in range(2,n):
	if isPrime(i):
		print(i)