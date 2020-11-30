
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
				./lib/host_led_state_reader.c \
				./lib/timelogger.c \
        ./lib/mode_icon_reader.c \

#--------------------------#
#RGBLIGHT_ENABLE = no
#RGB_MATRIX_ENABLE = WS2812
#--------------------------|
RGBLIGHT_ENABLE = no
#--------------------------#

TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = no
# enable OLED displays
OLED_DRIVER_ENABLE = no

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu
