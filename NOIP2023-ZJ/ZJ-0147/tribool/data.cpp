#include <bits/stdc++.h>
#define fq(i,a,b) for (int i = (a); i <= (b); i++)
#define fnq(i,a,b) for (int i = (a); i < (b); i++)
#define nfq(i,a,b) for (int i = (a); i >= (b); i--)
#define nfnq(i,a,b) for (int i = (a); i > (b); i--)
#define elif else if
using namespace std;

//#define int long long

inline int rd() {
	char ch = getchar ();
	int f = 1;
	while (!isdigit (ch)) {
		if (ch == '-') f *= -1;
		ch = getchar ();
	}
	int num = 0;
	while (isdigit (ch)) {
		num = num * 10 + ch - '0';
		ch = getchar ();
	} return num * f;
}
#define d rd()
mt19937 rnd(random_device{}());
int random (int a, int b) {
	return rnd()%(b-a+1)+a;
}
signed main () {
	cout << "1 1" << endl;
	int n = 5, m = 5;
	cout << n << ' ' << m << endl;
	fq (i, 1, m) {
		char op = "+-"[random(0,1)];
		int x = random (1, n), y = random (1, n);
		cout << op << ' ' << x << ' ' << y << endl;
	}
	return 0;
}

// where is my chinese shurufa??
// zhong guo ren bu yong yang wen.

// What you said is right, but wujisalt is the cuttest, obviously.
// I wonder if Nahida will pray for me.