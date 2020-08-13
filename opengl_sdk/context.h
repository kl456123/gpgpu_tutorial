#ifndef CONTEXT_H_
#define CONTEXT_H_
#include "opengl.h"

const char *GLGetErrorString(GLenum error);
void OpenGLCheckErrorWithLocation(int line);


#define OPENGL_CALL(func)                                                      \
{                                                                            \
    (func);                                                                    \
    OpenGLCheckErrorWithLocation(__LINE__);                                                      \
}

#define OPENGL_CHECK_ERROR            \
    OpenGLCheckErrorWithLocation(__LINE__)



#endif
