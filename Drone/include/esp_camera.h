#ifndef _ESP_CAMERA_H_
#define _ESP_CAMERA_H_

#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp_err.h"

#define PIXFORMAT_JPEG 0
#define FRAMESIZE_SVGA 10
#define LEDC_CHANNEL_0 0
#define LEDC_TIMER_0 0
#define ESP_OK 0

typedef struct {
    gpio_num_t pin_d0;
    gpio_num_t pin_d1;
    gpio_num_t pin_d2;
    gpio_num_t pin_d3;
    gpio_num_t pin_d4;
    gpio_num_t pin_d5;
    gpio_num_t pin_d6;
    gpio_num_t pin_d7;
    gpio_num_t pin_xclk;
    gpio_num_t pin_pclk;
    gpio_num_t pin_vsync;
    gpio_num_t pin_href;
    gpio_num_t pin_sscb_sda;
    gpio_num_t pin_sscb_scl;
    gpio_num_t pin_pwdn;
    gpio_num_t pin_reset;
    uint32_t xclk_freq_hz;
    uint8_t pixel_format;
    uint8_t frame_size;
    uint8_t jpeg_quality;
    uint8_t fb_count;
    ledc_channel_t ledc_channel;
    ledc_timer_t ledc_timer;
} camera_config_t;

typedef struct {
    uint8_t *buf;
    size_t len;
} camera_fb_t;

esp_err_t esp_camera_init(const camera_config_t *config);
camera_fb_t* esp_camera_fb_get();
void esp_camera_fb_return(camera_fb_t *fb);

#endif // _ESP_CAMERA_H_
