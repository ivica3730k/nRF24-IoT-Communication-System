
#include <iostream>
#include <string.h>
#include "payloads.h"
using namespace std;

int main(int argc, char** argv)
{

    payload pload;
    float a = 3.14159238;
    pload = makePayload(a,0XAABBCCDE);

    short type = ploadType(pload);
    cout<<a<<endl;

    if(type == is_uint64_t){
        uint64_t result = castTo_uint64_t(pload);
        cout<<result;
    }
    else if(type == is_float){
        float result = castTo_float(pload);
        cout<<result;
    }

    return 0;

}
