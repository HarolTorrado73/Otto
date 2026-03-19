#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/adc.h>
#include <driver/gpio.h>

/* Otto Robot Pet - Gato/Perro con servo en la cola
 * Hardware: ESP32-S3, Pantalla ST7789, MAX98357A + INMP441, 5 servos MG90S
 */

struct HardwareConfig {
    gpio_num_t power_charge_detect_pin;
    adc_unit_t power_adc_unit;
    adc_channel_t power_adc_channel;

    gpio_num_t right_leg_pin;
    gpio_num_t right_foot_pin;
    gpio_num_t left_leg_pin;
    gpio_num_t left_foot_pin;
    gpio_num_t left_hand_pin;
    gpio_num_t right_hand_pin;

    int audio_input_sample_rate;
    int audio_output_sample_rate;
    bool audio_use_simplex;

    gpio_num_t audio_i2s_gpio_ws;
    gpio_num_t audio_i2s_gpio_bclk;
    gpio_num_t audio_i2s_gpio_din;
    gpio_num_t audio_i2s_gpio_dout;

    gpio_num_t audio_i2s_mic_gpio_ws;
    gpio_num_t audio_i2s_mic_gpio_sck;
    gpio_num_t audio_i2s_mic_gpio_din;
    gpio_num_t audio_i2s_spk_gpio_dout;
    gpio_num_t audio_i2s_spk_gpio_bclk;
    gpio_num_t audio_i2s_spk_gpio_lrck;
    gpio_num_t audio_spk_sd_pin; /* MAX98357A SD: LOW=mute, HIGH=unmute. GPIO_NUM_NC si no se usa */

    gpio_num_t display_backlight_pin;
    gpio_num_t display_mosi_pin;
    gpio_num_t display_clk_pin;
    gpio_num_t display_dc_pin;
    gpio_num_t display_rst_pin;
    gpio_num_t display_cs_pin;

    gpio_num_t i2c_sda_pin;
    gpio_num_t i2c_scl_pin;
};

/* Configuración según tu conexión:
 * Servos: Antes/Front=17, Izquierda/Left=18, Derecha/Right=39, Atrás/Back=38, Cola/Tail=8
 * Mapeo Otto: left_leg=Front, left_foot=Left, right_leg=Right, right_foot=Back, left_hand=Cola
 * right_hand=NC (solo 5 servos)
 */
constexpr HardwareConfig PET_VERSION_CONFIG = {
    .power_charge_detect_pin = GPIO_NUM_NC,
    .power_adc_unit = ADC_UNIT_2,
    .power_adc_channel = ADC_CHANNEL_3,

    .right_leg_pin = GPIO_NUM_39,   /* Derecha (Phải) */
    .right_foot_pin = GPIO_NUM_38,  /* Atrás (Sau) */
    .left_leg_pin = GPIO_NUM_17,    /* Antes (Trước) */
    .left_foot_pin = GPIO_NUM_18,   /* Izquierda (Trái) */
    .left_hand_pin = GPIO_NUM_8,    /* Cola (Đuôi) */
    .right_hand_pin = GPIO_NUM_NC,  /* Sin 6º servo */

    .audio_input_sample_rate = 16000,
    .audio_output_sample_rate = 24000,
    .audio_use_simplex = true,

    .audio_i2s_gpio_ws = GPIO_NUM_NC,
    .audio_i2s_gpio_bclk = GPIO_NUM_NC,
    .audio_i2s_gpio_din = GPIO_NUM_NC,
    .audio_i2s_gpio_dout = GPIO_NUM_NC,

    .audio_i2s_mic_gpio_ws = GPIO_NUM_4,   /* INMP441 WS */
    .audio_i2s_mic_gpio_sck = GPIO_NUM_5,  /* INMP441 SCK */
    .audio_i2s_mic_gpio_din = GPIO_NUM_6,  /* INMP441 SD */
    .audio_i2s_spk_gpio_dout = GPIO_NUM_7, /* MAX98357A DIN */
    .audio_i2s_spk_gpio_bclk = GPIO_NUM_15,/* MAX98357A BCLK */
    .audio_i2s_spk_gpio_lrck = GPIO_NUM_16,/* MAX98357A LRC */
    .audio_spk_sd_pin = GPIO_NUM_21,       /* MAX98357A SD - control de mute/unmute */

    .display_backlight_pin = GPIO_NUM_3,   /* BLK - Naranja */
    .display_mosi_pin = GPIO_NUM_10,       /* SDA - Verde */
    .display_clk_pin = GPIO_NUM_9,         /* SCL - Cian */
    .display_dc_pin = GPIO_NUM_46,         /* DC - Púrpura */
    .display_rst_pin = GPIO_NUM_11,        /* RES - Azul oscuro */
    .display_cs_pin = GPIO_NUM_NC,         /* CS a GND de pantalla */

    .i2c_sda_pin = GPIO_NUM_NC,
    .i2c_scl_pin = GPIO_NUM_NC,
};

#define LCD_TYPE_ST7789_SERIAL
#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 240
#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY false
#define DISPLAY_INVERT_COLOR true
#define DISPLAY_RGB_ORDER LCD_RGB_ELEMENT_ORDER_RGB
#define DISPLAY_OFFSET_X 0
#define DISPLAY_OFFSET_Y 0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE 3

#define BOOT_BUTTON_GPIO GPIO_NUM_0

#endif
