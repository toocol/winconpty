#ifndef __PIPEIO_H_
#define __PIPEIO_H_

#include <functional>
#include "conptytypes.h"

// C ABI 
extern "C" typedef void (*RustCallback)(char* data, int len);

// C ABI Brige to startReadListener
extern "C" __declspec(dllexport) void startReadListenerBridge(int id,
                                                              RustCallback cb);

/**
 * Starting a thread to listen the read pipe to get data from conpty.
 */
__declspec(dllexport) void startReadListener(int,
                                             std::function<void(char*, int)>);
/**
 * Writing data to ConPty.
 */
__declspec(dllexport) void writeData(int, const char*);

#endif
