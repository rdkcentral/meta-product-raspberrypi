MACHINE = "raspberrypi4-64-rdke"
TARGET_VENDOR = "-rdk"
KERNEL_IMAGETYPE= "Image"

## RPi specific boot-config overrides for RDKV Stack.
ENABLE_HDMI_FORCE_HOTPLUG = "1"
# To enable serial console
ENABLE_UART = "1"
# Upstream meta-raspberrypi kirkstone branch has "vc4-kms-v3d". Ref RDKVREFPLT-1977
VC4DTBO = "vc4-fkms-v3d"
# Enable CPU boost for performance, ref: https://meta-raspberrypi.readthedocs.io/en/latest/extra-build-config.html
RPI_EXTRA_CONFIG += "\n \
    arm_boost=1\n \
    "

# This is needed for tmp directory to be named as tmp instead of tmp-glibc
TCLIBCAPPEND = ""

# Enabling this causes issue from glibc. Refer RDKCentral jira RDKE-13
#MACHINEOVERRIDES .= ":arm"

# This override is needed for systemd 2.30 patches to get applied. Refer RDKCentral jira RDKE-12
MACHINEOVERRIDES .= ":kirkstone"
DISTRO_FEATURES:append = " kirkstone"

require conf/multilib.conf
MULTILIBS = "multilib:lib32"
DEFAULTTUNE:virtclass-multilib-lib32 = "armv7athf-neon-vfpv4"

# Enabling this to solve syslog-ng packaging issue. Refer RDKCentral jira RDKE-14
DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = "systemd-compat-units"

# Middleware layer requirements.
DOBBY_DEVICESETTINGS_FILE = "dobby.generic.json"

# Platform does not have SVP support
DISTRO_FEATURES:remove = " rdk_svp"

## Move to common middleware configuration when its ready. Refer Comcast Jira: RDK-50625
# To remove SecAPI dependency.
DISTRO_FEATURES:append = " enable_icrypto_openssl"

# RDK-52444: Temporarily remove the SECUIRTY_CFLAGS -fstackprotector and fortify source 
SECURITY_CFLAGS:remove = " -fstack-protector -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Wno-error=format-security -Wno-error=unused-result"
SECURITY_LDFLAGS:remove = " -fstack-protector"

#Setting default build variant as debug.
BUILD_VARIANT ?= "debug"

OPENCDM_DRMS=""

# Setting dri card interface for the device
DRI_DEVICE_NAME = "/dev/dri/card1"

# Temporary until subtec is opensourced
DISTRO_FEATURES:remove = ' subtec'
