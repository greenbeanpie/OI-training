#include <bits/stdc++.h>
using namespace std;
int n;//10^5
int m;//10^5
int c,t;
long long k,d,v;
long long a[100010];
// 试运行的天数 挑战的个数 大 Y 单次跑步打卡的连续天数限制 大 Y 跑步打卡减少的能量值
int x,y;
struct ve{
	int l,r,val,s;
}vo[100010];
struct st{
	int s,id;
}b[100010];
long long ff[100010],ans;
int bianli[100010];
int lowbit(int x){
	return x&(-x);
}
void add(int p,long long val){
	for(int i=p;i<=n;i+=lowbit(i)){
		a[i]+=val;
	}
}
void minu(int p,long long val){
	for(int i=p;i<=n;i+=lowbit(i)){
		a[i]-=val;
	}
}
long long Getval(int p){
	long long sum=0;
	for(int i=p;i>=1;i-=lowbit(i)){
		sum+=a[i];
	}
	return sum;
}
long long Sum(int l,int r){
	return Getval(r)-Getval(l-1);
}
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

bool cmp1(ve x,ve y){
	return x.l<y.l;
}
bool cmp2(ve x,ve y){
	return x.r<y.r;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);

	c=read(),t=read();
	while(t--){
		memset(ff,0,sizeof(ff));
		memset(a,0,sizeof(a));
		n=read(),m=read(),k=read(),d=read();
		for(int i=1;i<=m;i++){
			x=read(),y=read(),v=read();
			vo[i].l=x-y+1,vo[i].r=x,vo[i].val=v;
			add(x,v);
		}
	//	for(int i=1;i<=5;i++){
	//		int a,b;
	//		cin>>a>>b;
	//		cout<<Sum(a,b)<<endl;
	//	}
		sort(vo+1,vo+1+m,cmp1);
		for(int i=1;i<=m;i++){
			vo[i].s=i;
	//		cout<<vo[i].l<<" "<<vo[i].r<<endl;
		}
	//	puts("");
		
		sort(vo+1,vo+1+m,cmp2);
		for(int i=1;i<=m;i++){
			bianli[vo[i].s]=i;
		}
	//	for(int i=1;i<=m;i++){
	//		cout<<vo[i].l<<" "<<vo[i].r<<" "<<bianli[i]<<endl;
	//	}
		int kkk=1,i;//j<=m  bianli[k]
		for(i=1;i<=n;i++){
			ans=max(ans,ff[i-1]);
	//		cout<<i-1<<" "<<ff[i-1]<<" "<<vo[bianli[kkk]].r<<endl;//<<" "<<kkk
			if(i<vo[bianli[kkk]].l){
	//			cout<<"guo\n";
				continue;
			}
	//		cout<<"lai\n";
			int totl=i-2;
			while(totl>0&&ff[totl]==0) totl--;
			for(int j=1;vo[j].r-vo[bianli[kkk]].l+1<=k&&j<=m&&vo[j].l>=vo[kkk].l;j++){
				ff[vo[j].r]=max(ff[vo[j].r],Getval(vo[j].r)+ff[totl]-(vo[j].r-vo[bianli[kkk]].l+1)*d);
	//			cout<<"    "<<j<<" "<<vo[j].r<<" "<<Getval(vo[j].r)<<endl;
			}
			minu(vo[bianli[kkk]].r,vo[bianli[kkk]].val);
				kkk++;
				if(kkk>m) break;
				if(vo[bianli[kkk]].l==vo[bianli[kkk-1]].l)
					i--;
	//		cout<<"        "<<i<<" "<<kkk<<" "<<Getval(n)<<endl;
		}
		for(i;i<=n+1;i++){
	//		cout<<i-1<<" "<<ff[i-1]<<endl;
			ans=max(ans,ff[i-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1 1
10 6 4 2
2 3 1
2 4 5
1 3 2
6 6 1
6 8 3
8 10 7
*/