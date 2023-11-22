#include<bits/stdc++.h>
using namespace std;
const int N=30005;
char ch[N];int cnt[N][26],Mx[N],Mn[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);Mn[i]=27426169;
		for(int j=1;j<=m;j++){
			cnt[i][ch[j]-'a']++;
			Mx[i]=max(Mx[i],ch[j]-'a');
			Mn[i]=min(Mn[i],ch[j]-'a');
		}
	}
	if(n==1){putchar('1');exit(0);}
	for(int i=1;i<=n;i++){
		bool flg=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(Mn[i]>=Mx[j]){flg=0;break;}
		}putchar(flg^48);
	}
	return 0;
}
// 100- pts