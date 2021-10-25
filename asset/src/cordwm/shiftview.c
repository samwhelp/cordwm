
/*
 * ## Reference
 *
 * * https://github.com/siduck76/chadwm/issues/49
 * * https://dwm.suckless.org/patches/shift-tools/
 * * https://dwm.suckless.org/patches/shift-tools/shift-tools.c
 * * https://lists.suckless.org/dev/1104/7590.html
 * * wget -c https://lists.suckless.org/dev/att-7590/shiftview.c
 *
 */

/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
void
shiftview(const Arg *arg) {
	Arg shifted;

	if(arg->i > 0) // left circular shift
		shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
			| (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));

	else // right circular shift
		shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
			| selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);

	view(&shifted);
}
