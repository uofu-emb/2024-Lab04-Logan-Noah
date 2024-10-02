#include <FreeRTOS.h>
#include <semphr.h>
#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data) {

    if (xSemaphoreTake(request, portMAX_DELAY) == pdTRUE) {
        data->output = data->input + 5;
        xSemaphoreGive(response);
    }
    else {
        return;
    }
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data) {

    xSemaphoreGive(request);
    // Wait time is arbitrarily chosen (10,000)
    if (xSemaphoreTake(response, 10000) == pdTRUE) {
        return pdTRUE;
    }
    else {
        return pdFALSE;
    }
}