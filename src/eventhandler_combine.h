/**
 *  @(#) eventhandler_combine.h
 *  @author quickpoint At HUST
 *  @version 1.0
 */
#ifndef _EVENT_HANDLER_COMBINE_H_
#define _EVENT_HANDLER_COMBINE_H_

#include "eventhandler.h"

C_STMT_BGN

event_handler* event_handler_combine_create(topic_t topic,  
        event_handler_handle_func handleFuncs[], int size);

C_STMT_END

#endif /* _EVENT_HANDLER_COMBINE_H_ */
