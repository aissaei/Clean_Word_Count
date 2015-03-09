# This file count the number of words on the file and write it
# on the text file. The result will be used by median_final.cpp

from __future__ import print_function
import glob
import os
path_=os.getcwd()
path_ = path_[:-4]
fout= open('median_interim.txt', 'w')
f=open("file_n.txt",'r')
myList = []
for line in f:
    myList.append(line.rstrip('\n'))
f.close();
for i in range(1,len(myList)):
    temp=myList[i]
    fname=path_+"/wc_input/"+temp
    num_lines = 0
    num_words = 0
    num_chars = 0
                        
    with open(fname, 'r') as f:
        for line in f:
            words = line.split()
                                    
            num_lines += 1
            num_words += len(words)
            num_chars += len(line)
            fout.write(str(num_words))
            fout.write("\n")
            num_words = 0


