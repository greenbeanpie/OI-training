#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct segmt{
	LL lson,rson,val;
}a[2000005];
LL n,i,j,k,m,cnt=0,useless,q,num1,num2,x,y;
LL val1[500005],val2[500005],tmp[1000005],num[1000005],root[500005];
LL maxx[500005];
LL id1[500005],id2[500005],tmp1[500005],tmp2[500005];
LL tree[2000005];
char ch;
LL tmp123=0;
map<LL,LL> mp;
LL read(){
	tmp123=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9'){
		tmp123=tmp123*10+ch-'0';
		ch=getchar();
	}
	return tmp123;
}
void build(LL l,LL r,LL id){
	if(l==r){
		tree[id]=val1[l];
		return ;
	}
	LL mid=(l+r)>>1;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
	tree[id]=max(tree[id*2],tree[id*2+1]);
}
LL query1(LL l,LL r,LL id,LL askl,LL askr){
	if(l>=askl && r<=askr) return tree[id];
	LL mid=(l+r)>>1,maxx=0;
	if(askl<=mid) maxx=max(maxx,query1(l,mid,id*2,askl,askr));
	if(askr>mid) maxx=max(maxx,query1(mid+1,r,id*2+1,askl,askr));
	return maxx;
}
bool check(LL x,LL l,LL y){
	//printf("%lld ",query1(1,n,1,l,x));
	if(y>query1(1,n,1,l,x)) return true;
	else return false;
}
void update(LL x){
	a[x].val=max(a[a[x].lson].val,a[a[x].rson].val);
}
void insert(LL l,LL r,LL rt1,LL rt2,LL x,LL val){
	//printf("%lld %lld %lld %lld %lld\n",l,r,rt1,rt2,x);
	if(l==r && r==x){
		a[rt2].val=val;
		return ;
	}
	LL mid=(l+r)>>1;
	if(x<=mid){
		a[rt2].lson=++cnt;a[rt2].rson=a[rt1].rson;
		insert(l,mid,a[rt1].lson,a[rt2].lson,x,val);
		update(rt2);
	}
	else{
		a[rt2].lson=a[rt1].lson;a[rt2].rson=++cnt;
		insert(mid+1,r,a[rt1].rson,a[rt2].rson,x,val);
		update(rt2);
	}
}
LL query(LL l,LL r,LL id,LL askl,LL askr){
	if(l>=askl && r<=askr){
		return a[id].val;
	}
	LL mid=(l+r)>>1,maxx=0;
	if(askl<=mid) maxx=max(maxx,query(l,mid,a[id].lson,askl,askr));
	if(askr>mid) maxx=max(maxx,query(mid+1,r,a[id].rson,askl,askr));
	return maxx;
}
void doit(){
	for(LL i=1;i<=n;i++)
	  tmp[++tmp[0]]=val1[i];
	for(LL i=1;i<=m;i++)
	  tmp[++tmp[0]]=val2[i];
	sort(tmp+1,tmp+tmp[0]+1);
	//printf("%lld %lld\n",n,m);
    /*
	for(LL i=1;i<=n;i++)
	  printf("%lld ",val1[i]);
	printf("\n");
	for(LL i=1;i<=m;i++)
	  printf("%lld ",val2[i]);
	printf("\n");*/
	cnt=0;
	for(LL i=1;i<=n+m;i++){
		//printf("%lld %lld\n",i,tmp[i]);
		if(i==1 || tmp[i]!=tmp[i-1]){
	  	    num[++num[0]]=tmp[i];
	  	    mp[tmp[i]]=num[0];
	    }
	}
	  
	bool flag1=false;
	if(val1[1]>val2[1]){
		for(LL i=1;i<=max(n,m);i++)
		  swap(val1[i],val2[i]);
		swap(n,m);
		flag1=true;
	}
	if(val1[1]==val2[1]) printf("0");
	else{
		bool flag=false;
	    root[0]=0;
	    for(LL i=1;i<=n;i++){
		    root[i]=++cnt;
		    insert(1,num[0],root[i-1],root[i],mp[val1[i]],i);
	    }
	    build(1,n,1);
		LL now=0;
		maxx[0]=0;
		for(LL i=1;i<=n;i++)
		  maxx[i]=max(maxx[i-1],val1[i]);
		for(LL i=1;i<=m;i++){
			LL l=now,r=n+1;
			while(l<r){
				LL mid=(l+r)>>1;
				if(check(mid,now,val2[i])) l=mid+1;
				else r=mid;
			}
			/*if(now==0 && r==1){
				printf("0");
				flag=true;
				break;
			}*/
			if(now<=r-1) now=r-1;
			else{
				if(mp[val2[i]]==1){
					flag=true;
					printf("0");
					break;
				}
				LL tmp1=query(1,num[0],root[now],1,mp[val2[i]]-1);
				if(tmp1==0){
					flag=true;
					printf("0");
					break;
			 	}
				else now=tmp1;
			}
			//printf("%lld %lld\n",now,r);
		}
		if(flag==false){
			if(now==n) printf("1");
			else printf("0");
		}
		for(LL i=1;i<=cnt;i++)
		  a[i].lson=a[i].rson=a[i].val=0;
		for(LL i=1;i<=n;i++)
		  root[i]=maxx[i]=0;
	}
	if(flag1==true){
		for(LL i=1;i<=max(n,m);i++)
		  swap(val1[i],val2[i]);
		swap(n,m);
    }
	for(LL i=1;i<=num[0];i++)
	  mp[num[i]]=0;
	for(LL i=0;i<=n+m;i++)
	  num[i]=tmp[i]=0;
	//tmp[0]=num[0]=0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	useless=read();n=read();m=read();q=read();
	for(i=1;i<=n;i++)
	  val1[i]=read();
	for(i=1;i<=m;i++)
	  val2[i]=read();
	doit();
	for(i=1;i<=q;i++){
		//printf("%lld %lld\n",n,m);
		num1=read();num2=read();
		for(j=1;j<=num1;j++){
			x=read();y=read();
			id1[j]=x,tmp1[j]=val1[x];
			val1[x]=y;
		}
		for(j=1;j<=num2;j++){
			x=read();y=read();
			id2[j]=x,tmp2[j]=val2[x];
			val2[x]=y;
		}
		doit();
		for(j=1;j<=num1;j++)
		  val1[id1[j]]=tmp1[j];
		for(j=1;j<=num2;j++)
		  val2[id2[j]]=tmp2[j];
	}
	return 0;
}
/*
51455166 103514862 150860075 152117195 226271763 233287783
888211710 754438381 742371390 703547613 510787265 233287783 


*/

