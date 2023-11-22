#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int MAXN = 3e3+7;
const int MAXM = 5e6+7;
inline read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m;
char s[MAXN][MAXN];
int tmp[30];
char tmps[MAXN];
struct trie{
	int cnt,nxt[MAXM][30],id[MAXN];
	int mn[MAXM];
	void insert(char* s,int idx){
		int len = strlen(s+1),j=0;
		up(i,1,len){
			int num = s[i]-'a';
			if(!nxt[j][num]){
				nxt[j][num]=++cnt;
				if(mn[j]==0)
					mn[j]=num+1;
				else 
					mn[j]=min(mn[j],num+1);	
			}
			j=nxt[j][num];
		//	printf("%lld\n",j);
		}
		id[idx] = j;
		return ;
	}
	bool query(char *s,int idx){
		int len = strlen(s+1),j=0;
		up(i,1,len){
			int num = s[i]-'a';
			if(mn[j]<num+1)return 0;
			else if(mn[j]>num+1)return 1;
			else{
				j=nxt[j][num];
			}
			
		}
		if(id[idx]==j)return 1;
		return 0;		
	}
}T;
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	if(n==1)printf("1");
	up(i,1,n){
		scanf("%s",s[i]+1);
		T.insert(s[i],i);
	}
	up(i,1,n){
		up(j,1,m)tmp[s[i][j]-'a']++;
		int cnt=0;
		up(j,0,25){
			while(tmp[j]){
				tmps[++cnt]='a'+j;
				tmp[j]--;
			}
		}
		printf("%lld",(int)T.query(tmps,i));
		memset(tmp,0,sizeof(tmp));
	}
	return 0;
}

