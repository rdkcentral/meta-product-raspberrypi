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
