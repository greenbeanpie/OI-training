#include<bits/stdc++.h>
#define LL long long
#define IL inline
using namespace std;
const int N = 4e3 + 10;
bool _u;
string s[N],t[N];
int n,m,ans[N];
bool _v;
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	//cerr << abs(&_u - &_v) / 1048576.0 << "MB" << endl;
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> s[i];
		sort(s[i].begin(),s[i].end());
		t[i] = s[i],reverse(t[i].begin(),t[i].end());
	}
	sort(t + 1,t + n + 1);
	for(int i = 1;i <= n;i ++)	ans[i] = (s[i] <= t[1]);
	for(int i = 1;i <= n;i ++)	cout << ans[i];
	cout << endl;
	return 0;
}
