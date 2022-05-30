#include QMK_KEYBOARD_H

// Miryoku style layer tap/hold
#define TH_CAPS  LT(_CAPS,  KC_CAPS)
#define TH_GUI   LT(_FN,    KC_LGUI) 
#define TH_ALT   LT(_ALT,   KC_LALT)    //LT(_SYM, KC_TAB)
#define TH_SPC              KC_SPC      //MT(MOD_LSFT, KC_SPC)
#define TH_BSPC  LT(_BSPC,  KC_BSPC)
#define TH_ENT              KC_ENT      //LT(_CAPS,    KC_ENT)  // LT(_NAV, KC_ENT)
#define TH_DEL              KC_DEL      //LT(_GUI, KC_DEL)
#define TH_RSFT  LT(_FN,    KC_RSFT)

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

// #define SL_BOF  C(S(KC_HOME)) // Select from cursor to Begin of File
#define SL_HOME   S(KC_HOME)  // Select from cursor to start of Line
// #define SL_PADN C(S(KC_DN))   // Select from Cursor to end of Paragraph
#define SL_CLDN A(S(KC_DOWN)) // Select from Cursor one line down
// #define SL_WLFT C(S(KC_LEFT)) // Select from Cursor one word left
// #define SL_CLFT   S(KC_LEFT)  // Select from Cursor one character left
// 
// #define SL_CRGT   S(KC_RGHT)
// #define SL_WRGT C(S(KC_RGHT))
#define SL_CLUP A(S(KC_UP))
// #define SL_PAUP C(S(KC_UP))
#define SL_END    S(KC_END)
// #define SL_EOF  C(S(KC_END))

#define GO_HOME C(KC_HOME)
#define GO_END  C(KC_END)

// Swap current line(s)
#define SWAP_UP A(KC_UP)
#define SWAP_DN A(KC_DOWN)

#define XL_HOME C(S(KC_HOME))
#define XL_END  C(S(KC_END))
#define XL_COL    C(KC_SPC)
#define XL_ROW    S(KC_SPC)
#define XL_DRP    A(KC_DOWN)
#define XL_BRK    C(KC_BRK)

// clean up
#define W_TSKMAN C(S(KC_ESC))
#define W_EXPLR    G(KC_E)
#define W_ALTF4    A(KC_F4)

#define OS_GUI   OSM(MOD_LGUI)

#define C_BSPC   C(KC_BSPC)
#define C_DEL    C(KC_DEL)

// VBA
#define VBA_BRK C(KC_BRK)
#define VBA_RUN KC_F5
#define VBA_STP KC_F8
#define VBA_PNT KC_F9
#define VBA_OVR S(KC_F8)
#define VBA_OUT C(S(KC_F8))
#define VBA_CRS C(KC_F8)

enum layer_names {
    _BASE,
    _MIRY,
    _CTL,
    _CAPS,
    _BSPC,
    _ALT,
    _FN,
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
    XL_NEW,
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
    XL_RMCOL,
    XL_NOW,
    XL_APND,
    XL_REMVAL,
    CE_JSFMT,
    ASC_BULL,
    ASC_DASH,
    ASC_BLORF,
    ASC_BJORN,
    ASC_EST,
    ASC_TM,
    ASC_DEG,
    ASC_DIA_A,
    ASC_DIA_E,
    ASC_DIA_I,
    ASC_DIA_O,
    ASC_DIA_U,
    CE_BTICK,
    WE_CMD,
    WE_DIR,
    WE_DIRS,
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
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  DM_PLY1,  KC_UP,    TH_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,             KC_BSPC,            KC_ENT,                       KC_APP,   KC_DEL,   KC_LEFT,  KC_DOWN,  KC_RGHT
        // CTL    WIN       n/a       Spc/Shift           Fun                 Pwr
        //        GUI       ALT       SPACE               BSCPC               ENTER
    ),
    
    [_MIRY] = LAYOUT_directional(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        TH_CAPS,            HR_Q_A,   HR_Q_S,   HR_Q_D,   HR_Q_F,   KC_TRNS,  KC_TRNS,  HR_Q_J,   HR_Q_K,   HR_Q_L,   KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TH_RSFT,
        OSL(_CTL),TH_GUI,   TH_ALT,   TH_SPC,             TH_BSPC,            TH_ENT,                       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        // CTL    WIN       n/a       Spc/Shift           Fun                 Pwr  
        //        GUI       ALT       SPACE               BSCPC               ENTER
    ),
    
    [_CAPS] = LAYOUT_directional(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    C(A(KC_F5)),KC_NO,  KC_NO,    KC_NO,    S(KC_F9), KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    XL_NOW,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,            XL_APND,  KC_NO,    C(KC_SCLN),XL_FIXFX,C(S(KC_GRV)),KC_NO, CE_JSFMT, KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    XL_HCPY,  KC_NO,    KC_NO,    XL_NTBL,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XL_COLF,  KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,                        XL_NULL,  KC_NO,    XL_ROWF,  XL_FILL,  KC_NO
    ),

    [_CTL] = LAYOUT_directional(
        XL_BRK,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XL_FLTAPL,XL_FLTCLR,RGB_TOG,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    C(KC_T),  C(KC_Y),  KC_NO,    KC_NO,    XL_OPEN,  KC_NO,    XL_FLTEV, XL_FLTEE, KC_NO,
        KC_NO,              C(KC_A),  C(KC_S),  KC_NO,    C(KC_F),  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XL_FLTNB, XL_FLTBL,           A(KC_SCLN),
        KC_NO,              C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  KC_NO,    XL_NEW,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    XL_HOME,  XL_COL,   XL_FLT,
        KC_TRNS,  KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,                        XL_ESV,   XL_EST,   XL_ROW,   XL_DRP,   XL_END
    ),

    [_ALT] = LAYOUT_directional( 
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    ASC_BULL, KC_NO,    ASC_BJORN,ASC_DASH, ASC_EST,  ASC_DEG,  KC_NLCK,
        KC_NO,              KC_NO,    KC_NO,    ASC_DIA_E,KC_NO,    ASC_TM,   KC_NO,    ASC_DIA_U,ASC_DIA_I,ASC_DIA_O,KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              ASC_DIA_A,KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    SWAP_UP,  SWAP_DN,  KC_NO,    GO_HOME,  KC_PGUP,  GO_END,
        KC_NO,    KC_NO,    KC_TRNS,  SL_HOME,            KC_NO,              SL_END,                       SL_CLUP,  SL_CLDN,  KC_HOME,  KC_PGDN,  KC_END
    ), 

    [_BSPC] = LAYOUT_directional(
        RESET,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    CE_BTICK, DM_REC1,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    XL_RMROW, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    XL_RMCOL, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    C_BSPC,   KC_NO,    C_DEL,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_TRNS,            KC_NO,                        C(KC_Z),  C(KC_Y),  KC_BSPC,  KC_NO,    KC_DEL
    ),

    [_FN] = LAYOUT_directional( 
        KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NO,    KC_PSCR,
        KC_NO,              WE_CMD,   W_ALTF4,  W_EXPLR,  KC_NO,    W_TSKMAN, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    VBA_OVR,  VBA_OUT,  KC_NO,
        KC_NO,              KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    G(KC_L),  WE_DIR,   WE_DIRS,            KC_NO,
        KC_NO,              VBA_BRK,  VBA_RUN,  VBA_STP,  VBA_PNT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    VBA_CRS,  W_UP,     KC_NO,
        OS_GUI,   KC_TRNS,  KC_APP,   MM_LEFT,            KC_NO,              MM_RGHT,                      ALTTAB_L, ALTTAB_R, W_LEFT,   W_DOWN,   W_RGHT
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
        if(!layer_state_is(_FN)) {
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
        layer_on(_MIRY);
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WE_CMD:
            // In Windows Explorer, opens a command prompt in the current folder
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("l")"cmd"SS_TAP(X_ENT));
            }
            break;
        case WE_DIR:
            // In command prompt, copies the directory listing to the clipboard
            if (record->event.pressed) {
                SEND_STRING("dir /b | clip"SS_TAP(X_ENT));
            }
            break;
        case WE_DIRS:
            // In command prompt, copies the directory listing to the clipboard, recursively, files only
            if (record->event.pressed) {
                SEND_STRING("dir /b/s/a-d | clip"SS_TAP(X_ENT));
            }
            break;
        case CE_BTICK:
            // Dancing backticks
            if (record->event.pressed) {
                SEND_STRING("``"SS_TAP(X_LEFT));
            }
            break;
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
            // Ctrl+A Ctrl+V Ctrl+Alt+M (JSFormat in Notepad++)
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("av")SS_DOWN(X_LCTL)SS_DOWN(X_LALT)"m"SS_UP(X_LCTL)SS_UP(X_LALT));
            }
            break;
        case XL_NEW:
            // Alt+F N L (Excel File New)
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("f")"nl");
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
            // Filter non blank values
            // Works with general AND date columns
            if (record->event.pressed) {
                //SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT));
                //SEND_STRING("fn"SS_TAP(X_ENT));
                SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_DOWN)))"ff"SS_DELAY(100));
                SEND_STRING(SS_LSFT(SS_TAP(X_TAB))SS_TAP(X_DOWN)SS_TAP(X_HOME)SS_DELAY(100));
                SEND_STRING(SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100));
                SEND_STRING(SS_TAP(X_ENT)SS_DELAY(100)SS_TAP(X_ENT)SS_DELAY(100));
            }
            break;
        case XL_FLTBL:
            // Filter blank values only
            // Works with general AND date columns
            if (record->event.pressed) {
                //SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT));
                //SEND_STRING("fe"SS_TAP(X_ENT));                
                SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_DOWN)))"ff"SS_DELAY(100));
                SEND_STRING(SS_LSFT(SS_TAP(X_TAB))SS_TAP(X_DOWN)SS_TAP(X_HOME)SS_DELAY(100));
                SEND_STRING(SS_TAP(X_DOWN)SS_DELAY(100));
                SEND_STRING(SS_TAP(X_ENT)SS_DELAY(100)SS_TAP(X_ENT)SS_DELAY(100));
            }
            break;
        case XL_FLTEV:
            // Filter selected value
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP)"ev");
            }
            break;
        case XL_FLTEE:
            // Clear filter on column
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP)"ee");
            }
            break;
        case XL_FLTCLR:
            // Clear all filters
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hsc");
            }
            break;
        case XL_FLTAPL:
            // Filter re-apply
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hsy");
            }
            break;
        case XL_COLF:
            // Reset column width to default
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"how8.43"SS_TAP(X_ENT));
            }
            break;
        case XL_ROWF:
            // Reset row height to default
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hoh15"SS_TAP(X_ENT));
            }
            break;
        case XL_RMROW:
            // Delete row
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP)"dr"SS_TAP(X_ENT));
            }
            break;
        case XL_RMCOL:
            // Delete col
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LALT)"hdc"SS_TAP(X_ENT));
            }
            break;
        case XL_FILL:
            // Fill values into selection
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
            // New sheet, paste, new table
            if (record->event.pressed) {
                //SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_F11)SS_UP(X_LSFT));
                SEND_STRING(SS_LCTL("c"));
                SEND_STRING(SS_TAP(X_LALT)"his"SS_TAP(X_ENT)SS_DELAY(100));
                SEND_STRING(SS_LCTL("v")SS_TAP(X_ESC)SS_DELAY(100));
                SEND_STRING(SS_LCTL("t")SS_TAP(X_ENT)SS_DELAY(100));
                SEND_STRING(SS_TAP(X_LALT)"jts"SS_DELAY(100)SS_TAP(X_RGHT)SS_TAP(X_RGHT)SS_TAP(X_RGHT)SS_TAP(X_RGHT)SS_DELAY(100)SS_TAP(X_APP)"c");
                SEND_STRING(SS_TAP(X_LALT)"how8.43"SS_TAP(X_ENT));
                SEND_STRING(SS_TAP(X_LALT)"hoh15"SS_TAP(X_ENT));
            }
            break;
        case XL_RFSH:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_TAP(X_F5)SS_UP(X_LALT)SS_UP(X_LCTL));
            }
            break;
        case XL_HCPY:
            // "Hard" copy
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_F2));
                SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_UP(X_LCTL));
                SEND_STRING(SS_LCTL("c")SS_TAP(X_ESC));
            }
            break;
        case XL_NOW:
            // Paste current time as value not formula
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_DEL)"=now()");
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
                SEND_STRING(SS_TAP(X_F2)SS_TAP(X_F9));
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
            }
            break;
        case XL_APND:
            // Append into currently selected cell
            if (record->event.pressed) {
                // Append clipboard to end of current cell
                // F2, Alt+Enter, Ctrl+V, Ctrl+Enter
                SEND_STRING(SS_TAP(X_F2));
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
        case ASC_BULL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P9)SS_UP(X_LALT));
            }
            break;
        case ASC_DASH:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P1)SS_UP(X_LALT));
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
        // ASCII Diaeresis
        case ASC_DIA_A:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P2) SS_TAP(X_P8)SS_UP(X_LALT));
            }
            break;
        case ASC_DIA_E:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P3) SS_TAP(X_P5)SS_UP(X_LALT));
            }
            break;
        case ASC_DIA_I:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P3) SS_TAP(X_P9)SS_UP(X_LALT));
            }
            break;
        case ASC_DIA_O:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P4) SS_TAP(X_P6)SS_UP(X_LALT));
            }
            break;
        case ASC_DIA_U:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P5) SS_TAP(X_P2)SS_UP(X_LALT));
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
        case _MIRY:
            rgblight_setrgb(RGB_WHITE);
            break;
        case _CTL:
            rgblight_setrgb(RGB_TEAL);
            break;
        case _CAPS:
            rgblight_setrgb(RGB_SPRINGGREEN);
            break;
        case _BSPC:
            rgblight_setrgb(RGB_ORANGE); //_CORAL
            break;
         case _ALT:
            rgblight_setrgb(RGB_ORANGE);
            break;
        case _FN:
            rgblight_setrgb(RGB_GREEN);
            break;
        default: 
            rgblight_setrgb(RGB_GOLD);
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