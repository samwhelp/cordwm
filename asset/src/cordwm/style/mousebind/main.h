
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button2,        setlayout,      {.v = &layouts[1]} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[0]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },

    /* Keep movemouse? */
    /* { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} }, */

    /* placemouse options, choose which feels more natural:
     *    0 - tiled position is relative to mouse cursor
     *    1 - tiled postiion is relative to window center
     *    2 - mouse pointer warps to window center
     *
     * The moveorplace uses movemouse or placemouse depending on the floating state
     * of the selected client. Set up individual keybindings for the two if you want
     * to control these separately (i.e. to retain the feature to move a tiled window
     * into a floating position).
     */
    { ClkClientWin,         MODWIN,         Button1,        moveorplace,    {.i = 0} },
    { ClkClientWin,         MODWIN,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODWIN,         Button3,        resizemouse,    {0} },
//    Note: ControlMask conflict File Manager Control Select File
//    { ClkClientWin,         ControlMask,    Button1,        dragmfact,      {0} },
//    { ClkClientWin,         ControlMask,    Button3,        dragcfact,      {0} },
    { ClkClientWin,         MODALT,         Button1,        dragmfact,      {0} },
    { ClkClientWin,         MODALT,         Button3,        dragcfact,      {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODWIN,         Button1,        tag,            {0} },
    { ClkTagBar,            MODWIN,         Button3,        toggletag,      {0} },
    { ClkTabBar,            0,              Button1,        focuswin,       {0} },
    { ClkTabBar,            0,              Button2,        killclient,     {0} },
    { ClkTabPrev,           0,              Button1,        movestack,      { .i = -1 } },
    { ClkTabNext,           0,              Button1,        movestack,      { .i = +1 } },
    { ClkTabClose,          0,              Button1,        killclient,     {0} },
};
