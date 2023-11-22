#include<bits/stdc++.h>
using namespace std;
int c ,t;
int n , m;
int a[100005];

struct node{
	char id;
	int x;
	int y;
};

struct node f[100005];

inline void fre() {
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out","w",stdout);
}

int main() {
	//freopen("tribool.in" , "r" , stdin);
	fre();
	for(cin >> c >> t; t;--t) {
		cin >> n >> m;
		if(c == 3 || c == 4) {
			int res = 0;
			for(int i = 1;i <= m; ++i) {
				char ch;
				cin >> ch;
				if(ch == 'T') {
					int num;
					cin >> num;
					a[num] = 1;
				}
				else if(ch == 'F') {
					int num;
					cin >> num;
					a[num] = 0;
				}
				else if(ch == 'U') {
					int num;
					res = max(res , num);
					cin >> num;
					a[num] = 2;
				}
			}
			int cnt = 0;
			for(int i = 1; i <= res;++i) {
				if(a[i] == 2) cnt++;
			}
			cout << cnt << '\n';
		}
		else if(c == 5 || c == 6) {
			int cnt = 0;
			int maxx = 0;
			int maxy = 0;
			for(int i = 1;i <= m; ++i) {
				cin >> f[i].id;
				if(f[i].id == 'U') {
					cin >> f[i].x;
					maxx = max(maxx,f[i].x);
				}
				if(f[i].id == '+') {
					cin >> f[i].x >> f[i].y;
					maxy = max(max(f[i].x, f[i].y),maxy);
				}
			}
	
			for(int i = 1;i <= maxx; ++i) {	
				if(f[i].id == 'U') {
					if(a[f[i].x] != 2) {
						cnt++;
						a[f[i].x] = 2;
					}
				}
			}
			
			for(int i = 1;i <= maxy; ++i) {
				if(f[i].id == '+') {
					if(a[f[i].y] == 2 && a[f[i].x] != 2) {
						a[f[i].x] = 2;
						cnt++;
					}
				}
			}	
			cout << cnt << '\n';
		}
	} 
    return 0;
}

//11:31T2做破防了 猪国杀整整写了4天 T2就写两个点 T1可能炸一个点
//开摆 
