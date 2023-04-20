
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "string.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "ds18b20.h"

/// @brief 
static const char *TAG = "example";

const int DS_PIN = 14; //GPIO where you connected ds18b20

void app_main()
{
    nvs_flash_init();
    ds18b20_init(DS_PIN);

    while (1) {
        printf("Temperature: %0.1f\n",ds18b20_get_temp());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
