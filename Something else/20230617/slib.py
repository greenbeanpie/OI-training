_10to16 = {y: str(y) if y < 10 else chr(65 + y - 10) for y in range(0, 16)}
_16to10 = {_10to16[x]: x for x in _10to16}


def f1(x: str):
    ans = 0
    while x:
        ans = ans << 1 | int(x[0])
        x = x[1:]
    return ans


def f2(x: int):
    ans = ""
    while x:
        ans = str(x & 1) + ans
        x >>= 1
    return ans.lstrip("0")


def f3(x: str):
    ans = 0
    while x:
        ans = ans << 4 | _16to10[x[0]]
        x = x[1:]
    return ans


def f4(x: int):
    ans = ""
    while x:
        ans = _10to16[x & 15] + ans
        x >>= 4
    return ans.lstrip("0")


def f5(x: str):
    ans = ""
    while x:
        cur = 0
        for i in x[-4:]:
            cur = cur << 1 | int(i)
        ans = _10to16[cur] + ans
        x = x[:-4:1]
    return ans.lstrip("0")


def f6(x: str):
    ans = ""
    while x:
        cur = ""
        for i in range(4):
            cur = str((_16to10[x[0]] >> i) & 1) + cur
        ans = ans + cur
        x = x[1:]
    return ans.lstrip("0")

if __name__=="__main__":
	f = [f1, f2, f3, f4, f5, f6]

	k = int(input("请输入操作"))
	n = input("请输入数字")
	if k == 2 or k == 4:
		n = int(n)
	print(f[k - 1](n))
