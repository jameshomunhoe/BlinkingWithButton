/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_BUTTON_H
#define _MOCK_BUTTON_H

#include "Button.h"

void mock_Button_Init(void);
void mock_Button_Destroy(void);
void mock_Button_Verify(void);




#define isButtonPress_IgnoreAndReturn(cmock_retval) isButtonPress_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void isButtonPress_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
#define isButtonPress_ExpectAndReturn(cmock_retval) isButtonPress_CMockExpectAndReturn(__LINE__, cmock_retval)
void isButtonPress_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
typedef _Bool (* CMOCK_isButtonPress_CALLBACK)(int cmock_num_calls);
void isButtonPress_StubWithCallback(CMOCK_isButtonPress_CALLBACK Callback);

#endif
