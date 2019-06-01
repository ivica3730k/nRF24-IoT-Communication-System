
#include <iostream>
#include <fstream>
#include <string>
#include "ArduinoJson/src/ArduinoJson.h"
#include "HTTPRequest-master/include/HTTPRequest.hpp"
#include "payloads.h"
using namespace std;

int main(int argc, char** argv)
{

    payload pload;
    int32_t a = 72138;
    pload = makePayload(a,0XFFFFFFFF);
    string c = payloadDataToString(pload.data);
    //cout<<c<<endl;

    DynamicJsonDocument  doc(200);
    doc["id"] = pload.id;
    doc["datatype"] = pload.datatype;
    doc["data"] = c;
    serializeJsonPretty(doc, std::cout);

    /*
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
    cout<<type<<endl;
    if(type == is_uint64_t){
        uint64_t result = castTo_uint64_t(bload);
        cout<<result;
    }
    else if(type == is_float){
        float result = castTo_float(bload);
        cout<<result;
    }
    else if(type == is_uint8_t){
        float result = castTo_uint8_t(bload);
        cout<<result;
    }
    else if(type == is_int8_t){
        float result = castTo_int8_t(bload);
        cout<<result;
    }

    return 0;
*/
}
