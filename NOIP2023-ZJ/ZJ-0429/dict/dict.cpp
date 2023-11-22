#include<bits/stdc++.h>
using namespace std;
const int Maxn=3010;
char s[Maxn][Maxn],s1[Maxn][Maxn],s2[Maxn][Maxn];
int mapp[Maxn][Maxn];
int cnt1[30]={0},cnt2[30]={0};
int toint(char c){
	return (int) c-'a'+1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		getchar();
		for(int j=1;j<=m;j++){
			s[i][j]=getchar();
			int k=toint(s[i][j]);
//			cout<<k<<" ";
			s1[i][j]=s2[i][j]=s[i][j];
//			cout<<s[i][j]<<endl;
			mapp[k][++cnt1[k]]=j;
			++cnt2[k];
		}
//		cout<<endl;
/*		for(int j=1;j<=m;j++)
			cout<<s1[i][j];
		cout<<endl;*/
		int  now;
		for(int i=1;i<=26;i++){
//			cout<<i<<' ';
			if(cnt1[i]>0) {
				now=i;
				break;
			}
		}
//		cout<<cnt1[now]<<endl;
		int k=cnt1[now];
		for(int j=1;j<=m;j++){
			if(cnt1[now]>0&&toint(s[i][j])!=now){
				s1[i][mapp[now][k]]=s[i][j];
				s1[i][j]=s[i][mapp[now][k]];
				break;
			} else {
				cnt1[now]--;
				if(cnt1[now]<=0) {
					for(int i=now;i<=26;i+=1){
//						cout<<i<<" ";
						if(cnt1[now]>0){
							now=i;
							k=cnt1[now];
							break;
						}
//						cout<<now<<" ";
					}
				}
			}
		}
/*		for(int j=1;j<=m;j++)
			cout<<s1[i][j];
		cout<<endl;*/
		for(int i=26;i>=1;i--){
			if(cnt2[i]>0){
				now=i;
				break;
			}
		}
		k=cnt2[now];
		for(int j=1;j<=m;j++){
			if(cnt2[now]>0&&toint(s[i][j])!=now){
				s2[i][mapp[now][k]]=s[i][j];
				s2[i][j]=s1[i][mapp[now][k]];
				break;
			} else{
				cnt2[now]--;
				if(cnt2[now]<=0){
					for(int i=now;i>=1;i--){
						if(cnt2[now]>0){
							now=i;
							k=cnt2[now];
							break;
						}
					}
				}
			}
		}
/*		for(int j=1;j<=m;j++)
			cout<<s2[i][j];
		cout<<endl;*/
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	int min1=1,min2=1;
	for(int i=2;i<=n;i++){
		int flag=1;
		for(int j=1;j<=m;j++){
			if(s2[i][j]>s2[min2][j]) break;
			if(s2[i][j]>s2[min1][j]) flag=0;
			if(s2[i][j]<s2[min2][j]){
				if(s2[i][j]<s2[min1][j]&&flag==1){
					min2=min1;
					min1=i;
//					cout<<min1<<" "<<min2<<endl;
				} else min2=i;
				break;
			}
		}
	}
/*	for(int i=1;i<=m;i++) cout<<s2[min1][i];
	cout<<endl;
	for(int i=1;i<=m;i++) cout<<s2[min2][i];
	cout<<endl;*/
	for(int i=1;i<=n;i++){
		int k=min1;
		if(min1==i) k=min2;
		for(int j=1;j<=m;j++){
			if(s1[i][j]<s2[k][j]){
				printf("1");
				break;
			}
			if(s1[i][j]>s2[k][j]){
				printf("0");
				break;
			}
		}
	}
	return 0;
}
