/**
@file

*/
/*
  Application example t

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_Blink_
#define _Application_atApp_Blink_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/atService_XYZ.h"
/* _____DEFINITIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_Blink;  
void atApp_Blink_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
const int LED_PIN = 2;
/**
 * This Application class is the application to manage the 
 */
class App_Blink : public Application
{
public:
  	App_Blink();
 	~App_Blink();
	void Blink_Led(int times);
protected:
private:
  	static void  App_Blink_Pend();
	static void  App_Blink_Start();
	static void  App_Blink_Restart();
	static void  App_Blink_Execute();
	static void  App_Blink_Suspend();
	static void  App_Blink_Resume();	  
	static void  App_Blink_End();
} atApp_Blink ;
/**
 * This function will be automaticaly called when a object is created by this class
 */

App_Blink::App_Blink(/* args */)
{
  	_Pend_User 	     = *App_Blink_Pend;
	_Start_User 	 = *App_Blink_Start;
	_Restart_User 	 = *App_Blink_Restart;
	_Execute_User 	 = *App_Blink_Execute;
	_Suspend_User	 = *App_Blink_Suspend;
	_Resume_User	 = *App_Blink_Resume;
	_End_User	     = *App_Blink_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"Blink Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_Blink::~App_Blink()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_Blink::App_Blink_Pend()
{
    // atService_XYZ.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_Blink::App_Blink_Start()
{
	// init atXYZ Service in the fist running time
	// atService_XYZ.Run_Service();
	pinMode(LED_PIN, OUTPUT);
}  
/**
 * Restart function of SNM  app
 */
void  App_Blink::App_Blink_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_Blink::App_Blink_Execute()
{	
	// atService_XYZ.Run_Service();
	static int state = 1;
	static int n = 0;

	if(atApp_Blink.User_Mode == APP_USER_MODE_DEBUG)
	{
		Serial.printf("State: %d, n: %d\n", state, n);
	}

	switch (state)
	{
		case 1:
			atApp_Blink.Blink_Led(1);
			if (n >= 5) state = 2;
			break;

		case 2:
			atApp_Blink.Blink_Led(2);
			if (n >= 20) state = 3;
			break;

		case 3:
			atApp_Blink.Blink_Led(3);
			if (n >= 25) state = 4;
			break;

		case 4:
			atApp_Blink.Blink_Led(4);
			if (n >= 30)
			{
				n = 0;
				state = 1;
			}
			break;
	}

	n++;
	vTaskDelay(1000 / portTICK_PERIOD_MS); // delay 1 giây mỗi vòng
    if(atApp_Blink.User_Mode == APP_USER_MODE_DEBUG)
    {
		
    }   
}
void  App_Blink::App_Blink_Suspend(){}
void  App_Blink::App_Blink_Resume(){}	  
void  App_Blink::App_Blink_End(){}
void  App_Blink::Blink_Led(int times)
{
	// This function will be called to blink the led
	// atService_XYZ.Blink_Led();
	for (int i = 0; i < times; i++)
	{
		digitalWrite(LED_PIN, HIGH);
		vTaskDelay(200 / portTICK_PERIOD_MS);
		digitalWrite(LED_PIN, LOW);
		vTaskDelay(200 / portTICK_PERIOD_MS);
	}
}
void atApp_Blink_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_Blink.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(100/ portTICK_PERIOD_MS);
  }
}
#endif