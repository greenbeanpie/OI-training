#include<bits/stdc++.h>
using namespace std;

int n,m;
struct node {
	int id;
	string S;
	int des[30];
	int mmax=0;
	int mmin=100;
} Dic[5000];
string s;
int T_des[30],T_minn,T_id;
int Now_mmin,Now_mmax,Now_flag;
signed main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s;
		Dic[i].S=s;
		Dic[i].id=i;
		for(int j=0; j<s.size(); j++) {
			Dic[i].des[s[j]-'a'+1]++;
			if(s[j]-'a'+1<Dic[i].mmin) {
				Dic[i].mmin=s[j]-'a'+1;
			}
			if(s[j]-'a'+1>Dic[i].mmax) {
				Dic[i].mmax=s[j]-'a'+1;
			}
		}
	}
	if(n==1) {
		cout<<1;
		return 0;
	}
	if(m==1) {
		T_minn=100;
		for(int i=1; i<=n; i++) {
			if(Dic[i].S[0]-'a'+1<T_minn) {
				T_minn=Dic[i].S[0]-'a'+1;
				T_id=i;
			}
		}
		for(int i=1; i<=n; i++) {
			if(i==T_id) {
				cout<<1;
			} else {
				cout<<0;
			}
		}
		return 0;
	}

	for(int i=1; i<=n; i++) {
		Now_mmin=Dic[i].mmin,Now_mmax=Dic[i].mmax;
		Now_flag=1;
		for(int j=1; j<=n; j++) {
			if(j==i) {
				continue;
			} else if(j!=i) {
				if(Dic[i].mmin>=Dic[j].mmax) {
					Now_flag=0;
					break;
				}
			}
		}
		if(Now_flag==0) {
			cout<<0;
		} else {
			cout<<1;
		}
	}
	return 0;
}
