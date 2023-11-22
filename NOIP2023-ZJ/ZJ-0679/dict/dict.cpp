#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[3050];
char s[3050];
int w[3050][30];
int nim[30];
bool cf=0;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		char a[30];
		int cnt=0;
		int cp='z'+1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<cp){
				cp=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==cp){
				vis[i]=1;
				cnt++;
			}
		}
		if(cnt>1){
			for(int i=1;i<=n;i++){
				printf("%d",0);
			}	
		}
		else{
			for(int i=1;i<=n;i++){
				printf("%d",vis[i]);
			}	
		}
	}
	else{
		int pos;
		nim[26]=3333;
		for(int k=1;k<=n;k++){
			scanf("%s",&s);
			for(int i=0;i<m;i++){
				w[k][s[i]-'a'+1]++;
			}
			int flag1=0;
			for(int i=26;i>=1;i--){
				if(nim[i]>0||w[k][i]>0){
					if(nim[i]>w[k][i]){
						flag1=2;
						break;
					}
					else if(w[k][i]>nim[i]){
						flag1=1;
						break;
					}
				}
			}
			if(flag1==2){
				cf=0;
				pos=k;
				for(int i=26;i>=1;i--){
					nim[i]=w[k][i];
				}
			}
			if(flag1==0){
				cf=1;
			}
		}
		for(int k=1;k<=n;k++){
			bool flag2=0;
			int cnt1=1,cnt2=26;
			while(w[k][cnt1]==0){
				cnt1++;
			}
			while(nim[cnt2]==0){
				cnt2--;
			}
			if(cnt1>=cnt2){
				flag2=0;
			}
			else if(cnt1<cnt2){
				flag2=1;
			}
			if(flag2){
				vis[k]=1;
			}
		}
		if(cf==0){
			vis[pos]=1;
		}
		for(int i=1;i<=n;i++){
			printf("%d",vis[i]);
		}
	}
	return 0;
}
