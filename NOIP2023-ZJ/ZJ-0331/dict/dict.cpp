#include<bits/stdc++.h>
#define ZJL using
#define AK namespace
#define IOI std
#define Name "dict"
#define ll long long
const ll N = 3e3 + 10;
ZJL AK IOI;

int Y, _;

int n, m;
int id1, id2;
bool ans[N];
string s[N], a[N];

inline string reads(){
	string s;
	char c = getchar();
	while(c >= 'a' && c <= 'z') s += c, c = getchar();
	return s;
}

inline ll read(){
	ll x = 0, y = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') y = -y;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * y;
}

int main(){
	freopen(Name ".in", "r", stdin);
	freopen(Name ".out", "w", stdout);
	n = read(), m = read();
	if(n == 1){
		puts("1");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		a[i] = s[i] = reads();
	}
	for(int i = 1;i <= n;i++){
		sort(a[i].begin(), a[i].end());
		reverse(a[i].begin(), a[i].end());
		if(i == 1) id1 = i;
		else if(i == 2){
			if(a[i] < a[id1]) id2 = id1, id1 = i;
			else id2 = i;
		}
		else{
			if(a[i] < a[id1]) id2 = id1, id1 = i;
			else if(a[i] < a[id2]) id2 = i;
		}
		sort(s[i].begin(), s[i].end());
	}
	for(int i = 1;i <= n;i++){
		if(i ^ id1) ans[i] = s[i] < a[id1];
		else ans[i] = s[i] < a[id2];
	}
	for(int i = 1;i <= n;i++) putchar(ans[i] ? '1' : '0');
	puts("");
	return ~~(Y^_^Y);
}