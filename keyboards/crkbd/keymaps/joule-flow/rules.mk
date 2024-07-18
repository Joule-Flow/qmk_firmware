BOOTLOADER = atmel-dfu # Bootloader selection for crkbd

# underside rgb led configuration
RGBLIGHT_ENABLE = no
#RGBLED_SPLIT = 6

# underswitch rgb led configuration
RGB_MATRIX_ENABLE  = yes

# oled configuration
OLED_ENABLE = yes

# keymap functionality
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes


MOUSEKEY_ENABLE = no
BOOTLOADER = atmel-dfu # Bootloader selection for crkbd

# reduce compiled size
LTO_ENABLE = yes # link time optimization
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
