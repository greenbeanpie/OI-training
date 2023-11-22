#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3005;

string a[N],b[N];
int n,m,p[N],tot[N];
void mysort(string &s) {
	vector<int>tot(26);
	for (char i:s) {
		tot[i-'a']++;
	}
	int cnt=0;
	for (int i=0;i<26;i++) {
		while (tot[i]--) {
			s[cnt++]=char('a'+i);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=a[i];
		mysort(a[i]);
		mysort(b[i]);
		reverse(b[i].begin(),b[i].end());
		tot[i]-=b[i]>a[i];
		p[i]=i;
	}
	sort(b+1,b+1+n,greater<string>());
	sort(p+1,p+1+n,[&](int x,int y) {
		return a[x]>a[y];
	});
	for (int i=1,j=1;i<=n;i++) {
		while (j<=n&&a[p[i]]<b[j]) {
			j++;
		}
		tot[p[i]]+=j-1;
	}
	for (int i=1;i<=n;i++) {
		cout<<(tot[i]==n-1);
	}
	
	return 0;
}
