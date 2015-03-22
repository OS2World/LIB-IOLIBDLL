 
#define __IOLIBDLL_C__
#define INCL_DOSDEVIOCTL
#define INCL_DOSERRORS
#define INCL_DOSPROCESS
#define INCL_DOS

#include <os2.h>
#include <stdio.h>
#include <string.h>

#include "iolib.h"
#include "iolibdll.h"

HFILE 	 driver_handle=0;

int main(void)
{
   return(1);
 }

int __dll_initialize(void)
{
        
        USHORT      rc;
        ULONG ActionTaken;
        unsigned long cbreturn;

        //Open the fastio driver
        if ((rc = DosOpen((PSZ) "wfastio$", &driver_handle, &ActionTaken, 0, 0, FILE_OPEN,
        	OPEN_SHARE_DENYNONE | OPEN_ACCESS_READWRITE, NULL)) !=0)
                {

                // Error code
                return 1;
		}
        cbreturn = sizeof(gdt);
        DosSleep(5);

        //IOCTL call obtains the gdt entry for I/O routines
        rc = DosDevIOCtl(driver_handle, 0x76, 0x60,(void *) 0, 0, 0,
		(void *) &gdt, cbreturn, &cbreturn);

       //Convert the gdt entry to a callable pointer. 16:32 indirect segment call
       rc = io_init();
       return 1;
 } 

int __dll_terminate(void)
{
   DosClose(driver_handle);
   return(1);
 }


//DLL Function to set up ioentry for making calls
int _export APIENTRY GetGdt(void)
{
   return gdt;
}

//Reads and returns a byte value from the specified hardware port
unsigned char _export APIENTRY inp(unsigned short port)
{
   return c_inb(port);
}

//Reads and returns a word value form the specified hardware port
unsigned short _export APIENTRY inport(unsigned short port)
{
   return c_inw(port);
}

//Reads and retuens a byte value from the specified hardware port
unsigned char _export APIENTRY  inportb(unsigned short port)
{
   return c_inb(port);
 }

 //Reads and returns a word from the specified hardware port
unsigned short _export APIENTRY inpw(unsigned short port)
{
   return c_inw(port);
 }

//Sends a byte to a hardware output port.
void _export APIENTRY outp(unsigned short port, unsigned char value)
{
   c_outb(port, value);
 }

//Sends a word to a hardware output port.
void _export APIENTRY outport(unsigned short port, unsigned short value)
{
   c_outw(port, value);
 }

//Sends a byte to a hardware output port
void _export APIENTRY outportb(unsigned short port, unsigned char value)
{
   c_outb(port, value);
}

//Reads and returns a word from the specified hardware port
void _export APIENTRY outpw(unsigned short port, unsigned short value)
{
   c_outw(port, value);
}

//Writes a byte to the specified hardware port
EXT void EXP OUTP8(unsigned short port, unsigned char value)
{
   c_outb(port, value);
}

//Writes a word to the specified hardware port
EXT void EXP OUTP16(unsigned short port, unsigned short value)
{
   c_outw(port, value);
}

//Reads a byte from the hardware port
EXT unsigned char EXP INP8(unsigned short port)
{             
   return c_inb(port);
}

//Reads a word from the hardware port
EXT unsigned short EXP INP16(unsigned short port)
{                 
   return c_inw(port);
}
