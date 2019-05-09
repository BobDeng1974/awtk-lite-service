﻿/**
 * File:   http_response.h
 * Author: AWTK Develop Team
 * Brief:  http response
 *
 * Copyright (c) 2019 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ===============================================================
 * 2019-05-09 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_HTTP_RESPONSE_H
#define TK_HTTP_RESPONSE_H

#include "tkc/mutex.h"
#include "http/http_common.h"

BEGIN_C_DECLS

/**
 * @class http_response_t
 *
 * HTTP response
 *
 */
struct _http_response_t {
  /**
   * @property {uint32_t} status_code
   * @annotation ["readable"]
   * HTTP response 的status code。
   */
  uint32_t status_code;

  /**
   * @property {char*} status_text
   * @annotation ["readable"]
   * HTTP response 的status text。
   */
  char* status_text;
  
  /**
   * @property {http_header_t*} header
   * @annotation ["readable"]
   * 额外的header信息。
   */
  http_header_t *header;

  /**
   * @property {void*} body
   * @annotation ["readable"]
   * PUT/POST请求上传的数据。
   */
  void* body;

  /**
   * @property {uint32_t} body_size
   * @annotation ["readable"]
   * PUT/POST请求上传的数据的长度。
   */
  uint32_t body_size;
  
  /**
   * @property {uint32_t} uploaded_size
   * @annotation ["readable"]
   * PUT/POST请求，已经上传的数据的长度。
   */
  uint32_t uploaded_size;
  
  /**
   * @property {uint32_t} downloaded_size
   * @annotation ["readable"]
   * GET请求，已经下载的数据的长度。
   */
  uint32_t downloaded_size;

  /**
   * @property {bool_t} done;
   * @annotation ["readable"]
   * 整个请求完成。
   */
  bool_t done;
  
  /**
   * @property {bool_t} fail;
   * @annotation ["readable"]
   * 请求失败。
   */
  bool_t fail;

  /*private*/
  tk_mutex_t* mutex;
};

/**
 * @method http_response_create
 *
 * 创建一个response对象。
 * 
 * @return {http_response_t*} 返回response对象。
 */
http_response_t* http_response_create(void);

/**
 * @method http_response_set_status
 *
 * 设置status。
 * 
 * @param {http_response_t*} response http response对象。
 * @param {uint32_t} code 响应码。
 * @param {const char*} text 响应的文本。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_set_status(http_response_t* response, uint32_t code, const char* text);

/**
 * @method http_response_add_header
 *
 * 增加一个header。
 * 
 * @param {http_response_t*} response http response对象。
 * @param {const char*} key header的键名。
 * @param {const char*} value header的键值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_add_header(http_response_t* response, const char* key, const char* value);

/**
 * @method http_response_find_header
 *
 * 查找指定的key，如果找到返回它的value。
 * 
 * @param {http_response_t*} response response对象。
 * @param {const char*} key header的key。
 *
 * @return {const char*} 如果找到，返回指定key的value，否则返回NULL。
 */
const char* http_response_find(http_response_t* response, const char* key);

/**
 * @method http_response_set_body
 *
 * 设置body。
 * 
 * @param {http_response_t*} response http response对象。
 * @param {void*} body 返回的数据。
 * @param {uint32_t} body_size 返回数据的长度。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_set_body(http_response_t* response, void* body, uint32_t body_size);

/**
 * @method http_response_set_done
 *
 * 设置完成标志。
 * 
 * @param {http_response_t*} response http response对象。
 * @param {bool_t} done 是否完成。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_set_done(http_response_t* response, bool_t done);

/**
 * @method http_response_set_fail
 *
 * 设置失败标志。
 * 
 * @param {http_response_t*} response http response对象。
 * @param {bool_t} fail 是否失败。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_set_fail(http_response_t* response, bool_t fail);

/**
 * @method http_response_set_uploaded_size
 *
 * 更新已经上传数据的大小。
 * 
 * @param {http_response_t*} response http response对象。
 * @param {uint32_t} uploaded_size 已经上传数据的大小。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_set_uploaded_size(http_response_t* response, uint32_t uploaded_size);

/**
 * @method http_response_set_downloaded_size
 *
 * 更新已经下载数据的大小。
 * 
 * @param {http_response_t*} response http response对象。
 * @param {uint32_t} downloaded_size 已经下载数据的大小。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_set_downloaded_size(http_response_t* response, uint32_t downloaded_size);

/**
 * @method http_response_lock
 *
 * lock response对象。
 * 
 * @param {http_response_t*} response http response对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_lock(http_response_t* response);

/**
 * @method http_response_unlock
 *
 * lock response对象。
 * 
 * @param {http_response_t*} response http response对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_unlock(http_response_t* response);

/**
 * @method http_response_destroy
 *
 * 销毁response对象。
 * 
 * @param {http_response_t*} response http response对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t http_response_destroy(http_response_t* response);

END_C_DECLS

#endif /*TK_HTTP_RESPONSE_H*/
