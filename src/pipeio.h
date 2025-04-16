#ifndef __PIPEIO_H_
#define __PIPEIO_H_

#include <functional>
#include "conptytypes.h"

#define REXPORT __declspec(dllexport)
#define RCALL __stdcall

extern "C" {
typedef void (*RustCallback)(int fd, char* data, int len);

// Brige to startReadListener
REXPORT void RCALL startReadListenerBridge(int id, RustCallback cb);

/**
 * Writing data to ConPty.
 */
REXPORT void RCALL writeData(int, const char*);
}

/**
 * Starting a thread to listen the read pipe to get data from conpty.
 */
void startReadListener(int, std::function<void(int, char*, int)>);
#endif
