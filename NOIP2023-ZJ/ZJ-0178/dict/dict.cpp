#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3050;
int n,m,ans[N],p[N][26],tmp[26];
char s[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> s+1;
		for(int j=1;j<=m;++j)
			p[i][s[j]-'a']++;
	}
	for(int i=1;i<=n;++i){
		ans[i]=1;
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			int k=25,ok=0;
			memcpy(tmp,p[j],sizeof(tmp));
			for(int w=0;w<26;++w){
				while(k>=0&&tmp[k]==0) --k;
				if(p[i][w]!=0&&w<k){
					ok=1;
					break;
				}
				int t=p[i][w];
				while(t){
					int mi=min(t,tmp[k]);
					tmp[k]-=mi;
					t-=mi;
					while(k>=0&&tmp[k]==0) --k;
				}
			}
			if(ok==0){
				ans[i]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)
		cout << ans[i];
	return 0;
}
