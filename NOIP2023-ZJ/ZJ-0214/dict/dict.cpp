#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=3e3+10; 
int n,m,res[N],q[N][26],minn,minn_; 
char s[N]; 

bool cmp(int x,int y) 
{
	int t=25;
	while (t>=0)
	{
		if (q[x][t]>q[y][t]) return true; 
		if (q[x][t]<q[y][t]) return false; 
		
		t--; 
	} 	
	
	return true; 
}

bool cmp_(int x,int y) 
{
	int tx=0; while (q[x][tx]==0) tx++; 
	int ty=25; while (q[y][ty]==0) ty--;
	if (ty>tx||(tx==ty&&q[y][ty]>q[x][tx])) return false;
	
	return true; 
}

int main()
{
	freopen("dict.in","r",stdin); 
	freopen("dict.out","w",stdout); 
	
	scanf("%d%d",&n,&m); 
	
	if (n==1) 
	{	
		printf("1"); 
		fclose(stdin); fclose(stdout); 
		return 0; 
	}
	
	for (int i=1;i<=n;i++) 
	{
		scanf("%s",s); 
		
		for (int j=0;j<m;j++) 
		{
			int t=int(s[j]-'a');   
			q[i][t]++; 
		}
	}
	
	if (cmp(1,2)) minn=2,minn_=1; else minn=1,minn_=2;  
	
	for (int i=3;i<=n;i++) 
	{
		if (cmp(minn,i)) minn_=minn,minn=i; 
		else if (cmp(minn_,i)) minn_=i; 
	}
	
	for (int i=1;i<=n;i++) 
	{
		if (i==minn)
		{
			if (cmp_(i,minn_)) cout<<0; else cout<<1; 
		}
		else 
		{
			if (cmp_(i,minn)) cout<<0; else cout<<1; 
		}
	}
	
	fclose(stdin); fclose(stdout); 
	return 0; 
}




