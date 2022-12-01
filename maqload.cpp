#include <bits/stdc++.h>
#include "opcodetable.h"
using namespace std;
#include "util.h"

int main(int argc,char* argv[]){
    //cout<<hextoi("0FA0")<<endl;
    unordered_map<string, unsigned int> regs;
    regs = {{"A", 0}, {"B", 0}, {"C", 0}, {"D", 0}, {"H", 0}, {"L", 0}};
    fstream obj; string line; int len, locctr, j=0, carry=0; vector<string> tokens;
    if(argc>1) obj.open(argv[1], ios::in);
    else cout<<"No file name."<<endl;
    while(getline(obj, line)){ tokens = tokenizeString(line,'.'); len = tokens.size();
        if(tokens[0]=="H") { locctr = hextoi(tokens[1]); }
        else if(tokens[0]=="T"){ tokens = tokenizebytes(tokens[2]);
            for(int i=0; i<tokens.size(); i++){
                //cout<<"Instruction "<<i<<":"<<tokens[i]<<endl;
                if(tokens[i]=="3E") regs["A"] = hextoi(tokens[++i]);
                else if(tokens[i]=="4F") regs["C"] = regs["A"];
                else if(tokens[i]=="3C") regs["A"] = regs["A"] + 1;
                else if(tokens[i]=="C2" && j) i= hextoi(tokens[i+1] + tokens[i+2])-locctr-1; 
                else if(tokens[i]=="0D") { regs["C"] = regs["C"]-1; j= regs["C"]; }
                else if(tokens[i]=="01") printf("%c\n", regs["A"]);
                else if(tokens[i]=="03") printf("%.2x", regs["A"]);
                else if(tokens[i]=="02") {unsigned char t; cin>>t; regs["A"]= t;}
                else if(tokens[i]=="D6") {regs["A"] = regs["A"] - hextoi(tokens[++i]); j=regs["A"];}
                else if(tokens[i]=="8F") {regs["A"] = regs["A"] + carry; carry = 0;}
                else if(tokens[i]=="81") {regs["A"] = regs["A"] + regs["C"]; if(regs["A"]>=256) carry=1; 
                regs["A"]= regs["A"]%256; }
                else if(tokens[i]=="04") {unsigned int t; cin>>t; if(t>=256) {cout<<"RE"; return 0;} regs["A"]= t;}
                else if(tokens[i]=="91") {regs["A"] = regs["A"]- regs["C"];}
                else if(tokens[i]=="92") {regs["A"] = regs["A"]- regs["D"];}
                else if(tokens[i]=="57") {regs["D"] = regs["A"];}
                else if(tokens[i]=="82"){regs["A"] = regs["A"] + regs["D"]; if(regs["A"]>=256) carry=1; 
                regs["A"]= regs["A"]%256; }
                else if(tokens[i]=="87"){regs["A"] = regs["A"] + regs["A"]; if(regs["A"]>=256) carry=1; 
                regs["A"]= regs["A"]%256; }
                else if(tokens[i]=="8A") {regs["D"] = regs["D"] + carry; carry = 0;}
                else if(tokens[i]=="83"){regs["A"] = regs["A"] + regs["E"]; if(regs["A"]>=256) carry=1; 
                regs["A"]= regs["A"]%256; }
                else if(tokens[i]=="5F") { regs["E"] = regs["A"];}
            }
        }

    }
    //cout<<"A: "<<regs["A"]<<endl;
    //cout<<"B: "<<regs["B"]<<endl;
    //cout<<"C: "<<regs["C"]<<endl;
    
    return 0;
}