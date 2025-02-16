DESCRIPTION = "A simple GPIO LED blinking program"
LICENSE = "CLOSED"
SRC_URI = "file://example.c"

S = "${WORKDIR}"

do_compile() {
        ${CC} ${CFLAGS} example.c -o gpio-blink ${LDFLAGS}   
}

do_install() {
        install -d ${D}${bindir}                
        install -m 0755 gpio-blink ${D}${bindir}/gpio-blink
}

FILES_${PN} = "${bindir}/gpio-blink"

