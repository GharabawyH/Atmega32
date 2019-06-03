/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "types.h"
#include "reg.h"
#include "lcd.h"
#include "lcd_cfg.h"
#include "ADC_isr.h"
#include "flex.h"
#include "ISD1820.h"

u32 volatile x;
u32 volatile y;
u32 volatile x1,y1,x2,y2,x3,y3,x4,y4;
u8 volatile i=1;
u8 volatile j=0;

void CallBackADC_INT(void)
{
	switch(i)
	{
	case 1:
	{
		x=Flex_GetResult();
//		x+=Flex_GetResult();
//		x+=Flex_GetResult();
//		x+=Flex_GetResult();
//		x+=Flex_GetResult();
//		x/=5;
		x=(x*500)/255;
		y=x%100;
		x=x/100;
//		LCD_SetPosition(1,0);
//		LCD_WriteNum(x);
//		LCD_WriteCharacter('.');
//		LCD_WriteNum(y);
		break;
	}
	case 2:
	{
		x1=Flex_GetResult();
//		x1+=Flex_GetResult();
//		x1+=Flex_GetResult();
//		x1+=Flex_GetResult();
//		x1+=Flex_GetResult();
//		x1/=5;
		x1=(x1*500)/255;
		y1=x1%100;
		x1=x1/100;
//		LCD_SetPosition(2,0);
//		LCD_WriteNum(x1);
//		LCD_WriteCharacter('.');
//		LCD_WriteNum(y1);
		break;
	}
	case 3:
	{
		x2=Flex_GetResult();
//		x2+=Flex_GetResult();
//		x2+=Flex_GetResult();
//		x2+=Flex_GetResult();
//		x2+=Flex_GetResult();
//		x2/=5;
		x2=(x2*500)/255;
		y2=x2%100;
		x2=x2/100;
//		LCD_SetPosition(1,6);
//		LCD_WriteNum(x2);
//		LCD_WriteCharacter('.');
//		LCD_WriteNum(y2);
		break;
	}
	case 4:
	{
		x3=Flex_GetResult();
//		x3+=Flex_GetResult();
//		x3+=Flex_GetResult();
//		x3+=Flex_GetResult();
//		x3+=Flex_GetResult();
//		x3/=5;
		x3=(x3*500)/255;
		y3=x3%100;
		x3=x3/100;
//		LCD_SetPosition(2,6);
//		LCD_WriteNum(x3);
//		LCD_WriteCharacter('.');
//		LCD_WriteNum(y3);
		break;
	}
	case 5:
	{
		x4=Flex_GetResult();
//		x4+=Flex_GetResult();
//		x4+=Flex_GetResult();
//		x4+=Flex_GetResult();
//		x4+=Flex_GetResult();
//		x4/=5;
		x4=(x4*500)/255;
		y4=x4%100;
		x4=x4/100;
//		LCD_WriteString("    ");
//		LCD_SetPosition(1,12);
//		LCD_WriteNum(x4);
//		LCD_WriteCharacter('.');
//		LCD_WriteNum(y4);
		break;
	}
	}
	i++;
	j++;
	if(i==6)
	{
		i=1;
	}
	if(j==5)
	{
		j=0;
	}
	StopReadingFlex();
}

void main(void)
{
	u8 flag=0;
	lcd_cfg LCD_CFG1;
	LCD_CFG1.datalength=1;
	LCD_CFG1.lines=1;
	LCD_CFG1.font=0;
	LCD_CFG1.cursor=0;
	LCD_CFG1.blinking=0;
	Init_LCD(&LCD_CFG1);
	ISD1820_Enable();
	SetCallBackADC_INT(CallBackADC_INT);
	while(1)
	{
		StartReadingFlex(j);
				if((x==3)&&(x1==2)&&(x2==3)&&(x3==3)&&(x4==2)&&(flag==1))
				{
					LCD_WriteCommand(1);
					LCD_SetPosition(1,0);
					LCD_WriteString("I am hungry");
					flag=0;
				}
				else if((x==3)&&(x1==3)&&(x2==3)&&(x3==3)&&(x4==3)&&(flag==1))
				{
					LCD_WriteCommand(1);
					LCD_SetPosition(1,0);
					LCD_WriteString("Stop Talking");
					flag=0;
				}
				else if((x==3)&&(x1==2)&&(x2==2)&&(x3==3)&&(x4==3)&&(flag==1))
				{
					LCD_WriteCommand(1);
					LCD_SetPosition(1,0);
					LCD_WriteString("Leave Me Alone");
					flag=0;
				}
				else if((x==2)&&(x1==3)&&(x2==3)&&(x3==3)&&(x4==2)&&(flag==1))
				{
					LCD_WriteCommand(1);
					LCD_SetPosition(1,0);
					LCD_WriteString("Call Doctor");
					ISD1820_StartMessage();
					flag=0;
				}
				if((x==2)&&(x1==2)&&(x2==2)&&(x3==2)&&(x4==2))
				{
//					LCD_WriteCommand(1);
					flag=1;
				}

	}
}
