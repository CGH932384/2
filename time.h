#ifndef _time_H
#define _time_H

#include "public.h"


//变量声明
extern u8 a;//ms级定义
extern u8 b;//秒定义
extern u8 c;//分定义
extern u8 d;//时定义

//函数声明
void time0_init(void);
void time0_start(void);
void time0_stop(void);
#endif
