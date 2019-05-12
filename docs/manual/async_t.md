## async\_t
### 概述

 异步请求。



----------------------------------
### 函数
<p id="async_t_methods">

| 函数名称 | 说明 | 
| -------- | ------------ | 
| <a href="#async_t_async_call">async\_call</a> |  |
#### async\_call 函数
-----------------------

* 函数功能：

> <p id="async_t_async_call"> 
 异步执行exec函数，执行完成后，在GUI线程调用on_result函数。







* 函数原型：

```
ret_t async_call (async_exec_t exec, async_on_result_t on_result, void* ctx);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| exec | async\_exec\_t | 需要异步支持的函数。 |
| on\_result | async\_on\_result\_t | 返回执行结果(可选) |
| ctx | void* | 两个回调函数的上下文。 |