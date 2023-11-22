#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3005];
string s_mn[3005];
string s_mx[3005];
int cnt[26];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) {
			cnt[s[i][j]-'a']++;
		}
		for(int j=0; j<26; j++) {
			while(cnt[j]) {
				cnt[j]--;
				s_mn[i]+=(char)(j+'a');
				s_mx[i]=(char)(j+'a')+s_mx[i];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		bool ok=true;
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			if(s_mn[i]>=s_mx[j]) {
				ok=false;
				break;
			}
		}
		if(ok) {
			cout<<'1';
		} else cout<<'0';
	}
	return 0;
}
