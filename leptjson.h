//
//  leptjson.h
//  leptjson
//
//  Created by junze xu on 2021/2/2.
//  Copyright © 2020年 junze xu. All rights reserved.
//

#ifndef LEPTJSON_H
#define LEPTJSON_H
/****************************************************************
* 文件包含
*****************************************************************/


/****************************************************************
* 宏定义
*****************************************************************/


/****************************************************************
* 外部数据
*****************************************************************/

//JSON的数据类型
typedef enum{
LEPT_NULL,
LEPT_FALSE,
LEPT_TURE,
LEPT_NUMBER,
LEPT_STRING,
LEPT_ARRARY,
LEPT_OBJECT,
} lept_type;

//JSON的数据结构 首先实现null，true， flase
typedef struct {
	lept_type type;
}lept_value;

//解析状态值
typedef enum {
LEPT_PARSE_OK = 0,
LEPT_PARSE_EXPECT_VALUE,
LEPT_PARSE_INVALID_VALUE,
LEPT_PARSE_ROOT_NOT_SINGULAR,
} parse_value;

/****************************************************************
* 函数声明
*****************************************************************/
//解析Json
parse_value lept_parse(lept_value * v, const char * json);

//获取JSON类型
lept_type lept_get_type(const lept_value * v);

#endif //LEPTJSON_H