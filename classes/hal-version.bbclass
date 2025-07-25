# hal-version.bbclass - Set version variables from HAL headers

require ${COREBASE}/../../common/meta-rdk-halif-headers/conf/include/rdk-headers-versions.inc

python __anonymous () {
    import re

    def parse_hal_version(d, pkg, prefix, enable_feature_below=None):
        """
        Extracts major, minor, build version from the given header package version
        and sets <prefix>_VER_MAJOR, _MINOR, _BUILD, _ENG variables.
        Optionally appends 'rdk-iarmmgrs-hal-unified-v1.0.1' to DISTRO_FEATURES if version <= enable_feature_below.
        """
        hal_ver = d.getVar(f'PV:pn-{pkg}')
        bb.note(f"DEBUG: {pkg} version = {hal_ver}")

        if enable_feature_below and hal_ver:
            cmp_result = bb.utils.vercmp_string(hal_ver, enable_feature_below)
            if cmp_result <= 0:
                features = d.getVar('DISTRO_FEATURES') or ""
                if "rdk-iarmmgrs-hal-unified-v1.0.1" not in features.split():
                    d.setVar('DISTRO_FEATURES', features + " rdk-iarmmgrs-hal-unified-v1.0.1")
                    bb.note(f"[hal-version.bbclass] Added 'rdk-iarmmgrs-hal-unified-v1.0.1' to DISTRO_FEATURES because {pkg} <= {enable_feature_below}")
                else:
                        bb.note(f"[hal-version.bbclass] 'rdk-iarmmgrs-hal-unified-v1.0.1' already present in DISTRO_FEATURES")

        if hal_ver:
            match = re.match(r"(\d+)\.(\d+)\.(\d+)", hal_ver)
            if match:
                major, minor, build = match.groups()
                d.setVar(f"{prefix}_VER_MAJOR", major)
                d.setVar(f"{prefix}_VER_MINOR", minor)
                d.setVar(f"{prefix}_VER_BUILD", build)
                d.setVar(f"{prefix}_VER_ENG", "0")
                bb.note(f"Set {prefix}_VER_MAJOR={major}, _MINOR={minor}, _BUILD={build}")
            else:
                bb.warn(f"[hal-version.bbclass] Could not parse version from: {hal_ver}")
        else:
            bb.warn(f"[hal-version.bbclass] {pkg} revision not found!")

    # Devicesettings HAL
    parse_hal_version(d, "devicesettings-hal-headers", "DEVICE_SETTINGS")

    # IARMMgrs HAL (feature rdk-iarmmgrs-hal-unified-v1.0.1 enabled if version <= 1.0.1)
    parse_hal_version(d, "iarmmgrs-hal-headers", "IARMMGRS", enable_feature_below="1.0.1")

    # TVSettings HAL
    parse_hal_version(d, "tvsettings-hal-headers", "TVSETTINGS")

    #RDK Gstreamer Utils
    parse_hal_version(d, "rdk-gstreamer-utils-headers", "RDK_GSTREAMER")
}
