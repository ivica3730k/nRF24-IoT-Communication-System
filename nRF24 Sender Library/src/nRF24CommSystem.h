#include <Arduino.h>
#include <RF24.h>

#define is_char 1
#define is_char16_t 2
#define is_char32_t 3
#define is_int8_t 4
#define is_int16_t 5
#define is_int32_t 6
#define is_int64_t 7
#define is_uint8_t 8
#define is_uint16_t 9
#define is_uint32_t 10
#define is_uint64_t 11
#define is_float 12
#define is_double 13
#define is_long_double 14

struct payload {
    uint32_t id;
    short datatype;
    /*pload dataytpe varies from data that we want to send
     * 0 for raw data
     * 1 for char
     * 2 for char16_t
     * 3 for char32_t
     * 4 for int8_t
     * 5 for int16_t
     * 6 for int32_t
     * 7 for int64_t
     * 8 for uint8_t
     * 9 for uint16_t
     * 10 for uint32_t
     * 11 for uint64_t
     * 12 for float
     * 13 for double
     * 14 for long double
     */
    char data[26];
};

class nRF24CommSystem{
    public:
        nRF24CommSystem(RF24 &_device);
        void setup(const uint32_t &_uplinkPipe,unsigned int &_channel);
    private:
        RF24 *nRF24;
        uint32_t uplinkPipe;
        unsigned int channel;
};