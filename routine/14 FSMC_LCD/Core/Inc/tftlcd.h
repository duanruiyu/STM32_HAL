#ifndef _tftlcd_H
#define _tftlcd_H	
#include "stm32f1xx_hal.h"	
#include "fsmc.h"	

//����LCD��������������  
#define TFTLCD_R61509VN

//0������  1������  Ĭ������
#define TFTLCD_DIR	0	

//TFTLCD��ַ�ṹ��
typedef struct
{
	uint16_t LCD_CMD;
	uint16_t LCD_DATA;
}TFTLCD_TypeDef;


//ʹ��NOR/SRAM�� Bank1.sector4,��ַλHADDR[27,26]=11 A10��Ϊ�������������� 
//ע������16λ����ʱSTM32�ڲ�������һλ����!			    
#define TFTLCD_BASE        ((uint32_t)(0x6C000000 | 0x000007FE))
#define TFTLCD             ((TFTLCD_TypeDef *) TFTLCD_BASE)
  
//TFTLCD��Ҫ������
typedef struct  
{										    
	uint16_t width;			//LCD ���
	uint16_t height;			//LCD �߶�
	uint16_t id;				//LCD ID
	uint8_t  dir;            //LCD ����
}_tftlcd_data;


//LCD����
extern _tftlcd_data tftlcd_data;	//����LCD��Ҫ����
//LCD��ǰ����ɫ�ͱ���ɫ	   
extern uint16_t  FRONT_COLOR;//ǰ����ɫ Ĭ�Ϻ�ɫ    
extern uint16_t  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ


//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 	 0x001F
#define BRED             0XF81F
#define GRED 			 			 0XFFE0
#define GBLUE			 			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 		 0XBC40 
#define BRRED 			 		 0XFC07 
#define GRAY  			 		 0X8430 



void LCD_WriteCmd(uint16_t cmd);
void LCD_WriteData(uint16_t data);
void LCD_WriteCmdData(uint16_t cmd,uint16_t data);
void LCD_WriteData_Color(uint16_t color);

void TFTLCD_Init(void);           //��ʼ��
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);
void LCD_Clear(uint16_t Color);	 												//����
void LCD_Fill(uint16_t xState,uint16_t yState,uint16_t xEnd,uint16_t yEnd,uint16_t color);
void LCD_DrawPoint(uint16_t x,uint16_t y);//����
void LCD_DrawFRONT_COLOR(uint16_t x,uint16_t y,uint16_t color);
uint16_t LCD_ReadPoint(uint16_t x,uint16_t y);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_DrawLine_Color(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);
void LCD_DrowSign(uint16_t x, uint16_t y, uint16_t color);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r);
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode);
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode);
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p);
void LCD_ShowFontHZ(uint16_t x, uint16_t y, uint8_t *cn);					   						   																			
void LCD_ShowPicture(uint16_t x, uint16_t y, uint16_t wide, uint16_t high,uint8_t *pic);

#endif  
	 
	 



