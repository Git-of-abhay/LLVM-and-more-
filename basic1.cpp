#include<bits/stdc++.h>

using namespace std;
#define dxt string::npos
string parse_output_line(const string& line){
    size_t pos=line.find("output");
    if(pos==dxt) throw runtime_error("expected 'output'");
        size_t pos1=line.find('"',pos+6);
        if(pos1==dxt) throw runtime_error("expected opening quote after output");
            size_t pos2=line.find('"',pos1+1);
            if(pos2==dxt) throw runtime_error("expected closing quote after output");
            return line.substr(pos1+1,pos2-pos1-1);
}

int main(){
    string line;
    getline(cin,line);
    try { cout << parse_output_line(line) << endl; }
    catch (const exception& error) { cerr << "error: " << error.what() << '\n'; return 1; }
    return 0;
}
