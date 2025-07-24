/**
@file

*/
/*
  Application example t

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_Blink_Funcpointer_
#define _Application_atApp_Blink_Funcpointer_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/atService_XYZ.h"
/* _____DEFINITIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_Blink_Funcpointer;  
void atApp_Blink_Funcpointer_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
const int LED_BUILT = 2;
enum Blink_FuncpointerState {
		STATE_1,
		STATE_2,
		STATE_3,
		STATE_4,
		NUM_STATES
	};
int state = STATE_1;
int n = 0;
/**
 * This Application class is the application to manage the 
 */
class App_Blink_Funcpointer : public Application
{
public:
  	App_Blink_Funcpointer();
 	~App_Blink_Funcpointer();
	void handleState1();
	void handleState2();
	void handleState3();
	void handleState4();
	void Blink_Funcpointer_Led(int times);

// Mảng con trỏ hàm
	void (App_Blink_Funcpointer::*stateHandlers[NUM_STATES])() = {
		&App_Blink_Funcpointer::handleState1,
		&App_Blink_Funcpointer::handleState2,
		&App_Blink_Funcpointer::handleState3,
		&App_Blink_Funcpointer::handleState4
	};
protected:
private:
  	static void  App_Blink_Funcpointer_Pend();
	static void  App_Blink_Funcpointer_Start();
	static void  App_Blink_Funcpointer_Restart();
	static void  App_Blink_Funcpointer_Execute();
	static void  App_Blink_Funcpointer_Suspend();
	static void  App_Blink_Funcpointer_Resume();	  
	static void  App_Blink_Funcpointer_End();
} atApp_Blink_Funcpointer ;
/**
 * This function will be automaticaly called when a object is created by this class
 */

App_Blink_Funcpointer::App_Blink_Funcpointer(/* args */)
{
  	_Pend_User 	     = *App_Blink_Funcpointer_Pend;
	_Start_User 	 = *App_Blink_Funcpointer_Start;
	_Restart_User 	 = *App_Blink_Funcpointer_Restart;
	_Execute_User 	 = *App_Blink_Funcpointer_Execute;
	_Suspend_User	 = *App_Blink_Funcpointer_Suspend;
	_Resume_User	 = *App_Blink_Funcpointer_Resume;
	_End_User	     = *App_Blink_Funcpointer_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"Blink_Funcpointer Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_Blink_Funcpointer::~App_Blink_Funcpointer()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_Blink_Funcpointer::App_Blink_Funcpointer_Pend()
{
    // atService_XYZ.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_Blink_Funcpointer::App_Blink_Funcpointer_Start()
{
	// init atXYZ Service in the fist running time
	// atService_XYZ.Run_Service();
	pinMode(LED_PIN, OUTPUT);
}  
/**
 * Restart function of SNM  app
 */
void  App_Blink_Funcpointer::App_Blink_Funcpointer_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_Blink_Funcpointer::App_Blink_Funcpointer_Execute()
{	
	// atService_XYZ.Run_Service();
	(atApp_Blink_Funcpointer.*(atApp_Blink_Funcpointer.stateHandlers[state]))(); // gọi hàm xử lý tương ứng với trạng thái
	n++;
	vTaskDelay(1000 / portTICK_PERIOD_MS);
	if(atApp_Blink_Funcpointer.User_Mode == APP_USER_MODE_DEBUG)
	{
		printf("State: %d, n: %d\n", state, n);
	}   
}
void  App_Blink_Funcpointer::App_Blink_Funcpointer_Suspend(){}
void  App_Blink_Funcpointer::App_Blink_Funcpointer_Resume(){}	  
void  App_Blink_Funcpointer::App_Blink_Funcpointer_End(){}
void  App_Blink_Funcpointer::handleState1()
{
	// This function will be called to Blink_Funcpointer the led
	// atService_XYZ.Blink_Funcpointer_Led();
	atApp_Blink_Funcpointer.Blink_Funcpointer_Led(1);
    if (n >= 5) state = STATE_2;
}
void  App_Blink_Funcpointer::handleState2()
{
	// This function will be called to Blink_Funcpointer the led
	// atService_XYZ.Blink_Funcpointer_Led();
	atApp_Blink_Funcpointer.Blink_Funcpointer_Led(2);
    if (n >= 10) state = STATE_3;
}
void  App_Blink_Funcpointer::handleState3()
{
	// This function will be called to Blink_Funcpointer the led
	// atService_XYZ.Blink_Funcpointer_Led();
	atApp_Blink_Funcpointer.Blink_Funcpointer_Led(3);
    if (n >= 15) state = STATE_4;
}
void  App_Blink_Funcpointer::handleState4()
{
	// This function will be called to Blink_Funcpointer the led
	// atService_XYZ.Blink_Funcpointer_Led();
	atApp_Blink_Funcpointer.Blink_Funcpointer_Led(4);
    if (n >= 20){
		n = 0;
		state = STATE_1;
	} 
}
void  App_Blink_Funcpointer::Blink_Funcpointer_Led(int times)
{
	// This function will be called to Blink_Funcpointer the led
	// atService_XYZ.Blink_Funcpointer_Led();
	for (int i = 0; i < times; i++)
	{
		digitalWrite(LED_BUILT, HIGH);
		vTaskDelay(200 / portTICK_PERIOD_MS);
		digitalWrite(LED_BUILT, LOW);
		vTaskDelay(200 / portTICK_PERIOD_MS);
	}
}
void atApp_Blink_Funcpointer_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_Blink_Funcpointer.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(100/ portTICK_PERIOD_MS);
  }
}
#endif