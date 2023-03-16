

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class            instance    title       tags mask     iscentered   isfloating   monitor */
    { "Gimp",           NULL,       NULL,       0,            0,           1,           -1 },
    { "eww",            NULL,       NULL,       0,            0,           1,           -1 },
    { "pcmanfm-qt",     NULL,       NULL,       1 << 1,       0,           0,           -1 },
    { "pcmanfm",        NULL,       NULL,       1 << 1,       0,           0,           -1 },
    { "Thunar",         NULL,       NULL,       1 << 1,       0,           0,           -1 },
    { "Atom",           NULL,       NULL,       1 << 2,       0,           0,           -1 },
    { "firefox",        NULL,       NULL,       1 << 3,       0,           0,           -1 },

};

/*

* https://dwm.suckless.org/customisation/rules/
* https://dwm.suckless.org/customisation/tagmask/

```
 1 << 1 : tag 2
 1 << 2 : tag 3
 1 << 3 : tag 4
 1 << 4 : tag 5
```

*/
