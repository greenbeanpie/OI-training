#include<bits/stdc++.h>
using namespace std;
int q,n,m,s,x,y,b[100010],flag,a[100010];
char opt;
struct node {
	int val,num;
} c[100010];
int read() {
	int x=0,f=1;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if (ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-48;
	return x*f;
}
void qinkong() {
	for(int i=0; i<=n; i++) a[i]=i;
	a[100001]=100001;
	return;
}
int pd(int x){
	if (x<0) x=-x;
	return x;
}
bool cmp(node a,node b){
	return pd(a.val)<pd(b.val);
}
/*int pd(int x,int s) {
	if (a[x]==0&&s==0) return 0;
	if (a[x]==1&&s==1) return 0;
	return 1;
}*/
/*int find(int x,int s) {
	if (a[x].val==x&&s==0) return x;
	else if (a[x].val==x&&s==1) return -x;
	else a[x].val=find(a[x].val,pd(a[x].pd,s));
	if (s==0)  return a[x].val;
	else if (s==1) return -a[x].val;
}*/
int find1(int x) {
	if (b[x]==x) return x;
	return b[x]=find1(b[x]);
}
signed main() {//si hu shi bing cha ji why I don't have zhongwen shuru fa.
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	q=read();
	if (q==1||q==2||q==7||q==8||q==9||q==10) {
		for(int T=read(); T; T--) {
			s=0;
			n=read();
			m=read();
			qinkong();
			for(int i=1; i<=m; i++) {
				scanf("%c",&opt);
				if (opt=='-') {
					x=read();
					y=read();
					a[x]=-a[y];

				} else if (opt=='+') {
					x=read();
					y=read();
					a[x]=a[y];
				} else if (opt=='T') {
					x=read();
					a[x]=100001;
				} else if (opt=='F') {
					x=read();
					a[x]=-100001;
				} else if (opt=='U') {
					x=read();
					a[x]=0;
				}
			}
			for(int i=1; i<=n; i++) {
				c[i].val=a[i],c[i].num=i;
				if (a[i]==-i) a[i]=0;
			}
			sort(c+1,c+1+n,cmp);
			for(int i=1; i<=n; i++) if (a[pd(a[c[i].num])]==0) s++,a[c[i].num]=0; //,printf("%d %d \n",i,c[i].num);
			printf("%d\n",s);
		}
		return 0;
	}
	if (q==3||q==4) {
		for(int T=read(); T; T--) {
			s=0;
			n=read();
			m=read();
			for(int i=1; i<=n; i++) b[i]=i;
			for(int i=1; i<=m; i++) {
				scanf("%c",&opt);
				if (opt=='T') {
					x=read();
					b[x]=100001;
				} else if (opt=='F') {
					x=read();
					b[x]=-100001;
				} else if (opt=='U') {
					x=read();
					b[x]=0;
				}
			}
			for(int i=1; i<=n; i++) if (b[i]==0) s++;
			printf("%d\n",s);
		}
		return 0;
	}
	if(q==5||q==6) {
		for(int T=read(); T; T--) {
			s=0;
			n=read();
			m=read();
			for(int i=0; i<=n; i++) b[i]=i;
			for(int i=1; i<=m; i++) {
				scanf("%c",&opt);
				if (opt=='+') {
					x=read();
					y=read();
					b[x]=find1(y);
				} else if (opt=='U') {
					x=read();
					b[x]=0;
				}
			}
			for(int i=1; i<=n; i++) if (b[find1(i)]==0) s++;
			printf("%d\n",s);
		}
		return 0;
	}
	/*	for(int T=read(); T; T--) {
			s=0;
			n=read();
			m=read();
			qinkong();
			for(int i=1; i<=m; i++) {
				scanf("%c",&opt);
				if (opt=='-') {
					x=read();
					y=read();
					a[x].pd=-a[x].pd;
					if (find(y,a[x].pd)<0)
						a[x].val=a[-find(y,a[x].pd)].val*(-1);
					else a[x].val=a[find(y,a[x].pd)].val;

				} else if (opt=='+') {
					x=read();
					y=read();
	//				if (x==y) continue;
					a[x].val=a[find(y,a[x].pd)].val;
				} else if (opt=='T') {
					x=read();
					a[x].val=100001;
				} else if (opt=='F') {
					x=read();
					a[x].val=-100001;
				} else if (opt=='U') {
					x=read();
					a[x].val=0;
				}
			}
			for(int i=1; i<=n; i++) {
				int fy=find(a[i].val,a[x].pd);
				if (a[fy].pd>0) {
					a[i].pd=1;
				} else {
					a[i].pd=0;
				}
				a[i].val=a[fy].val;
			}
			/*for(int i=1;i<=n;i++) {
				c[i].val=a[i],c[i].num=i;
				int fx=find(i),fy=find(pd(a[i]));
				if (a[i]==-i) a[i]=0;
				else
				if (fx==fy) a[fx]=a[fy];
			//			if (a[i]==-i) a[i]=0;
			//			if (a[pd(a[i])]==0) a[i]=0;
			}
			//		sort(c+1,c+1+n,cmp);
			//		for(int i=1;i<=n;i++) if (a[pd(a[c[i].num])]==0) s++,a[c[i].num]=0;//,printf("%d %d \n",i,c[i].num);
	//	*/	//for(int i=1; i<=n; i++) if (a[find(i,a[i].pd)].val==0) s++;
//		printf("%d\n",s);
//	}
	return 0;
}

