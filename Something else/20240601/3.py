def isprime(n):
	for i in range(2,n-1):
		if n%i==0:
			return False
	return True

for i in range(100,1000):
	if isprime(i):
		print(i,end=" ")

