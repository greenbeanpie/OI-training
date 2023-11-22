#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define endl "\n"
using namespace std;
const int N=3e3+5;
int n,m;
struct node{
	string s;
	int op;
}a[N<<1];
bool cmp1(node x,node y){
	if(x.s==y.s) return x.op<y.op;
	return x.s<y.s;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n){
		string ch;
		cin>>ch;
		sort(ch.begin(),ch.end());
		a[i].s=ch;
		a[i].op=i;
		reverse(ch.begin(),ch.end());
		a[i+n].s=ch;
		a[i+n].op=-i;
	}
	sort(a+1,a+n*2+1,cmp1);
	FOR(i,1,n){
		bool flg=1;
		FOR(j,1,n*2){
			if(a[j].op<0&&a[j].op!=-i){
				flg=0;
				break;
			}
			if(a[j].op==i){
				break;
			}
		}
		cout<<(int)(flg);
	}
	return (0-0);
}
