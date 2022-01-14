# Useful Excel Macros for QMK


## Macros

| Key | Value |
| ----------- | ----------- |
| Paste Values | `SEND_STRING(SS_LALT("e")"sv"SS_TAP(X_ENT));`       |
| Paste Formatting | `SEND_STRING(SS_LALT("e")"st"SS_TAP(X_ENT));    `    |
| Resize column to default width | `SEND_STRING(SS_TAP(X_LALT)"how8.43"SS_TAP(X_ENT));` |
| Resize row to default height | `SEND_STRING(SS_TAP(X_LALT)"hoh15"SS_TAP(X_ENT));` |
| Fill Down | `SEND_STRING(SS_TAP(X_LALT)"hfid"SS_TAP(X_ENT));` |
| Hide cell contents via number formatting | `SEND_STRING(SS_TAP(X_LALT)"hfm"SS_TAP(X_TAB)SS_TAP(X_END)SS_TAP(X_TAB)";;;"SS_TAP(X_ENT));` |

## Filters
| Key | Value |
| ----------- | ----------- |
| Filter Drop-down | `SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT));`|
| Filter Non-blank cells | `SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT)"fn"SS_TAP(X_ENT));` |
| Filter Blank cells | `SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_DOWN)SS_UP(X_LSFT)SS_UP(X_LALT)"fe"SS_TAP(X_ENT));` |
| Filter by Current Value | `SEND_STRING(SS_TAP(X_APP)"ev");` |
| Re-apply filter | `SEND_STRING(SS_TAP(X_LALT)"hsy");` |
| Clear filter on current column | `SEND_STRING(SS_TAP(X_APP)"ee");` |
| Clear all filters | `SEND_STRING(SS_TAP(X_LALT)"hsc");` |

## More macros

### Fix formula in column:
If you type a formula in a cell where the number formatting is set to "Text", it will obviously not evaluate the formula. This macro changes the number formatting, reapplies the formula, then copies it to all the other cells in the same column.
```
SEND_STRING(SS_LCTL("~")SS_TAP(X_F2));
SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_ENT)SS_UP(X_LCTL)SS_DELAY(100));
SEND_STRING(SS_LCTL("c v"));
```

### Paste Clipboard contents as a Table in a new sheet:
Creates a new worksheet, pastes the clipboard contents, then creates a table.
Will accept Excel's default suggestion of whether or not your selection includes headers.
> Shift+F11, Ctrl+V, Ctrl+T, Enter
```
SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_F11)SS_UP(X_LSFT));
SEND_STRING(SS_LCTL("vt")SS_TAP(X_ENT));
```

### Copy to clipboard permanently:
Excel's default Copy to Clipboard uses the actively selected range.
This macro copies the contents of the cell to the clipboard instead.
> F2, Ctrl+Shift+Home, Ctrl+C, Esc
```
SEND_STRING(SS_DOWN(X_F2));
SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_UP(X_LCTL));
SEND_STRING(SS_LCTL("c")SS_TAP(X_ESC));
```

### Paste and format current time:
Inserts the date and time into the current cell.
Ctrl+; and Ctrl+: only insert the date and the time, respectively.
> Del, '=now', Ctrl+Enter, F2, F9, Ctrl+Enter
```
SEND_STRING(SS_TAP(X_DEL)"=now()");
SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
SEND_STRING(SS_TAP(X_F2)SS_TAP(X_F9));
SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
```

### Append to current cell contents:
Appends the contents of the clipboard to the end of the current cell
> F2, Alt+Enter, Ctrl+V, Ctrl+E
```
SEND_STRING(SS_TAP(X_F2));
SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_ENT)SS_UP(X_LALT));
SEND_STRING(SS_LCTL("v"));
SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
```

### Remove all rows with selected value in this field:
Filter selected value, select entire column, select visible,
Delete rows, move to top of column, remove filter.
```
SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_F10)SS_UP(X_LSFT)"ev");
SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPC)SS_UP(X_LCTL));
SEND_STRING(SS_LALT(";"));
SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_F10)SS_UP(X_LSFT)"dr");
SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_UP)SS_UP(X_LCTL));
SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_F10)SS_UP(X_LSFT)"ee");
```