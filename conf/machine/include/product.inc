ENABLE_HDMI_FORCE_HOTPLUG = "1"

MACHINE = "raspberrypi4-64-rdke"
TARGET_VENDOR = "-rdk"
KERNEL_IMAGETYPE= "Image"

# To enable serial console
ENABLE_UART = "1"

# This is needed for tmp directory to be named as tmp instead of tmp-glibc
TCLIBCAPPEND = ""

# Enabling this causes issue from glibc. Refer RDKCentral jira RDKE-13
#MACHINEOVERRIDES .= ":arm"

# This override is needed for systemd 2.30 patches to get applied. Refer RDKCentral jira RDKE-12
MACHINEOVERRIDES .= ":dunfell"
DISTRO_FEATURES_append = " dunfell"

require conf/multilib.conf
MULTILIBS = "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 = "armv7athf-neon-vfpv4"

# Enable Syslog-ng
DISTRO_FEATURES_append = " syslog-ng"

# Enabling this to solve syslog-ng packaging issue. Refer RDKCentral jira RDKE-14
DISTRO_FEATURES_append = " systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = "systemd-compat-units"
# This distro is used in westeros recipes
DISTRO_FEATURES_append = " rdkshell"

# Middleware layer requirements.
DOBBY_DEVICESETTINGS_FILE = "dobby.generic.json"

# Platform does not have SVP support
DISTRO_FEATURES_remove = " rdk_svp"

## Move to common middleware configuration when its ready. Refer Comcast Jira: RDK-50625
# To remove SecAPI dependency.
DISTRO_FEATURES_append = " enable_icrypto_openssl open-middleware"

# To remove rdkfwupgrade package dependency
DISTRO_FEATURES_remove = "enable_maintenance_manager ctrlm"

# White list host tools for generating binary images
WHITELIST_GPLv3 += "${MLPREFIX}dosfstools ${MLPREFIX}coreutils ${MLPREFIX}findutils"
WHITELIST_GPL-3.0 = "${WHITELIST_GPLv3}"
