#include "unity.h"
#include "mock_Button.h"
#include "Message.h"
#include "ButtonSM.h"


void setUp(void){}

void tearDown(void){}



void test_buttonInitData_should_set_state_to_RELEASE(){



  ButtonData button;



  buttonInitData(&button);



  UnityAssertEqualNumber((_U_SINT)((RELEASE)), (_U_SINT)((button.state)), (((void *)0)), (_U_UINT)15, UNITY_DISPLAY_STYLE_INT);



}



void test_buttonSM_should_set_state_to_PRESS(){



  ButtonData button;



  isButtonPress_CMockExpectAndReturn(23, 1);



  buttonInitData(&button);

  buttonSM(&button);





  UnityAssertEqualNumber((_U_SINT)((PRESS)), (_U_SINT)((button.state)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);



}



void test_buttonSM_should_set_state_to_RELEASE_when_enter_case_twice(){



  ButtonData button;

  buttonInitData(&button);



  isButtonPress_CMockExpectAndReturn(38, 1);

  isButtonPress_CMockExpectAndReturn(39, 1);



  buttonSM(&button);

  buttonSM(&button);





  UnityAssertEqualNumber((_U_SINT)((PRESS)), (_U_SINT)((button.state)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);



}



void test_buttonSM_should_set_to_PRESS_if_hold(){

  ButtonData button;

  buttonInitData(&button);



  isButtonPress_CMockExpectAndReturn(53, 1);

  isButtonPress_CMockExpectAndReturn(54, 1);

  isButtonPress_CMockExpectAndReturn(55, 1);



  buttonSM(&button);

  buttonSM(&button);

  buttonSM(&button);





  UnityAssertEqualNumber((_U_SINT)((PRESS)), (_U_SINT)((button.state)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);



}
