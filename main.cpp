#include <iostream>
#include <fstream>
#include <string>

#include "C++Libs/ArduinoJson/src/ArduinoJson.h"
#include "C++Libs/HTTPRequest-master/include/HTTPRequest.hpp"
#include "C++PyModules/payloads.h"

using namespace std;


int main(int argc, char** argv)
{
    payload pload;
    uint8_t a = 231345;
    pload = makePayload(a,0XFFFFFFFF);
    DynamicJsonDocument doc(256);
    doc["id"] = pload.id;
    doc["datatype"] = pload.datatype;
    doc["data"] = pload.data;
    serializeJsonPretty(doc, std::cout);


    return 0;
}
