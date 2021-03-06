#pragma once
#include <atomic>

//result要么是基本类型，要么是结构体；当请求成功时，code为0, 如果请求是无返回类型的，则result为空; 
//如果是有返回值的，则result为返回值。response_msg会序列化为一个标准的json串，回发给客户端。 
//网络消息的格式是length+body，由4个字节的长度信息（用来指示包体的长度）加包体组成。 
template<typename T>
struct response_msg
{
	int code;
	T result; 
};
 
enum result_code
{
	OK = 0,
	FAIL = 1,
	EXCEPTION = 2,
};

const int MAX_BUF_LEN = 8192;