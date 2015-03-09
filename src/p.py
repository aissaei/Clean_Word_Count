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
for file in glob.glob("*.txt"):
    
            f.write(file)
            f.write('\n')
            i=i+1
f.close();

