from random import randint
import os

arr = [0, 1, 10, 100, 1000, 100000, 1]
temp = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

for id in range(1, 7):
  inname = "trie" + str(id) + '.in'
  ansname = 'trie' + str(id) + '.ans'
  f = open(inname, 'w', newline='\n')
  t = arr[id]
  f.write(str(t) + '\n')
  if id != 6:
    for tt in range(t):
      n = 100000 // t
      m = n
      last = 500000 // t
      text = []
      f.write(str(n) + " " + str(m) + '\n')
      for i in range(m - 1):
        s = str()
        lst = randint(1, (last // (m - i + 1)))
        for j in range(lst):
          s += temp[randint(0, len(temp) - 1)]
        text.append(s)
        last -= lst
      s = str()
      for i in range(last):
        s += temp[randint(0, len(temp) - 1)]
      text.append(s)
      last = 1500000 // t
      for i in range(n - 1):
        j = randint(0, len(text) - 1)
        lst = randint(1, (last // (m - i + 1)))
        s = text[j]
        for k in range(lst):
           s += temp[randint(0, len(temp) - 1)]
        f.write(s + '\n')
        last -= lst
      s = str()
      for i in range(last):
        s += temp[randint(0, len(temp) - 1)]
      f.write(s + '\n')
      for i in range(m):
        f.write(text[i] + '\n')
  else:
    f.write("100000 100000\n")
    lst = 1900000
    for i in range (100000):
      last = randint(0, lst // (100000 - i) - 1)
      s = 'a'
      for j in range(last):
        s += temp[randint(0, len(temp) - 1)]
      f.write(s + '\n')
      lst -= last
    for i in range(100000):
      f.write('a\n')
  f.flush()
  os.system('std.exe < ' + inname + ' > ' + ansname)