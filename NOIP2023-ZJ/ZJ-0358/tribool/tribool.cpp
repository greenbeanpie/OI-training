#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int c,t,n,m,a[maxn],b[maxn][3];
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

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	t=read();
	if(c==3 || c==4){
		while(t--){
			int cnt=0;
			memset(a,0,sizeof(a));
			n=read();
			m=read();
			while(m--){
				char v;
				int xx;
				cin>>v>>xx;
				if(v=='U'){
					a[xx]=-1;
				}
				else if(v=='T'){
					a[xx]=1;
				}
				else{
					a[xx]=0;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==-1){
					cnt++;
				}
			}
			printf("%d\n",cnt);
		}
	}
	else if(c==5 || c==6){
		while(t--){
			map<int,int> mp;
			int cnt=0;
			n=read();
			m=read();
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for(int i=1;i<=m;i++){
				char v;
				int xx,yy;
				cin>>v>>xx;
				if(v=='U'){
					a[xx]=-1;
				}
				else{
					cin>>yy;
					b[i][0]=xx;
					b[i][1]=yy;
					a[xx]=a[yy];
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==-1){
					cnt++;
				}
			}
			for(int i=1;i<=m;i++){
				if(b[i][0]==0 || b[i][1]==0){
					continue;
				}
				if(a[b[i][0]]==-1 && a[b[i][1]]!=-1){
					a[b[i][0]]=0;
					if(mp[b[i][0]]){
						mp[b[i][0]]=0;
						cnt--;
					}
				}
				if(a[b[i][0]]!=-1 && a[b[i][1]]==-1){
					a[b[i][0]]=-1;
					mp[b[i][0]]=1;
					cnt++;
				}
			}
			printf("%d\n",cnt);
		}
	}
	else if(c<=2){
		while(t--){
			n=read();
			m=read();
			memset(b,0,sizeof(b));
			for(int i=1;i<=m;i++){
				char v;
				int xx,yy;
				cin>>v>>xx;
				if(v=='U'){
					b[i][1]=xx;
					b[i][2]=0;
				}
				else if(v=='T'){
					b[i][1]=xx;
					b[i][2]=1;
				}
				else if(v=='F'){
					b[i][1]=xx;
					b[i][2]=-1;
				}
				else{
					cin>>yy;
					b[i][0]=xx;
					b[i][1]=yy;
					if(v=='+'){
						b[i][2]=1;
					}
				}
			}
			int minn=11;
			int cnr=1;
			for(int i=1;i<=n;i++){
				cnr*=3;
			}
			for(int jj=0;jj<cnr;jj++){
				int tt=jj,cc[15],ccc[15],cntt=0;
				memset(cc,0,sizeof(cc));
				memset(ccc,0,sizeof(ccc));
				while(tt){
					cc[++cc[0]]=tt%3-1;
					ccc[++ccc[0]]=tt%3-1;
					tt/=3;
				}
				for(int i=1;i<=m;i++){
					if(b[i][1]==0){
						continue;
					}
					else{
						if(b[i][0]==0){
							cc[b[i][1]]=b[i][2];
						}
						else if(b[i][2]==1){
							cc[b[i][0]]=cc[b[i][1]];
						}
						else{
							cc[b[i][0]]=0-cc[b[i][1]];
						}
					}
				}
				int flag11=1;
				for(int i=1;i<=n;i++){
					if(cc[i]!=ccc[i]){
						flag11=0;
						break;
					}
				}
				if(flag11){
					for(int i=1;i<=n;i++){
						if(cc[i]==0){
							cntt++;
						}
					}
					if(cntt<minn){
						minn=cntt;
					}
				}
			}
			printf("%d\n",minn);
		}
	}
	else{
		while(t--){
			n=read();
			m=read();
			for(int i=1;i<=m;i++){
				char v;
				int xx,yy;
				cin>>v>>xx;
				if(v=='+' || v=='-'){
					cin>>yy;
				}
			}
			printf("%d\n",n);
		}
	}
	return 0;
}