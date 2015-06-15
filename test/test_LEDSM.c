#include "unity.h"
#include "LEDSM.h"
#include "ButtonSM.h"
#include "Message.h"
#include "mock_Time.h"
#include "mock_Button.h"

void setUp(void){}
void tearDown(void){}


// void test_ledSM_state_will_go_LED_BLINKING_ON(){
  
  // LedData led;
  // ButtonData button;
  
  // ledInitData(&led);
  // buttonInitData(&button);
  
  
  // isButtonPress_ExpectAndReturn(1);
  // getCurrentTime_ExpectAndReturn(500);
  // getCurrentTime_ExpectAndReturn(999);
  
  // buttonSM(&button);
  // ledSM(&led);
  // ledSM(&led);
  
  // TEST_ASSERT_EQUAL(LED_BLINKING_ON,led.state);
  // TEST_ASSERT_EQUAL(DO_NOTHING,msg);
  // TEST_ASSERT_EQUAL(PRESS,button.state);
  
// }

// void test_ledSM_state_will_go_LED_BLINKING_OFF(){
  
  // LedData led;
  // ButtonData button;
  
  // ledInitData(&led);
  // buttonInitData(&button);
  
  
  // isButtonPress_ExpectAndReturn(1);
  // getCurrentTime_ExpectAndReturn(500);
  // getCurrentTime_ExpectAndReturn(1000);
  // getCurrentTime_ExpectAndReturn(1001);
  
  // buttonSM(&button);
  // ledSM(&led);
  // ledSM(&led);
  
  // TEST_ASSERT_EQUAL(LED_BLINKING_OFF,led.state);
  // TEST_ASSERT_EQUAL(DO_NOTHING,msg);
  // TEST_ASSERT_EQUAL(PRESS,button.state);
  
// }

void test_ledSM_state_will_go_LED_BLINKING_ON_with_button_released(){
  
  LedData led;
  ButtonData button;
  
  ledInitData(&led);
  buttonInitData(&button);
  
  
  isButtonPress_ExpectAndReturn(1);
  getCurrentTime_ExpectAndReturn(500);
  getCurrentTime_ExpectAndReturn(999);
  getCurrentTime_ExpectAndReturn(1000);
  isButtonPress_ExpectAndReturn(0);
  
  buttonSM(&button);
  ledSM(&led);
  ledSM(&led);
  buttonSM(&button);
  
  TEST_ASSERT_EQUAL(LED_BLINKING_ON,led.state);
  TEST_ASSERT_EQUAL(DO_NOTHING,msg);
  TEST_ASSERT_EQUAL(PRESS,button.state);
  
}