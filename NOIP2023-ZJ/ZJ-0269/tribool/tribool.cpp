#include<bits/stdc++.h>
using namespace std;
int c,t,val[100010],n,q,pos,u,vv,ans,sum[100010],a[100010],b[100010];
vector<int>v[2];
char ch;
int op(int x){
	if(x==0)return 0;
	else if(x==-1)return -2;
	else return -1;
}
void solve1(int k){
	if(k>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(val[i]<=0)b[i]=a[i];
			else if(val[i]<=n)b[i]=a[val[i]];
			else b[i]=op(a[val[i]-n]);
			cnt+=(a[i]==0);
		}
		bool pd=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i]){
				pd=1;
				break;
			}
		if(!pd)ans=min(ans,cnt);
		return;
	}
	if(val[k]<=0){
		a[k]=val[k];
		solve1(k+1);
	}
	else if(val[k]<=n&&val[k]<k){
		a[k]=a[val[k]];
		solve1(k+1);
	}
	else if(val[k]==k+n){
		a[k]=0;
		solve1(k+1);
	}
	else if(val[k]>n&&val[k]-n<k){
		a[k]=op(a[val[k]-n]);
		solve1(k+1);
	}
	else{
		a[k]=-2;
		solve1(k+1);
		a[k]=-1;
		solve1(k+1);
		a[k]=0;
		solve1(k+1);
	}
}
void solve2(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)val[i]=i;
	while(q--){
		char ch;
		cin>>ch;
		if(ch=='U'){
			cin>>pos;
			val[pos]=0;
		}
		else{
			cin>>u>>vv;
			if(val[vv]==0)val[u]=0;
			else val[u]=vv;
		}
	}
	ans=0;
	int cnt=0;
	v[0].clear();
	v[1].clear();
	for(int i=1;i<=n;i++)
		if(val[i]==0)ans++;
		else v[0].push_back(i);
	while(1){
		cnt^=1;
		int lasans=ans;
		for(int i=0;i<v[cnt^1].size();i++){
			int p=v[cnt^1][i];
			if(val[val[p]]==0){
				ans++;
				val[p]=0;
			}
			else v[cnt].push_back(p);
		}
		v[cnt^1].clear();
		if(ans==lasans)break;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==5||c==6){
		while(t--)solve2();
		return 0;
	}
	while(t--){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)val[i]=i;
		bool pd=0;
		int qq=q;
		while(q--){
			cin>>ch;
			if(ch=='T'){
				scanf("%d",&pos);
				val[pos]=-1;
			}
			if(ch=='F'){
				scanf("%d",&pos);
				val[pos]=-2;
			}
			if(ch=='U'){
				scanf("%d",&pos);
				val[pos]=0;
			}
			if(ch=='+'){
				scanf("%d%d",&u,&vv);
				if(val[vv]<=0)val[u]=val[vv];
				else val[u]=vv;
			}
			if(ch=='-'){
				scanf("%d%d",&u,&vv);
				if(val[vv]<=0)val[u]=op(val[vv]);
				else{
					if(val[vv]<=n)val[u]=n+val[vv];
					else val[u]=val[vv]-n;
				}
			}
		}
		if(c==3||c==4){
			ans=0;
			for(int i=1;i<=n;i++)ans+=(a[i]==0);
			printf("%d\n",ans);
		}
		else{
			ans=INT_MAX;
			solve1(1);
			printf("%d\n",ans);
		}
	}
	return 0;
}
