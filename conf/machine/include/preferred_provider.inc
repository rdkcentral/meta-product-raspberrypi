#TYPE: Soc
#Product: raspberrypi4
#@DESCRIPTION: Include only the default providers name for HAL,mfr,egl,iarmmgr,
#              device settings,dvrmgr,westeros,hdmicec and wifi.
#

PREFERRED_PROVIDER_virtual/kernel = "android-raspberrypi"
PREFERRED_PROVIDER_virtual/vendor-westeros-drm = "westeros-soc-drm"
PREFERRED_PROVIDER_virtual/vendor-westeros-soc = "westeros-soc-drm"
PREFERRED_PROVIDER_virtual/vendor-westeros-sink = "westeros-sink"

PREFERRED_PROVIDER_virtual/egl = "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "mesa", "userland", d)}"
PREFERRED_PROVIDER_virtual/libgles2 = "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "mesa", "userland", d)}"
PREFERRED_PROVIDER_virtual/libgl = "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "mesa", "mesa-gl", d)}"
PREFERRED_PROVIDER_virtual/mesa = "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "mesa", "mesa-gl", d)}"
PREFERRED_PROVIDER_virtual/libgbm = "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "mesa", "mesa-gl", d)}"

PREFERRED_PROVIDER_virtual/vendor-devicesettings-hal = "devicesettings-hal-raspberrypi4"
PREFERRED_PROVIDER_virtual/vendor-iarmmgrs-hal = "iarmmgrs-hal-raspberrypi4"
PREFERRED_PROVIDER_virtual/vendor-pwrmgr-hal = "pwrmgr-hal-raspberrypi4"
PREFERRED_PROVIDER_virtual/vendor-deepsleepmgr-hal = "deepsleepmgr-hal-raspberrypi4"
PREFERRED_PROVIDER_virtual/mfrlib = "mfrlibs-hal-raspberrypi4"
PREFERRED_PROVIDER_virtual/vendor-hdmicec-hal = "hdmicec-hal-raspberrypi4"
PREFERRED_PROVIDER_virtual/vendor-tvsettings-hal = "tvsettings-hal-noop"
PREFERRED_PROVIDER_virtual/vendor-rdk-gstreamer-utils-platform = "rdk-gstreamer-utils-platform"

#Temp add media-utils as provider for vendor-media-utils, to be re-worked if hal changes are required.
PREFERRED_PROVIDER_virtual/vendor-media-utils = "media-utils"
PREFERRED_PROVIDER_virtual/vendor-audio-service = "audio-service-rpi"
PREFERRED_PROVIDER_virtual/vendor-gst-drm-plugins = "gst-drm-plugins-rpi"
PREFERRED_PROVIDER_virtual/vendor-secapi2-adapter = "secapi2-adapter-rpi"
PREFERRED_PROVIDER_virtual/vendor-systemaudioplatform = "systemaudioplatform"

# Cobalt must be compiled from sources until REFPLTV-2693 is resolved
PREFERRED_PROVIDER_virtual/cobalt-evergreen = "cobalt-evergreen-src"
