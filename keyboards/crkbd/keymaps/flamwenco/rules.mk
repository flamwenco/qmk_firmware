
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
VIA_ENABLE = yes
OLED_DRIVER_ENABLE = yes
LTO_ENABLE = yes
WPM_ENABLE = yes
MOUSE_KEYS = yes
# RAW_ENABLE = yes            # Enable RAW HID communication to PC
EXTRAFLAGS += -flto