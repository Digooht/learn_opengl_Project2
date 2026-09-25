#pragma once //防止重编译



//预编译宏

#ifdef DEBUG

#define GL_CALL(func) func;checkError();

#else

#define GL_CALL(func) func;

#endif // DEBUG

#pragma once 

void checkError();
