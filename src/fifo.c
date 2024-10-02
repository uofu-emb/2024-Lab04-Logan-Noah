#include <FreeRTOS.h>
#include <queue.h>
#include "fifo.h"

void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id) {
    struct request_msg data = {};
    while(1) {
        if(xQueueReceive(requests, &data, 1000)) {
            data.output = data.input + 5;
            data.handled_by = id;
            xQueueSendToBack(results, &data, portMAX_DELAY);
        }
    }
}