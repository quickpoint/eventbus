/**
 *  @(#) eventhandler_combine.h
 *  @author quickpoint At HUST
 *  @version 1.0
 */
#ifndef _EVENT_HANDLER_COMBINE_H_
#define _EVENT_HANDLER_COMBINE_H_

#include "eventhandler.h"

C_STMT_BGN

/**
 * Creates a combined event handler with multiple handle functions.
 * @param topic The topic for the combined event handler
 * @param handleFuncs Array of handle functions to combine
 * @param size Size of the handle functions array
 * @return Pointer to the created combined event handler
 */
event_handler* event_handler_combine_create(topic_t topic,
                                            event_handler_handle_func handleFuncs[], int size);

C_STMT_END

#endif /* _EVENT_HANDLER_COMBINE_H_ */
