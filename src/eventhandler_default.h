/**
 *  @(#) eventhandler_default.h
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#ifndef _EVENT_HANDLER_DEFAULT_H_
#define _EVENT_HANDLER_DEFAULT_H_

#include "eventhandler.h"

C_STMT_BGN

int event_handler_default_handle(event_handler* thiz, topic_t topic, void* data, void* context);

int event_handler_default_should_handle(event_handler* thiz, topic_t topic);

void event_handler_default_destroy(event_handler* thiz);

C_STMT_END

#endif /* _EVENT_HANDLER_DEFAULT_H */

