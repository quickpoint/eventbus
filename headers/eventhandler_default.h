/**
 * @(#) eventhandler_default.h
 * @author quickpoint AT HUST
 * @version 1.0
 */
#ifndef _EVENT_HANDLER_DEFAULT_H_
#define _EVENT_HANDLER_DEFAULT_H_

#include "eventhandler.h"

C_STMT_BGN

/**
 * Default handler function to handle an event.
 * @param thiz The event handler instance
 * @param topic The topic of the event
 * @param data The event data
 * @param context Additional context for the event
 * @return 0 always
 */
int event_handler_default_handle(event_handler* thiz, topic_t topic, void* data, void* context);

/**
 * Default function to check if the event should be handled by the handler.
 * @param thiz The event handler instance
 * @param topic The topic of the event
 * @return 1 always
 */
int event_handler_default_should_handle(event_handler* thiz, topic_t topic);

/**
 * Default function to destroy the event handler (no action performed).
 * @param thiz The event handler instance to destroy
 */
void event_handler_default_destroy(event_handler* thiz);

C_STMT_END

#endif /* _EVENT_HANDLER_DEFAULT_H */