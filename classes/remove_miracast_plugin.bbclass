# RDKECOREMW-936: Workaround to fix miracast plugin crash on reactivation. 
# Todo: Remove when https://github.com/rdkcentral/entservices-casting/pull/133 is released

remove_miracast_plugin() {
    if [ -f "${IMAGE_ROOTFS}/etc/WPEFramework/plugins/MiracastService.json" ]; then
        rm -f ${IMAGE_ROOTFS}/etc/WPEFramework/plugins/MiracastService.json
    fi
    if [ -f "${IMAGE_ROOTFS}/etc/WPEFramework/plugins/MiracastPlayer.json" ]; then
        rm -f ${IMAGE_ROOTFS}/etc/WPEFramework/plugins/MiracastPlayer.json
    fi
}
ROOTFS_POSTPROCESS_COMMAND += "remove_miracast_plugin; "
