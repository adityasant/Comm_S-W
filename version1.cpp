//First version program for He Radio that implements No Op
 
#include "mbed.h"
 
//Defining the serial ports
Serial pc(USBTX,USBRX);
Serial uart(p9,p10);
 
//Defining the different functions that will be used
void func_InterpretGSTCFrame();
void func_UnpackTC();
int func_TCCount();
void func_ExecuteTC();
void func_PackTM();
void func_FillPayload();
void func_Transmit();
void func_WaitForAck();
 
//Defining the global constants:
 
DigitalOut led1(LED1);
DigitalOut led2(LED2);
int main()
{
    int ReceiveLength = 128;
    while(1)
    {
        int ReceiveCounter = 0;
        /*Create a linked list for the TM*/
        /*Create a TC buffer*/
        int TCCounter = 0;
        int TCLength;
        
        while(ReceiveCounter < ReceiveLength)
        {
            //read and store value in buffer
            ReceiveCounter ++;
        }
        
        /*returns TC frame buffer*/func_InterpretGSTCFrame(/*pass He header plus TC frame*/);
        
        /*Function to calculate the number of TC's in the frame*/
        TCLength = func_TCCount(/*pass the TC frame buffer*/);
        
        for(TCCounter =0; TCCounter<TCLength; TCCounter++)
        {
            /*unpacked TC (char* type) = */ func_UnpackTC(/*tcbuffer{TCCounter]*/);
            /*returns TM (char* type) */func_ExecuteTC(/*unpacked TC*/);
            /*Returns a char* data type*/ func_PackTM(/*TM*/);
            {
                /*routine to push the TM into the list*/
            }
        }
        /*
        UNDER CONSTRUCTION
        
        func_FillPayload();
        func_Transmit();
        func_WaitForAck();
        */
    }
}
 
void func_InterpretGSTCFrame()
{
    //Remove He headers
    
}
 
int func_TCCount(/*tc frame buffer*/)
{
    return 0; 
}
 
void func_UnpackTC()
{
    
}
 
void func_ExecuteTC()
{
    
}
 
void func_PackTM()
{
    
}
