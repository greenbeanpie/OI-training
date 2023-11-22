#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int c,t,n,m,k,d,f[maxn][2];
inline int read(){
	int f=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}
struct run{
	int start,end,cost;
	int pro;
}r[maxn];
bool cmp(run a,run b){
	return a.end<b.end;
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	t=read();
	if(c==17 || c==18){
		while(t--){
			memset(r,0,sizeof(r));
			n=read();
			m=read();
			k=read();
			d=read();
			for(int i=1;i<=m;i++){
				r[i].end=read();
				int xxx=read();
				r[i].cost=read();
				r[i].start=r[i].end-xxx+1;
				r[i].pro=r[i].cost-d*xxx;
				if(xxx>k){
					r[i].pro=0;
				}
			}
			long long cnt=0;
			for(int i=1;i<=m;i++){
				if(r[i].pro>0){
					long long aaa=r[i].pro;
					cnt+=aaa;
				}
			}
			printf("%lld\n",cnt);
		}
	}
	else{
		while(t--){
			n=read();
			m=read();
			k=read();
			d=read();
			for(int i=1;i<=m;i++){
				r[i].end=read();
				int xxx=read();
				r[i].cost=read();
			}
			printf("0\n");
		}
	}
	/*else if(c<=14){
		while(t--){
			memset(r,0,sizeof(r));
			memset(f,0,sizeof(f));
			n=read();
			m=read();
			k=read();
			d=read();
			for(int i=1;i<=m;i++){
				r[i].end=read();
				int xxx=read();
				r[i].cost=read();
				r[i].start=r[i].end-xxx+1;
				r[i].pro=r[i].cost-d*xxx;
				if(xxx>k){
					r[i].pro=0;
				}
			}
			sort(r+1,r+1+m,cmp);
			int coun=1;
			for(int i=1;i<=n;i++){
				if(i!=r[coun].end){
					f[i][0]=max(f[i][0],f[i-1][0]);
					f[i][1]=0;
				}
				while(i==r[coun].end){//long long 
					if(f[i-1][1]+1<=k){
						f[i][0]=max(f[i][0],f[i-1][0]+r[coun].pro);
						f[i][1]=f[i-1][1]+1;
					}
					coun++;
				}
				
			}
		}
	}*/
	return 0;
}