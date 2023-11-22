#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x7fffffff
const int N(3005);
int n,m;
int ct[N][30];
char ch[N];
int mn[N],mx[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>(ch+1);
		mn[i]=100;
		mx[i]=0;
		for(int j=1;j<=m;++j){
			ct[i][ch[j]-'a']+=1;
			mn[i]=min(mn[i],ch[j]-'a');
			mx[i]=max(mx[i],ch[j]-'a');
		}
	}
	bool OK;
	for(int i=1;i<=n;++i){
		OK=1;
		for(int j=1;j<=n;++j){
			if(i==j||mx[j]>mn[i]) continue;
			if(mx[j]<mn[i]){
				OK=0;
				break;
			}
			if(ct[j][mx[j]]<=ct[i][mn[i]]){
				OK=0;
				break;
			}
		}
		if(OK) cout<<"1";
		else cout<<"0";
	}
}