#include "mbed.h"
#include "LCD_DISCO_F469NI.h"



DigitalOut led1(LED1) ;
LCD_DISCO_F469NI lcd;

int main()
{
    
    BSP_LCD_SetFont(&Font24);
  
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"Moin", CENTER_MODE);
     ThisThread::sleep_for(1s);
  
    lcd.Clear(LCD_COLOR_BLUE);
    lcd.SetBackColor(LCD_COLOR_BLUE);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"Los gehts...", CENTER_MODE); 
    ThisThread::sleep_for(1s);
    lcd.Clear(LCD_COLOR_BLUE);
 
    while(1)
    {
      
        ThisThread::sleep_for(100ms);
    }

    
}
