#include <bits/stdc++.h>
using namespace std;
const int N=3000;
string w[N+1],lw[N+1],lg[N+1];
int t[26];
string lowest(string s) {
	memset(t,0,sizeof(t));
	for(int i=0;i<s.size();i++)
		t[s[i]-'a']++;
	string res;
	for(int i=0;i<26;i++)
		while(t[i]>0) {
			res+=char(i+'a');
			t[i]--;
		}
	return res;
}
string largest(string s) {
	memset(t,0,sizeof(t));
	for(int i=0;i<s.size();i++)
		t[s[i]-'a']++;
	string res;
	for(int i=25;i>=0;i--)
		while(t[i]>0) {
			res+=char(i+'a');
			t[i]--;
		}
	return res;
}
bool check(string s1,string s2) {
	for(int i=0;i<s1.size();i++) {
		if(s1[i]<s2[i])
			return true;
		if(s1[i]>s2[i])
			return false;
	}
	return false;
}
void prework(int n) {
	for(int i=1;i<=n;i++) {
		lw[i]=lowest(w[i]);
		lg[i]=largest(w[i]);
	}
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	prework(n);
	string ans;
	for(int i=1;i<=n;i++) {
		bool flag=true;
		for(int j=1;j<=n;j++)
			if(j!=i&&!check(lw[i],lg[j])) {
				flag=false;
				break;
			}
		if(flag)
			ans+='1';
		else
			ans+='0';
	}
	cout<<ans;
	return 0;
}