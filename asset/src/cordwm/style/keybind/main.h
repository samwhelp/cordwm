

/*

run

``` sh
pacman -Ql | grep X11/keysym.h
```

show

```
xorgproto /usr/include/X11/keysym.h
```

run

``` sh
grep '#include' /usr/include/X11/keysym.h
```

show

```
#include <X11/keysymdef.h>
```


run

``` sh
pacman -Ql | grep keysymdef.h
```

show

```
python-xlib /usr/lib/python3.9/site-packages/Xlib/keysymdef/hebrew.py
xorgproto /usr/include/X11/keysymdef.h
```

run

``` sh
less /usr/include/X11/keysymdef.h
```

run

```
grep 'XK_Return' /usr/include/X11/keysymdef.h
```

*/


#define TAGKEYS(KEY,TAG) \
    { MODALT,                                     KEY,                view,               {.ui = 1 << TAG} }, \
    { MODWIN,                                     KEY,                tag,                {.ui = 1 << TAG} }, \
    { MODALT | ControlMask,                       KEY,                toggleview,         {.ui = 1 << TAG} }, \
    { MODALT | ShiftMask,                         KEY,                toggletag,          {.ui = 1 << TAG} },



/* commands */
//static const char *termcmd[]  = {  "st", NULL }; // change this to your term
/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
//static const char *termcmd[]  = {  "sakura", NULL }; // change this to your term



static Key keys[] = {
    /* Modifier                                   Key                 Function            Argument */

    // ## Example:
    //{ MODKEY,                                     XK_Return,          spawn,              {.v = termcmd }},
    //{ MODKEY,                                     XK_Return,          spawn,              SHCMD("~/.local/bin/./st_settings && st")},

    // ## System:
    { MODALT | ShiftMask,                         XK_c,               quit,               {1} },
    { MODALT | ShiftMask,                         XK_x,               quit,               {0} },
    { MODALT | ShiftMask,                         XK_z,               spawn,              SHCMD("shutdown now") },

    // ## Terminal:
    { MODALT,                                     XK_Return,          spawn,              SHCMD("cordwm-app-ctrl run_terminal") },
    { MODALT | ShiftMask,                         XK_a,               spawn,              SHCMD("cordwm-app-ctrl run_terminal") },
    //{ MODALT | ControlMask,                       XK_a,               spawn,              SHCMD("cordwm-focus-ctrl the_sakura") },

    { MODALT | ShiftMask,                         XK_t,               spawn,              SHCMD("cordwm-app-ctrl run_terminal_1") },
    //{ MODALT | ControlMask,                       XK_t,               spawn,              SHCMD("cordwm-focus-ctrl the_xfce4_terminal") },


    // ## Rofi:
    { MODALT | ShiftMask,                         XK_d,               spawn,              SHCMD("cordwm-rofi-ctrl show_drun") },
    { MODALT | ShiftMask,                         XK_w,               spawn,              SHCMD("cordwm-rofi-ctrl show_window") },
    { MODALT | ShiftMask,                         XK_r,               spawn,              SHCMD("cordwm-rofi-ctrl show_run") },

    // ## App / Launch:
    { MODALT | ShiftMask,                         XK_f,               spawn,              SHCMD("cordwm-app-ctrl run_file_manager") },
    { MODALT | ShiftMask,                         XK_g,               spawn,              SHCMD("cordwm-app-ctrl run_file_manager_1") },
    { MODALT | ShiftMask,                         XK_b,               spawn,              SHCMD("cordwm-app-ctrl run_web_browser") },
    { MODALT | ShiftMask,                         XK_e,               spawn,              SHCMD("cordwm-app-ctrl run_text_editor") },


    // ## App / Focus:
    //{ MODALT | ControlMask,                       XK_f,               spawn,              SHCMD("cordwm-focus-ctrl the_pcmanfm_qt") },
    //{ MODALT | ControlMask,                       XK_g,               spawn,              SHCMD("cordwm-focus-ctrl the_thunar") },
    //{ MODALT | ControlMask,                       XK_b,               spawn,              SHCMD("cordwm-focus-ctrl the_firefox") },
    //{ MODALT | ControlMask,                       XK_e,               spawn,              SHCMD("cordwm-focus-ctrl the_atom") },
    //{ MODALT | ControlMask,                       XK_r,               spawn,              SHCMD("cordwm-focus-ctrl the_mousepad") },


    // ## Wallpaper :
    { MODALT,                                     XK_w,               spawn,              SHCMD("cordwm-wallpaper-ctrl shuf") },
    { MODALT | ControlMask,                       XK_w,               spawn,              SHCMD("cordwm-wallpaper-ctrl default") },


    // ## Screenshot :
    { 0,                                          XK_Print,           spawn,              SHCMD("cordwm-screenshot-ctrl now") },
    { MODALT,                                     XK_Print,           spawn,              SHCMD("cordwm-screenshot-ctrl select") },



    // ## Window / Border:
    { MODWIN,                                     XK_comma,           setborderpx,        {.i = -1 } },
    { MODWIN,                                     XK_period,          setborderpx,        {.i = +1 } },
    { MODWIN,                                     XK_slash,           setborderpx,        {.i = default_border } },
    { MODWIN,                                     XK_semicolon,       setborderpx,        {.i = zero_border } },
    //{ MODWIN,                                     XK_space,           setborderpx,        {.i = zero_border } },


    // ## Window / Close:
    { MODWIN,                                     XK_q,               killclient,         {0} },

    // ## Window / Toggle Hide:
    { MODWIN | ControlMask,                       XK_x,               restorewin,         {0} },
    { MODWIN,                                     XK_x,               hidewin,            {0} },
    { MODWIN,                                     XK_c,               restorewin,         {0} },

    // ## Window / Toggle Fullscreen:
    { MODWIN,                                     XK_f,               togglefullscr,      {0} },
    { MODWIN,                                     XK_F11,             togglefullscr,      {0} },

    // ## Window / Toggle Floating :
    { MODWIN,                                     XK_v,               togglefloating,     {0} },

    // ## Window / Focus Stack :
    { MODWIN,                                     XK_a,               focusstack,         {.i = -1 } },
    { MODWIN,                                     XK_s,               focusstack,         {.i = +1 } },
    { MODWIN,                                     XK_h,               focusstack,         {.i = -1 } },
    { MODWIN,                                     XK_l,               focusstack,         {.i = +1 } },

    // ## Window / Move Stack :
    { MODWIN,                                     XK_grave,           movestack,          {.i = -1 } },
    { MODWIN,                                     XK_Tab,             movestack,          {.i = +1 } },
    { MODWIN,                                     XK_k,               movestack,          {.i = -1 } },
    { MODWIN,                                     XK_j,               movestack,          {.i = +1 } },

    // ## Window / Move Stack / Top (Master) :
    { MODWIN,                                     XK_m,               zoom,               {0} },
    { MODWIN,                                     XK_r,               zoom,               {0} },

    // ## Layout / Specific Layout:
    { MODWIN,                                     XK_w,               setlayout,          {.v = &layouts[1]} },
    { MODWIN,                                     XK_e,               setlayout,          {.v = &layouts[0]} },

    // ## Layout / Toggle tabmode
    { MODWIN,                                     XK_i,               tabmode,            { -1 } },

    // ## Layout / Toggle Layout:
    { MODALT,                                     XK_Escape,          setlayout,          {0} },
    { MODALT,                                     XK_i,               setlayout,          {0} },


    // ## Layout / Cycle Layout:
    { MODALT,                                     XK_grave,           cyclelayout,        {.i = -1 } },
    { MODALT,                                     XK_Tab,             cyclelayout,        {.i = +1 } },
    { MODALT,                                     XK_k,               cyclelayout,        {.i = -1 } },
    { MODALT,                                     XK_j,               cyclelayout,        {.i = +1 } },

    // ## Layout / Master Number:
    { MODALT,                                     XK_comma,           incnmaster,         {.i = -1 } },
    { MODALT,                                     XK_period,          incnmaster,         {.i = +1 } },

    // ## Layout / Master Width:
    { MODALT | ControlMask,                       XK_h,               setmfact,           {.f = -0.05} },
    { MODALT | ControlMask,                       XK_l,               setmfact,           {.f = +0.05} },
    //{ MODALT | ControlMask,                       XK_u,               setmfact,           {.f = 0.00} },


    { MODALT | ControlMask,                       XK_k,               setcfact,           {.f = -0.25} },
    { MODALT | ControlMask,                       XK_j,               setcfact,           {.f = +0.25} },
    { MODALT | ControlMask,                       XK_i,               setcfact,           {.f =  0.00} },

    // ## Layout / Toggle Show Bar:
    { MODALT,                                     XK_b,               togglebar,          {.i = +1 } },


    // ## Tag / Cycle Tag: TODO:
    { MODALT,                                     XK_a,               shiftview,           {.i = -1 } },
    { MODALT,                                     XK_s,               shiftview,           {.i = +1 } },
    { MODALT,                                     XK_h,               shiftview,           {.i = -1 } },
    { MODALT,                                     XK_l,               shiftview,           {.i = +1 } },

    // ## Tag / Specific Tag:
    TAGKEYS(                                      XK_1,               0)
    TAGKEYS(                                      XK_2,               1)
    TAGKEYS(                                      XK_3,               2)
    TAGKEYS(                                      XK_4,               3)
    TAGKEYS(                                      XK_5,               4)
    TAGKEYS(                                      XK_6,               5)
    TAGKEYS(                                      XK_7,               6)
    TAGKEYS(                                      XK_8,               7)
    TAGKEYS(                                      XK_9,               8)

    // ## Tag / Toggle Win Show On All Tag :
    { MODWIN,                                     XK_n,               view,               {0} },
    { MODWIN,                                     XK_o,               view,               {.ui = ~0 } },
    { MODWIN,                                     XK_p,               tag,                {.ui = ~0 } },


    // ## TODO:
    { MODWIN,                                     XK_minus,           focusmon,           {.i = -1 } },
    { MODWIN,                                     XK_equal,           focusmon,           {.i = +1 } },
    { MODWIN,                                     XK_bracketleft,     tagmon,             {.i = -1 } },
    { MODWIN,                                     XK_bracketright,    tagmon,             {.i = +1 } },


    // ## VolumeControl:
    { MODALT | ShiftMask,                         XK_v,               spawn,              SHCMD("cordwm-volume-ctrl volume_control") },

    // ## VolumeToggleMute
    { MODALT,                                     XK_m,               spawn,              SHCMD("cordwm-volume-ctrl volume_toggle_mute") },

    // ## VolumeDecrease
    { MODALT | ShiftMask,                         XK_comma,           spawn,              SHCMD("cordwm-volume-ctrl volume_decrease") },

    // ## VolumeIncrease
    { MODALT | ShiftMask,                         XK_period,          spawn,              SHCMD("cordwm-volume-ctrl volume_increase") },

    // ## VolumeDecreaseSlowly
    { MODALT | ControlMask,                       XK_comma,           spawn,              SHCMD("cordwm-volume-ctrl volume_decrease_slowly") },

    // ## VolumeIncreaseSlowly
    { MODALT | ControlMask,                       XK_period,          spawn,              SHCMD("cordwm-volume-ctrl volume_increase_slowly") },

    // ## VolumeToggleMute
    { 0,                                          XF86AudioMute,      spawn,              SHCMD("cordwm-volume-ctrl volume_toggle_mute") },

    // ## VolumeDecrease
    { 0,                                          XF86AudioLowerVolume,      spawn,       SHCMD("cordwm-volume-ctrl volume_decrease") },

    // ## VolumeIncrease
    { 0,                                          XF86AudioRaiseVolume,      spawn,       SHCMD("cordwm-volume-ctrl volume_increase") },


    // ## Gaps:

    { MODALT,                                     XK_Home,            defaultgaps,        {0} },
    { MODALT,                                     XK_End,             togglegaps,         {0} },

    { ControlMask,                                XK_Escape,          defaultgaps,        {0} },
    { MODWIN,                                     XK_Escape,          togglegaps,         {0} },

    // overall gaps
    { MODALT,                                     XK_Page_Up,         incrgaps,           {.i = -1 } },
    { MODALT,                                     XK_Page_Down,       incrgaps,           {.i = +1 } },

    // outer gaps
    { MODALT,                                     XK_minus,           incrogaps,          {.i = -1 } },
    { MODALT,                                     XK_equal,           incrogaps,          {.i = +1 } },

    // inner gaps
    { MODALT,                                     XK_bracketleft,     incrigaps,          {.i = -1 } },
    { MODALT,                                     XK_bracketright,    incrigaps,          {.i = +1 } },

    // h inner gaps
    { MODALT,                                     XK_Up,              incrihgaps,         {.i = +1 } },
    { MODALT,                                     XK_Down,            incrihgaps,         {.i = -1 } },
    { MODALT,                                     XK_Left,            incrivgaps,         {.i = -1 } },
    { MODALT,                                     XK_Right,           incrivgaps,         {.i = +1 } },

    // v outer gaps
    { MODALT | ControlMask,                       XK_Up,              incrohgaps,         {.i = +1 } },
    { MODALT | ControlMask,                       XK_Down,            incrohgaps,         {.i = -1 } },
    { MODALT | ControlMask,                       XK_Left,            incrovgaps,         {.i = -1 } },
    { MODALT | ControlMask,                       XK_Right,           incrovgaps,         {.i = +1 } },

};
