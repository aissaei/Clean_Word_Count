#!/usr/bin/env bash

# this file gives permission to p.py, p2.py, word_count.cpp and median_final.cpp. Then it complies them and eventually run them.
install g++
install python-pandas
cd src
chmod +x p.py
chmod +x p2.py
python p.py
g++ word_count.cpp
./a.out
python p2.py
g++ median_final.cpp
./a.out





