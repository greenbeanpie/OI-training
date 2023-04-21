#pragma once
#define MOD 1000000007
long long quickpower(long long a,long long b){
    if(b==0)
    {
        return 1;
    }
    long long answer=1;
    while(b)
    {
        if(b&1)
        {
            answer=answer*a%MOD;
        } 
        a=a*a%MOD;
        b>>=1;
    } 
    return answer;
}