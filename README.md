# CBUS - A Simple Event Bus Implementation in C

## Introduction

CBus is a lightweight event bus library for C. It provides a simple mechanism for event handling and propagation within your C applications.

## Usage

```c
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
```

## Getting Started

To start using CBUS in your project, simply include the necessary headers and link against the library. Don't forget to initialize the event handlers and the event bus before using them.

```cmake
# Add CBUS library to your CMakeLists.txt
add_subdirectory(cbus)

# Link against CBUS library in your target
target_link_libraries(your_target cbus)

# Install CBUS headers and library
install(DIRECTORY cbus/include/cbus DESTINATION include)
install(TARGETS cbus DESTINATION lib)
```

### Using Event Handlers
#### 1. Print Handler
The `eventhandler_print` handler is used to print event data to the console.
```c
event_handler* print = event_handler_print_create(a_topic);
```

#### 2. Limit Handler
The `eventhandler_limit` handler limits the number of times an event can be handled.
```c
event_handler* limit_print = event_handler_limit_create(print, 3);
```

#### 3. Combine Handler
The `eventhandler_combine` handler combines multiple event handlers into one.
```c
event_handler_handle_func handleFuncs[] = {
    event_handler_print_handle,
    event_handler_print_handle,
};

event_handler* combine = event_handler_combine_create(b_topic, handleFuncs, nr);
```

#### Example
```c 
int i = 0;

// Create a topic with a key of 1 and a comparison function int_compare
topic_t a_topic = {.key = (void*)1, .compare = &int_compare};

// Create a print event handler for the topic
event_handler* print = event_handler_print_create(a_topic);

// Create a limit event handler that limits the print handler to handle events 3 times
event_handler* limit_print = event_handler_limit_create(print, 3);

// Process events for 5 iterations
for (i = 0; i < 5; i++) {
    // Check if the print handler should handle the event and handle it if true
    if (event_handler_should_handle(print, a_topic)) {
        event_handler_handle(print, a_topic, "hello", NULL);
    }

    // Check if the limit print handler should handle the event and handle it if true
    if (event_handler_should_handle(limit_print, a_topic)) {
        event_handler_handle(limit_print, a_topic, "world", NULL);
    }
}

// Clean up the created handlers to free memory
event_handler_destroy(print);
event_handler_destroy(limit_print);
```