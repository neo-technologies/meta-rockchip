# Copyright (C) 2014 NEO-Technologies
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = "Linux kernel for Rockchip's ARM platforms"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel

SRC_URI = "git://github.com/linux-rockchip/rockchip-3.0.git;branch=${SRCBRANCH}"
