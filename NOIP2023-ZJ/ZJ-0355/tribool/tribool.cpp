#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re(i,a,b) for(int i=(a);i<=(b);i++)
int c,t,n,m;
tuple<char,int,int> op[100005];
il int read(){
	char c=getchar();
	int ret=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
il char read_c(){
	char c=getchar();
	while(c!='T'&&c!='F'&&c!='U'&&c!='+'&&c!='-'){
		c=getchar();
	}
	return c;
}
namespace algo1{
	int ans=0x7fffffff,cnt_u=0;
	char ori[15],fin[15];
	il char opp(char c){
		switch(c){
			case 'T':
				return 'F';
			case 'F':
				return 'T';
			case 'U':
				return 'U';
		}
		return 'U';
	}
	il bool check(){
		re(i,1,n){
			if(ori[i]!=fin[i])return false;
		}
		return true;
	}
	void dfs(int dep){
		if(dep>n){
			memcpy(fin,ori,sizeof(ori));
			re(i,1,m){
				char o=get<0>(op[i]);
				int di=get<1>(op[i]),dj=get<2>(op[i]);
				switch(o){
					case '+':
						fin[di]=fin[dj];
						break;
					case '-':
						fin[di]=opp(fin[dj]);
						break;
					default:
						fin[di]=o;
						break;
				}
			}
			if(!check())return;
			ans=min(ans,cnt_u);
			return;
		}
		if(cnt_u>=ans)return;
		ori[dep]='T';
		dfs(dep+1);
		ori[dep]='F';
		dfs(dep+1);
		ori[dep]='U';
		cnt_u++;
		dfs(dep+1);
		cnt_u--;
	}
	il void run(){
		cnt_u=0;
		ans=0x7fffffff;
		dfs(1);
		printf("%d\n",ans);
	}
}
namespace algo2{
	char fin[100005];
	il void run(){
		memset(fin,0,sizeof(fin));
		re(i,1,m){
			fin[get<1>(op[i])]=get<0>(op[i]);
		}
		int ans=0;
		re(i,1,n){
			if(fin[i]=='U')ans++;
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	re(round,1,t){
		n=read(),m=read();
//		printf("n=%d\n",n);
		re(i,1,m){
			get<0>(op[i])=read_c();
			get<1>(op[i])=read();
			if(get<0>(op[i])=='+'||get<0>(op[i])=='-'){
				get<2>(op[i])=read();
			}
		}
		if(c<=2)algo1::run();
		else if(c==3||c==4)algo2::run();
		else algo1::run();
	}
	return 0;
}
