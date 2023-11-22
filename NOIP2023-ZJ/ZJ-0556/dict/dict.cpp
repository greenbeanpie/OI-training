#include <bits/stdc++.h>
using namespace std;
const int N=3e3+7;
struct node {
	char c1,c2; // max and min
} a[N];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string cur;
	for(int i=1; i<=n; ++i) { // aaaaaaaaaaaaaaaaaaaaaaa
		cin>>cur;
		a[i].c1=*min_element(cur.begin(),cur.end());
		a[i].c2=*max_element(cur.begin(),cur.end());
	}
	bool vis;
	for(int i=1; i<=n; ++i) {
		vis=1;
		for(int j=1; j<=n; ++j) {
			if(j==i) continue;
			if(a[i].c1<a[j].c2) continue;
			vis=0;
		}
		cout<<vis;
	}
	return 0;
}