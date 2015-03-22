
/* Copyright (C) 1996 by  Alger Pike ( Alger@avenger.mri.psu.edu */
/* Use at your own risk! No Warranty! The author(s) is not responsible for
 * any damage or loss of data caused by proper or improper use of this
 * device driver or related software
 */
/*           wiolib 1.0- handles resources for wfastio.sys
                             exproted functions allow user to
                             access the driver's I/O services.  To
                             use this file include this file link in
                             wiolib.lib and you can call any of
                             I/O functions below.  Note the driver
                             initialization is done for you automatically
                             when the wiolibdll.dll is loaded by
                             the calling application.- Enjoy!  */
              


#ifndef __IOLIBDLL_H__

#define __IOLIBDLL_H__

//Preprocessor directives to determine whether
//we are compiling the dll or application code

#ifdef __IOLIBDLL_C__
	#define EXP _export
	#define EXT
#else
	#define EXP
	#define EXT extern
#endif

//Function to return Gdt to application
//If zero the device driver is not loaded
//Makes a good test function
EXT int EXP APIENTRY GetGdt(void);

//Reads and returns a byte value from the specified hardware port
EXT unsigned char EXP APIENTRY inp(unsigned short port);

//Reads and returns a word value form the specified hardware port
EXT unsigned short EXP APIENTRY inport(unsigned short port);

//Reads and retuens a byte value from the specified hardware port
EXT unsigned char EXP APIENTRY inportb(unsigned short port);

//Reads and returns a word from the specified hardware port
EXT unsigned short EXP APIENTRY inpw(unsigned short port);

//Sends a byte to a hardware output port.
EXT void EXP APIENTRY outp(unsigned short port, unsigned char value);

//Sends a word to a hardware output port.
EXT void EXP APIENTRY outport(unsigned short port, unsigned short value);

//Sends a byte to a hardware output port
EXT void EXP APIENTRY outportb(unsigned short port, unsigned char value);

//Writes a word from the specified hardware port
EXT void EXP APIENTRY outpw(unsigned short port, unsigned short value);

//Writes a byte to the specified hardware port
EXT void EXP OUTP8(unsigned short port, unsigned char value);

//Writes a word to the specified hardware port
EXT void EXP OUTP16(unsigned short port, unsigned short value);

//Reads a byte from the hardware port
EXT UCHAR INP8(unsigned short port);

//Reads a word from the hardware port
EXT USHORT INP16(unsigned short port);

#endif