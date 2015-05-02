# OpenSlider
After being thoroughly impressed by the flying faders on my church's new soundboard, and being completely unimpressed by the lack of flying faders in DMX consoles, I have decided to work towards remedying this.

##Basic hardware specifications
* Uses any standard off the shelf motorized pot with a minimum of 1 track.
  * any additional linked pots can be used for the Users' purposes
* minimum of 8 digital inputs
* SPI and IIC busses for expansion
  * 2 CS lines for SPI
* Optional ~1” 64px or better LCD/OLED for status/scribblestrip
  * RGB Outputs for LCD backlight
* Interface bus is user selectable
  * CAN
  * Multipoint RS485
  * Multimaster IIC for comms.
  * USART breakout pins available for debugging
*EEPROM/FLASH for storing default settings,icons,configurations,fonts

##Firmware features
* Link multiple sliders together
* force feedback detent over center or userdefineable points
* Built in support for SPI and IIC LED Drivers, up to 8 RGB LEDs
* LCD can be programmed to switch between icons, and display text/slider value.
* Slider value transfer curve can be reported in the following formats
  * 0 to <ADC_MAX>(default)
  * 0 to 255
  * 0.0 to 1.0 floating point,
  * NEG_INF dB to +15dB,
  * User definable cubic spline
  * User definable Log and Anti-log(exponential) curves
  * User definable <TBD>pt transfer map with quadratic interpolation
* Custom Screens on LCD, complete with graphics sprites and overlayable text.
* Self Programming for development support

