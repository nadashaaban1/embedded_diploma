/*
 * lcd.c
 *
 * Created: 9/21/2023 1:43:27 AM
 *  Author: Nada
 */ 

#include "lcd.h"

void LCD_init(void)
{
	
	_delay_ms(20);
	dataDIR_LCD_DATA = 0xFF; // set data port as output
	dataDIR_LCD_CTRL = 0xFF; //set (RS,RW,E) as outputs
	LCD_CTRL &=(~(1<<EN_switch | 1<<RW_switch | 1<<RS_switch)); //write , 
	_delay_ms(15);
	LCD_clear_screen();
	
	#ifdef EIGHT_BIT_MODE
	LCD_write_command(LCD_FUNCTION_8BIT_2LINES);
	
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_write_command(LCD_RETURN_HOME);
	LCD_write_command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_write_command(LCD_ENTRY_MODE);
	LCD_write_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_command(LCD_DISP_ON_CURSOR_BLINK);
	
	
}

void LCD_write_command(unsigned char command)
{
	LCD_isbusy();
	LCD_CTRL&=~(1<<RS_switch); //select command register
	LCD_CTRL&=~(1<<RW_switch); //write
	
	#ifdef EIGHT_BIT_MODE
		LCD_DATA = command;
	#endif
	
	#ifdef FOUR_BIT_MODE
		LCD_DATA =((LCD_DATA & 0x0F) | (command & 0xF0));
		LCD_EN_kick();
		LCD_DATA = ((LCD_DATA & 0x0F) | (command << 4));
		LCD_EN_kick();
		LCD_CTRL &=  (~((1<<RW_switch) | (1<<RS_switch)));
	#endif
	
		LCD_EN_kick();
	
	
	
}

void LCD_write_char(unsigned char data)
{
	LCD_isbusy();
	LCD_CTRL|=(1<<RS_switch); //select data register
	LCD_CTRL&=~(1<<RW_switch); //write 
	
	#ifdef EIGHT_BIT_MODE
		LCD_DATA = data;
		
	#endif
		
	#ifdef FOUR_BIT_MODE
	LCD_DATA =((LCD_DATA & 0x0F) | (data & 0xF0));
	LCD_EN_kick();
	LCD_DATA = ((LCD_DATA & 0x0F) | (data << 4));
	LCD_EN_kick();
	#endif
	
	LCD_EN_kick();
	
}

void LCD_write_string(char* data)
{
	int counter =0;
	while(*data > 0)
	{
		counter++;
		LCD_write_char(*data++);
		if(counter == 16)
			LCD_Cursor_XY(1,0);
		else if(counter == 32)
		{
			LCD_clear_screen();
			LCD_Cursor_XY(0,0);
			counter = 0;
		}
	}
	
}

void LCD_Cursor_XY(unsigned char line, unsigned char col)
{
	if(line==0)
	{
		if(col < 16 && col >= 0)
			LCD_write_command(LCD_BEGIN_AT_FIRST_ROW + col);
			
	}
	else if(line ==1)
	{
		if(col < 16 && col >= 0)
			LCD_write_command(LCD_BEGIN_AT_SECOND_ROW + col);
	}
}

void LCD_EN_kick()
{
	LCD_CTRL &= ~(1<<EN_switch);
	_delay_ms(30);
	LCD_CTRL |= (1<<EN_switch);
}

void LCD_isbusy(void)
{
	dataDIR_LCD_DATA = 0; //set data port as input
	//make DB7 as busy flag
	LCD_CTRL |= (1<<RW_switch); 
	LCD_CTRL &= ~(1<<RS_switch);
	LCD_EN_kick();
	
	#ifdef EIGHT_BIT_MODE
 		dataDIR_LCD_DATA = 0xFF; // set data port as output
	#endif
	
	#ifdef FOUR_BIT_MODE
		dataDIR_LCD_DATA = 0xF0;// set data port as output
	#endif

}

void LCD_clear_screen()
{
	LCD_write_command(LCD_CLEAR_SCREEN);
	
}

void LCD_display_intNum(int num)
{
	char str[10];
	sprintf(str,"%d",num);
	LCD_write_string(str);
}

void LCD_display_realNum(double num)
{
	char str[16];
	char*tempSign=(num<0)? "-": "";
	float tempVal=(num<0)?-num: num;
	int tempInt1=tempVal;
	float tempFrac=tempVal-tempInt1;
	int tempInt2=tempFrac*10000;
	sprintf(str,"%s%d.%04d",tempSign,tempInt1,tempInt2);
	
	LCD_write_string(str);
}
