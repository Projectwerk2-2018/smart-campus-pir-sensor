#include "mbed.h"
 
DigitalOut myPulse(D13);
DigitalOut myPulse2(D1); 
InterruptIn PIR(A0);
 
int pulseCount;
 
void highPulseDetected() {
    pulseCount++;
}
 
int main() {  
        PIR.rise(&highPulseDetected);
        pulseCount=0; 
         
        while(1){
            if(pulseCount==3) {
                myPulse=1;
                myPulse2=0;
                wait_ms(1000);      
                pulseCount=0;
            }else{
                myPulse2=1;
                myPulse=0;
            } 
        }
}