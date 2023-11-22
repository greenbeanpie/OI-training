#include<bits/stdc++.h>
using namespace std;
int YD[3005][30]={0},MAXN[3005],minn[3005],x2,supmin=9999,cnt1,cnt2,Next1,Next2,temp,num;
char rrr;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	memset(MAXN,-1,sizeof(MAXN));
	memset(minn,99,sizeof(minn));
	int ans[3005];
	memset(ans,0,sizeof(ans));
	if(m==1)//pian 40 fen 
	{
		int ch[3005];
		char c;
		for(int i=1;i<=n;i++)
		{
			cin>>c;	
			ch[i]=c-'a'+1;
		}
		int mann=999,cnt;
		for(int i=1;i<=n;i++)
			if(ch[i]<mann)
			{
				mann=ch[i];
				cnt=i;
			}
		ans[cnt]=1;
		for(int i=1;i<=n;i++)
			if(ans[i]!=1)
				cout<<0;
			else
				cout<<1;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>rrr;
				temp=rrr-'a'+1;
				YD[i][temp]++;
				if(temp>MAXN[i])
					MAXN[i]=temp;
				if(temp<minn[i])
					minn[i]=temp; 
			}
			if(MAXN[i]<supmin)
			{
				supmin=MAXN[i];
				x2=i;
			}
		}
		for(int i=1;i<=n;i++){
			cnt1=minn[i],cnt2=MAXN[x2];
			if(i==x2)
				cout<<1;
			else{
				if(cnt1<cnt2)
					cout<<1;
				else
					cout<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}