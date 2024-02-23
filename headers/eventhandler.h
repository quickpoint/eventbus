/**
 * @(#) eventhandler.h
 * @author quickpoint AT HUST
 * @version 1.0
 */
#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "eventbus_typedef.h"

C_STMT_BGN

/** Data structure for a topic */
struct _topic_t;

/** Definition of a topic */
typedef struct _topic_t {
    /** The key associated with the topic */
    void* key;
    /**
     * Comparison function for topics.
     * @param thiz The topic itself
     * @param that Another topic to compare with
     * @return Result of the comparison
     */
    int (*compare)(void* thiz, void* that);
} topic_t;

/** Data structure for an event handler */
struct _event_handler;

/** Definition of an event handler */
typedef struct _event_handler event_handler;

/** Function pointer type for checking if an event should be handled */
typedef int (*event_handler_should_handle_func)(event_handler* thiz, topic_t topic);

/** Function pointer type for handling an event */
typedef int (*event_handler_handle_func)(event_handler* thiz, topic_t topic, void* data, void* context);

/** Function pointer type for destroying an event handler */
typedef void (*event_handler_destroy_func)(event_handler* thiz);

/** Structure representing an event handler */
struct _event_handler {
    /** The topic that the event handler is associated with */
    topic_t topic;
    /** Function pointer for determining if an event should be handled */
    event_handler_should_handle_func should_handle;
    /** Function pointer for handling an event */
    event_handler_handle_func handle;
    /** Function pointer for destroying the event handler */
    event_handler_destroy_func destroy;
    /** Extension field for future use */
    char ext[ZERO_LEN_ARRAY];
};

/**
 * Get the topic associated with an event handler.
 * @param thiz The event handler instance
 * @return The topic associated with the event handler
 */
void* event_handler_get_topic(event_handler* thiz);

/**
 * Check if an event should be handled by the event handler.
 * @param thiz The event handler instance
 * @param topic The topic of the event
 * @return 1 if the event should be handled, 0 otherwise
 */
int event_handler_should_handle(event_handler* thiz, topic_t topic);

/**
 * Handle an event using the event handler.
 * @param thiz The event handler instance
 * @param topic The topic of the event
 * @param data The event data
 * @param context Additional context for the event
 * @return 0 on success, -1 on failure
 */
int event_handler_handle(event_handler* thiz, topic_t topic, void* data, void* context);

/**
 * Destroy an event handler and free up resources.
 * @param thiz The event handler instance to destroy
 */
void event_handler_destroy(event_handler* thiz);

C_STMT_END

#endif /* _EVENT_HANDLER_H_ */