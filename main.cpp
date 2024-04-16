#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "TS_DISCO_F469NI.h"
#include <cstdio>
#include "button.h"
#include "stm32469i_discovery.h"

// In der Headerdatei stm32f469i_discovery.h unter ... anpassen!!


DigitalOut led1(LED1) ;
LCD_DISCO_F469NI lcd;
TS_DISCO_F469NI ts;

int main()
{
    
    BSP_LCD_SetFont(&Font24);
  
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"Moin", CENTER_MODE);
     ThisThread::sleep_for(1s);
  

    status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
    if (status != TS_OK)
    {
      lcd.Clear(LCD_COLOR_RED);
      lcd.SetBackColor(LCD_COLOR_RED);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN INIT FAIL", CENTER_MODE);
    }
    else
    {
      lcd.Clear(LCD_COLOR_GREEN);
      lcd.SetBackColor(LCD_COLOR_GREEN);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN INIT OK", CENTER_MODE);      
    }

    ThisThread::sleep_for(1s);


    lcd.Clear(LCD_COLOR_BLUE);
    lcd.SetBackColor(LCD_COLOR_BLUE);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"Los gehts...", CENTER_MODE); 
    ThisThread::sleep_for(1s);
    lcd.Clear(LCD_COLOR_BLUE);


    Button Button( lcd,ts,10, 10, 200, 200, LCD_COLOR_GREEN, LCD_COLOR_GREEN, "Moin",  Font12,LCD_COLOR_WHITE);

    while(1)
    {
      
        if(Button.Touched(LCD_COLOR_RED, LCD_COLOR_WHITE))
        {
                led1=0;

        }else{

            Button.Redraw();
            led1=1;

        }
        ThisThread::sleep_for(100ms);
     
    }

    
}
