#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
int n,m,C,q;
int X[MAXN],Y[MAXN];
int changeX[MAXN],changeY[MAXN],ciX[MAXN],ciY[MAXN],kX,kY;//X,Y change stack
int aval[MAXN],taval[MAXN],laval,ltaval;//X>Y

int check(){
	int *pX=X,*pY=Y;
	int nn=n,mm=m;
	if(pX[1]==pY[1]||pX[nn]==pY[mm]||pX[1]<pY[1]&&pX[nn]>pY[mm]||pX[1]>pY[1]&&pX[nn]<pY[mm])
		return 0;
	if(pX[1]<pY[1]){
		swap(pX,pY);
		swap(nn,mm);
	}
		
	int x=1,y;
	for(y=1;y<=mm;y++){
		if(pX[x]<=pY[y])
			break;
		aval[y]=y;
	}
	laval=y-1;
	int i;
	for(x=2;x<=nn;x++){
		ltaval=0;
		for(i=1;i<=laval;i++){
			y=aval[i];
			if(pY[y]<pX[x])
				taval[++ltaval]=y;//same pos
			while((i==laval||y+1<aval[i+1])&&y+1<=mm&&pY[y+1]<pX[x])
				taval[++ltaval]=++y;//next pos
		}
		laval=ltaval;
		for(i=1;i<=ltaval;i++)
			aval[i]=taval[i];
		aval[laval+1]=1000001;
	}
	return laval!=0&&aval[laval]==mm;
}

void update(){
	for(int i=1;i<=kX;i++)
		swap(X[ciX[i]],changeX[i]);
	for(int i=1;i<=kY;i++)
		swap(Y[ciY[i]],changeY[i]);
}

inline int read(){
	int ans=0;
	char c;
	c=getchar();
	while(c==' '||c=='\n')
		c=getchar();
	while(c>='0'&&c<='9'){
		ans*=10;
		ans+=c-'0';
		c=getchar();
	}
	return ans;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&q);
	for(int i=1;i<=n;i++)
//		scanf("%d",X+i);
		X[i]=read();
	for(int i=1;i<=m;i++)
//		scanf("%d",Y+i);
		Y[i]=read();
	printf("%d",check());
	for(int iq=1;iq<=q;iq++){
		scanf("%d%d",&kX,&kY);
		for(int i=1;i<=kX;i++)
		{
			ciX[i]=read();
			changeX[i]=read();
		}
//			scanf("%d%d",ciX+i,changeX+i);
		for(int i=1;i<=kY;i++)
		{
			ciY[i]=read();
			changeY[i]=read();
		}
//			scanf("%d%d",ciY+i,changeY+i);
		update();
		printf("%d",check());
		update();
	}
	return 0;
}
