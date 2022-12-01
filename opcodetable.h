#include <bits/stdc++.h>
using namespace std;
unordered_map<string, unsigned char> opt;

void initializeTable(){
opt = {
    {"MOV A,", 0x3E},
    {"MOV C,A", 0x4F},
    {"PRINTCN A", 0x01},
    {"INR A", 0x3C},
    {"JNZ", 0xC2},
    {"DCR C", 0x0D},
    {"SUI A,", 0xD6},
    {"INPUT A", 0x02},
    {"PRINT A", 0x03},
    {"ADC A", 0x8F},
    {"ADD C", 0x81},
    {"INPUTN A", 0x04},
    {"MOV D,A", 0x57},
    {"SUB D", 0x92},
    {"SUB C", 0x91},
    {"ADD D", 0x82},
    {"ADC D", 0x8A},
    {"ADD A", 0x87},
    {"ADD E",0x83},
    {"MOV E,A", 0x5F}

    }; 
}



