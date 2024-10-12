p, k = input(), input()

p1 = [bin(ord(i))[2:].rjust(8,"0") for i in p]
print(p1)


def xor(a: str, b: str):
    ans = ""
    for i in range(len(a)):
        ans += "1" if a[i] != b[i] else "0"
    return ans

s="".join(p1)

for i in range(len(s)):
    if s[i]!=k[i%len(k)]:
        print("1",end="")
    else:
        print("0", end="")

