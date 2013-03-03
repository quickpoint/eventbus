/**
 *  @(#) eventhandler_limit.h
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#ifndef _EVENT_HANDLER_LIMIT_H_
#define _EVENT_HANDLER_LIMIT_H_

#include "eventhandler.h"

C_STMT_BGN

event_handler* event_handler_limit_create(event_handler* proxyHandler, int maxLimit);

C_STMT_END

#endif /* _EVENT_HANDLER_LIMIT_H_ */
