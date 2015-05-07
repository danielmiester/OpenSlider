#ifndef protocol_h
#define protocol_h
#include "Arduino.h"

const size_t PROTOCOL_BUF_SIZE 65;
typedef int32_t address_t;

class Protocol{
  public:
    Protocol(address_t addr);
    void inputData(size_t len, char* data);
    void setAddress(address_t addr);
    void processData(void);
  private:
    address_t  _address;
    char*     _buf;
    int       _buf_pointer;
    uint8_t   _state;
};
#endif
