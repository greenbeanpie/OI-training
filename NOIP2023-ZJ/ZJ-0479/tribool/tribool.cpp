#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t;
int kkk[200];
struct subtask1{
	int pow(int x,int y){
		int res=1;
		for(int i=1;i<=y;i++) res*=x;
		return res;
	}
	char op[20];
	int a[20],b[20],n,m;
	int check(int x){
		int temp[20],s[20],cnt=n;
		memset(temp,0,sizeof(temp));
		memset(s,0,sizeof(s));
		while(x){
			s[cnt]=temp[cnt]=x%3;
			x/=3;cnt--;
		}
		for(int i=1;i<=m;i++){
			if(op[i]=='-'){
				if(temp[b[i]]==2) temp[a[i]]=2;
				else temp[a[i]]=temp[b[i]]^1;
			}else if(op[i]=='+') temp[a[i]]=temp[b[i]];
			else temp[a[i]]=kkk[op[i]];
		}
		int res=0;
		for(int i=1;i<=n;i++){
			res+=(temp[i]==2);
			if(s[i]!=temp[i]) return 1<<28;
		}
		return res;
	}
	void work(){
		while(t--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>op[i];scanf("%d",&a[i]);
				if(op[i]=='-'||op[i]=='+') scanf("%d",&b[i]);
			}
			int ans=1<<28;
			for(int i=0;i<pow(3,n);i++) ans=min(ans,check(i));
			printf("%d\n",ans);
		}
	}
}S1;
struct subtask2{
	char op;
	int a,b,n,m,temp[N];
	void work(){
		while(t--){
			memset(temp,0,sizeof(temp));
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>op;scanf("%d",&a);
				if(op=='-'||op=='+') scanf("%d",&b);
				else temp[a]=kkk[(int)op];
			}
			int ans=0;
			for(int i=1;i<=n;i++) ans+=(temp[i]==2);
			printf("%d\n",ans);
		}
	}
}S2;
struct subtask3{
	char op[N];
	int a[N],b[N],n,m,temp[N];
	void work(){
		while(t--){
			memset(temp,0,sizeof(temp));
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>op[i];scanf("%d",&a[i]);
				if(op[i]=='+'){
					scanf("%d",&b[i]);
					temp[a[i]]=temp[b[i]];
				}
				else temp[a[i]]=kkk[(int)op[i]];
			}
			int last=0;
			while(1){
				for(int i=1;i<=m;i++){
					if(op[i]=='+'){
						temp[a[i]]=temp[b[i]];
					}
					else temp[a[i]]=kkk[(int)op[i]];
				}
				int ans=0;
				for(int i=1;i<=n;i++) if(temp[i]==2) ans++;
				if(last==ans) break;
				last=ans;
			}
			printf("%d\n",last);
		}
	}
}S3;
struct subtask4{
	char op[N];
	int a[N],b[N],n,m,temp[N];
	void work(){
		while(t--){
			memset(temp,-1,sizeof(temp));
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>op[i];scanf("%d",&a[i]);
				if(op[i]=='+'){
					scanf("%d",&b[i]);
					temp[a[i]]=temp[b[i]];
				}
				if(op[i]=='-'){
					scanf("%d",&b[i]);
					temp[a[i]]=(temp[b[i]]==2||temp[b[i]]==-1)?temp[b[i]]:temp[b[i]]^1;
				}
				else temp[a[i]]=kkk[(int)op[i]];
			}
			int last=0;
			while(1){
				for(int i=1;i<=m;i++){
					if(op[i]=='+'){
						temp[a[i]]=temp[b[i]];
					}
					if(op[i]=='-'){
						temp[a[i]]=(temp[b[i]]==2||temp[b[i]]==-1)?temp[b[i]]:(temp[b[i]]^1);
					}
					else temp[a[i]]=kkk[(int)op[i]];
				}
				int ans=0;
				for(int i=1;i<=n;i++) if(temp[i]==2) ans++;
				if(last==ans) break;
				last=ans;
			}
			printf("%d\n",last);
		}
	}
}S4;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	kkk[(int)'F']=0;kkk[(int)'T']=1;kkk[(int)'U']=2;
	scanf("%d%d",&c,&t);
	if(c==1||c==2)
		S1.work();
	else if(c==3||c==4)
		S2.work();
	else if(c==5||c==6)
		S3.work();
	else S4.work();
	return 0;
}
/*
3 1
10 10
U 1
F 1
T 2
F 2
F 3
U 3
U 4
F 1
T 4
U 5
*/
