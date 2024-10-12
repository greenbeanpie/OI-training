import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams["font.sans-serif"]=["SimHei"]

"""##1、统计一段文本中某个字母的个数
a="What's the weather today?"
key="a"
n=0
#方法1:用for循环遍历字符串，统计指定字母的个数
for i in a:
    if i==key:
        n+=1
        
print("a的个数是：",n)

#方法2:直接用count()函数
print(a.count(key))

##2、统计一篇文章中某个单词出现的次数
#文章内容在“202201A.txt”
txt=open("202201A.txt","r",encoding="utf-8").read()
key=input("请输入要统计的单词：")    #比如to，it
print(txt.count(key))

##这种统计有个bug，当出现单词tomorrow时，也会认为出现to，次数统计不准！

##2.1、统计一篇文章中所有单词出现的次数
keys={}
word=""
for i in txt:   ##读取每个字符
    #单词判断
    if "a"<=i<="z" or "A"<=i<="Z":
        word+=i
    else:
        keys[word]=keys.get(word,0)+1   
        #get的作用是：当keys中不存在键是word的情况下，自动添加word并默认值为0
        word=""

print(keys)
"""
##3、统计一篇文章中出现频率最高的3个词（中文）
#文章内容在“xiaowangzi.txt”  

text = open("xiaowangzi.txt","r").read()

import jieba

words = jieba.lcut(text,cut_all=False)

cnt = {}

stopwords = {"……","..."}

for i in words:
    if len(i)>=2 and not(i.islower() or i.isdigit()) and not(i in stopwords):
        try:
            cnt[i]+=1
        except:
            cnt[i]=1

df = pd.DataFrame(cnt.items())

df1 = df.sort_values(df.columns[1],ascending=False)

df2 = df1.head(10)

plt.bar(df2[df1.columns[0]],df2[df1.columns[1]])

plt.show()

#如何实现按词频排序？
#方法1:把字典转成列表，通过列表排序实现




    
#方法2：把字典转成dataframe,再排序实现





##拓展：如果第3名出现相同次数，如何显示出所有同次数的数据？
#参照20240915作业第11题第3小题




"""
#4、用标签云呈现文本分析结果
import numpy as np
from PIL import Image
from wordcloud import WordCloud
import matplotlib.pyplot as plt
text=open(______________________).read()          #打开文章文件
seg_list=jieba.cut(___________________)          #利用jieba分词
words_split = " ".join(seg_list)
mask_1=np.array(Image.open('1.jpg'))         #设置词云形状图像
wc = WordCloud(background_color='white',mask=mask_1,width=1800,height=1800)
#设置词云背景颜色、图像大小等
wc.font_path="simhei.ttf"   #设置词云字体
my_wordcloud = wc.generate(words_split)
plt.figure(figsize=(12,8),dpi=100)
plt.imshow(my_wordcloud)
plt.axis("off")
plt.show()
"""