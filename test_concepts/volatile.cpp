#include <iostream>
#include <stdexcept>

typedef struct
{
  int command;
  int data;
  bool isbusy;
} MyHardwareGadget;


// While loop checks the memory once and loops infinitely
void SendCommand(MyHardwareGadget *gadget, int command, int data)
{
	// wait while the gadget is busy:
	while (gadget->isbusy)
	{
		// do nothing here.
	}
	// set data first:
	gadget->data    = data;
	// writing the command starts the action:
	gadget->command = command;
}

// It will tell the compiler not to cache the value of this variable. 
// So it will generate code to take the value of the given volatile variable 
// from the main memory every time it encounters it
void SendCommand_vol(volatile MyHardwareGadget *gadget, int command, int data)
	{
	// wait while the gadget is busy:
	while (gadget->isbusy)
	{
		// do nothing here.
	}
	// set data first:
	gadget->data    = data;
	// writing the command starts the action:
	gadget->command = command;
	printf("%d\n", gadget->data);
}


int	main(void)
{
	MyHardwareGadget gadget;
	volatile MyHardwareGadget gadget_vol;
	gadget.isbusy = true;
	SendCommand_vol(&gadget_vol, 1, 5);
	gadget.isbusy = false;
	printf("%d\n", gadget_vol.data);
	gadget.isbusy = true;

	// Loops forever
	SendCommand(&gadget, 1, 5);
	printf("%d\n", gadget.data);
	
}