
##
## ## Link
##
## * https://aur.archlinux.org/packages/dwm/
## * https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=dwm
##

pkgname=cordwm
pkgver=0.1
pkgrel=1
pkgdesc="Cordwm (Dynamic window manager for X from Dwm)"
arch=('x86_64')
url="https://github.com/samwlep/cordwm"
license=('MIT')
#depends=()
depends=('libx11' 'libxinerama' 'libxft' 'freetype2')
optdepends=(
	'feh: for wallpaper'
	'scrot: for screenshot'
	'st: for terminal'
	'dmenu: as app launcher'
)
options=(!strip !emptydirs)


prepare () {
	cp -af "../asset/." "${srcdir}"
}


build () {

	make -C "${srcdir}/src/cordwm"

}


package () {

	cp -af "${srcdir}/usr" "${pkgdir}"

	#install -Dm755 "${srcdir}/src/cordwm/cordwm" "${pkgdir}/usr/bin/cordwm"
	install -Dm755 "${srcdir}/src/cordwm/dwm" "${pkgdir}/usr/bin/cordwm"


}
