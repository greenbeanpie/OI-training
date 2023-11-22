#include<bits/stdc++.h>

using namespace std;

const int N=500005;

inline int read(){
	int t=1,x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') t=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return t*x;
}

int c,n,m,q;
int x[N],y[N],a[N],b[N];
int cnta[N],cntb[N];
int tota,totb;
int flagl;
int len;

bool check(){
	int pd=1;
	int ok=0;
	if(cnta[1]-cntb[1]<0) ok=-1;
	else ok=1;
	for(int i=1;i<=len;i++){
		if(cnta[i]==cntb[i]) return 0;
		if((cnta[i]-cntb[i])/abs(cnta[i]-cntb[i])!=ok) return 0;
	}
	return 1;
}

void dfs(int x){
	if(flagl) return ;
	if(x>n+m){
		len=max(tota,totb);
		if(tota<len) for(int i=tota+1;i<=len;i++) cnta[i]=a[n];
		if(totb<len) for(int i=totb+1;i<=len;i++) cntb[i]=b[m];
		if(check()) flagl=1;
		return ;
	}
	if(x<=n){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=i;j++) cnta[++tota]=a[x];
			dfs(x+1);
			tota-=i;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++) cntb[++totb]=b[x-n];
			dfs(x+1);
			totb-=i;
		}
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	for(int i=1;i<=m;i++){
		y[i]=read();
	}
	for(int o=1;o<=q+1;o++){
		for(int i=1;i<=n;i++) a[i]=x[i];
		for(int i=1;i<=m;i++) b[i]=y[i];
		if(o!=1){
			int lena=read(),lenb=read();
			while(lena--){
				int loc=read(),val=read();
				a[loc]=val;
			}
			while(lenb--){
				int loc=read(),val=read();
				b[loc]=val;
			}
		}
		if(n==1 && m==1){
			if(a[1]>b[1]) cout<<"1";
			else cout<<"0";
			continue;
		}
		if(n==1 && m==2){
			if(a[1]>b[1] && a[1]>b[2]) cout<<"1";
			else if(a[1]<b[1] && a[1]<b[2]) cout<<"1";
			else cout<<"0";
			continue;
		}
		if(n==2 && m==1){
			if(a[1]>b[1] && a[2]>b[1]) cout<<"1";
			else if(a[1]<b[1] && a[2]<b[1]) cout<<"1";
			else cout<<"0";
			continue;
		}
		if(n==2 && m==2){
			if(a[1]>b[1] && a[2]>b[2]) cout<<"1";
			else if(a[1]<b[1] && a[2]<b[2]) cout<<"1";
			else cout<<"0";
			continue;
		}
		if(n<=6 && m<=6){
			flagl=0;
			dfs(1);
			cout<<flagl;
			continue;
		}
		if(a[1]<b[1]){
			if(a[n]>=b[m]) cout<<"0";
			else{
				int l=1,r=1;
				int flag=1;
				while(l<=n && r<=m){
					if(a[l]<b[r]) l++;
					else r++;
				}
				while(l<=n){
					if(a[l]>=b[m]){
						flag=0;
						break;
					}
					else l++;
				}
				while(r<=m){
					if(a[n]>=b[r]){
						flag=0;
						break;
					}
					else r++;
				}
				cout<<flag;
			}
		}
		else if(a[1]>b[1]){
			if(a[n]<=b[m]) cout<<"0";
			else{
				int l=1,r=1;
				int flag=1;
				while(l<=n && r<=m){
					if(a[l]>b[r]) l++;
					else r++;
				}
				while(l<=n){
					if(a[l]<=b[m]){
						flag=0;
						break;
					}
					else l++;
				}
				while(r<=m){
					if(a[n]<=b[r]){
						flag=0;
						break;
					}
					else r++;
				}
				cout<<flag;
			}
		}
		else cout<<"0";
	}
	return 0;
}
