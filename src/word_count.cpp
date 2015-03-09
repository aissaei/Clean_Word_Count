//
//  main.cpp
//  Word Count
//
//  Created by Amir Issaei on 2015-03-07.
//  Copyright (c) 2015 Amir Issaei. All rights reserved.
//

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
using namespace std;

int main(int argc, const char * argv[]) {
    //insert code here...
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
    fprintf( stderr, "cwd: %s\n", getenv("PWD") );
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
    myfileo.open(name_of_files.at(0)+"/wc_output/wc_result.txt");
    for(i=1;i<=name_of_files.size()-1;++i)
    {
        cout<<"file"<<i<<"\n";
        cout<<name_of_files.at(0)+"/wc_input/"+name_of_files.at(i)<<"\n";
        ifstream myfile(name_of_files.at(0)+"/wc_input/"+name_of_files.at(i));
         if(myfile.is_open())
        
         {
            while (myfile>>word)
            {
                
                remove_copy_if(word.begin(), word.end(),back_inserter(word_copy),
                               ptr_fun<int, int>(ispunct));
                transform(word_copy.begin(), word_copy.end(), word_copy.begin(), ::tolower);
                for (unsigned int m = 0; m < strlen(chars); ++m)
                {
                    word_copy.erase (std::remove(word_copy.begin(), word_copy.end(), chars[i]), word_copy.end());
                }
                
                unique_words.insert(word_copy);
                if(unique_words.size()!=set_size)
                {
                    words.push_back(word_copy);
                    counts.push_back(1);
                    set_size++;
                    
                }
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
       
        myfile.close();
        
    }
    for (n=0;n<=counts.size()-1;n++)
    {
        words.at(n)=words.at(n)+to_string(counts.at(n));
    }
    sort(words.begin(),words.end());
    for (n=0;n<=counts.size()-1;n++)
    {
        k=words.at(n).back();
        words.at(n)=words.at(n).substr(0,words.at(n).size()-1);
        myfileo<<words.at(n)<<"\t"<<k<<"\n";
    }
    myfileo.close();
    return 0;
}


