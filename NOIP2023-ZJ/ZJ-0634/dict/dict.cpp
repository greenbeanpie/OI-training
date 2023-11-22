#include<bits/stdc++.h>
using namespace std;
inline int read() {char c=getchar();int res=0,b=1;while(!isdigit(c)) {if(c=='-') b=-1;c=getchar();}while(isdigit(c)) {res=res*10+(c^48);c=getchar();}return res*b;}
inline void write(int x) {if(x<0) putchar('-'),x=-x;if(x>9) {write(x/10);putchar(x%10+'0');} else {putchar(x+'0');}}
inline bool print(int x) {write(x);putchar(' ');return 0;}inline bool put(int x) {write(x);putchar('\n');return 0;}
int n,m;
char s[3005][3005],s0[3005][3005],mn[3005];
char mx[3005][3005];
namespace sub1{
	int main(){
		printf("%d",1);
		return 0;
	}
}
namespace sub2{
	inline bool xy(char a[],char b[]){
		for(int i=1;i<=m;++i){
			//cout<<a[i]<<" "<<b[i]<<endl;
			if(a[i]==b[i]) continue;
			return a[i]<b[i]?1:0;
		}
		return 0;
	}
	inline bool dy(char a[],char b[]){
		for(int i=1;i<=m;++i){
			if(a[i]==b[i]) continue;
			return 0;
		}
		return 1;
	}
	int sz[45],sta[45],ed[45];
	int flag=1;
	inline int main(){
		mn[1]='z'+1;
		for(int i=1;i<=n;++i)
		{
			for(int i=0;i<=44;++i) sz[i]=ed[i]=sta[i]=0;
			for(int j=1;j<=m;++j){
				sz[s[i][j]-'a'+1]++;
			}
			for(int j=26;j>=1;--j){
				ed[j]=ed[j+1]+sz[j];
			}
			for(int j=1;j<=m;++j){
				mx[i][ed[s[i][j]-'a'+1]--]=s[i][j];
			}
			if(xy(mx[i],mn)){
				for(int j=1;j<=m;++j){
					mn[j]=mx[i][j];
				}
				flag=1;
			}
			else if(dy(mx[i],mn)){
				flag=0;
			}
			for(int j=1;j<=26;++j){
				sta[j]=sta[j-1]+sz[j];
			}
			for(int j=1;j<=m;++j){
				s0[i][sta[s[i][j]-'a'+1]--]=s[i][j];
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(xy(s0[i],mn))printf("%d",1);
			else {
				if(dy(s0[i],mn)&&dy(s0[i],mx[i])){
					printf("%d",flag);
				}
				else printf("%d",0);	
			}
		}
		return 0;
	}
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
	}
	if(n==1){
		sub1::main();
	}
	else {
		sub2::main();
	}
	return 0;
}