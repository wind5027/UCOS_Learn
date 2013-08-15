/*
*************************************************************************************
**�ļ�˵�����������Ͷ����ļ�
**�ļ����ƣ�user_type.h 
**�������ڣ�2009.07.21  
**�� �� �ˣ�����
**-----------------------------------------------------------------------------------
**�޸����ڣ�2013.xx.xx
**�޸�˵����
*************************************************************************************
*/


#ifndef USER_TYPE_H
#define USER_TYPE_H
/*
------------------------------------------------------------------------------------
˵�����������ͣ�λ���ȡ�
------------------------------------------------------------------------------------
*/
typedef unsigned char       Bool;
typedef unsigned char       Uint8;
typedef unsigned short int  Uint16;
typedef unsigned int        Uint32;
typedef signed char         Int8;
typedef signed short int    Int16;
typedef signed int          Int32;
typedef float               Float32;


/*
-------------------------------------------------------------------------------------
˵��: USB������
-------------------------------------------------------------------------------------
*/
typedef struct 
{
	Uint8 Cmd;
	Uint8 CmdPar[7];
}USBCmd;

		
#endif