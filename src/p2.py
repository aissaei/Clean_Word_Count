from __future__ import print_function
import glob
import os
path_=os.getcwd()
path_ = path_[:-4]
f=open("median_file_info.txt",'r')
file_numbers=f.readline()

for i in range(1,file_numbers):
    file_p=f.readline()
    num_lines = 0
    num_words = 0
    num_chars = 0

    with open(fname, 'r') as f:
        for line in f:
            words = line.split()
        
            num_lines += 1
            num_words += len(words)
            num_chars += len(line)
print num_lines
print num_words