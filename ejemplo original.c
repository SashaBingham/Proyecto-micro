// ------------------------------------------------------------------- INCLUDES

#include "board.h"
#include "log.h"
#include "temphum11.h"

// ------------------------------------------------------------------ VARIABLES

static temphum11_t temphum11;
static log_t logger;

static float temperature;
static float humidity;

// ------------------------------------------------------ APPLICATION FUNCTIONS

void application_init ( void )
{
    log_cfg_t log_cfg;
    temphum11_cfg_t cfg;

    /** 
     * Logger initialization.
     * Default baud rate: 115200
     * Default log level: LOG_LEVEL_DEBUG
     * @note If USB_UART_RX and USB_UART_TX 
     * are defined as HAL_PIN_NC, you will 
     * need to define them manually for log to work. 
     * See @b LOG_MAP_USB_UART macro definition for detailed explanation.
     */
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );

    //  Click initialization.

    temphum11_cfg_setup( &cfg );
    TEMPHUM11_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    temphum11_init( &temphum11, &cfg );

    // Test comunication

    if ( temphum11_read_data( &temphum11, TEMPHUM11_REG_DEVICE_ID ) == TEMPHUM11_DEVICE_ID )
    {
        log_printf( &logger, "--- Comunication OK!!! ---\r\n" );
    }
    else
    {
        log_printf( &logger, "--- Comunication ERROR!!! ---\r\n" );
        for ( ; ; );
    }

    temphum11_default_cfg( &temphum11 );
    log_printf( &logger, "--- Start measurement --- \r\n" );
    Delay_ms( 500 );
}

void application_task ( void )
{
    temperature = temphum11_get_temperature( &temphum11, TEMPHUM11_TEMP_IN_CELSIUS );
    
    log_printf( &logger, " Temperature : %.2f\r\n", temperature );
    
    humidity = temphum11_get_humidity( &temphum11 );
    
    log_printf( &logger, " Humidity :  %.2f\r\n", humidity );
    
    log_printf( &logger, "-----------------\r\n" );
    Delay_ms( 1500 );
}

void main ( void )
{
    application_init( );

    for ( ; ; )
    {
        application_task( );
    }
}


// ------------------------------------------------------------------------ END
