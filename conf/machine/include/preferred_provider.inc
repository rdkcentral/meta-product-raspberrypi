#TYPE: Soc
#Product: raspberrypi4
#@DESCRIPTION: Include only the default providers name for HAL,mfr,egl,iarmmgr,
#              device settings,dvrmgr,westeros,hdmicec and wifi.
#

PREFERRED_PROVIDER_virtual/kernel = "android-raspberrypi"
PREFERRED_PROVIDER_virtual/vendor-westeros-drm = "westeros-soc-drm"
PREFERRED_PROVIDER_virtual/vendor-devicesettings-hal = "devicesettings-hal-raspberrypi4"
