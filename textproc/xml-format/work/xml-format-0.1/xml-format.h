
#define COPY_BUFF_SIZE  16384
#define MAX_LINE_LEN    4096
#define MAX_COLS        80

#define MAX(x,y)    ((x) > (y) ? (x) : (y))
#define MIN(x,y)    ((x) < (y) ? (x) : (y))

#define INCREASE(indent,step)    (indent = MIN((indent+step),40))
#define DECREASE(indent,step)    (indent = MAX((indent-step),0))

#include "protos.h"

