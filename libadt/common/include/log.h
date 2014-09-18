#ifndef LOG_H
#define LOG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  inline bool xmlBegin(FILE *stream, char const *title)
  { 
    time_t now; 
    int retval; 
    now = time(NULL); 
    retval = fprintf(stream, "<%s>\r\n\t", title); 
    if(retval < 0) 
      { 
	perror("xmlBegin"); 
	return false;
      }
    retval = fprintf(stream, "<time>\r\n\t%s\r\t</time>\r\n\t<content>\r\n\t", ctime(&now));
    if(retval < 0)
      {
	perror("xmlBegin");
	return false;
      }
    return true;
  } /* end xmlBegin */

  inline bool xmlEnd(FILE *stream, char const *title)
  {
    int retval;
    retval = fprintf(stream, "\r\t</content>\r\n</%s>\r\n", title);
    if(retval < 0)
      {
	perror("xmlEnd");
	return false;
      }
    return true;
  } /* end xmlEnd */
  
  inline void log2file(char const *format, ...)
  {
    int retval;
    FILE *stream = LOGFILE;
    if(!xmlBegin(stream, "log"))
      {
	return;
      }

    va_list ap;
    va_start(ap, format);
    retval = vfprintf(stream, format, ap);
    va_end(ap);
    
    if(retval >= 0) retval = fprintf(stream, "\r\n");
    if(retval < 0)
      {
	perror("log2file");
      }
    
    xmlEnd(stream, "log");
  } /* end log2file */

#define LOG2FILE log2file

#ifdef USE_LOG
#ifdef USE_LOG_HOOK
#define LOG LOG_HOOK
#else
#define LOG LOG2FILE
#endif /* USE_LOG_HOOK */
#else
#define LOG
#endif /* USE_LOG */

#define PARAMLOG2FILE(param, paramstr, paramlogfile) inline void param##log2file(char const *format, ...) \
  { \
    int retval; \
    FILE *stream = paramlogfile;\
    char title_begin[PARAM_MAX], title_end[PARAM_MAX]; \
    if(!xmlBegin(stream, paramstr)) \
      { \
	return; \
      } \
    va_list ap; \
    va_start(ap, format);\
    retval = vfprintf(stream, format, ap);\
    va_end(ap);\
    if(retval >= 0) retval = fprintf(stream, "\r\n");\
    if(retval < 0)\
      {\
	perror("log2file");\
      }\
    xmlEnd(stream, paramstr); \
  } /* end log2file */

#ifdef USE_ERRLOG
  PARAMLOG2FILE(err, "err", ERRLOGFILE)
#define ERRLOG2FILE errlog2file

#ifdef USE_ERRLOG_HOOK
#define ERRLOG ERRLOG_HOOK
#else
#define ERRLOG ERRLOG2FILE
#endif /* USE_ERRLOG_HOOK */
#else
#define ERRLOG
#endif /* USE_ERRLOG */

#ifdef __cplusplus
       }
#endif /* __cplusplus */

#endif /* LOG_H */
