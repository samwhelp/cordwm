

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
static const char *termcmd[]  = {  "sakura", NULL }; // change this to your term



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
    { MODALT,                                     XK_Return,          spawn,              SHCMD("sakura") },
    { MODALT | ShiftMask,                         XK_a,               spawn,              SHCMD("sakura") },
    { MODALT | ControlMask,                       XK_a,               spawn,              SHCMD("cordwm-focus-ctrl the_sakura") },

    { MODALT | ShiftMask,                         XK_t,               spawn,              SHCMD("xfce4-terminal") },
    { MODALT | ControlMask,                       XK_t,               spawn,              SHCMD("cordwm-focus-ctrl the_xfce4_terminal") },


    // ## Rofi:
    { MODALT | ShiftMask,                         XK_d,               spawn,              SHCMD("rofi -show drun") },
    { MODALT | ShiftMask,                         XK_w,               spawn,              SHCMD("rofi -show window") },
    { MODALT | ShiftMask,                         XK_r,               spawn,              SHCMD("rofi -show run") },

    // ## App / Launch:
    { MODALT | ShiftMask,                         XK_f,               spawn,              SHCMD("pcmanfm-qt") },
    { MODALT | ShiftMask,                         XK_g,               spawn,              SHCMD("thunar") },
    { MODALT | ShiftMask,                         XK_b,               spawn,              SHCMD("firefox") },
    { MODALT | ShiftMask,                         XK_e,               spawn,              SHCMD("mousepad") },


    // ## App / Focus:
    { MODALT | ControlMask,                       XK_f,               spawn,              SHCMD("cordwm-focus-ctrl the_pcmanfm_qt") },
    { MODALT | ControlMask,                       XK_g,               spawn,              SHCMD("cordwm-focus-ctrl the_thunar") },
    { MODALT | ControlMask,                       XK_b,               spawn,              SHCMD("cordwm-focus-ctrl the_firefox") },
    { MODALT | ControlMask,                       XK_e,               spawn,              SHCMD("cordwm-focus-ctrl the_atom") },
    { MODALT | ControlMask,                       XK_r,               spawn,              SHCMD("cordwm-focus-ctrl the_mousepad") },


    // ## Wallpaper :
    { MODALT,                                     XK_w,               spawn,              SHCMD("cordwm-wallpaper-ctrl shuf") },
    { MODALT | ControlMask,                       XK_w,               spawn,              SHCMD("cordwm-wallpaper-ctrl default") },


    // ## Window / Border:
    { MODWIN,                                     XK_comma,           setborderpx,        {.i = -1 } },
    { MODWIN,                                     XK_period,          setborderpx,        {.i = +1 } },
    { MODWIN,                                     XK_slash,           setborderpx,        {.i = default_border } },
    { MODWIN,                                     XK_space,           setborderpx,        {.i = zero_border } },


    // ## Window / Close:
    { MODWIN,                                     XK_q,               killclient,         {0} },

    // ## Window / Toggle Hide:
    { MODWIN | ShiftMask,                         XK_x,               restorewin,         {0} },
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

    // ## Layout / Cycle Layout:
    { MODALT,                                     XK_grave,           cyclelayout,        {.i = -1 } },
    { MODALT,                                     XK_Tab,             cyclelayout,        {.i = +1 } },
    { MODALT,                                     XK_k,               cyclelayout,        {.i = -1 } },
    { MODALT,                                     XK_j,               cyclelayout,        {.i = +1 } },

    // ## Layout / Toggle Show Bar:
    { MODALT,                                     XK_b,               togglebar,          {.i = +1 } },


    // ## Tag / Cycle Tag: TODO:
    //{ MODALT,                                     XK_a,               cycletag,           {.i = -1 } },
    //{ MODALT,                                     XK_s,               cycletag,           {.i = +1 } },
    //{ MODALT,                                     XK_h,               cycletag,           {.i = -1 } },
    //{ MODALT,                                     XK_l,               cycletag,           {.i = +1 } },

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
    //{ MODALT,                                     XK_0,               focusmon,           {.i = -1 } },
    //{ MODALT,                                     XK_0,               focusmon,           {.i = +1 } },
    //{ MODALT,                                     XK_0,               tagmon,             {.i = -1 } },
    //{ MODALT,                                     XK_0,               tagmon,             {.i = +1 } },


};
