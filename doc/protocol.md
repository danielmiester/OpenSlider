#OpenSlider Interface Protocol
OpenSlider uses a simple yet powerful text based protocol.
##Format
All transactions on the wire consist of a verb, an address and optional comma separated parameters, terminated with a semicolon ';'
##Verbs
Currently Supported Verbs:
* '?'

```
query			= "?";
set				= "=";
announce		= "!";
system			= "&";
verb			= query | set | announce | system;
address			= 2*hex_digit;
data			= '"' , string , '"' | 2*hex_digit
statement		= verb,address,{",", <data>};

```
