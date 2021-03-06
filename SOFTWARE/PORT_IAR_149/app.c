
#include "includes.h"

#define  TASK_STK_SIZE                  64       /* 定义任务堆栈大小     */


OS_STK   TaskStartStk[TASK_STK_SIZE];

void   TaskStart(void *data);                    /* 前导声明任务（函数） */



void  main (void)
{
    WDTCTL = WDTPW + WDTHOLD;					/* 禁止看门狗              */

    OSInit();                                              /* 初始化uCOS-II */
    OSTaskCreate(TaskStart, (void *)0, &TaskStartStk[TASK_STK_SIZE - 1], 3);
    OSStart();                                             /* 开始任务调度  */
}



void  TaskStart (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    WDTCTL = WDT_MDLY_32;                                  /* 设置时钟节拍间隔为32ms     */
    IE1   |= 0x01;                                         /* 开看门狗定时器中断         */

    /*************************************
    *       应用程序初始化
    *************************************/
    
    P6SEL &= BIT7; 											
    P6DIR |= BIT7;
    
    

    while (1) {
        /******************************************************************************************
        *         测试代码
        *
        × 此处我们仅测试移植代码的正确，只是定时在P1.0输出高低电平，对应MSP-FET449学习板的P1.0 LED闪烁。
        *
        *          MSP430F449
        *     -----------------
        *  /|\|              XIN|-  
        *   | |                 |
        *   --|RST          XOUT|-
        *     |                 |
        *     |             P1.0|-->LED  
        * 
        *******************************************************************************************/
        
    	P6OUT ^= BIT7; 	 								    

        OSTimeDly(50);   /* 眼时10个时钟节拍，挂起本任务等待延时结束 */
    }
}
