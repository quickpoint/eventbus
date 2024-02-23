/**
 * @(#) eventhandler_limit.h
 * @author quickpoint AT HUST
 * @version 1.0
 */
#ifndef _EVENT_HANDLER_LIMIT_H_
#define _EVENT_HANDLER_LIMIT_H_

#include "eventhandler.h"

C_STMT_BGN

/**
 * Creates a limit event handler that limits the number of times events can be handled.
 * @param proxyHandler The event handler to limit
 * @param maxLimit The maximum number of times the event can be handled
 * @return Pointer to the created limit event handler
 */
event_handler* event_handler_limit_create(event_handler* proxyHandler, int maxLimit);

C_STMT_END

#endif /* _EVENT_HANDLER_LIMIT_H_ */