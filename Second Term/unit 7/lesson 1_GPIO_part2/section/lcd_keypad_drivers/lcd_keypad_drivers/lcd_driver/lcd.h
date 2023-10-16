/*
 * lcd.h
 *
 * Created: 9/21/2023 1:43:19 AM
 *  Author: Nada
 */ 

#ifndef LCD_H_
#define LCD_H_


#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>

#define LCD_DATA          PORTA
#define dataDIR_LCD_DATA  DDRA
#define LCD_CTRL          PORTB
#define dataDIR_LCD_CTRL  DDRB

#define RS_switch 1
#define RW_switch 2
#define EN_switch 3

//RS
#define LCD_SEND_COMMAND 0
#define LCD_SEND_DATA 1
//RW
#define LCD_WRITE_DATA 0
#define LCD_READ_DATA 1
//EN
#define LCD_ENABLE 1
#define LCD_DISABLE 0

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_8BIT_1LINE   					(0x30)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_FUNCTION_4BIT_1LINE   					(0x20)

#define LCD_ENTRY_MODE								(0x06)
#define LCD_DISP_OFF_CURSOR_OFF   					(0x08)
#define LCD_DISP_ON_CURSOR_ON   					(0x0E)
#define LCD_DISP_ON_CURSOR_OFF 						(0x0C)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)

#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CHAR_RIGHT   					    (0x14)
#define LCD_MOVE_CHAR_LEFT 	  					    (0x10)
#define LCD_BEGIN_AT_FIRST_ROW                      (0x80)
#define LCD_BEGIN_AT_SECOND_ROW                     (0xC0)
#define LCD_CLEAR_SCREEN						    (0x01)
#define LCD_RETURN_HOME                             (0x02)


void LCD_init(void);
void LCD_write_command(unsigned char command);
void LCD_write_char(unsigned char data);
void LCD_write_string(char* data);
void LCD_isbusy(void);
void LCD_clear_screen();
void LCD_Cursor_XY(unsigned char line, unsigned char col);
void LCD_display_intNum(int num);
void LCD_display_realNum(double num);




#endif /* LCD_H_ */