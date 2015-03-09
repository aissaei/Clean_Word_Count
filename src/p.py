# This file red the w_c directory and extract the file names

from __future__ import print_function
import glob
import os
i=1
path_=os.getcwd()
path_ = path_[:-4]
f = open('file_n.txt', 'w')
f.write(path_)
f.write('\n')
os.chdir(path_+"/wc_input")
# Here we write the path and file names intop the file. This will be used by word_count.cpp file
for file in glob.glob("*.txt"):
    
            f.write(file)
            f.write('\n')
            i=i+1
f.close();

