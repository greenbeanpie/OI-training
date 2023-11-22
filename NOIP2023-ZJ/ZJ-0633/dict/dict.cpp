#include<bits/stdc++.h>
#define ll long long
#define MAXN 30005
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m;
int a[MAXN],alpb[MAXN][30];
string sup[MAXN],sdown[MAXN];
bool cmpdown(int x,int y){
	return x>y;
}
bool cmpup(int x,int y){
	return x<y;
}
char s[3505];
int main(){
	memset(alpb,0,sizeof(alpb));
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("1\n");
		return 0;
	}
	if(n<=300){
		rep(i,1,n){
			string s;cin>>s;
			rep(j,0,m-1)
				a[j+1]=(int)s[j]-'a';
			sort(a+1,a+1+m,cmpup);
			rep(j,1,m)
				sup[i]+=(char)(a[j]+'a');
			sort(a+1,a+1+m,cmpdown);
			rep(j,1,m)
				sdown[i]+=(char)(a[j]+'a');
		}
		rep(i,1,n){
			int flag=0;
			rep(j,1,n){
				if(i==j)continue;
				if(sdown[j]<sup[i]){
					flag=1;
					break;
				}
			}
			if(flag)printf("0");
			else printf("1");
		}
	}
	else{
		rep(i,1,n){
			scanf("%s",&s);
			rep(j,0,m-1)
				alpb[i][s[j]-'a']++;
		}
		rep(i,1,n){
			int flag=0;
			rep(j,1,n){
				if(i==j)continue;
				int sti=0,stj=25;
				while(!alpb[i][sti])sti++;
				while(!alpb[j][stj])stj--;
				if(sti<stj);
				else if(sti>stj){
					flag=1;
					break;
				}
				else{
					if(alpb[i][sti]>alpb[j][stj]);
					else{
						flag=1;
						break;
					}
				}
			}
			if(!flag)printf("1");
			else printf("0");
		}
	}
	return 0;
}
