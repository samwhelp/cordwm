
# cordwm


## Orginal Project

* [chadwm](https://github.com/siduck76/chadwm)


## New Project

* [cordwm](https://github.com/samwhelp/cordwm)


## Docs

| Spec |
| --- |
| [keybind](asset/usr/share/cordwm/docs/spec-keybind.md) |
| [mousebind](asset/usr/share/cordwm/docs/spec-mousebind.md) |
| [boot](asset/usr/share/cordwm/docs/spec-boot.md) |


## Note

### transparent: dwm bar

set [picom.conf](asset/usr/share/cordwm/config/cordwm/share/style-profile/main/picom/picom.conf#L231)

```
  "90:class_g     = 'dwm'",
  "90:class_g     = 'dwmsystray'",
```

use `xprop` to find WM_CLASS

```
WM_CLASS(STRING) = "dwm", "dwm"
```

```
WM_CLASS(STRING) = "dwmsystray", "dwmsystray"
```


## Reference

* https://wiki.archlinux.org/title/Creating_packages
* https://wiki.archlinux.org/title/Arch_User_Repository
* https://archlinux.org/groups/x86_64/base-devel/
* https://wiki.archlinux.org/title/pacman
* https://wiki.archlinux.org/title/makepkg
* https://wiki.archlinux.org/title/PKGBUILD
* https://wiki.archlinux.org/title/Arch_package_guidelines
