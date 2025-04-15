#ifndef __WINCONPTY_H_
#define __WINCONPTY_H_

#include "pipeio.h"

extern "C" {
/**
 * Open a Windows pseudo console, and return the fd.
 */
REXPORT int RCALL openConPty(int, int);
/**
 * Set global utf8 mode.
 */
REXPORT void RCALL setUTF8Mode(bool);
/**
 * Close Windows pseudo console by fd.
 */
REXPORT void RCALL closeConPty(int);
/**
 * Resize Windows pseudo console by fd.
 */
REXPORT void RCALL resizeConPty(int, int, int);
/**
 * Start an sub process by command and combine it to Windows pseudo console by
 * fd.
 */
REXPORT bool RCALL startSubProcess(int, LPWSTR);
}
#endif
