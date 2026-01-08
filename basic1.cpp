#include<bits/stdc++.h>
using namespace std;

#define dxt string::npos
int main(){
    string line;
    getline(cin,line);
    size_t pos=line.find("output");
    if(pos==dxt) cerr<<"error: expected 'output'\n";
    else{
        size_t pos1=line.find('"',pos+6);
        if(pos1==dxt) cerr<<"Error: Expected opening after output '\"'\n";
        else{
            size_t pos2=line.find('"',pos1+1);
            if(pos2==dxt) cerr<<"Error: Expected closing  after output '\"'\n";
            else{
                string toprint = line.substr(pos1+1,pos2-pos1 - 1 );
                cout<<toprint<<endl;
            }
        }
    }
    return 0;
}
