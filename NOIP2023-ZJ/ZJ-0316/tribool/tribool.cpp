#include<bits/stdc++.h>
#define rep(i,l,r) for(int i(l), i##end(r); i<=i##end; ++i)
using namespace std;
const int N = 101000;
int arr[N], n, m, ans;
struct node{
	char Opt;int i, j;
}opt[N];
struct task1{
	int temparr[12];
	void work() {
		rep(i, 1, n) {
			temparr[i] = arr[i];
		}
		for(int i=1; i<=m; ++i) {
			if(opt[i].Opt == '+') {
				temparr[opt[i].i] = temparr[opt[i].j];
			} else if(opt[i].Opt == '-') {
				if(temparr[opt[i].j] == 2) {
					temparr[opt[i].i] = 2;
				} else {
					temparr[opt[i].i] = !temparr[opt[i].j];
				}
			} else {
				if(opt[i].Opt == 'T') {
					temparr[opt[i].i] = 0;
				} else if(opt[i].Opt == 'F'){
					temparr[opt[i].i] = 1;
				} else {
					temparr[opt[i].i] = 2;
				}
			}
		}
	}
	bool check() {
		bool bl = 1;
		rep(i, 1, n) {
			if(temparr[i] != arr[i]) {
				bl = 0;
				return bl;
			}
		}
		return bl;
	}
	int calc() {
		int tempans = 0;
		rep(i, 1, n) {
			(temparr[i] == 2) && (tempans++);
		}
		return tempans;
	}
	void dfs(int index) {
		if(index == n + 1) {
			work();
			if(check()) {
				ans = min(ans, calc());
			}
			return;
		}
		arr[index] = 0; dfs(index+1);
		arr[index] = 1; dfs(index+1);
		arr[index] = 2; dfs(index+1);
	}
};
task1 TASK1;
struct task2{
	void work() {
		rep(i, 1, m) {
			if(opt[i].Opt == 'T') {
				arr[opt[i].i] = 0;
			} else if(opt[i].Opt == 'F') {
				arr[opt[i].i] = 1;
			} else {
				arr[opt[i].i] = 2;
			}
		}
		rep(i, 1, n) {
			if(arr[i] == 2) {
				ans++;
			}
		}
	}
};
task2 TASK2;
int brr[N*2];
struct task3{
	int fa[N*2];
	int find(int index) {
		if(fa[index] == index) return index;
		return fa[index] = find(fa[index]);
	}
	void merge(int a, int b) {
		int x = find(a), y = find(b);
		fa[x] = y;
	}
	void work() {
		int tot = 0;
		rep(i, 1, n) {arr[i] = ++tot; brr[tot] = 3;}
		rep(i, 1, n+m) fa[i] = i;
		rep(i, 1, m) {
			if(opt[i].Opt == '+') {
				arr[opt[i].i] = arr[opt[i].j];
			} else {
				arr[opt[i].i] = ++tot;
				brr[tot] = 2;
			}
		}
		rep(i, 1, n) {
			merge(i, arr[i]);
		}
		rep(i,1,tot) {
			if(brr[i] == 2) {
				brr[find(i)] = 2;
			}
		}
		rep(i,1,n) {
			if(brr[find(arr[i])] == 2) {
				ans++;
			}
		}
	}
};
task3 TASK3;
struct task4{
	int fa[N*2];
	int tot;
	int find(int index) {
		if(fa[index] == index) return index;
		return fa[index] = find(fa[index]);
	}
	void merge(int a, int b) {
		int x = find(a), y = find(b);
		fa[x] = y;
	}
	int ene(int index) {
		if(index > n) {
			return index - n;
		} else {
			return index + n;
		}
	}
	void work() {
		rep(i, 1, 2*n) fa[i] = i;
		rep(i, 1, n) arr[i] = i;
		rep(i, 1, m) {
			if(opt[i].Opt == '+') {
				arr[opt[i].i] = arr[opt[i].j];
			} else {
				arr[opt[i].i] = ene(arr[opt[i].j]);
			}
		}
		rep(i, 1, n) {
			merge(i, arr[i]);
		}
		rep(i, 1, n) {
			if(find(i) == find(i+n)) {
				brr[find(i)] = 2;
			}
		}
		rep(i, 1, n) {
			if(brr[find(arr[i])] == 2) {
				ans++;
			}
		}
	}
};
task4 TASK4;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c, t; cin >> c >> t;
	while(t--) {
		memset(arr, 0, sizeof arr); ans = 0;
		memset(brr, 0, sizeof brr);
		cin >> n >> m;
		bool Task2 = 1, Task3 = 1, Task4 = 1;
		rep(i, 1, m) {
			cin >> opt[i].Opt;
			if(opt[i].Opt == '+') {
				Task2 = 0;
				cin >> opt[i].i >> opt[i].j;
			} else if(opt[i].Opt == '-') {
				Task2 = 0; Task3 = 0;
				cin >> opt[i].i >> opt[i].j;
			} else {
				Task4 = 0;
				if(opt[i].Opt != 'U') {
					Task3 = 0;
				}
				cin >> opt[i].i;
			}
		}
		if(n <= 10 && m <= 10) {
			ans = n; TASK1.dfs(1);
			cout << ans << endl;
		} else if(Task2) {
			TASK2.work();
			cout << ans << endl;
		} else if(Task3) {
			TASK3.work();
			cout << ans << endl;
		} else if(Task4) {
			TASK4.work();
			cout << ans << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}