/**
 *  @(#) eventbus_test.c
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#include "eventbus.h"
#include "eventhandler_print.h"
#include "util.h"

int main(int argc, char* argv[]) {
    topic_t a_topic = {.key = (void*) 1, .compare = &int_compare};

    event_handler* print = event_handler_print_create(a_topic);

    eventbus* bus = eventbus_create();
    eventbus_subscribe(bus, print, NULL);
    eventbus_subscribe(bus, print, NULL);

    eventbus_post(bus, a_topic, "hello");

    event_handler_destroy(print);
    eventbus_destroy(bus);

    return 0;
}
