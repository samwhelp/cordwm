/* See LICENSE file for copyright and license details. */

#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int zero_border = -9999;     // to switch back to zero border after dynamic border resizing via keybinds
static const unsigned int default_border = 0;  // to switch back to default border after dynamic border resizing via keybinds
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails,display systray on the 1st monitor,False: display systray on last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always };
static const int showtab            = showtab_auto;
static const int toptab             = True;
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 5;
static const int vertpadbar         = 11;
static const int vertpadtab         = 33;
static const int horizpadtabi       = 15;
static const int horizpadtabo       = 15;
static const int scalepreview       = 4;
static       int tag_preview        = 0;        /* 1 means enable, 0 is off */

static const char *fonts[]          = { "JetBrainsMono Nerd Font:style:medium:size=10",
                                        "Material Design Icons-Regular:size=10",
                                      };
static const char dmenufont[]       = "monospace:size=10";
static const int colorfultag        = 1;  /* 0 means use SchemeSel for selected non vacant tag */

// theme
//#include "style/theme/onedark.h"
//#include "style/theme//nord.h"
//#include "style/theme/gruvchad.h"
#include "style/theme/main.h"

static const char *colors[][3]      = {
    /*                        fg        bg        border   */
    [SchemeNorm]          = { gray3,    black,    gray2 },
    [SchemeSel]           = { gray4,    blue,     blue  },
    [TabSel]              = { blue,     gray2,    black },
    [TabNorm]             = { gray3,    black,    black },
    [SchemeTag]           = { gray3,    black,    black },
    [SchemeTag1]          = { blue,     black,    black },
    [SchemeTag2]          = { red,      black,    black },
    [SchemeTag3]          = { orange,   black,    black },
    [SchemeTag4]          = { green,    black,    black },
    [SchemeTag5]          = { pink,     black,    black },
    [SchemeLayout]        = { green,    black,    black },
    [SchemeBtnPrev]       = { green,    black,    black },
    [SchemeBtnNext]       = { yellow,   black,    black },
    [SchemeBtnClose]      = { red,      black,    black },
};

/* tagging */
//static char *tags[] = {" ", " ", " ", " ", " "};
//static char *tags[] = {"", "", " ", "", "輸"};
static char *tags[] = {"", "", "", "", "輸"};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5
                                };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */


//#include "style/rule/default.h"
#include "style/rule/main.h"


/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "functions.h"


#include "style/layout/default.h"


/* key definitions */
#define MODKEY Mod4Mask
#define MODWIN Mod4Mask
#define MODALT Mod1Mask

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


//#include "style/keybind/default.h"
#include "style/keybind/main.h"


#include "style/mousebind/default.h"
