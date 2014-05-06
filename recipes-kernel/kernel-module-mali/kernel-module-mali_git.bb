# Copyright (C) 2014 NEO-Technologies
# Released under the MIT license (see COPYING.MIT for the terms)

SUMMARY = "Mali modules for Rockchip RK30/RK31 (Mali400-MP4)"
LICENSE = "GPLv2"

SRC_URI = "git://github.com/linux-rockchip/mali-modules.git;branch=r3p2-01rel2-olegk0"
SRCREV_pn-${PN} = "83e63dcdd2703e3007af5054c21d02f4ac636914"

LIC_FILES_CHKSUM = "file://DX910-SW-99002-r3p2-01rel2/driver/src/devicedrv/mali/linux/license/gpl/mali_kernel_license.h;beginline=1;endline=9;md5=f2b35655f83d2efb4bdbecd45446ba59"

S = "${WORKDIR}/git"

EXTRA_OEMAKE += "KDIR=${STAGING_KERNEL_DIR}"

inherit module

do_compile() {
    # mali_drm.ko
    cd ${S}/DX910-SW-99002-r3p2-01rel2/driver/src/egl/x11/drm_module/mali_drm.rk30
    module_do_compile

    # ump.ko
    cd ${S}/DX910-SW-99002-r3p2-01rel2/driver/src/devicedrv/ump
    sed -i 's/^SVN_REV.*/SVN_REV:="0000"/g' Kbuild # fix subversion revision issues
    MAKE_TARGETS="BUILD=release CONFIG=rk30-m400-4" module_do_compile

    # mali.ko
    cd ${S}/DX910-SW-99002-r3p2-01rel2/driver/src/devicedrv/mali
    MAKE_TARGETS="BUILD=release USING_UMP=1 TARGET_PLATFORM=rk30 MALI_PLATFORM=rk30 MALI_SHARED_INTERRUPTS=1" module_do_compile
}

do_install() {
    # mali_drm.ko
    oe_runmake DEPMOD=echo INSTALL_MOD_PATH="${D}" -C ${STAGING_KERNEL_DIR} modules_install \
               M=${S}/DX910-SW-99002-r3p2-01rel2/driver/src/egl/x11/drm_module/mali_drm.rk30

    # ump.ko
    oe_runmake DEPMOD=echo INSTALL_MOD_PATH="${D}" -C ${STAGING_KERNEL_DIR} modules_install \
               M=${S}/DX910-SW-99002-r3p2-01rel2/driver/src/devicedrv/ump

    # mali.ko
    oe_runmake DEPMOD=echo INSTALL_MOD_PATH="${D}" -C ${STAGING_KERNEL_DIR} modules_install \
               M=${S}/DX910-SW-99002-r3p2-01rel2/driver/src/devicedrv/mali
}

