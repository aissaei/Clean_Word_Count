//Second challenge
// Written by: Amir Issaei on Xcode
//  main.cpp
//  Word Count
//
//  Created by Amir Issaei on 2015-03-07.
//  Copyright (c) 2015 Amir Issaei. All rights reserved.
//


// Add some libraries
#include <iostream>
#include <string>
#include<stdlib.h>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <set>
#include <vector>
#include <list>
#include<sstream>
#include<algorithm>
#include<sstream>
using namespace std;


int main(int argc, const char * argv[]) {

    // Initialization of some variables
    string line, file_name_lines;
    int j;
    double median;
    vector<int> numbers;
    vector<string> name_of_files;
    ifstream myfile;
    
    // Read the file created by p2.py. This file includes the counting of words on each line fo all the files inside wc_input
    
    myfile.open ("./median_interim.txt");
    
    
    // Need to find the path of the working directory
    ifstream file_name ("./file_n.txt");
    if(file_name.is_open())
    {
        while(getline(file_name,file_name_lines))
        {
            name_of_files.push_back(file_name_lines);
            file_name_lines.clear();
        }
    }
    file_name.close();
    sort( name_of_files.begin(), name_of_files.end());
    ofstream myfileo;
    myfileo.open(name_of_files.at(0)+"/wc_output/median_result.txt");
  
    // Start reading the file that was created by p2.py and
    // finding the median
    while ( getline (myfile,line) )
    {
        numbers.push_back(stoi(line));
        sort( numbers.begin(), numbers.end());
        if(div(numbers.size(),2).rem==0)
        {
            
            median=(numbers.at(div(numbers.size(),2).quot-1)+numbers.at(div(numbers.size(),2).quot))/2.0;
            
        }
        else
        {
            
            median=numbers.at(div(numbers.size(),2).quot);
            
        }
        myfileo<<median;
        myfileo<<"\n";
    }
    
    // Close the files and remove unnecessarry files
    myfile.close();
    myfileo.close();
    remove("./file_n.txt");
    remove("./median_interim.txt");
    remove("./a.out");
    return 0;
}