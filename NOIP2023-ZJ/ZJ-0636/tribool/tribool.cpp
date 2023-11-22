#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,i,j,minn=10005;
bool flag=false,recg[10005];
char v;
int a[10005],b[10005];
struct mingling{
	char leixing;
	int shou,gei;
}ling[10005];


void add()
{
	a[n]++;
	for(int x=n;x>=1;x++)
	if(a[x]>2) {
		a[x]=0;a[x-1]++;//zuihouyici,tepan,biebaole!!!
	}
	else break;
}
int qufou(int asdf)
{
	if(b[asdf]==1)return 0;
	if(b[asdf]==0)return 1;
	if(b[asdf]==2)return 2;
}
void zhixing(int th)
{
	if(ling[th].leixing=='+') {b[ling[th].shou]=b[ling[th].gei];}
	if(ling[th].leixing=='-') {b[ling[th].shou]=qufou(ling[th].gei); }
	if(ling[th].leixing=='T') b[ling[th].shou]=1;
	if(ling[th].leixing=='F') b[ling[th].shou]=0;
	if(ling[th].leixing=='U') b[ling[th].shou]=2;
}
int suanshu(int zhishu)
{
int jieguo=1;
	for(int x=1;x<=zhishu;x++)
	jieguo*=3;
	return jieguo;
}


bool check()
{
	for(int x=1;x<=n;x++)
	if(a[x]!=b[x]) return false;
	
	
	flag=true;return true;
}

int tongji()
{
int cnt=0;
	for(int x=1;x<=n;x++)
	{
		if(a[x]==2) cnt++;
	}
   
	return cnt;
}

int meiju()
{

	for(int x=1;x<=m;x++)
	{	
	zhixing(x);
	}
	if(check()) {flag=true;return tongji();}
	else return 10010;
}


int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    cin>>c>>t;
    
   if(c>=1&&c<=2)
    {for(int x=1;x<=t;x++)
		{cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		flag=false;
		for(int y=1;y<=m;y++)
		 {
			cin>>ling[y].leixing;
			if(ling[y].leixing=='-'||ling[y].leixing=='+') {cin>>ling[y].shou;cin>>ling[y].gei;}
			else cin>>ling[y].shou;
		 }//OK
		
		for(int xxx=1;xxx<suanshu(n);xxx++)	
		{for(int y=1;y<=n;y++) b[y]=a[y];
		  minn=min(meiju(),minn);
		add();
		}
		if(!flag) minn=n;
		cout<<minn<<endl;
		
		}
	}
	
	if(c>=3&&c<=4)
	{
		for(int x=1;x<=t;x++)
		{
			memset(recg,false,sizeof(recg));
		int num=0;
		cin>>n>>m;
		for(int y=1;y<=m;y++)
		 {
			cin>>ling[y].leixing;
		    cin>>ling[y].shou;
			
		 }
		 for(int y=1;y<=m;y++)
		 {
			if(ling[y].leixing=='U') recg[ling[y].shou]=true;
		    else recg[ling[y].shou]=false;
		 }
		 for(int y=1;y<=n;y++)
		 {
		 	if(recg[y]==true)
		 	num++;
		 }
		 cout<<num<<endl;
	    }
	}
	


	return 0;
}
