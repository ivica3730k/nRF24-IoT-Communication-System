
#include <iostream>
#include <fstream>
#include <string>
#include "payloads.h"
using namespace std;

int main(int argc, char** argv)
{

    payload pload;
    uint64_t a = UINT64_MAX;
    pload = makePayload(a,0XAABBCCDE);
    string c = payloadDataToString(pload.data);
    cout<<c<<endl;

    std::ofstream out("output.txt");
    out << c;
    out.close();

    string b;

    ifstream myfile ("output.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,b) )
        myfile.close();
    }

    payload bload;

    for(int i = 0; i<b.length();i++){
        bload.data[i] = b[i];
    }

    bload.datatype = pload.datatype;
    bload.id = pload.id;


    short type = ploadType(bload);

    if(type == is_uint64_t){
        uint64_t result = castTo_uint64_t(bload);
        cout<<result;
    }
    else if(type == is_float){
        float result = castTo_float(bload);
        cout<<result;
    }

    return 0;

}
