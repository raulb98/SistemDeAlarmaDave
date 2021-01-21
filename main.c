/*
 * main.c
 *
 *  Created on: 2021 Jan 10 14:28:29
 *  Author: rbucur
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */


void delay()
{
    int i = 0;
    for(i=0;i<0xfffff;i++)
    	;
}

void add_char(unsigned char* message, int *idx, char chr)
{
    if(*idx < 100)
    {
    	message[*idx] = chr;
    	*idx++;
    }
}

void buzzer()
{
	  DIGITAL_IO_SetOutputHigh (&buzz);
	  DIGITAL_IO_SetOutputLow (&buzz);
	  DIGITAL_IO_SetOutputHigh (&buzz);
	  DIGITAL_IO_SetOutputLow (&buzz);
	  DIGITAL_IO_SetOutputHigh (&buzz);
	  DIGITAL_IO_SetOutputLow (&buzz);
	  DIGITAL_IO_SetOutputHigh (&buzz);
	  DIGITAL_IO_SetOutputLow (&buzz);
	  DIGITAL_IO_SetOutputHigh (&buzz);
	  DIGITAL_IO_SetOutputLow (&buzz);
	  DIGITAL_IO_SetOutputHigh (&buzz);
	  DIGITAL_IO_SetOutputLow (&buzz);
	  DIGITAL_IO_SetOutputHigh (&buzz);
	  DIGITAL_IO_SetOutputLow (&buzz);
}

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

  }

  int value_to_display = 0;
  int ok = 0;
  BUS_IO_Write (&bit_array, value_to_display); //sting ledurile
  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	 if(DIGITAL_IO_GetInput (&inc)==0)
	 {
		 value_to_display++;
		 ok = 1;
	 }
	 if(DIGITAL_IO_GetInput (&dec)==0)
	 {
	     value_to_display--;
	     ok = 1;
	 }
	 if(ok == 0)
	 {
	     delay();
	     delay();
	     value_to_display++;
	     BUS_IO_Write (&bit_array,value_to_display);
	     delay();
	     delay();

	     if((value_to_display % 15) == 0)
	     {
	    	 buzzer();
	    	 value_to_display = 0;
	     }
	 }
	 else
	 {
		 delay();
		 BUS_IO_Write (&bit_array,value_to_display);
		 delay();
		 BUS_IO_Write (&bit_array,value_to_display);
		 delay();
		 ok = 0;
	 }
  }
}
