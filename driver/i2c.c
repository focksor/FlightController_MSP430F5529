#include "i2c.h"
//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������V3
//MPU6050 IIC���� ����
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/1/17
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

void SDA_High();
void SDA_Low();
void SCL_High();
void SCL_Low();

#define MPU_SDA_OUT()  P3DIR |=  SDA;
#define MPU_SDA_IN()   P3DIR &= ~SDA;
#define MPU_IIC_SDA_HIGH   SDA_High()
#define MPU_IIC_SDA_LOW    SDA_Low()
#define MPU_IIC_SCL_HIGH   SCL_High()
#define MPU_IIC_SCL_LOW    SCL_Low()

#define MPU_READ_SDA       P3IN & SDA

 //MPU IIC ��ʱ����
void MPU_IIC_Delay(void)
{
//	_delay_us(1);
	_NOP(); _NOP(); _NOP();
	_NOP(); _NOP(); _NOP();
	_NOP(); _NOP(); _NOP();
}

//��ʼ��IIC
void MPU_IIC_Init(void)
{


}

//SDA�ߵ�ƽ�Ĳ���
//**************************************
void SDA_High()    //SDA�ߵ�ƽ�Ĳ���
{
   P3DIR|=SDA;
   P3OUT|=SDA;
   _NOP();
   _NOP();
   _NOP();
   return;
}
//**************************************
//SDA�͵�ƽ�Ĳ���
//**************************************
void SDA_Low()   //SDA�͵�ƽ�Ĳ���
{
   P3DIR|=SDA;
   P3OUT&=~SDA;
   _NOP();
   _NOP();
   _NOP();
   return;
}
//**************************************
//SCL�ߵ�ƽ����
//**************************************
void SCL_High()  //SCL�ߵ�ƽ����
{
   P3DIR|=SCL;
   P3OUT|=SCL;
   _NOP();
   _NOP();
   _NOP();
   return;
}
//**************************************
//SCL�͵�ƽ�Ĳ���
//**************************************
void SCL_Low() //SCL�͵�ƽ�Ĳ���
{
	   P3DIR|=SCL;
	   P3OUT&=~SCL;
	   _NOP();
	   _NOP();
	   _NOP();
	   return;
}

//����IIC��ʼ�ź�
void MPU_IIC_Start(void)
{
	MPU_SDA_OUT();     //sda�����
	MPU_IIC_SDA_HIGH;
	MPU_IIC_SCL_HIGH;
	MPU_IIC_Delay();
 	MPU_IIC_SDA_LOW;//START:when CLK is high,DATA change form high to low
	MPU_IIC_Delay();
	MPU_IIC_SCL_LOW;//ǯסI2C���ߣ�׼�����ͻ��������
}
//����IICֹͣ�ź�
void MPU_IIC_Stop(void)
{
	MPU_SDA_OUT();//sda�����
	MPU_IIC_SCL_LOW;
	MPU_IIC_SDA_LOW;//STOP:when CLK is high DATA change form low to high
 	MPU_IIC_Delay();
	MPU_IIC_SCL_HIGH;
	MPU_IIC_SDA_HIGH;//����I2C���߽����ź�
	MPU_IIC_Delay();
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 MPU_IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	MPU_SDA_IN();      //SDA����Ϊ����
	MPU_IIC_SDA_HIGH;MPU_IIC_Delay();
	MPU_IIC_SCL_HIGH;MPU_IIC_Delay();
	while(MPU_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			MPU_IIC_Stop();
			return 1;
		}
	}
	MPU_IIC_SCL_LOW;//ʱ�����0
	return 0;
}
//����ACKӦ��
void MPU_IIC_Ack(void)
{
	MPU_IIC_SCL_LOW;
	MPU_SDA_OUT();
	MPU_IIC_SDA_LOW;
	MPU_IIC_Delay();
	MPU_IIC_SCL_HIGH;
	MPU_IIC_Delay();
	MPU_IIC_SCL_LOW;
}
//������ACKӦ��
void MPU_IIC_NAck(void)
{
	MPU_IIC_SCL_LOW;
	MPU_SDA_OUT();
	MPU_IIC_SDA_HIGH;
	MPU_IIC_Delay();
	MPU_IIC_SCL_HIGH;
	MPU_IIC_Delay();
	MPU_IIC_SCL_LOW;
}
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
void MPU_IIC_Send_Byte(u8 txd)
{
    u8 t;
	MPU_SDA_OUT();
    MPU_IIC_SCL_LOW;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {
    	if ((txd&0x80)>>7)
    		MPU_IIC_SDA_HIGH;
        else
        	MPU_IIC_SDA_LOW;
        txd<<=1;
		    MPU_IIC_SCL_HIGH;
		    MPU_IIC_Delay();
		    MPU_IIC_SCL_LOW;
		    MPU_IIC_Delay();
    }
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
u8 MPU_IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	MPU_SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        MPU_IIC_SCL_LOW;
        MPU_IIC_Delay();
		MPU_IIC_SCL_HIGH;
        receive<<=1;
        if(MPU_READ_SDA)receive++;
		MPU_IIC_Delay();
    }
    if (!ack)
        MPU_IIC_NAck();//����nACK
    else
        MPU_IIC_Ack(); //����ACK
    return receive;
}





