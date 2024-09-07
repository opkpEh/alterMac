#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef long long int int64;

struct s_mac {
  int64 addr:48;
};

typedef struct s_mac Mac;

Mac generatemac(void);

int main(int , char**);

Mac generatemac() {
  int64 a, b;
  Mac mac;

  a= (long)random();
  b= (long)random();
  
  mac.addr = ((a*b) % 281474976710656);

  return mac;
}

int main(int argc , char *argv[])
{
  srand(getpid());
  mac= generatemac();
  printf("0x%ll\n", mac.addr);

}
