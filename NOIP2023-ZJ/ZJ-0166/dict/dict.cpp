#include<bits/stdc++.h>
using namespace std;
void fileIO(){
	const string probname="dict";
	const string suff_in ="in";
	const string suff_out="out";
	const string file_in =probname+"."+suff_in;
	const string file_out=probname+"."+suff_out;
	freopen(file_in.c_str(),"r",stdin);
	freopen(file_out.c_str(),"w",stdout);
}
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
string s[10010];
string ssortl[10010];
string ssortg[10010];
string prefmin[10010];
string suffmin[10010];
int cnt[27],n,m;
string sort_s_l(string s){
	memset(cnt,0,sizeof(cnt));
	for (char c:s) cnt[c-'a'+1]++;
	string snew;snew.resize(m);
	int sum=0;
	for (int i=1;i<=26;i++){
		for (int j=1;j<=cnt[i];j++){
			snew[sum++]=char(i+'a'-1);
		}
	}
	return snew;
}
string sort_s_g(string s){
	memset(cnt,0,sizeof(cnt));
	for (char c:s) cnt[c-'a'+1]++;
	string snew;snew.resize(m);
	int sum=0;
	for (int i=26;i>=1;i--){
		for (int j=1;j<=cnt[i];j++){
			snew[sum++]=char(i+'a'-1);
		}
	}
	return snew;
}
int main(){
	fileIO();fastIO();
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		ssortl[i]=sort_s_l(s[i]);
		ssortg[i]=sort_s_g(s[i]);
	}
	prefmin[1]=ssortg[1];
	suffmin[n]=ssortg[n];
	for (int i=2;i<=n;i++){
		prefmin[i]=min(prefmin[i-1],ssortg[i]);
	}
	for (int i=n-1;i>=1;i--){
		suffmin[i]=min(suffmin[i+1],ssortg[i]);
	}
	if (n==1){
		cout<<"1\n";
		return 0;
	}
	for (int i=1;i<=n;i++){
		string mins;
		if (i==1) mins=suffmin[2];
		else if (i==n) mins=prefmin[n-1];
		else mins=min(prefmin[i-1],suffmin[i+1]);
		if (ssortl[i]<mins) cout<<"1";
		else cout<<"0";
	}
	cout<<"\n";
	return 0;
}
