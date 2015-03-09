#!/usr/bin/env bash

cd src
chmod +x p.py
chmod +x p2.py
python p.py
g++ word_count.cpp
./a.out
python p2.py
g++ median_final.cpp
./a.out





