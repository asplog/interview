#ifndef __BINARY__
#define __BINARY__
void binary_write(unsigned int value,int fd);
unsigned int binary_from_string(const char*str);
unsigned int binary_pop(unsigned int);
unsigned int binary_ntf(unsigned int);
unsigned int binary_ntt(unsigned int);
unsigned int binary_nlf(unsigned int);
unsigned int binary_nlt(unsigned int);
unsigned int binary_dozu(unsigned int,unsigned int);
int binary_doz(int,int);
#endif
