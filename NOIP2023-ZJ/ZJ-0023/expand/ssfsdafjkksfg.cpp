void shabi(){
    sort(ia+1,ia+1+n,[](int x,int y){return a[x]<a[y];});
    sort(ib+1,ib+1+m,[](int x,int y){return b[x]<b[y];});
    int l,r,p;
    l=m+1,r=0,p=1;
    rep(i,1,n){
        int x=ia[i];
        while(p<=m && b[ib[p]]<a[x]){
            ckmn(l,ib[p]);
            ckmx(r,ib[p]);
            p++;
        }
        ra[x]=mkp(l,r);
    }
    l=n+1,r=0,p=n;
    per(i,m,1){
        int x=ib[i];
        while(p>0 && a[ia[p]]>b[x]){
            ckmn(l,ia[p]);
            ckmx(r,ia[p]);
            p--;
        }
        rb[x]=mkp(l,r);
    }
    rep(i,1,n) if(ra[i].fir>ra[i].sec){cout<<'0';return;}
    rep(i,1,m) if(rb[i].fir>rb[i].sec){cout<<'0';return;}
    fill(c+1,c+1+n,m+1);
    rep(i,1,m) ckmn(c[rb[i].fir],i);
    per(i,n,2) ckmn(c[i-1],c[i]);
    rep(i,1,n) if(c[i]<ra[i].fir){cout<<'0';return;}
    fill(c+1,c+1+n,0);
    rep(i,1,m) ckmx(c[rb[i].sec],i);
    rep(i,1,n-1) ckmx(c[i+1],c[i]);
    rep(i,1,n) if(c[i]>ra[i].sec){cout<<'0';return;}
    cout<<'1';
}