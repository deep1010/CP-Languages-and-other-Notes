from collections import Counter 
t = int(input())
for i in range(0,t):
	a = str(input())
	b = str(input())
	countA = Counter(a)
	countB = Counter(b)
	print(countA)
	print(countB)
	finalAnswer = 0

	for i in 'abcdefghijklmnopqrstuvwxyz':
		finalAnswer += abs(countA[i] - countB[i])

	print(finalAnswer)