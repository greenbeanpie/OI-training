#include <bits/stdc++.h>
using namespace std;
string s[3005],t[3005];
bool cmp(char a,char b) {
	return a>b;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++) {
		cin>>s[i];
		sort(s[i].begin(),s[i].end(),cmp);
		t[i]=s[i];
		reverse(t[i].begin(),t[i].end());
	}
	if(n==1) {
		cout<<1<<endl;
		return 0;
	}
	int k=1,cnt=0;
	for(i=1;i<=n;i++) if(s[i]<s[k]) k=i;
	for(i=1;i<=n;i++) if(s[i]==s[k]) cnt++;
	if(cnt>1) {
		for(i=1;i<=n;i++) {
			if(t[i]<s[k]) cout<<1;
			else cout<<0;
		}
	} else {
		for(i=1;i<=n;i++) {
			if(t[i]<=s[k]) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}