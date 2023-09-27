import os
import datetime
a=False
b=0
ct=datetime.datetime.now()
os.chdir("C:\\Users\\Administrator\\OI-traning")
os.system("git commit -a -m 上传"+str(ct.year)+"."+str(ct.month)+"."+str(ct.day))
while b==256:
    b=os.system("git push")