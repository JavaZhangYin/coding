#ifndef DEBUG_H
#define DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define DEBUG_FPRINTF0(text) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : %s\n", \
__FILE__, __LINE__, __PRETTY_FUNCTION__, (text));


#define DEBUG_FPRINTF1(format, text) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (text)); fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF2(format, t1, t2) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2)); fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF3(format, t1, t2, t3) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2), (t3)); fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF4(format, t1, t2, t3, t4) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2), (t3), (t4));  fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF5(format, t1, t2, t3, t4, t5) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2), (t3), (t4), (t5)); fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF6(format, t1, t2, t3, t4, t5, t6) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2), (t3), (t4), (t5), (t6)); fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF7(format, t1, t2, t3, t4, t5, t6, t7) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2), (t3), (t4), (t5), (t6), (t7)); fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF8(format, t1, t2, t3, t4, t5, t6, t7, t8) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2, (t3), (t4), (t5), (t6), (t7), (t8)); fprintf(DEBUGFILE, "\n");

#define DEBUG_FPRINTF9(format, t1, t2, t3, t4, t5, t6, t7, t8, t9) \
fprintf(DEBUGFILE, "File : %s   Line : %d\nFunction : %s\nDebug info : ", \
__FILE__, __LINE__, __PRETTY_FUNCTION__); fprintf(DEBUGFILE, (format), (t1), (t2), (t3), (t4), (t5), (t6), (t7), (t8), (t9)); fprintf(DEBUGFILE, "\n");


#ifdef USE_DEBUG
#ifdef USE_DEBUG_HOOK
#define DEBUG DEBUG_HOOK
#else
#define DEBUG0 DEBUG_FPRINTF0
#define DEBUG1 DEBUG_FPRINTF1
#define DEBUG2 DEBUG_FPRINTF2
#define DEBUG3 DEBUG_FPRINTF3
#define DEBUG4 DEBUG_FPRINTF4
#define DEBUG5 DEBUG_FPRINTF5
#define DEBUG6 DEBUG_FPRINTF6
#define DEBUG7 DEBUG_FPRINTF7
#define DEBUG8 DEBUG_FPRINTF8
#define DEBUG9 DEBUG_FPRINTF9

#endif /* USE_DEBUG_HOOK */
#else
#define DEBUG0 
#define DEBUG1 
#define DEBUG2 
#define DEBUG3 
#define DEBUG4 
#define DEBUG5 
#define DEBUG6 
#define DEBUG7 
#define DEBUG8 
#define DEBUG9 

#endif /* USE_DEBUG */

#ifndef DEBUG
#define DEBUG DEBUG0
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DEBUG_H */
