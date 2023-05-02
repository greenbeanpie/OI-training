import random
start=random.randint(1,10000)
end=random.randint(1,10000)
if(start>end):
    mid=start
    start=end
    end=mid
for i in range(25000):
    a=random.randint(1,5339)
    b=random.randint(1,5339)
    print(min(a,b),max(a,b))
for i in range(25000):
    a=random.randint(5341,10000)
    b=random.randint(5341,10000)
    print(min(a,b),max(a,b))