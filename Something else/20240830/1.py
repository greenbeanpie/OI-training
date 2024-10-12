def enFence(string,space):#string是明文,space是栅栏数量
    s=''
    # 外层循环控制栅栏的数量
    for i in range(0,space):
        # 内层循环遍历明文，每次跳过space个字符进行加密 
        for j in range(i,len(string),space):
            s+=string[j]
    return s
def deFence(string,space): #sting是密文,space是栅栏数量
    s=''
    if len(string) % space == 0:  
        key=len(string)//space        
    else:
        key=len(string)//space+1 #第一组（最多一组）有的数量
    # for i in range(0,key-1):
    #     j=i
    #     end=len(string)%space
    #     cnt=0
    #     while cnt<=end:
    #         s+=string[j]
    #         j+=key
    #     while j<len(string):
    #         s+=string[j]
    #         j+=key-1
    # j=key-1
    # cnt=len(string)%space
    # for i in range(cnt):
    #     s+=string[j]
    #     j+=key
    j=0
    end = len(string)%space
    cnt=1
    while len(s)!=len(string):
        s+=string[j]
        if cnt>end:
            j+=key-1
        else:
            j+=key
        cnt+=1
        if j>=len(string):
            j-=len(string)-1
            cnt=1
    
    return s

k=int(input("请输入整数0或1,0表示加密,1表示解密:"))
if k==0:
    mingwen=input("请输入明文:")
    x=int(input("请输入栅数:"))
    miwen=enFence(mingwen,x)
    print("加密后的密文是:",miwen)
elif k==1:
    miwen=input("请输人密文:")
    x=int(input("请输入栅数:"))
    mingwen=deFence(miwen, x)
    print("解密后的明文是:",mingwen)