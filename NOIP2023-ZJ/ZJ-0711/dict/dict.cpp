#include<bits/stdc++.h>
using namespace std;
int n,m;
struct s{
	int cnt[30];
	int num;
}sum[3010];
int ans[3010],a[30],b[30];
bool cmp(s x,s y){
	for(int i=26;i>=1;i--){
		if(x.cnt[i]>y.cnt[i]) return 0;
		else if(x.cnt[i]<y.cnt[i]) return 1;
	}
	return 1;
}
int check(int t,int s){
	int x=m;
	for(int i=1;i<=26;i++) a[i]=sum[t].cnt[i];
	for(int i=1;i<=26;i++) b[i]=sum[s].cnt[i];
	int tt=1,ss=26;
	while(a[tt]==0) tt++;
	while(b[ss]==0) ss--;
	if(tt<ss) return 1;
	if(tt>=ss) return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	char c=getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c=getchar();
			sum[i].cnt[c-'a'+1]++;
		}
		sum[i].num=i;
		c=getchar();
	}
	sort(sum+1,sum+n+1,cmp);
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			ans[sum[i].num]=check(1,2);
			continue;
		}
		ans[sum[i].num]=check(i,1);
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	return 0;
}
