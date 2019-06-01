
#include <iostream>
#include <string.h>
#include "payloads.h"
using namespace std;

int main(int argc, char** argv)
{

    payload pload;
    float a = 3.14159238;
    pload = makePayload(a,0XAABBCCDE);
    string b = payloadDataToString(pload.data);
    cout<<b<<endl;
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
