#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long f=1,w=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		w=w*10+ch-'0';
		ch=getchar();
	}
	return w*f;
}
long long c,n,m,q,x[500001],y[500001],xma=0,xmi=100000000,yma=0,ymi=1000000000;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		x[i]=read();
		if(i==1){
			continue;
		}
		if(x[i]>xma){
			xma=x[i];
		}
		if(x[i]<xmi){
			xmi=x[i];
		}
	}
	for(int i=1;i<=m;i++){
		y[i]=read();
		if(i==1){
			continue;
		}
		if(y[i]>yma){
			yma=y[i];
		}
		if(y[i]<ymi){
			ymi=y[i];
		}
	}
	if(c==1){
		if(x[1]!=y[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		for(int i=0;i<q;i++){
			int k1=read(),k2=read();
			for(int j=0;j<k1;j++){
				int px=read(),vx=read();
				x[px]=vx;
			}
			for(int j=0;j<k2;j++){
				int py=read(),vy=read();
				y[py]=vy;
			}
			if(x[1]!=y[1]){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else if(c==2){
		if((x[1]-y[1])*x[1]-y[1]>0){
			cout<<1;
		}else{
			cout<<0;
		}
		for(int i=0;i<q;i++){
			int k1=read(),k2=read();
			for(int j=0;j<k1;j++){
				int px=read(),vx=read();
				x[px]=vx;
			}
			for(int j=0;j<k2;j++){
				int py=read(),vy=read();
				y[py]=vy;
			}
			if((x[1]-y[1])*(x[n]-y[m])>0){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else if(c>=8&&c<=14){
		if(x[n]*y[m]>=0||xmi>yma){
			cout<<0;
		}
		if(ymi>xma){
			cout<<1;
		}
		bool flagxa=false,flagyi=false,flagya=false;
		for(int i=0;i<q;i++){
			int k1=read(),k2=read();
			for(int j=0;j<k1;j++){
				int px=read(),vx=read();
				if(px!=1){
					if(!flagxa&&x[px]==xma){
						flagxa=true;
					}
					if(vx>=xma){
						xma=vx;
						flagxa=false;
					}
				}
				x[px]=vx;
			}
			for(int j=0;j<k2;j++){
				int py=read(),vy=read();
				if(!flagyi&&y[py]==ymi){
					flagyi=true;
				}
				if(vy<=ymi){
					ymi=vy;
					flagyi=false;
				}
				y[py]=vy;
			}
			if(flagxa){
				for(int j=1;j<=n;j++){
					if(x[j]>xma){
						xma=x[j];
					}
				}
			}
			if(flagyi){
				for(int j=1;j<=m;j++){
					if(y[j]<ymi){
						ymi=y[j];
					}
				}
			}
			xmi=x[n];
			yma=y[m];
			if(x[n]*y[m]>=0||xmi>yma){
				cout<<0;
			}
			if(ymi>xma){
				cout<<1;
			}
		}
	}else{
		if(x[1]>xma){
			xma=x[1];
		}
		if(x[1]<xmi){
			xmi=x[1];
		}
		if(y[1]>yma){
			yma=y[1];
		}
		if(y[1]<ymi){
			ymi=y[1];
		}
		if((x[1]-y[1])*(x[n]*y[m])<=0){
			cout<<0;
		}
		if(yma<xmi||ymi>xma){
			cout<<1;
		}
		bool flagxi=false,flagxa=false,flagyi=false,flagya=false;
		for(int i=0;i<q;i++){
			int k1=read(),k2=read();
			for(int j=0;j<k1;j++){
				int px=read(),vx=read();
				if(!flagxa&&x[px]==xma){
					flagxa=true;
				}
				if(!flagxi&&x[px]==xmi){
					flagxi=true;
				}
				if(vx>=xma){
					xma=vx;
					flagxa=false;
				}
				if(vx<=xmi){
					xmi=vx;
					flagxi=false;
				}
				x[px]=vx;
			}
			for(int j=0;j<k2;j++){
				int py=read(),vy=read();
				if(!flagya&&y[py]==yma){
					flagya=true;
				}
				if(!flagyi&&y[py]==ymi){
					flagyi=true;
				}
				if(vy>=yma){
					yma=vy;
					flagyi=false;
				}
				if(vy<=ymi){
					ymi=vy;
					flagyi=false;
				}
				y[py]=vy;
			}
			if(flagxa&&flagxi){
				for(int j=1;j<=n;j++){
					if(x[j]>xma){
						xma=x[j];
					}
					if(x[j]<xmi){
						xmi=x[j];
					}
				}
			}else if(flagxa){
				for(int j=1;j<=n;j++){
					if(x[j]>xma){
						xma=x[j];
					}
				}
			}else if(flagxi){
				for(int j=1;j<=n;j++){
					if(x[j]<xmi){
						xmi=x[j];
					}
				}
			}
			if(flagya&&flagyi){
				for(int j=1;j<=m;j++){
					if(y[j]>yma){
						yma=y[j];
					}
					if(y[j]<ymi){
						ymi=y[j];
					}
				}
			}else if(flagya){
				for(int j=1;j<=m;j++){
					if(y[j]>yma){
						yma=y[j];
					}
				}
			}else if(flagyi){
				for(int j=1;j<=m;j++){
					if(y[j]<ymi){
						ymi=y[j];
					}
				}
			}
			if((x[1]-y[1])*(y[n]-y[m])<=0){
				cout<<0;
			}
			if(yma<xmi||ymi>xma){
				cout<<1;
			}
		}
	}
	fclose(stdin);
	fclse(stdout);
	return 0;
}

