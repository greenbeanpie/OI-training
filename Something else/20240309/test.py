from docx import Document as Doc
word=[]
doc = Doc("test.docx")
for i in doc.paragraphs:
    temp = i.text.replace("_"," ")
    temp = temp.replace("("," ")
    temp = temp.replace("（"," ")
    temp = temp.replace(")"," ")
    temp = temp.replace("）"," ")
    temp = temp.replace(","," ")
    temp = temp.replace("."," ")
    for j in temp.split():
        if j[0]=='a' and j not in word:
            word.append(j)

for i in word:
    print(i,sep=" ")
