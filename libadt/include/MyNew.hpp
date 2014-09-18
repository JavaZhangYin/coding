#ifndef MY_NEW
#define MY_NEW

#ifdef __DEBUG_NEW__

#ifdef USE_SELF_POOL

#define new(p) DEBUG_NEW(p)
#define DEBUG_NEW(p) new((p), (char*)__FILE__, (int)__LINE__)
#define delete(p, q) DEBUG_DELETE((p), (q))
#define DEBUG_DELETE(p, q) operator delete((p), (q), (char*)__FILE__, (int)__LINE__)

#else


#define new DEBUG_NEW
#define DEBUG_NEW new((char*)__FILE__, (int)__LINE__)
#define delete(p) DEBUG_DELETE(p)
#define DEBUG_DELETE(p) operator delete((p), (char*)__FILE__, (int)__LINE__)

#endif

#endif

#endif //MY_NEW
