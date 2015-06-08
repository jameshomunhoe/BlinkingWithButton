#include "unity.h"
#include "mock_Button.h"
#include "Message.h"
#include "LEDSM.h"
#include "ButtonSM.h"


void setUp(void){}

void tearDown(void){}



void test_message_passing_send_a_message_LedState_should_change_to_LED_ON(void){

 LedData ledData;

  ButtonData buttonData;





  ledInitData(&ledData);

  buttonInitData(&buttonData);



  ledSM(&ledData);

  UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_OFF)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);



  isButtonPress_CMockExpectAndReturn(21, 1);

  buttonSM(&buttonData);

  ledSM(&ledData);



  UnityAssertEqualNumber((_U_SINT)((buttonData.state)), (_U_SINT)((PRESS)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_ON)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);



}
