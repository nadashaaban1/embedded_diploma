/*
 * lcd_keypad_drivers.c
 *
 * Created: 9/21/2023 1:41:47 AM
 * Author : Nada
 */ 

#include "lcd_driver/lcd.h"
#include "keypad_driver/keypad.h"

int main(void)
{
	LCD_init();
	KEYPAD_INIT();
	_delay_ms(50);
	char pressed_key=0,second_pressed_key=0,op='$';
	float res=0,val1=0,val2=0,i;
	LCD_write_string("Hello, I'm Nada Shaaban");
	_delay_ms(300);
	LCD_clear_screen();
	LCD_write_string("Calculator Project:");
	_delay_ms(300);
	LCD_clear_screen();
	unsigned char count=0;
	unsigned char flag1=0, flag2=0;
	
	
	while(1)
	{
		
		
		if(!flag1)
			pressed_key = KEYPAD_GET_CHAR();
		else if(flag2)
		{
			second_pressed_key = KEYPAD_GET_CHAR();
			pressed_key=second_pressed_key;
		}
	
		if (pressed_key == '+' || pressed_key == '-' || pressed_key == '*' || pressed_key == '/')
		{
			op=pressed_key;
			flag1=1;
			flag2=1;
		}
		
		if(pressed_key >= '0' && pressed_key <= '9' && op == '$')
		{
			val1=val1*10+(pressed_key-'0');
		}
		
		else if(pressed_key >= '0' && pressed_key <= '9' && op != '$')
		{
			val2=val2*10+(pressed_key-'0');
		}
		

			
		switch (pressed_key)
		{
		case ('?'):
			LCD_clear_screen();
			op = '$';
			val1=0;
			val2=0;
			flag1=0;
			flag2=0;
			break;
		case('N'):
			break;
		default:
			if(count == 16)
			{
				LCD_Cursor_XY(1,0);
				count=0;
			}
			LCD_write_char(pressed_key);
			
			if(pressed_key=='=')
				{
				    res=KEYPAD_CALC(val1 ,val2 ,op);
					if(op == '/')
						LCD_display_realNum(res);
					else
						LCD_display_intNum(res);
					
					 op = '$'; 
					 val1=0;
					 val2=0;
					 flag1=0;
					 flag2=0;
				}

			count++;
			break;
		}
			
	}
}
