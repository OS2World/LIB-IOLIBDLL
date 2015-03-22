/* Copyright (C) 1995 by Holger Veit (Holger.Veit@gmd.de) */
/* Copyright (C) 1996 by  Alger Pike ( Alger@avenger.mri.psu.edu */
/* Use at your own risk! No Warranty! The author(s) is not responsible for
 * any damage or loss of data caused by proper or improper use of this
 * device driver or related software
 */

#ifndef _IOLIB_H
#define _IOLIB_H

#if     defined(__BORLANDC__)
#define _System _cdecl
#endif

#if defined (__WATCOMC__)
  #pragma aux io_init parm [] caller reverse;
  #pragma aux c_inb parm [] caller reverse;
  #pragma aux c_inw parm [] caller reverse;
  #pragma aux c_inl parm [] caller reverse;
  #pragma aux c_outb parm [] caller reverse;
  #pragma aux c_outw parm [] caller reverse;
  #pragma aux c_outl parm [] caller reverse;
  #pragma aux c_enon parm [] caller reverse;
  #pragma aux c_enoff parm [] caller reverse;
  #pragma aux c_getcount parm [] caller reverse;
  #pragma aux c_setcount parm [] caller reverse;
#endif
extern unsigned short gdt;

int _System io_init(void);
char _System c_inb(short port);
short _System c_inw(short port);
long _System c_inl(short port);
void _System c_outb(short port, unsigned char value);
void _System c_outw(short port, short data);
void _System c_outl(short port, long data);
void _System c_enon();
void _System c_enoff();
unsigned long _System c_getcount(void);
void _System c_setcount(unsigned long value);

#endif  /* _IOLIB_H */
