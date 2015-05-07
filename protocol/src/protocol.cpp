#include "Arduino.h"
#include "protocol.h"
#define IDLE 	0
#define FOUND_VERB 1
#define FOUND_ADDR 2
#define FOUND_ADDR_DELIM 3
#define FOUND_DATA 4
#define FOUND_DATA_DELIM 5

//#123:123,123;
Protocol::Protocol(address_t addr){
  _buf = malloc(PROTOCOL_BUF_SIZE);
  _address = addr;
}
Protocol::inputData(size_t len, char* data){
    
}
Protocol::setAddress(address_t addr){
	_address = addr;
}
Protocol::stateMachine(char data){
	switch(state){
	case IDLE:
		if(data){}	
	}
}
Protocol::processData(char data){
	this->stateMachine(data);
	switch(state){
	case 
	}
}
