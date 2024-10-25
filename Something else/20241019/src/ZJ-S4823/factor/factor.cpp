#include<iostream>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int a[100005],b[100005];
int seg[10000000],L[10000000],R[10000000],segcnt;
int n;
int QUERY(int sl,int sr,int p,int l,int r)
{
	if(!p)return 0;
	if(l>=sl&&r<=sr)return seg[p];
	int mid=(l+r)>>1;
	if(sr<=mid)return QUERY(sl,sr,L[p],l,mid);
	if(mid<sl)return QUERY(sl,sr,R[p],mid+1,r);
	return max(QUERY(sl,sr,L[p],l,mid),QUERY(sl,sr,R[p],mid+1,r));
}
int query(int a,int b)
{
	int ret=0;
	for(;a>0;a-=lowbit(a))
		ret=max(ret,QUERY(1,b,a,1,n));
	return ret;
}
void INST(int aim,int v,int&p,int l,int r)
{
	if(!p)
		p=++segcnt;
	if(l==r)
	{
		seg[p]=max(seg[p],v);
		return;
	}
	int mid=(l+r)>>1;
	if(aim<=mid)
		INST(aim,v,L[p],l,mid);
	else
		INST(aim,v,R[p],mid+1,r);
	seg[p]=max(seg[L[p]],seg[R[p]]);
}
void inst(int a,int b,int v)
{
	for(;a<=n;a+=lowbit(a))
		INST(b,v,a,1,n);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		cin>>b[i];
	segcnt=n;
	int ans=0;
	for(int i=1,f;i<=n;++i)
	{
		f=query(a[i],b[i])+1;
		ans=max(ans,f);
		inst(a[i],b[i],f);
	}
	cout<<ans;
}
