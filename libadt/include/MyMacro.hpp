#ifndef MY_MACRO
#define MY_MACRO

namespace ADT
{
#define BITSOFBYTE 8
#define bitsizeof(t) (sizeof((t)) * BITSOFBYTE)
  
#ifndef Max
#define Max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef Min
#define Min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
  
}

#endif
