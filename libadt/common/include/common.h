#ifndef COMMON_H
#define COMMON_H

/*Use C style symbol names.*/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  /* Set the maxmium length of the parameter. */
#ifndef PARAM_MAX
#define PARAM_MAX 128
#endif

  /*
   * This is the logging system for ADT.
   * log messages will be directed to the standard output.
   */
#ifndef LOGFILE
#define LOGFILE stdout
#endif

  /* Redirect error messages to stderr */
#ifndef ERRLOGFILE
#define ERRLOGFILE stderr
#endif

  /* Macro to debug the project, and the output will be directed to standard output*/
#ifndef DEBUGFILE
#define DEBUGFILE stdout
#endif /* DEBUGFILE */

  /* Path to store the log files. Default to current directory. */
#ifndef LOGFILE_PATH
#define LOGFILE_PATH "."
#endif

  /* Path to store the error log files. Default to current directory. */
#ifndef ERRLOGFILE_PATH
#define ERRLOGFILE_PATH "."
#endif

  /* Path to store the debug files. Default to current directory. */
#ifndef DEBUFFILE_PATH
#define DEBUGFILE_PATH "."
#endif

#ifdef USE_INITHOOK
#define INIT INITHOOK
#else
#ifdef USE_FILE_DEFAULT
#define INIT() initlog(); initerrlog(); initdebug()
#else
#define INIT()
#endif
#endif

#ifdef USE_EXITHOOK
#define EXIT EXITHOOK
#else
#ifdef USE_FILE_DEFAULT
#define EXIT(p) exitlog(); exiterrlog(); exitdebug(); exit(p)
#else
#define EXIT(p) exit(p) 
#endif
#endif
#include <stdio.h>
#include <string.h>

  inline FILE* setupfile(char const *dir, char const *name)
  {
    time_t now;
    struct tm local_time;
    char digits[16];
    char filename[PARAM_MAX];
    int retval;
    FILE *stream;
    
    now = time(NULL);
    local_time = *(localtime(&now));
    
    if(dir == NULL)
      sprintf(filename, "./%s_", name);
    else
      sprintf(filename, "%s/%s_", dir, name);
 
    sprintf(digits, "%d", local_time.tm_year + 1900);
    strcat(filename, digits);
    strcat(filename, "_");

    sprintf(digits, "%u", local_time.tm_mon + 1);
    strcat(filename, digits);
    strcat(filename, "_");

    sprintf(digits, "%u", local_time.tm_mday);
    strcat(filename, digits);
    strcat(filename, "_");

    sprintf(digits, "%u", local_time.tm_min);
    strcat(filename, digits);
    strcat(filename, "_");

    sprintf(digits, "%u", local_time.tm_sec);
    strcat(filename, digits);

    strcat(filename, ".xml");

    if((stream = fopen(filename, "wb")) == NULL)
      {
	perror("setupfile");
      }
    return stream;
  }
  
  inline void initlog() 
  {
#ifdef USE_FILE_DEFAULT
    LOGFILE = setupfile(LOGFILE_PATH, "log"); 
#endif
	}

  inline void exitlog()
  {
#ifdef USE_FILE_DEFAULT
    if(LOGFILE != NULL)
      fclose(LOGFILE);
    LOGFILE = 0;
#endif
  }
  
  inline void initerrlog() 
  {
#ifdef USE_FILE_DEFAULT
    ERRLOGFILE = setupfile(ERRLOGFILE_PATH, "errlog");
#endif
  }

  inline void exiterrlog()
  {
#ifdef USE_FILE_DEFAULT
    if(ERRLOGFILE != NULL)
      fclose(ERRLOGFILE);
    ERRLOGFILE = 0;
#endif
  }
  
  inline void initdebug() 
  {
#ifdef USE_FILE_DEFAULT
    DEBUGFILE = setupfile(DEBUGFILE_PATH, "debug");
#endif
  }

  inline void exitdebug()
  {
#ifdef USE_FILE_DEFAULT
    if(DEBUGFILE != NULL)
      fclose(DEBUGFILE);
    DEBUGFILE = 0;
#endif
  }

#ifdef __cplusplus
}
#endif /* ednif __cplusplus */

#endif /* endif COMMON_H */
