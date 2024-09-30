#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data) {

    if (xSemaphoreTake(request, portMAX_DELAY) == pdTRUE) {
        data->output = data->input + 5;
        xSemaphoreGive(response);
    }
    else
        return;
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data) {

    xSemaphoreGive(request);
    if (xSemaphoreTake(response, portMAX_DELAY) == pdTRUE) {
        return pdTRUE;
    }
    else {
        return pdFALSE;
    }
}