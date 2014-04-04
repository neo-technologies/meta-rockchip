# Copyright (C) 2014 NEO-Technologies
# Released under the MIT license (see COPYING.MIT for the terms)

require conf/machine/include/tune-cortexa7.inc

PREFERRED_PROVIDER_virtual/xserver = "xserver-xorg"

XSERVER = "xserver-xorg \
           xf86-video-fbturbo \
           xf86-input-evdev \
           xf86-input-mouse \
           xf86-input-keyboard"

PREFERRED_PROVIDER_virtual/kernel = "linux-rockchip-3.0"

IMAGE_CLASSES += "rockchip-update-img"
IMAGE_FSTYPES += "ext3 tar.gz rockchip-update-img"

SERIAL_CONSOLE = "115200 ttyFIQ0"

