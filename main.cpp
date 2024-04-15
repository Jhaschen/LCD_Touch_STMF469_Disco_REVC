#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "TS_DISCO_F469NI.h"
#include <cstdio>



DigitalOut led1(LED1) ;
LCD_DISCO_F469NI lcd;
TS_DISCO_F469NI ts;
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
 
    char buffer[100];
    TS_StateTypeDef TS_State;
    uint16_t x, y;
    uint8_t text[30];
    uint16_t prev_nb_touches = 0;
    led1=1; // LED 1 aus
    while(1)
    {  
        // Prüfe, ob Touchpanel berührt. 
        ts.GetState(&TS_State);      
      if (TS_State.touchDetected)
      {
          led1=0;

          x = TS_State.touchX[0];
          y = TS_State.touchY[0];
          sprintf((char*)text, "Touch %d: x=%d y=%d    ",prev_nb_touches,  x, y);
          lcd.DisplayStringAt(0, LINE(5), (uint8_t *)&text, LEFT_MODE);
          sprintf((char*)text, "Touches: %d", prev_nb_touches);
          lcd.DisplayStringAt(0, LINE(1), (uint8_t *)&text, LEFT_MODE);
          prev_nb_touches++;
      
        }else{
            led1=1;
            ThisThread::sleep_for(250ms);
            lcd.ClearStringLine(5);
        }
      
        
    }

    
}
