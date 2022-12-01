#include <bits/stdc++.h>
using namespace std;
#include "opcodetable.h"
#include "util.h"

int main(int argc, char* argv[]){
    initializeTable();
    unordered_map<string, int> symtab;
    fstream f, obj; string line; unsigned int locctr, hex, loc, ll=0;
    f.open(argv[1], ios::in);
    if(argc==3)
        obj.open(argv[2], ios::out);
    else
        obj.open("o.mo5", ios::out);
    getline(f, line); vector<string> tokens = tokenizeString(line);
    if(tokens[0]=="START") { locctr = stoi(tokens[1]); obj<<"H."<<itohex(stoi(tokens[1]));}
    else { cout<<"Error: No start address found."<<endl; return 0; }
    while(getline(f, line)){ if(line.at(0)=='.') continue;
        tokens = tokenizeString(line);
        if(ll==0) obj<<"\nT." + itohex(locctr) + ".";
        if(tokens.size()==3) symtab[tokens[0]] = locctr;
        if(hex = opt[tokens[tokens.size()-2] + " " + tokens[tokens.size()-1]]) { locctr+=1; obj<<itohex(hex,2); ll+=2; }
        else if(hex = opt[tokens[tokens.size()-2] + " " + tokens[tokens.size()-1].substr(0,2)]) { locctr+=2; 
        obj<<itohex(hex,2)<<itohex(stoi(tokens[tokens.size()-1].substr(2)),2); ll+=4; }
        else if(hex = opt[tokens[tokens.size()-2]]) {locctr+=3; 
            if(loc = symtab[tokens[tokens.size()-1]]) { obj<<itohex(hex,2)<<itohex(loc); ll+=6;}
            else { cout<<"Label not found in line"<<line<<endl; return 0;} }
        else if(tokens[0]=="END") { 
            if(loc = symtab[tokens[1]]) {obj<<"."<<itohex(ll,2)<<"\nE."<<itohex(loc); break;} 
            else { cout<<"Error: No End address found."<<endl; return 0; }}
        else { cout<<"Wrong instruction in "<<line<<endl; return 0; }
        if(ll>=60) { obj<<"."<<itohex(ll,2); ll=0; }
    }
    for(auto e: symtab) cout<<e.first<<" "<<e.second<<endl;
    f.close();
    obj.close();
    printf("%X\n", int(opt["MOV A,B"]));
}
