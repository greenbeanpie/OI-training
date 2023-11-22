#include<bits/stdc++.h>
#define ll long long 
#define UF(i,x,y) for(int i=x;i<=y;i++)
#define DF(i,x,y) for(int i=x;i>=y;i--)
#define ce continue
#define inf 0x7fffffff
#define N 100005
using namespace std;
int n,m,k,d,c,T,ans;
bool b[N];
struct rec{int x,y,v;}a[N];
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') f=-f,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f;}
bool cmp(rec q,rec e){return q.x<e.x;}
inline void check()
{
	int cnt=0,Max=0,sum=0;
	UF(i,1,n) if(b[i]) cnt++,sum++;else Max=max(Max,cnt),cnt=0;
	Max=max(Max,cnt);
	if(Max>k) return;
	int score=-d*sum;
	UF(i,1,m)
	{
		int j=a[i].x;
		while(j>=1&&b[j]==1) j--;
		if(a[i].x-j>=a[i].y) score+=a[i].v;
	}
	ans=max(ans,score);
}
inline void work()
{
	ans=0;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	UF(i,1,m) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
	sort(a+1,a+m+1,cmp);
	memset(b,0,sizeof(b));
	while(!b[0])
	{
		int j=n;
		while(j>0&&b[j]==1) b[j--]=0;
		b[j]=1;
		check();
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) work();
	fclose(stdin);fclose(stdout);
	return 0;
}
//stO 977 Orz
//Though u rest school,u are the Master of Power
//And Power will --> Wonder

//Final Echoes

//Time to Say Goodbye
//Although it's not my habit to write sth at the bottom of Prob.4
//This time is a bit different
//I hope that the words below have no grammar problems.

//Goodbye OI & OIers
//Goodbye CCF
//Goodbye Hangz. Normal University
//-- But
//-- I hate this place. F HZNU
//-- NO more chance to be here again!!!!!!!
//I used more than 5 minutes to write this!
//So,
//Last sentence, it's good to meet u all.

//Shang ci de ji zi you zhong wen shu ru fa
//Zhe ci mei you
//Wo ye mei ban fa
//**Yang hua gai**

//I eat my sentence, what's it saying?
//Oh, I remember -- 
//For 5 years, I only cares about one certain she.
//Yes, Coffee's sweet .

//rk--, rk--, plz, rk-- plz!!!
