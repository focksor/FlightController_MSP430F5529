#ifndef INCLUDE_PPM_H_
#define INCLUDE_PPM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <msp430.h>
#include <sys.h>

#define Normal 1
#define ToHeight 2

void PPM_Capture_Init();
void fresh_rc(int);

extern __rc_channel rc;

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_PPM_H_ */
