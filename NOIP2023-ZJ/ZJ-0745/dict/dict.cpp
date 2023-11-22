//      Author:WangJingze      //
//      Deep Dark Fantasy      //
#include<bits/stdc++.h>
#define re register
#define il inline 
#define u32 unsigned int 
#define u64 unsigned long long
#define ll long long 
using namespace std;
const u32 MAXN=3e3+10;
char s[MAXN][MAXN];
int mn[MAXN];
int nw[MAXN];
int mp[30];
u32 n,m;

il void Get_mn(re u32 pre){
	memset(mn,0x7f,sizeof(mn));
	for(re u32 i=1;i<=n;++i){
		if(i==pre) continue;
		re bool pd=false;
		for(re u32 j=0;j<m;++j){
			if(pd){mn[j]=s[i][j]-'a'; continue;}
			if(s[i][j]-'a'==mn[j]) continue;
			if(s[i][j]-'a'<mn[j]) {
				mn[j]=s[i][j]-'a';
				pd=true;
			}else break;
		}
	}
return;}

signed main(){
	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	scanf("%u%u",&n,&m);
	for(re u32 i=1;i<=n;++i) scanf("%s",s[i]);
	
	
	for(re u32 i=1;i<=n;++i){
		re bool flag=true;
		for(re u32 j=0;j<m;++j) ++mp[s[i][j]-'a'];	
		
		re u32 pre=0,cct=0;
		while(pre<26){
			while(mp[pre]!=0){
				nw[cct++]=pre;
				--mp[pre];
			}
			++pre;
		}
		
		Get_mn(i);
		
		//-----------------
//		puts("");
//		for(re u32 j=0;j<m;++j) printf("%d ",nw[j]); puts("");
//		for(re u32 j=0;j<m;++j) printf("%d ",mn[j]); puts("");
		//-----------------
		
		for(re u32 j=0;j<m;++j){
			if(nw[j]==mn[j]) continue;
			if(nw[j]>mn[j]){
				flag=false; break;
			}else break;
		}
			
				
			
		if(flag) printf("1");
		else printf("0");
		
	}return 0;
}
/*


4 7
abandon
bananaa
baannaa
notnotn

AFO 
Hope 80pts+

*/
