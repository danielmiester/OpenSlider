#ifndef protocol_h
#define protocol_h
#include "Arduino.h"

const size_t PROTOCOL_BUF_SIZE 65;
typedef int32_t address_t;

class Protocol{
  public:
    enum STATE{
      IDLE,
      FOUND_VERB,
      FOUND_ADDR,
      FOUND_ADDR_DELIM,
      FOUND_DATA,
      FOUND_DATA_DELIM
    };
    enum VERB:char{
      QUERY='?',
      SET='=',
      ANNC='!',
      SYS='$',
      IDLE
    };
    enum COMMAND{
      NOP,
      DATA_RECIEVED,
      ADDRESS_DATA_RECIEVED,
      ADDRESS_COMPLETED
    };
    Protocol(address_t addr);
    void inputData(size_t len, char* data);
    void setAddress(address_t addr);
    void processData(void);
  private:
    address_t  _address;
    char*     _buf;
    int       _buf_pointer;
    char      _prev_char;
    uint8_t   _state;
    VERB      _command;
    char      _error;
};
#endif
