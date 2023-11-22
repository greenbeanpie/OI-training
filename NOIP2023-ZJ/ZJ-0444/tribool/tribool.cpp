#include <bits/stdc++.h>
using namespace std;
#define wr(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
const int N=114514;
int read(){
	int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int c,t;
int n,m;
int ans;
int com[N][3];

char change(char s){
	if(s=='0') return '1';
	if(s=='1') return '0';
	return '2';
}

void dfs(int pos,int sum,string s){
    if(pos==n+1){
    	string ori_s=s;
		wr(i,1,m){
			if(com[i][0]==1){
				s[com[i][1]]='1';
			}
			if(com[i][0]==0){
				s[com[i][1]]='0';
			}
			if(com[i][0]==2){
				s[com[i][1]]='2';
			}
			if(com[i][0]==3){
				s[com[i][1]]=s[com[i][2]];
			}
			if(com[i][0]==4){
				s[com[i][1]]=change(s[com[i][2]]);
			}
		}	
		if(s==ori_s) ans=min(ans,sum);
		return;
	}
	dfs(pos+1,sum,s+"0");
	dfs(pos+1,sum,s+"1");
	dfs(pos+1,sum+1,s+"2");
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	if(c==1||c==2){
		while(t--){
			n=read(),m=read();
			ans=n+1;
			int x,y;
			char ch;
			wr(i,1,m){
				cin>>ch;
				x=read();
				if(ch=='T'){
					com[i][0]=1;
					com[i][1]=x;
				}
				if(ch=='F'){
					com[i][0]=0;
					com[i][1]=x;
				}
				if(ch=='U'){
					com[i][0]=2;
					com[i][1]=x;
				}
				if(ch=='+'){
					y=read();
					com[i][0]=3;
					com[i][1]=x;
					com[i][2]=y;
				}
				if(ch=='-'){
					y=read();
					com[i][0]=4;
					com[i][1]=x;
					com[i][2]=y;
				}
		    }	
			dfs(1,0," ");
			cout<<ans<<endl;
		}
	}
	if(c==3||c==4){
		while(t--){
			n=read(),m=read();
			int x;
			char ch;
			int a[N];
			ans=0;
			wr(i,1,m){
				cin>>ch;
				x=read();
				if(ch=='T'){
					a[x]=1;
				}
				if(ch=='F'){
					a[x]=0;
				}
				if(ch=='U'){
					a[x]=2;
				}
			}
			wr(i,1,n){
				if(a[i]==2) ans++;
			}
			cout<<ans<<endl;
		}
	}
	if(c==5||c==6){
		while(t--){
			n=read(),m=read();
			int x,y;
			char ch;
			int a[N];
			ans=0;
			wr(i,1,m){
				cin>>ch;
				x=read();
				if(ch=='U'){
					a[x]=2;
				}
				if(ch=='+'){
					y=read();
					a[x]=a[y];
				}
			}
			wr(i,1,n){
				if(a[i]==2) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
5 1
4 4 
+ 2 1
U 2
+ 3 2
+ 4 2
*/