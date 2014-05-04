# Copyright (C) 2014 NEO-Technologies
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = "Linux kernel for Rockchip's ARM platforms"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel

SRCBRANCH ?= "rockchip-3.0"
DEFCONFIG ?= "rk3188_steak_defconfig"

SRC_URI = "git://github.com/linux-rockchip/rockchip-3.0.git;branch=${SRCBRANCH} \
           git://github.com/radxa/initrd.git;destsuffix=${WORKDIR}/initrd"
SRCREV_pn-${PN} = "${AUTOREV}"

S = "${WORKDIR}/git"

do_configure_prepend() {
    oe_runmake -C "${S}" ${DEFCONFIG}

    # Fix arch QA issues ("Architecture did not match")
    rm -f ${S}/mkkrnlimg
}

do_install_prepend() {
    # Dummy Makefile so the make target "clean _mrproper_scripts" from kernel.bbclass works.
    # This is required since the release "daisy".
    kerneldir=${D}${KERNEL_SRC_PATH}
    install -d $kerneldir/arch/arm/plat-rk/rk_pm_tests
    touch $kerneldir/arch/arm/plat-rk/rk_pm_tests/Makefile
}

do_deploy_append() {
    install -d ${DEPLOYDIR}
    cd ${WORKDIR}/initrd
    find . ! -path "*/.git*" ! -path "./README.md" ! -path "./Makefile" \
    | cpio -H newc -o > ${DEPLOYDIR}/initrd.img
}
