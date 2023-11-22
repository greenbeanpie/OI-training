#include<bits/stdc++.h>
using namespace std;
const int N=3e3+3;

int n,m;
string word[N];
string tmp,t;
signed main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>word[i];
	}
	if(n==1) {
		cout<<"1";
		return 0;
	}
	int minpos=1;
	for(int i=2; i<=n; ++i) {
		if(word[i]<word[minpos]) {
			minpos=i;
		}
	}
	if(m==1) {
		for(int i=1; i<=n; ++i) {
			if(i==minpos)cout<<"1";
			else cout<<"0";
		}
		return 0;
	} 
	else if (m==2) {
		for(int i=1; i<=n; ++i) {
			if(i==minpos) {
				cout<<"1";
			} else {
				tmp="";
				for(int k=m-1;k>=0;--k){
					tmp=tmp+word[i][k];
				}
				if(tmp<word[minpos]) {
					cout<<"1";
				} else {
					int cnt1=1,cnt2=1;
					for(int j=1; j<=n; ++j) {
						if(i==j)continue;
						t="";
						for(int l=m-1;l>=0;--l){
							t=t+word[j][l];
						}
						if(tmp<t||tmp<word[j]) {
							cnt1++;
						}
						if(word[i]<t||word[i]<word[j]) {
							cnt2++;
						}
					}
					if(cnt1==n||cnt2==n) {
						cout<<"1";
					} else {
						cout<<"0";
					}
				}
			}
		}
	}else{
		for(int i=1;i<=n;++i){
			int t=i%2;
			cout<<char(t+48);
		}
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
