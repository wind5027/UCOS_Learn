UCOSII实验5：消息队列的使用测试

 1. 实验目的：消息队列创建发送请求测试
 2. 实验现象：KEY0按键按下，显示Received到的消息数据顺序为 4,3,2,1，0
           KEY1按键按下，显示Received到的消息数据顺序为 0,1,2,3,4
           当然，这只是测试程序，你的按键不要连续按。		   
		  
3.用到的UCOSII函数
这里我们不重复讲解之前讲解过的函数。
 
消息队列创建函数：     
OS_EVENT  *OSQCreate (void **start, INT16U size)
LIFO方式发送消息函数：
 INT8U  OSQPostFront (OS_EVENT *pevent, void *msg)//后进先出
FIFO方式发送消息函数：
 INT8U  OSQPost (OS_EVENT *pevent, void *msg)//先进先出

OSTaskCreate()函数创建TaskStart任务，
在TaskStart任务4次调用ucos任务创建函数OSTaskCreate()创建4个任务：TaskLed，TaskLed1，TaskLCD，TaskKey 。同时创建消息队列
Str_Q =  OSQCreate(&MsgGrp[0],N_MESSAGES);。
然后调用OSTaskSuspend()函数将TaskStart任务挂起，因为在4个任务创建后，TaskStart任务该做的事情已经完毕，挂起任务。然后4个任务在开始执行执行；

TaskLed： 	LED0循环闪烁，反转间隔为200ms
TaskLed1：	LED1循环闪烁,反转间隔为200ms
TaskLCD:  	每隔50ms请求消息队列，并显示得到的消息
TaskKey： 	每隔20ms扫描按键值 。

TaskKey进行按键扫描，这里在任务TaskLCD和TaskKey之间有一个任务挂起OSTaskSuspend和恢复OSTaskResume操作，这个操作的目的是为了让按键扫描之后发送消息到消息队列完成之后，TaskLCD任务才开始请求消息邮箱，也就是消息发送完成了才开始请求，这样方便查看队列顺序。

如果为KEY0按下，那么以LIFO(后进先出)方式向消息队列发送消息0-4，发送之后，可以看到液晶显示收到的消息顺序为4,3,2,1,0，为什么？因为是后进先出嘛，自然最后发送的4最先收到了.
如果KEY1按下，那么以FIFO(先进先出)方式向消息队列发送消息0-4，发送之后，可以看到液晶显示收到的消息顺序为0,1,2,3,4，因为是先进先出嘛，自然最先发送的0最先收到.



注意:
1,本代码可以SWD下载,但是不支持仿真,下载完后,请拔了仿真器.否则可能导致部分功能不正常.


	       购买：http://shop62103354.taobao.com
                     http://shop62057469.taobao.com
               技术支持论坛：www.openedv.com
               ALIENTEK//广州星翼电子科技有限公司
