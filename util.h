vector<string> tokenizeString(string str, char delim=' '){
    vector<string> res;
    string word = "";
    for(int i=0; i<str.length(); i++){
        if(str.at(i)==delim){
            res.push_back(word);
            word = "";
        }
        else{
            word = word + str.at(i);
        }
    }
     res.push_back(word);
    return res;
}

string itohex(int n, int size =4){
    string res = "";
    int d;
    while(n){
        d = n%16;
        if(d==15) res = "F" + res;
        else if(d==14) res = "E" + res;
        else if(d==13) res = "D" + res;
        else if(d==12) res = "C" + res;
        else if(d==11) res = "B" + res;
        else if(d==10) res = "A" + res;
        else res =  to_string(d) + res;
        n/=16;
    }
    
    for(int i=res.length();i<size; i++)
        res = "0" + res;
    return res;
}

int hextoi(string hex){
    int i = 0; char d;
    for(int j=hex.length()-1, k=1; j>=0; j--){
        d= hex.at(j);
        if(d=='F') i += 15*k;
        else if(d=='E') i += 14*k;
        else if(d=='D') i += 13*k;
        else if(d=='C') i += 12*k;
        else if(d=='B') i += 11*k;
        else if(d=='A') i += 10*k;
        else i +=  (d-'0')*k;
        k *= 16;      
    }
    return i;
}

vector<string> tokenizebytes(string bytes){
    vector<string> byte; 
    string a = "";
    for(int i=0; i<bytes.length(); i+=2) { a+=bytes.at(i); a+=bytes.at(i+1); byte.push_back(a); a=""; }
    return byte;
}