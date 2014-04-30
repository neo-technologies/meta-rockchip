# Copyright (C) 2014 NEO-Technologies
# Released under the MIT license (see COPYING.MIT for the terms)

inherit image_types

# This image depends on the rootfs ext4 image
IMAGE_TYPEDEP_rockchip-update-img = "ext4"

DEPENDS = "mkbootimg-native"

IMAGE_CMD_rockchip-update-img () {
	# Fetch bootloader
	# TODO

	# Fetch parameter
	# TODO

	# Build update.img using afptool and img_maker
	# TODO
	touch "${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.update.img"
}
