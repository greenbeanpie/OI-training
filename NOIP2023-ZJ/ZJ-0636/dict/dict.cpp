#include<bits/stdc++.h>
using namespace std;
int n,m,ans[3005];
string w[3005];
/*struct ccc{
priority_queue<char> zhenchuan;	
}cc[3005];*/

/*priority_queue<char,vector<int>,greater<int> > beibizhe;*/

long long read()
{
	long long x=0;int w=1;
	char ch='0';
	
		ch=getchar();

	while(ch>='0'&&ch<='9')
	{
	x=x*10+(ch-'0');
		ch=getchar();
	}
	return (long long)x*w;
}
void solve_1()
{
int mi_n=99999;
	for(int i=1;i<=n;i++)
	{
		if(w[i][0]<mi_n) mi_n=w[i][0];
	}
	for(int i=1;i<=n;i++)
	if(w[i][0]!=mi_n) ans[i]=0;
	else ans[i]=1;
}

bool ch_eck1(int i)
{
	bool fla=true;
		for(int j=1;j<=n;j++)
	{
    if(j==i) continue;
	if(w[j][0]<=w[i][0]&&w[j][1]<=w[i][0]&&w[j][0]<=w[i][1]&&w[j][1]<=w[i][1])
	 {
		fla=false;break;
	}else continue;
    }   
	return fla;

}

void solve_2()
{
	for(int i=1;i<=n;i++)
	{
		if(ch_eck1(i)) ans[i]=1;
		else ans[i]=0;
	}	
	
}
/*bool ch_eck2(i)
{
	
}
void solve_3()
{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<m;j++)
			cc.zhenchuan.push(w[i][j]);
		}
		
		
		for(int i=1;i<=n;i++)
	{
	
		
		if(ch_eck2(i)) ans[i]=1;
		else ans[i]=0;
	}	
}*/
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
   if(m==1){
   	if(n==1) {cout<<1;return 0;}
   	else{
   	solve_1();
   	for(int i=1;i<=n;i++) cout<<ans[i];return 0;
   	    }
   }
   else{
   	 if(m==2) 
	 {solve_2();for(int i=1;i<=n;i++) cout<<ans[i];return 0;}
   	 
	 else{
   	    /*solve_3();*/
   	 	for(int i=1;i<=n;i++) cout<<ans[i];return 0;
		}
   }
	return 0;
}
