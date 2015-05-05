#include "Arduino.h"
#include "protocol.h"

Protocol::Protocol(address_t addr){
  _buf = malloc(PROTOCOL_BUF_SIZE);
  _address = addr;
}
Protocol::inputData(size_t len, char* data){
    
}
Protocol::setAddress(address_t addr){
	_address = addr;
}
Protocol::processData(void){}