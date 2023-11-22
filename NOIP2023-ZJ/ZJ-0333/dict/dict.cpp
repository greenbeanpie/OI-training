#include<cstdio>
int n,m;
char s[3005][3005];
int cnt[3005][30];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++){
            cnt[i][s[i][j]-'a']++;
        }
    }
    for(int i=1;i<=n;i++){
        bool f=1;
        for(int j=1;j<=n;j++){
            if(j==i){
                continue;
            }
            char nowi='a',nowj='z';
            int cnti=0,cntj=0;
            while(nowi<='z'&&nowj>='a'){
                int prei=cnti,prej=cntj;
                cntj+=cnt[j][nowj-'a'];
                nowj--;
                char nj=nowj+1;
                if(cnt[j][nj-'a']==0){
                    continue;
                }
                char ns=nowi;
                bool fns=0;
                if(prei>prej){
                    ns--;
                }
                while(cnti<cntj){
                    cnti+=cnt[i][nowi-'a'];
                    if(fns==0){
                        if(cnt[i][nowi-'a']>0){
                            ns=nowi;
                            fns=1;
                        }
                    }
                    nowi++;
                }
                char nt=nowi-1;
                if(ns>nj){
                    f=0;
                    break;
                }
                if(ns<nj){
                    break;
                }
                if(ns==nj){
                    if(nt==nj){
                        continue;
                    }
                    if(nt>nj){
                        f=0;
                        break;
                    }
                }
            }
        }
        if(f){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf("\n");
    return 0;
}