void vTimerInterrupt( void )
{
    // 'Give' the semaphore.  This will wake the high priority task.
    xSemaphoreGiveFromISR( xTimingSemaphore );
    
    // The high priority task will now be able to execute but as
    // the cooperative scheduler is being used it will not start
    // to execute until we explicitly cause a context switch.
    taskYIELD();    
}

void HighPriorityTaskTask( void *pvParameters )
{
    // Start by obtaining the semaphore.
    xSemaphoreTake( xSemaphore, DONT_BLOCK );  

    for( ;; )
    {
        // Another call to take the semaphore will now fail until
        // the timer interrupt has called xSemaphoreGiveFromISR().
        // We use a very long block time as the timing is controlled
        // by the frequency of the timer.
        if( xSemaphoreTake( xSemaphore, VERY_LONG_TIME ) == pdTRUE )
        {
            // We unblocked because the semaphore became available.
            // It must be time to execute the control algorithm.
            PlantControlCycle();
            
            // Followed by the keyscan.
            if( KeyPressed( &Key ) )
            {
                UpdateDisplay( Key );
            }
        }
        
        // Now we go back and block again until the next timer interrupt.
    }
}

void vRS232Task( void *pvParameters )
{
DataType Data;

    for( ;; )
    {
       if( cQueueReceive( xRS232Queue, &Data, MAX_DELAY ) )
        {
            ProcessRS232Data( Data );
        }        
    }
}

void IdleTaskHook( void )
{
static TickType_t LastFlashTime = 0;

    ProcessHTTPRequests();
    
    // Check the tick count value to see if it is time to flash the LED
    // again.
    if( ( xTaskGetTickCount() - LastFlashTime ) > FLASH_RATE )
    {
        UpdateLED();
        
        // Remember the time now so we know when the next flash is due.
        LastFlashTime = xTaskGetTickCount();
    } 
}