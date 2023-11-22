#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(; isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f*x;
}
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline char readc(){
	char ch=getchar();
	for(;ch=='\n'||ch==' '||ch==EOF;ch=getchar());
	return ch;
}
const int N=1e5+10;
int n,m;
int works[N][3];
void init(){
	n=read(),m=read();
	char ch;
	for(int i=1;i<=m;i++){
		switch(readc()){
			case 'T':
				works[i][0]='T';		
				works[i][1]=read();
			break;
			case 'U':
				works[i][0]='U';		
				works[i][1]=read();
			break;
			case 'F':
				works[i][0]='F';	
				works[i][1]=read();
			break;
			case '+':
				works[i][0]='+';		
				works[i][1]=read();
				works[i][2]=read();
			break;
			case '-':
				works[i][0]='-';
				works[i][1]=read();
				works[i][2]=read();
			break;
		}
	}
}
namespace sub1{
	int s1[20];
	int s2[20];
	int ans=12;
	void dfs(int k,int u){
		if(!k){
			for(int i=1;i<=n;i++) s2[i]=s1[i];
			for(int i=1;i<=m;i++){
				switch(works[i][0]){
					case 'T':
						s2[works[i][1]]=1;
					break;
					case 'U':
						s2[works[i][1]]=2;
					break;
					case 'F':
						s2[works[i][1]]=0;
					break;
					case '+':
						s2[works[i][1]]=s2[works[i][2]];
					break;
					case '-':
						switch(s2[works[i][2]]){
							case 0:s2[works[i][1]]=1;break;
							case 2:s2[works[i][1]]=2;break;
							case 1:s2[works[i][1]]=0;break;
						}
					break;
				}
			}
			int i=1;
			for(;i<=n;i++) if(s1[i]!=s2[i]) break;
			if(i==n+1) if(ans>u) ans=u;
		}else{
			s1[k]=1;
			dfs(k-1,u);
			s1[k]=0;
			dfs(k-1,u);
			s1[k]=2;
			dfs(k-1,u+1);
		}
	}
	void clac(){
		init();
		dfs(n,0);
		write(ans);
		putchar('\n');
		ans=12;
	}
}
namespace sub2{
	int s2[100010];
	int ans=0;
	void clac(){
		init();
		for(int i=1;i<=n;i++) s2[i]=0;
		for(int i=1;i<=m;i++){
			switch(works[i][0]){
				case 'T':
					s2[works[i][1]]=1;
				break;
				case 'U':
					s2[works[i][1]]=2;
				break;
				case 'F':
					s2[works[i][1]]=0;
				break;
			}
		}
		for(int i=1;i<=n;i++) ans+=(s2[i]==2);
		write(ans);
		putchar('\n');
		ans=0;
	}
}
namespace sub3{
	int s2[100010];
	int s1[100010];
	int ans=0;
	void ty(){
		for(int i=1;i<=m;i++){
			switch(works[i][0]){
				case 'U':
					s2[works[i][1]]=2;
				break;
				case '+':
					s2[works[i][1]]=s2[works[i][2]];
				break;
			}
		}
		int i=1;
		for(;i<=n;i++) if(s1[i]!=s2[i]) break;
		if(i!=n+1) ty();
	}
	void clac(){
		init();
		for(int i=1;i<=n;i++) s2[i]=0,s1[i]=0;
		ty();
		for(int i=1;i<=n;i++) ans+=(s2[i]==2);
		write(ans);
		putchar('\n');
		ans=0;
	}
}
namespace sub4{
	int ans=0;
	void clac(){
		write(ans);
		putchar('\n');
		ans=0;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c;c=read();
	int t;t=read();
	switch(c){
		case 1:
			while(t--) sub1::clac();
		break;
		case 2:
			while(t--) sub1::clac();
		break;
		case 3:
			while(t--) sub2::clac();
		break;
		case 4:
			while(t--) sub2::clac();
		break;
		case 5:
			while(t--) sub3::clac();
		break;
		case 6:
			while(t--) sub3::clac();
		break;
		default:
			while(t--) sub4::clac(); 
	}
	return 0;
}//90