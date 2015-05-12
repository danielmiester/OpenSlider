#include "protocol.h"


//#123:123,123;
Protocol::Protocol(address_t addr){
  _buf = malloc(PROTOCOL_BUF_SIZE);
  _address = addr;
  _command = Protocol::VERB::IDLE;
}
Protocol::inputData(size_t len, char* data){
    
}
Protocol::setAddress(address_t addr){
	_address = addr;
}
Protocol::stateMachine(char data){
	switch(state){
	case Protocol::STATE::IDLE:
	    if(_prev_char != '\\'){
    		switch(data){
    	    case Protocol::VERB::QUERY:
    	    case Protocol::VERB::SET:
    	    case Protocol::VERB::ANNC:
    	    case Protocol::VERB::SYS:
    	    	_state =  Protocol::STATE::FOUND_VERB;
    	    	_command = (Protocol::VERB)data;
    	    	_error = 0;
    	    	break;
    		default:
    		    _state =  Protocol::STATE::IDLE;
    	    	_command = Protocol::VERB::IDLE;
    	    	_error = -1;
    	    	break;
    		}
	    }
	    break;
	case Protocol::STATE::FOUND_VERB:
	    switch(data){
	    case '0' ... '9':
	       _buf[_buf_pointer++] = data;
        case ':':
            _state = Protocol::STATE::FOUND_ADDR_DELIM;
            _command =    
	    }
	}
}
Protocol::processData(char data){
	this->stateMachine(data);
	switch(state){
	case 
	}
}
