DESCRIPTION = "The Openmoko Dialer"
SECTION = "openmoko/pim"
PKG_TAGS_${PN} = "group::communication"
DEPENDS += " libmokoui2 libmokojournal2 pulseaudio dbus-glib libnotify libjana libframeworkd-glib"
PV = "0.0.1+svnr${SRCDATE}"
PR = "r8"
PE = "1"

inherit shr pkgconfig autotools

do_stage () {
        oe_libinstall -so libframeworkd-glib-phonegui-gtk ${STAGING_LIBDIR}
}

