/****************************************************************
 *  Copyright © 2021年 junze xu. All rights reserved.
 *  All rights reserved.
 *
 *  文件名称: leptjson.c
 *  简要描述:	Json解析实现
 *
 *  创建日期: Created by junze xu on 2021/2/2.
 *  作者: junze xu
 *  说明: Json解析器
 *
 *  修改日期:
 *  作者:
 *  说明:
*****************************************************************/

/****************************************************************
* 文件包含
*****************************************************************/

#include "leptjson.h"
#include <assert.h>
#include <stdlib.h>

/****************************************************************
* 宏定义
*****************************************************************/
#define ECPERT(c, ch)	do{ assert(*c->json == (ch)); c->json++; }while(0)

/****************************************************************
* 全局变量
*****************************************************************/
typedef struct{
	const char* json;
}lept_context;

/****************************************************************
* 函数
*****************************************************************/


/****************************************************************
*  功能描述: JSON解析器
*  输入参数：v, 根节点指针类型
		   json，需要解析的C字符串
*  输出参数：v
*  返回值：JSON的解析状态
******************************************************************/
parse_value lept_parse(lept_value * v, const char * json)
{
	//ToDo JSON-test = ws value ws 以下实现没有处理最后的ws 和 LEPT_PARSE_NOT_SIGULAR
	lept_context c;
	assert(v != NULL);
	c.json = json;
	v->type = LEPT_NULL;
	lept_parse_whitespace(&c);
	return lept_parse_value(&c, v);
}