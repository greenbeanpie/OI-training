#include <bits/stdc++.h>

using namespace std;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while (! isdigit(ch)){
		if (ch == '-')
			f = - f;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

void write(int x){
	if (x < 0){
		putchar('-');
		write(- x);
		return;
	}
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + 48);
	return;
}

inline void writesp(int x){
	write(x);
	putchar(' ');
	return;
}

inline void writeln(int x){
	write(x);
	puts("");
	return;
}

const int MAXN = 3055;
int n, m;
int ans[MAXN];
char tu[MAXN], td[MAXN];

struct Luck{
	string val;
	int num;
}upp[MAXN], dwn[MAXN];

inline bool cmpupp1(char x, char y){
	return x < y;
}

inline bool cmpdwn1(char x, char y){
	return x > y;
}

inline bool cmpdwn2(Luck x, Luck y){
	return x.val > y.val;
}

signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++ i){
		char ch = getchar();
		int tot = 0;
		upp[i].val += ' ';
		dwn[i].val += ' ';
		upp[i].num = dwn[i].num = i;
		while (ch < 'a' || ch > 'z')
			ch = getchar();
		while (ch >= 'a' && ch <= 'z'){
			tu[++ tot] = int(ch);
			td[tot] = int(ch);
			ch = getchar();
		}
		sort(tu + 1, tu + m + 1, cmpupp1);
		sort(td + 1, td + m + 1, cmpdwn1);
		for (int j = 1; j <= m; ++ j){
			upp[i].val += char(tu[j]);
			dwn[i].val += char(td[j]);
		}
	}
	sort(upp + 1, upp + n + 1, cmpdwn2);
	sort(dwn + 1, dwn + n + 1, cmpdwn2);
//	for (int i = 1; i <= n; ++ i)
//		cout << upp[i].val << " " << upp[i].num << endl;
//	for (int i = 1; i <= n; ++ i)
//		cout << dwn[i].val << " " << dwn[i].num << endl;
	int l = 1;
	for (int i = 1; i <= n; ++ i){
		bool flag = true;
		while (l <= n){
//			cout << upp[i].val << dwn[l].val << endl;
			if (upp[i].val <= dwn[l].val)
				l ++;
			else{
				flag = false;
				break;
			}
		}
		if (flag)
			ans[upp[i].num] = 1;
		else
			ans[upp[i].num] = 0;
	}
	for (int i = 1; i <= n; ++ i)
		write(ans[i]);
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
