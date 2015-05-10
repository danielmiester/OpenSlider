#include "Arduino.h"
#include "protocol.h"


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
	case Protocol::STATE::IDLE:
	    if(_prev_char != '\'){
    		switch(data){
    		    case Protocol::VERB::QUERY:break;
    		    
    		}
	    }
	}
}
Protocol::processData(char data){
	this->stateMachine(data);
	switch(state){
	case 
	}
}
