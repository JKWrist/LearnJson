/****************************************************************
*  Copyright © 2020年 junze xu. All rights reserved.
*  All rights reserved.
*
*  文件名称: test.cc
*  简要描述: 测试程序
*
*  创建日期: Created by junze xu on 2021/2/2.
*  作者: junze xu
*  说明:
*
*  修改日期:
*  作者:
*  说明:
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leptjson.h"

//TDD开发，先写测试程序，然后再实现

/****************************************************************
* 全局变量
*****************************************************************/

/****************************************************************
* 杂项
*****************************************************************/
static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;
/****************************************************************
* 宏定义
*****************************************************************/
#define EXPECT_EQ_BASE(equality, expect, actual, format)\
	do{\
		test_count++;\
		if(equality)\
			test_pass++;\
		else {\
		fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
		main_ret = 1;\
		}\
	} while(0)
		
#define EXPECT_EQ_INT(expect, actual)  EXPECT_EQ_BACE((expect) == (actual), expect, actual, "%d");
/****************************************************************
* 函数
*****************************************************************/

static void test_parse_null()
{
	lept_value v;
	v.type = LEPT_TURE;
	EXPECT_EQ_INT(LEPT_PARSE_OK, lept_parse(&v, "null"));
	EXPECT_EQ_INT(LEPT_NULL, lept_get_type(&v));
}

static void test_parse()
{
	test_parse_null();
}

int main(int argc, char *argv[]) 
{
	test_parse();
	printf("%d/%d (%3.2f%%) passed \n", test_pass, test_count, test_pass * 100.0 / test_count);
	return main_ret;
}