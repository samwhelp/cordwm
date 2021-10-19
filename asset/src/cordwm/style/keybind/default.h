

#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = {  "st", NULL }; // change this to your term
static const char *term_1[]  = {  "sakura", NULL };
static const char *term_2[]  = {  "xfce4-terminal", NULL };
static const char *rofi[] = {"rofi", "-show", "drun", NULL };
static const char *xi[] = {"xbacklight", "-inc", "7", NULL};
static const char *xd[] = {"xbacklight", "-dec", "7", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_c,      spawn,          {.v = rofi } },

    // if you dont use st and this script my rm this and uncomment line below it!
    //{ MODKEY,                       XK_Return, spawn,   SHCMD("~/.local/bin/./st_settings && st")},
    //{ MODKEY,                       XK_Return, spawn,    {.v = termcmd }},
	{ MODALT , XK_Return, spawn, {.v = term_1 }},
	{ MODALT | ShiftMask, XK_a, spawn, {.v = term_1 }},
	{ MODALT | ShiftMask, XK_t, spawn, {.v = term_2 }},

    {MODKEY | ControlMask, XK_u, spawn, SHCMD("maim | xclip -selection clipboard -t image/png")},
    {MODKEY, XK_u, spawn,   SHCMD("maim --select | xclip -selection clipboard -t image/png")},
    {0, XF86MonBrightnessDown, spawn, {.v = xd}},
    {0, XF86MonBrightnessUp, spawn, {.v = xi}},
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY|ControlMask,                       XK_w,      tabmode,        { -1 } },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
    { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },

    // overall gaps
    { MODKEY|ControlMask,           XK_i,      incrgaps,       {.i = +1 } },
    { MODKEY|ControlMask,           XK_d,      incrgaps,       {.i = -1 } },

    // inner gaps
    { MODKEY|ShiftMask,                XK_i,      incrigaps,      {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },

    // outer gaps
    { MODKEY|ControlMask,              XK_o,      incrogaps,      {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },

    { MODKEY|ControlMask,              XK_6,      incrihgaps,     {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
    { MODKEY|ControlMask,              XK_7,      incrivgaps,     {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
    { MODKEY|ControlMask,              XK_8,      incrohgaps,     {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
    { MODKEY|ControlMask,              XK_9,      incrovgaps,     {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },

    { MODKEY|ControlMask,           XK_t,      togglegaps,     {0} },
    { MODKEY|ControlMask|ShiftMask,             XK_d,      defaultgaps,    {0} },

    { MODKEY,                       XK_q,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY|ControlMask,           XK_g,      setlayout,      {.v = &layouts[10]} },
    { MODKEY|ControlMask|ShiftMask, XK_t,      setlayout,      {.v = &layouts[13]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ControlMask,		XK_comma,  cyclelayout,    {.i = -1 } },
    { MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,             XK_minus, 		setborderpx,    {.i = -1 } },
    { MODKEY|ShiftMask,             XK_p, 	        setborderpx,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_w, 	        setborderpx,    {.i = default_border } },

    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    {
        MODKEY|ControlMask,           XK_q,      quit,           {0}
    },
    { MODKEY|ShiftMask,             XK_r,      quit,           {1} },
    { MODKEY,                       XK_e,      hidewin,        {0} },
    { MODKEY|ShiftMask,             XK_e,      restorewin,     {0} },

};
