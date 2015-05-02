#OpenSlider Interface Protocol
OpenSlider uses a simple yet powerful text based protocol that can be switched to a binary version for improving bus capacity
##Format
All transactions on the wire consist of a verb, an address and optional comma separated parameters, terminated with a semicolon ';'
##Verbs
Currently Supported Verbs:
* `!` - **Announce,repsonse**
  * Responses from Sliders when a parameter is queried
  * Broadcast from Sliders when a parameter is changed
    * When manual changes occur, format takes the form `!<address>,function,values;`
    * When triggered by programmatic change, the form is `!<address>?;` for a negative ACK, or `!<address>!;` for a positive ACK
  * **Example**: In reponse to querying the fader value on slider 123: `!123,0,33;`
* `?` - **Query**
  * Used for retrieving values from the slider
  * **Example**: Get the fader setting on slider 123 (currently set to 33%) `?123,0;` **Response:** `!123,0,33;`
* `=` - **Set**
  * Used for setting a value
  * **Example:** Set the fader level on 123: `=123,0,50;` **Response:** `!123!;`
* `&` - **System command**
  * Definition TBD

##Addressing
Addresses are to be written in hexadecimal, and are sign-extended to 32 bits if less than 8 hex characters are specified
This means that `FF` is internally extended to `FFFFFFFF` in the slider, while `7f` is internally extended to `0000007F`.
This allows for access to the special addresses in a more compact form.
Special addresses are all addresses with the most significant bit set.
`FF` is used to broadcast to all nodes
`00` is used as a special announce address used to gather data from all nodes in one go.

##Notes and considerations
Just my musings on the future of this protocol
* Figure out the details of mass gather
* Figure out binary method
* Direct parameter addressing

##Binary mode
TBD


##Pseudo BNF:
```
query			= "?";
set				= "=";
announce		= "!";
system			= "&";
verb			= query | set | announce | system;
address			= 1*8hex_digit;
data			= '"' , string , '"' | 1*2hex_digit
statement		= verb,address,{",", <data>},";";
```
