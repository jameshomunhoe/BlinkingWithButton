#include "unity.h"
#include "Message.h"
#include "ButtonSM.h"
#include "mock_Button.h"

void setUp(void){}
void tearDown(void){}

void test_buttonInitData_should_set_state_to_RELEASE(){

  ButtonData button;
  
  buttonInitData(&button);
  
  TEST_ASSERT_EQUAL( RELEASE, button.state);

}

void test_buttonSM_should_set_state_to_PRESS(){

  ButtonData button;
  
  isButtonPress_ExpectAndReturn(1);
  
  buttonInitData(&button);
  buttonSM(&button);
  
  
  TEST_ASSERT_EQUAL( PRESS, button.state);

}

void test_buttonSM_should_set_state_to_RELEASE_when_enter_case_twice(){

  ButtonData button;
  buttonInitData(&button);
  
  isButtonPress_ExpectAndReturn(1);
  isButtonPress_ExpectAndReturn(1);
  
  buttonSM(&button);
  buttonSM(&button);
  
  
  TEST_ASSERT_EQUAL( PRESS, button.state);

}

void test_buttonSM_should_set_to_PRESS_if_hold(){
  ButtonData button;
  buttonInitData(&button);
  
  isButtonPress_ExpectAndReturn(1);
  isButtonPress_ExpectAndReturn(1);
  isButtonPress_ExpectAndReturn(1);
  
  buttonSM(&button);
  buttonSM(&button);
  buttonSM(&button);
  
  
  TEST_ASSERT_EQUAL( PRESS, button.state);

}