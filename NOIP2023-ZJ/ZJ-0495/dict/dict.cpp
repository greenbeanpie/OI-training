#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 2;
const int base = 131;

int n, m, ans[N];
int cnt[300];
bool flag;
struct node{
	int idx;
	string s;
}mx;
string t, mn[N];


signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);

	cin >> n >> m;
	mx.s = "";
	for(int i = 1; i <= n; i ++){
		cin >> t;
		for(char j = 'a'; j <= 'z'; j ++)  cnt[j] = 0;
		for(auto c : t)  cnt[c] ++; int tmp = 0;
		for(char j = 'a'; j <= 'z'; j ++)
			for(int k = 1; k <= cnt[j]; k ++, tmp ++)
				t[tmp] = j;
		mn[i] = t;
		for(int i = 0, j = m - 1; i < j; i ++, j --)
			swap(t[i], t[j]);
		if(mx.s == "" || mx.s > t){
			mx.idx = i;
			flag = 0;
			mx.s = t;
		}
		else if(!flag && mx.s == t){
			if(!mx.idx)
				mx.idx = i;
			else
				flag = 1;
		}
	}
	for(int i = 1; i <= n; i ++){
		if(mn[i] < mx.s || (!flag && mx.idx == i))
			cout << '1';               
		else                            
			cout << '0';
	}

	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/