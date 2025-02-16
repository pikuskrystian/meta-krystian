
# meta-krystian - Custom Yocto Layer

This [Yocto](https://www.yoctoproject.org/) layer adds a GPIO blinking application (`gpio-blink`). It is a simple example of using a custom C application inside a Yocto build.

## How to Use:
1. Clone this repository into your Yocto `sources` directory:

```git clone https://github.com/pikuskrystian/meta-krystian.git ~/poky/meta-krystian```

2. Add it to `bblayers.conf`:

```bitbake-layers add-layer meta-krystian```

3. Build the package:

```bitbake gpio-blink```

4. (Optional) Add to the image:

```echo 'IMAGE_INSTALL:append = " gpio-blink"' >> ~/poky/build/conf/local.conf bitbake core-image-minimal```
