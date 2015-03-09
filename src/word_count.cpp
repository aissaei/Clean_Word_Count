// This file is soluiton ot the first problem.
// Written by: Amir Issaei
// Created by: Xcode
//
//  main.cpp
//  Word Count
//
//  Created by Amir Issaei on 2015-03-07.
//  Copyright (c) 2015 Amir Issaei. All rights reserved.
//


// Define some libraries that are used later on
#include <iostream>
#include <string>
#include<stdlib.h>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <set>
#include <vector>
#include <list>
#include<algorithm>

// using namespace std
using namespace std;

int main(int argc, const char * argv[]) {
    
// Define some constanbcts and start initialization
    char k;
    int i,j,n;
    set <string> unique_words;
    vector<string> alphabetic_order;
    int set_size=unique_words.size();
    string main_path;
    char chars[] = " -";
    vector<string> words;
    vector<string>name_of_files;
    vector<int> counts;
    string word,word_copy,word_final,file_name_lines;
    
    
    // Find the working directory
    fprintf( stderr, "cwd: %s\n", getenv("PWD") );
    
    //Open this file that is created by Python ealier. Please refer to p.py for more info. This file contains the directory path and the name of the files inside wc_input folder
    
    ifstream file_name ("./file_n.txt");
    
// Read the file and stoore the file names
    if(file_name.is_open())
    {
        while(getline(file_name,file_name_lines))
        {
            name_of_files.push_back(file_name_lines);
            file_name_lines.clear();
        }
    }
    file_name.close();
    
 // Sort the file names in alphabetic order
    sort( name_of_files.begin(), name_of_files.end());
    
// Open the output file to write the result in
    ofstream myfileo;
    myfileo.open(name_of_files.at(0)+"/wc_output/wc_result.txt");
    
// This for loop corresponds to each text file inside the wc_input folder
    
    for(i=1;i<=name_of_files.size()-1;++i)
    {
        cout<<"file"<<i<<"\n";
        cout<<name_of_files.at(0)+"/wc_input/"+name_of_files.at(i)<<"\n";
        ifstream myfile(name_of_files.at(0)+"/wc_input/"+name_of_files.at(i));
        
    // The text file is open. Now we need to read the words
        
         if(myfile.is_open())
        
         {
            
             // Read the words until the end of the file
             
             while (myfile>>word)
            {
                
                // Remove punctuation from each words
                remove_copy_if(word.begin(), word.end(),back_inserter(word_copy),
                        ptr_fun<int, int>(ispunct));
                
                // Since we dont care about capital or small letter we make all letters small
                transform(word_copy.begin(), word_copy.end(), word_copy.begin(), ::tolower);
                
            // Remove extra spaces, etc from the words
                
                for (unsigned int m = 0; m < strlen(chars); ++m)
                {
                    word_copy.erase (std::remove(word_copy.begin(), word_copy.end(), chars[i]), word_copy.end());
                }
                
                
                // Start putting unique words inside a set
                unique_words.insert(word_copy);
                
                // If the word is uniw we need to add 1 to the counter, which is responsible for the new word
                if(unique_words.size()!=set_size)
                {
                    words.push_back(word_copy);
                    counts.push_back(1);
                    set_size++;
                    
                }
                
                // If the word is not unique, we need to find what word it is. Then we add 1 to the counter
                // that is responsible for that specific word
                else
                {
                    
                    for(j=0;j<=words.size()-1;++j)
                    {
                        
                        if(words.at(j)==word_copy)
                        {
                            counts.at(j)=counts.at(j)+1;
                            
                        }
                        
                    }
                }
                
                
                word_copy.clear();
                
            }
             
         }
        
       // End of the file. Need to move to the next file
        myfile.close();
        
    }
    
    //We need to sort the words in alphabetic order before writing them into the file.
    for (n=0;n<=counts.size()-1;n++)
    {
        words.at(n)=words.at(n)+to_string(counts.at(n));
    }
    sort(words.begin(),words.end());
    
    // Write the final result to the file and return
    for (n=0;n<=counts.size()-1;n++)
    {
        k=words.at(n).back();
        words.at(n)=words.at(n).substr(0,words.at(n).size()-1);
        myfileo<<words.at(n)<<"\t"<<k<<"\n";
    }
    myfileo.close();
    return 0;
}


