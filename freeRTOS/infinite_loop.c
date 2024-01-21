/*

// 1. Plant control function

void plantControllCycle(void){
    transmitRequest();
    waitForFirstSensorRespond();
    if(got data from first sensor){
        waitForSencondSensorRespond();
        if(got data from second sensor){
            performControlAlgorithm();
            transmitResult();
        }
    }
}

// 2. Human interface functions => require execute quickly enough

int main(){
    initialise();

    for(;;){
        scanKeypad();
        updateLCD();
        processRS232();
        processHttpRequest();
    }
        // never get here
    return 0;
}
*/
#include <stdint.h>
// 3. Scheduling the plant control with timmer
int timerExpired; // each 10ms true/false

void timerISR(){
    timerExpired = true;
}

int main(){
    initialise();
    for(;;){
        if(timerExpired){
            timerExpired = false;
            // do st
        }
    }
}

// => not acceptable solution



// Solution 1: Split each function into a number of states

typedef enum
{
    eStart = 0,
    eWait1,
    eWait2
} eControlState_t;

void PlantControlCycle( void )
{
static eControlState_t eState = eStart;

    switch( eState )
    {
        case eStart :
            TransmitRequest();
            eState = eWait1;
            break;
            
        case eWait1;
            if( Got data from first sensor )
            {
                eState = eWait2;
            }
            // How are time outs to be handled?
            break;
            
        case eWait2;
            if( Got data from first sensor )
            {
                PerformControlAlgorithm();
                TransmitResults();
                
                eState = eStart;
            }
            // How are time outs to be handled?
            break;           
    }
}


// Solution 2:
 for( ;; )
    {
        if( TimerExpired )
        {
            Counter++;
            
            // Process the control cycle every other loop.
            switch( Counter )
            {
                case 0  : ControlCycle();
                          break;
                          
                case 1  : Counter = -1;
                          break;
            }

            // Process just one of the other functions.  Only process
            // a function if there is something to do.  EventStatus()
            // checks for events since the last iteration.
            switch( EventStatus() )
            {
                case EVENT_KEY  :   ScanKeypad();
                                    UpdateLCD();
                                    break;
                           
                case EVENT_232  :   ProcessRS232Characters();
                                    break;
                            
                case EVENT_TCP  :   ProcessHTTPRequests();
                                    break;
            }
            
            TimerExpired = false;
        }
    }
