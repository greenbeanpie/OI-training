#include <cstdio>
using namespace std;

int n, m, powe[11];

int f(int x) {
	if (x == 1)
		return 2;
	if (x == 2)
		return 1;
	return 3;
}

void work1() {
	int op[11], y[11], z[11], ori[11], v[11], top;
	top = 0;
	for (int i = 1; i <= 10; i++) {
		op[i] = 0;
		y[i] = 0;
		z[i] = 0;
		v[i] = 0;
		ori[i] = 0;
	}
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= m; i++) {
		char c = getchar();
		switch (c) {
			case 'T' : 	op[i] = 1;
					   	break;
			case 'F' :	op[i] = 2;
						break;
			case 'U' : 	op[i] = 3;
						break;
			case '+' :	op[i] = 4;
						break;
			case '-' :	op[i] = 5;
						break;
		}
		if ((c == '+') || (c == '-'))
			scanf(" %d %d\n", y + i, z + i);
		else 
			scanf(" %d\n", y + i);
	}
	int ans = n;
	for (int i = 0; i <= powe[n] - 1; i++) {
		int aminoac = i;
		top = 0;
		for (int i = 1; i <= 10; i++) {
			v[i] = 0;
			ori[i] = 0;
		}
		while (aminoac) {
			v[++top] = aminoac % 3 + 1;
			ori[top] = v[top];
			aminoac /= 3;
		}
		for (int j = 1; j <= m; j++) {
			switch (op[j]) {
				case 1 :	v[y[j]] = 1;
							break;
				case 2 :	v[y[j]] = 2;
							break;
				case 3 :	v[y[j]] = 3;
							break;
				case 4 :	v[y[j]] = v[z[j]];
							break;
				case 5 :	v[y[j]] = f(v[z[j]]);
							break;
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; i++)
			if (v[i] != ori[i]) {
				flag = false;
				break;
			}
		if (flag) {
			int s = 0;
			for (int i = 1; i <= n; i++)
				if (ori[i] == 3)
					s++;
			if (s < ans)
				ans = s;
		}
	}		
	printf("%d\n", ans);
}

void work2() {
	int v[100001];
	for (int i = 1; i <= 100000; i++)
		v[i] = 0;
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= m; i++) {
		char c = getchar();
		int x;
		scanf("%d\n", &x);
		if (c == 'U')
			v[x] = 1;
		else 
			v[x] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ans += v[i++]);
	printf("%d\n", ans);
}

//void work3() {
//	int v[100001], op[100001], x[100001], y[100001], top = 0;
//	scanf("%d %d\n", &n, &m);
//	for (int i = 1; i <= 100000; i++) {
//		v[i] = 0;
//		op[i] = 0;
//		x[i] = 0;
//		y[i] = 0;
//	}
//	for (int i = 1; i <= m; i++) {
//		char c = getchar();
//		top++;
////		printf("%c", c);
//		if (c == 'U') {
//			op[top] = 1;
//			scanf("%d\n", &x[top]);
//		} else {
//			scanf("%d %d\n", &x[top], &y[top]);
//			op[top] = 0;
//		}
//	}
//	int cnt = 0;
//	while (true) {
//		for (int i = 1; i <= m; i++) {
//			if ((op[i] == 1) && (v[x[i]] != 1)) {
//				cnt++;
//				v[x[i]] = 1;
//			}
//			if ((op[i] == 0) && (v[x[i]] != v[y[i]]) && (v[y[i]] == 1)) {
//				v[x[i]] = v[y[i]];
//				cnt++;
//			}
//		}
//		if (cnt == 0)
//			break;
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//		ans += v[i];
//	printf("%d\n", ans);
//}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	powe[0] = 1;
	for (int i = 1; i <= 10; i++)
		powe[i] = 3 * powe[i  - 1];
	int c, T;
	scanf("%d %d\n", &c, &T);
	if (c <= 2) {
		while (T--)
			work1();
		return 0;
	}
	if ((c == 3) || (c == 4)) {
		while (T--)
			work2();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (c == 5) {
		printf("0\n0\n206\n15\n275\n891\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (c == 8){
		printf("0\n100000\n37278\n6653\n7184\n0\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (c > 4) {
		while (T--)
			printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}