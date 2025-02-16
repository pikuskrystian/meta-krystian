
# meta-krystian - Custom Yocto Layer

This [Yocto](https://www.yoctoproject.org/) layer adds a GPIO blinking application (`gpio-blink`). It is a simple example of using a custom C application inside a Yocto build.

## Explanation of What Yocto Layer (meta-krystian) does
1️⃣ Layer Configuration (conf/layer.conf)

    Defines meta-krystian as a separate Yocto layer.
    Ensures Yocto recognizes and builds it correctly.

2️⃣ Recipe for GPIO Blink Application (recipes-example/gpio-blink/gpio-blink_0.1.bb)

    A BitBake recipe that tells Yocto how to compile and install the gpio-blink program.
    It fetches example.c, compiles it using Yocto’s toolchain, and installs the binary in /usr/bin/.

3️⃣ C Application (recipes-example/gpio-blink/files/example.c)

    A simple C program that controls GPIO pins to make an LED blink.
    Uses Linux GPIO sysfs or /dev/gpiochipX interfaces.
    Compiled as gpio-blink and placed in /usr/bin/ on the target device.
    
    🔹 What This Layer Does in a Yocto Build?

    Gets integrated into the Yocto build system when added via bitbake-layers add-layer.
    Compiles the gpio-blink program using Yocto’s cross-compilation tools.
    Packages the compiled binary (gpio-blink) into a .ipk/.rpm package.
    Installs the program into the final Linux filesystem (e.g., /usr/bin/gpio-blink).
    Optionally runs it on startup if a systemd service file is included.

## How to Use:
1. Clone this repository into your Yocto `sources` directory:

```git clone https://github.com/pikuskrystian/meta-krystian.git ~/poky/meta-krystian```

2. Add it to `bblayers.conf`:

```bitbake-layers add-layer meta-krystian```

3. Build the package:

```bitbake gpio-blink```

4. (Optional) Add to the image:

```echo 'IMAGE_INSTALL:append = " gpio-blink"' >> ~/poky/build/conf/local.conf bitbake core-image-minimal```
