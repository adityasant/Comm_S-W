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
    wait(0.5); /*wait for the printf error*/
    
    int ReceiveLength = 128;
    int ReceiveCounter;
    int TCCounter = 0;
    int TCLength;
    while(1)
    {
        char ReceiveBuffer[ReceiveLength] ;
        ReceiveCounter = 0 ;
        /*Create a linked list for the TM*/
        /*Create a TC buffer*/
        TCCounter = 0;
                
        while(ReceiveCounter < ReceiveLength)
        {
            //read and store value in buffer
            if( ReceiveCounter == 6)
            {
                ReceiveLength = (16* (int)ReceiveBuffer[4]) + (int)ReceiveBuffer[5];
            }
                
            ReceiveBuffer[ReceiveCounter] = pc.getc();
            wait(0.1);
            pc.printf("%d------%d--------%d\n\r",ReceiveCounter,ReceiveBuffer[ReceiveCounter],ReceiveLength);
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
       
        func_FillPayload();
        func_Transmit();
        func_WaitForAck();
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

void func_FillPayload()
{
       
}

void func_Transmit()
{
    /*Transmit no op command to Matlab code*/
    #define NoOp 0x01
    pc.putc(NoOp);
}

void func_WaitForAck()
{
    int NoOpAck;
    int NoOpCounter = 0;
    int NoOpFlag = 0;
    while(1)
    {
         func_Transmit();
         if(NoOpCounter>=9)
         {
            break;
         }
         pc.scanf("%x",&NoOpAck);
         if(NoOpAck==0x00)
         {
            NoOpFlag = 1;
            break;
         }
         NoOpCounter ++;
    }
}
