/**
 * @(#) eventhandler_print.h
 * @author quickpoint.h
 * @version 1.0
 */
#ifndef _EVENT_HANDLER_PRINT_H_
#define _EVENT_HANDLER_PRINT_H_
#include "eventbus_typedef.h"
#include "eventhandler.h"

C_STMT_BGN

/**
 * Creates a print event handler for a specific topic.
 * @param topic The topic for which the print handler is created
 * @return Pointer to the created print event handler
 */
event_handler* event_handler_print_create(topic_t topic);

C_STMT_END

#endif /* _EVENT_HANDLER_PRINT_H_ */