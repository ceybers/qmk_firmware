#include QMK_KEYBOARD_H

// Miryoku style layer tap/hold
#define TH_CAPS  LT(_CAPS,    KC_CAPS)
// OSL(_CTL)
#define TH_GUI   KC_LGUI                 //LT(_GUI,     KC_LGUI) //LT(_ZFN, KC_ESC)
#define TH_ALT   LT(_ALT,     KC_LALT)  //LT(_SYM, KC_TAB)
#define TH_LSFT  MT(MOD_LSFT, KC_SPC)
#define TH_BSPC  LT(_BSPC,    KC_BSPC)
#define TH_ENT   LT(_CAPS,    KC_ENT)  // LT(_NAV, KC_ENT)
#define TH_DEL                KC_DEL   //LT(_GUI, KC_DEL)
#define TH_RSFT  LT(_SFT,     KC_NO)

// Qwerty Homerow Mods
#define HR_Q_A  LGUI_T(KC_A)
#define HR_Q_S  LALT_T(KC_S)
#define HR_Q_D  LSFT_T(KC_D)
#define HR_Q_F  LCTL_T(KC_F)

#define HR_Q_J  RCTL_T(KC_J)
#define HR_Q_K  RSFT_T(KC_K)
#define HR_Q_L  LALT_T(KC_L)
#define HR_Q_0  RGUI_T(KC_SCLN)

// Extend selection
#define SL_ALL    C(KC_A)     // Select all

#define SL_BOF  C(S(KC_HOME)) // Select from cursor to Begin of File
#define SL_HOME   S(KC_HOME)  // Select from cursor to start of Line
#define SL_PADN C(S(KC_DN))   // Select from Cursor to end of Paragraph
#define SL_CLDN A(S(KC_DOWN)) // Select from Cursor one line down
#define SL_WLFT C(S(KC_LEFT)) // Select from Cursor one word left
#define SL_CLFT   S(KC_LEFT)  // Select from Cursor one character left
//
#define SL_CRGT   S(KC_RGHT)
#define SL_WRGT C(S(KC_RGHT))
#define SL_CLUP A(S(KC_UP))
#define SL_PAUP C(S(KC_UP))
#define SL_END    S(KC_END)
#define SL_EOF  C(S(KC_END))
//
#define GO_HOME C(KC_HOME)
#define GO_END  C(KC_END)

// Swap current line(s)
#define SWAP_UP C(S(KC_UP))
#define SWAP_DN C(S(KC_DOWN))

#define XL_HOME C(S(KC_HOME))
#define XL_END C(S(KC_END))
#define XL_COL C(KC_SPC)
#define XL_ROW S(KC_SPC)
#define XL_DRP A(KC_DOWN)

// Teams
#define TM_ACPT C(S(KC_S))
#define TM_HANG C(S(KC_B))
#define TM_MUTE C(S(KC_M))
#define TM_SCRN C(S(KC_E))
#define TM_TEAM G(KC_9)

// clean up
#define W_TSKMAN C(S(KC_ESC))
#define W_EXPLR G(KC_E)
#define W_ALTF4 A(KC_F4)

enum layer_names {
    _BASE,
    _MIRY,
    _CTL,
    _CAPS,
    _BSPC,
    _ALT,
    _SFT,
};

enum custom_keycodes {
    CE_SU1234 = SAFE_RANGE,
    W_LEFT,
    W_DOWN,
    W_UP,
    W_RGHT,
    MM_LEFT,
    MM_RGHT,
    ALTTAB_L,
    ALTTAB_R,
    XL_ESV,
    XL_EST,
    XL_FLT,
    XL_OPEN,
    XL_ROWF,
    XL_COLF,
    XL_FILL,
    XL_NULL,
    XL_FIXFX,
    XL_NTBL,
    XL_FLTNB,
    XL_FLTBL,
    XL_FLTEV,
    XL_FLTEE,
    XL_FLTCLR,
    XL_FLTAPL,
    XL_RFSH,
    XL_HCPY,
    XL_RMROW,
    XL_NOW,
    XL_APND,
    XL_REMVAL,
    ZZZ,
    CE_JSFMT,
    ASC_DASH,
    ASC_BLORF,
    ASC_BJORN,
    ASC_EST,
    ASC_TM,
    ASC_DEG
};

// Define variables for Super Alt+Tab
bool is_alt_tab_active = false; 
uint16_t alt_tab_timer = 0;
uint16_t ALT_TAB_TIMER_MAX = 1000;

bool is_GUI_active = false;
uint16_t win_timer = 0;
uint16_t WIN_TIMER_MAX = 1000;

bool is_dynmac_busy = false;
bool is_dynmac_active = false;
uint16_t dynmac_timer = 0;
uint16_t DYNMAC_TIMER_MAX = 3000;

uint16_t init_rgb_timer = 0;
uint16_t INIT_RGB_MAX = 3000;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    [_blank] = LAYOUT_directional(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_blank] = LAYOUT_directional(
        KC_NO,              KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_RCTL,  KC_RSFT,  KC_LALT,  KC_RGUI,  KC_NO,              KC_NO,

        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
    ), 
    */

    [_BASE] = LAYOUT_directional(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_GRV,   TG(_MIRY),
        KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    KC_UP,    TH_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,             KC_BSPC,            KC_ENT,                       KC_APP,   KC_DEL,   KC_LEFT,  KC_DOWN,  KC_RGHT
        // CTL    WIN       n/a       Spc/Shift           Fun                 Pwr
        //        GUI       ALT       SPACE               BSCPC               ENTER
    ),

    [_MIRY] = LAYOUT_directional(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_REC1,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        TH_CAPS,            HR_Q_A,   HR_Q_S,   HR_Q_D,   HR_Q_F,   KC_TRNS,  KC_TRNS,  HR_Q_J,   HR_Q_K,   HR_Q_L,   KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_PLY1,  KC_TRNS,  TH_RSFT,
        OSL(_CTL),TH_GUI,   TH_ALT,   TH_LSFT,            TH_BSPC,            TH_ENT,                       KC_BSPC,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        // CTL    WIN       n/a       Spc/Shift           Fun                 Pwr  
        //        GUI       ALT       SPACE               BSCPC               ENTER
    ),
    
    [_CAPS] = LAYOUT_directional(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    C(A(KC_F5)),KC_NO,  KC_NO,    KC_NO,    S(KC_F9), KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    XL_REMVAL,XL_NOW,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,            XL_APND,  KC_NO,    C(KC_SCLN),XL_FIXFX,C(S(KC_GRV)),KC_NO, CE_JSFMT, KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    XL_HCPY,  KC_NO,    KC_NO,    XL_NTBL,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XL_COLF,  KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,              XL_RMROW,           KC_NO,                        XL_RMROW, XL_NULL,  XL_ROWF,  XL_FILL,  KC_NO
    ),

    [_CTL] = LAYOUT_directional(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    ASC_BJORN,ASC_DASH, ASC_EST,  ASC_TM,   RGB_TOG,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    C(KC_T),  C(KC_Y),  KC_NO,    KC_NO,    XL_OPEN,  KC_NO,    ASC_BLORF,ASC_DEG,  KC_NO,
        KC_NO,              C(KC_A),  C(KC_S),  KC_NO,    C(KC_F),  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XL_FLTAPL,XL_FLTCLR,          A(KC_SCLN),
        KC_NO,              C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  XL_ESV,   XL_EST,   KC_NO,    KC_NO,    XL_FLTEV, XL_FLTEE, XL_HOME,  XL_COL,   XL_FLT,
        KC_TRNS,    KC_NO,  KC_NO,    KC_NO,              KC_NO,              KC_NO,                        XL_FLTNB, XL_FLTBL, XL_ROW,   XL_DRP,   XL_END
    ),

    [_ALT] = LAYOUT_directional(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    SWAP_DN,  SWAP_DN,  GO_HOME,  KC_PGUP,  GO_END,
        KC_NO,    KC_NO,    KC_TRNS,  KC_NO,              KC_NO,              KC_NO,                        SL_CLDN,  SL_CLUP,  KC_HOME,  KC_PGDN,  KC_END
    ), 

    [_BSPC] = LAYOUT_directional(
        RESET,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    TG(_MIRY),
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    C(KC_Z),  KC_NO,    C(KC_Y),
        KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_TRNS,            KC_NO,                        KC_NO,    KC_NO,    KC_BSPC,  KC_NO,    KC_DEL
    ),

    [_SFT] = LAYOUT_directional(
        KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NO,    KC_PSCR,
        KC_NO,              KC_NO,    W_ALTF4,  W_EXPLR,  KC_NO,    W_TSKMAN, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              ALTTAB_L, KC_NO,    ALTTAB_R, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    G(KC_L),  KC_NO,    KC_NO,              KC_NO,
        KC_NO,              MM_LEFT,  KC_NO,    MM_RGHT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
    ), 
};

void win_key_macro(bool pressed, uint16_t keycode) {
    if (pressed) {
        if (!is_GUI_active) { 
            is_GUI_active = true; 
            register_code(KC_LGUI); 
        } 
        win_timer = timer_read();
        register_code(keycode);
    } else { 
        unregister_code(keycode); 
    }
}

void activate_alt_tab_timer(void) {
    if (!is_alt_tab_active) { 
        is_alt_tab_active = true; 
        register_code(KC_LALT); 
    } 
    alt_tab_timer = timer_read();
}

void alt_tab_macro(bool pressed, bool direction) {
    if (pressed) {
        activate_alt_tab_timer();
        if (!direction) register_code(KC_LSFT);
        register_code(KC_TAB);
    } else {
        unregister_code(KC_TAB);
        if (!direction) unregister_code(KC_LSFT);
    }
}

void check_alt_tab_timer(void) {
    if (is_alt_tab_active) { // Super Alt+Tab
        if(!layer_state_is(_SFT)) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
            return;
        }
        if (timer_elapsed(alt_tab_timer) > ALT_TAB_TIMER_MAX) { 
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

void check_GUI_timer(void) {
    if (is_GUI_active) { // Timeout on switching windows between multiple monitors
        if (timer_elapsed(win_timer) > WIN_TIMER_MAX) {
            unregister_code(KC_LGUI);
            is_GUI_active = false;
        }
    }
}

void check_dynmac_timer(void) {
    if (is_dynmac_active) { // Timeout on switching windows between multiple monitors
        if (timer_elapsed(dynmac_timer) > DYNMAC_TIMER_MAX) {
            rgblight_setrgb(RGB_WHITE);
            is_dynmac_active = false;
        }
    }
}

void dynamic_macro_record_start_user(void) {
    is_dynmac_busy = true;
    rgblight_setrgb(RGB_RED);
};

void dynamic_macro_record_end_user(int8_t direction) {
    is_dynmac_busy = false;
    rgblight_setrgb(RGB_GREEN);
    is_dynmac_active = true;
    dynmac_timer = timer_read();
}

void delay_initial_rgb_timer(void) {
    init_rgb_timer = timer_read();
}

void run_initial_rgb_timer(void) {
    static bool runonce = true;
    if (runonce && timer_elapsed(init_rgb_timer) > INIT_RGB_MAX) {
        runonce = false;
        rgblight_setrgb(RGB_GOLD);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case XL_ESV:
            // Alt+E, S, V (Excel Paste Values)
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("e")"sv"SS_TAP(X_ENT));
            }
            break;
        case XL_EST:
            // Alt+E, S, T (Excel Paste Formats)
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("e")"st"SS_TAP(X_ENT));
            }
            break;
        case CE_JSFMT:
            // Ctrl+A Ctrl+V Ctrl+Alt+M (JSFormat)
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("av")SS_DOWN(X_LCTL)SS_DOWN(X_LALT)"m"SS_UP(X_LCTL)SS_UP(X_LALT));
            }
            break;
        case XL_OPEN:
            // Alt+F O (Excel File Open)
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("f")"o");
            }
            break;
        case XL_FLT:
            // Alt+Shift+Down (Excel Filters)
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT));
            }
            break;
        case XL_FLTNB:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT));
                SEND_STRING("fn"SS_TAP(X_ENT));
            }
            break;
        case XL_FLTBL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT));
                SEND_STRING("fe"SS_TAP(X_ENT));
            }
            break;
        case XL_FLTEV:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP)"ev");
            }
            break;
        case XL_FLTEE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP)"ee");
            }
            break;
        case XL_FLTCLR:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hsc");
            }
            break;
        case XL_FLTAPL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hsy");
            }
            break;
        case XL_COLF:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"how8.43"SS_TAP(X_ENT));
            }
            break;
        case XL_ROWF:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hoh15"SS_TAP(X_ENT));
            }
            break;
        case XL_RMROW:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP)"dr");
            }
            break;
        case XL_FILL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hfid"SS_TAP(X_ENT));
            }
            break;
        case XL_NULL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hfm"SS_TAP(X_TAB)SS_TAP(X_END)SS_TAP(X_TAB)";;;"SS_TAP(X_ENT));
            }
            break;
        case XL_FIXFX:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("~")SS_TAP(X_F2));
                SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_ENT)SS_UP(X_LCTL)SS_DELAY(100));
                // Always include short delay between back to back SS_UP()SS_DOWN() of same mod
                //SEND_STRING(SS_DOWN(X_LCTL)SS_DELAY(500)"c"SS_DELAY(500)" "SS_DELAY(500)"v"SS_DELAY(500)SS_UP(X_LCTL));
                SEND_STRING(SS_LCTL("c v"));
            }
            break;
        case XL_NTBL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_F11)SS_UP(X_LSFT));
                SEND_STRING(SS_LCTL("vt")SS_TAP(X_ENT));
            }
            break;
        case XL_RFSH:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_TAP(X_F5)SS_UP(X_LALT)SS_UP(X_LCTL));
            }
            break;
        case XL_HCPY:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_F2));
                SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_UP(X_LCTL));
                SEND_STRING(SS_LCTL("c")SS_TAP(X_ESC));
            }
            break;
        case XL_NOW:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_DEL)"=now()");
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
                SEND_STRING(SS_TAP(X_F2)SS_TAP(X_F9));
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
            }
            break;
        case XL_APND:
            if (record->event.pressed) {
                // Append clipboard to end of current cell
                // F2, Alt+Enter, Ctrl+V, Ctrl+Enter
                SEND_STRING(SS_TAP(X_F2)"=now()");
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_ENT)SS_UP(X_LALT));
                SEND_STRING(SS_LCTL("v"));
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
            }
            break;
        case XL_REMVAL:
            if (record->event.pressed) {
                // Remove all rows with selected value in this field
                //   Filter selected value, select entire column, select visible,
                //   Delete rows, move to top of column, remove filter.
                SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_F10)SS_UP(X_LSFT)"ev");
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPC)SS_UP(X_LCTL));
                SEND_STRING(SS_LALT(";"));
                SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_F10)SS_UP(X_LSFT)"dr");
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_UP)SS_UP(X_LCTL));
                SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_F10)SS_UP(X_LSFT)"ee");
            }
            break;
        // ASCII Stuff
        case ASC_DASH:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P1)SS_UP(X_LALT));
            }
            break;
        case ASC_BLORF:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P4) SS_TAP(X_P6)SS_UP(X_LALT));
            }
            break;
        case ASC_BJORN:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P4) SS_TAP(X_P8)SS_UP(X_LALT));
            }
            break;
        case ASC_EST:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P7)SS_UP(X_LALT));
            }
            break;
        case ASC_TM:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P3)SS_UP(X_LALT));
            }
            break;
        case ASC_DEG:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P6)SS_UP(X_LALT));
            }
            break;

        // Window management
        case W_LEFT:
            win_key_macro(record->event.pressed, KC_LEFT);
            break;
        case W_DOWN:
            win_key_macro(record->event.pressed, KC_DOWN);
            break;
        case W_UP:
            win_key_macro(record->event.pressed, KC_UP);
            break;
        case W_RGHT:
            win_key_macro(record->event.pressed, KC_RGHT);
            break;
        case MM_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)SS_UP(X_LGUI));
            }
            break;
        case MM_RGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_RGHT)SS_UP(X_LSFT)SS_UP(X_LGUI));
            }
            break;
        

        //  Super Alt Tab
        case ALTTAB_L:
           alt_tab_macro(record->event.pressed, false);
            break;
        case ALTTAB_R:
            alt_tab_macro(record->event.pressed, true);
            break;
    }

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 200;
            break;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 200;
            break;
        case LALT_T(KC_S):
            return TAPPING_TERM + 100;
            break;
        case LALT_T(KC_L):
            return TAPPING_TERM + 100;
            break;
        default:
            return TAPPING_TERM;
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_dynmac_busy) return state;

    rgblight_mode_noeeprom(1);
    switch (get_highest_layer(state)) {
        case _BSPC:
            rgblight_setrgb(RGB_ORANGE); //_CORAL
            break;
        case _CTL:
            rgblight_setrgb(RGB_TEAL);
            break;
        case _CAPS:
            rgblight_setrgb(RGB_SPRINGGREEN);
            break;
/*         case _GUI:
            rgblight_setrgb(RGB_GOLDENROD);
            break; */
        case _SFT:
            //rgblight_setrgb(RGB_GOLDENROD);
            rgblight_setrgb(RGB_GREEN);
            break;
/*         case _TEAM:
            rgblight_setrgb(RGB_AZURE);
            rgblight_mode_noeeprom(21);
            break; */
        case _MIRY:
            rgblight_setrgb(RGB_WHITE);
            break;
        default: 
            rgblight_setrgb(RGB_AZURE);
            break;
    }
    return state;
}

void matrix_init_user(void) {
    delay_initial_rgb_timer();
}

void matrix_scan_user(void) { 
    check_alt_tab_timer();
    check_GUI_timer();
    check_dynmac_timer();
    run_initial_rgb_timer();
}
