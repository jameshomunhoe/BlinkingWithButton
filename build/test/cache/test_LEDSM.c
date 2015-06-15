#include "unity.h"
#include "mock_Time.h"
#include "mock_Button.h"
#include "Message.h"
#include "LEDSM.h"
#include "ButtonSM.h"


void setUp(void){}

void tearDown(void){}

void test_ledSM_state_will_go_LED_BLINKING_ON_with_button_released(){



  LedData led;

  ButtonData button;



  ledInitData(&led);

  buttonInitData(&button);





  isButtonPress_CMockExpectAndReturn(68, 1);

  getCurrentTime_CMockExpectAndReturn(69, 500);

  getCurrentTime_CMockExpectAndReturn(70, 999);

  getCurrentTime_CMockExpectAndReturn(71, 1000);

  isButtonPress_CMockExpectAndReturn(72, 0);



  buttonSM(&button);

  ledSM(&led);

  ledSM(&led);

  buttonSM(&button);



  UnityAssertEqualNumber((_U_SINT)((LED_BLINKING_ON)), (_U_SINT)((led.state)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((DO_NOTHING)), (_U_SINT)((msg)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((PRESS)), (_U_SINT)((button.state)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);



}
