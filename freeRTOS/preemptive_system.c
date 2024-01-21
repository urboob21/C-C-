/*
 - use alot of RAM and queue
 - waste processors cycle when switch between tasks of the same priority

*/

// 1.   Plant control task - 10ms /s  - strict timming
#define CYCLE_RATE_MS 10 //10ms
#define MAX_COMMS_DELAY   //

void plantControlTask(void *pvParameters){
    TickType_t xLastWakeTime;
    DataType data1,data2;

    initialiseTheQueue();

    xLastWakeTime = xTaskGetTickCount();

    for(;;){

        // 10ms - do
        vTaskDelayUntil(&xLasWakeTime,CYCLE_RATE_MS);
        
        transmitRequest();

        if(xQueueReceived(theQueue,&Data1,MAX_COMMS_DELAY)){
            if(xQueueReceived(theQueue,&Data2,MAX_COMMS_DELAY)){
                performControlAlgorithm();
                transmitResult();
            }
        }
    }
}

//2. httpServer task: lower priority
void WebServerTask( void *pvParameters )
{
DataTypeA Data;

    for( ;; )
    {
        // Block until data arrives.  xEthernetQueue is filled by the
        // Ethernet interrupt service routine.
        if( xQueueReceive( xEthernetQueue, &Data, MAX_DELAY ) )
        {
            ProcessHTTPData( Data );
        }        
    }
}

// 3. RS232Task : 
void RS232Task( void *pvParameters )
{
DataTypeB Data;

    for( ;; )
    {
        // Block until data arrives.  xRS232Queue is filled by the
        // RS232 interrupt service routine.
        if( xQueueReceive( xRS232Queue, &Data, MAX_DELAY ) )
        {
            ProcessSerialCharacters( Data );
        }        
    }
}