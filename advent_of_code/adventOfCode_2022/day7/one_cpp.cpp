#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

typedef struct FileSystem{
    // 0 for directory , 1 for file
    int f=1;
    unordered_map<string,struct FileSystem*> dirs;
    unordered_map<string,struct FileSystem*> files;
    struct FileSystem *parent=NULL;
} fsys;


int main(){
    ifstream input_file("input.txt");
    fsys *root= new fsys();
    fsys *curr_pointer = root;
    string line;
    while(getline(input_file,line)){
        
        if(line.substr(2,2) == "cd"){
            cout <<"----\n"; 
            if( line[5] == '/'){
                curr_pointer = root;
            }
            else if(line.substr(5,2) == ".."){
                curr_pointer= curr_pointer->parent;
            }
            else {
                cout << line.substr(5) <<endl;
                curr_pointer = curr_pointer->dirs[line.substr(5)];
            }
        }
    }
    return 0;
}