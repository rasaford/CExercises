/** \file
 * \brief User API
 * IUP - A Portable User Interface Toolkit
 * Tecgraf: Computer Graphics Technology Group, PUC-Rio, Brazil
 * http://www.tecgraf.puc-rio.br/iup  mailto:iup@tecgraf.puc-rio.br
 *
 * See Copyright Notice at the end of this file
 */
 
#ifndef __IUP_H 
#define __IUP_H

/** \file
 * \brief Keyboard Keys definitions.
 *
 * See Copyright Notice in "iup.h"
 */
 
#ifndef __IUPKEY_H 
#define __IUPKEY_H

/* from 32 to 126, all character sets are equal,
   the key code is the same as the ASCii character code. */

#define K_SP          ' '   /* 32 (0x20) */
#define K_exclam      '!'   /* 33 */
#define K_quotedbl    '\"'  /* 34 */
#define K_numbersign  '#'   /* 35 */
#define K_dollar      '$'   /* 36 */
#define K_percent     '%'   /* 37 */
#define K_ampersand   '&'   /* 38 */
#define K_apostrophe  '\''  /* 39 */
#define K_parentleft  '('   /* 40 */
#define K_parentright ')'   /* 41 */
#define K_asterisk    '*'   /* 42 */
#define K_plus        '+'   /* 43 */
#define K_comma       ','   /* 44 */
#define K_minus       '-'   /* 45 */
#define K_period      '.'   /* 46 */
#define K_slash       '/'   /* 47 */
#define K_0           '0'   /* 48 (0x30) */
#define K_1           '1'   /* 49 */
#define K_2           '2'   /* 50 */
#define K_3           '3'   /* 51 */
#define K_4           '4'   /* 52 */
#define K_5           '5'   /* 53 */
#define K_6           '6'   /* 54 */
#define K_7           '7'   /* 55 */
#define K_8           '8'   /* 56 */
#define K_9           '9'   /* 57 */
#define K_colon       ':'   /* 58 */
#define K_semicolon   ';'   /* 59 */
#define K_less        '<'   /* 60 */
#define K_equal       '='   /* 61 */
#define K_greater     '>'   /* 62 */
#define K_question    '?'   /* 63 */
#define K_at          '@'   /* 64 */
#define K_A           'A'   /* 65 (0x41) */
#define K_B           'B'   /* 66 */
#define K_C           'C'   /* 67 */
#define K_D           'D'   /* 68 */
#define K_E           'E'   /* 69 */
#define K_F           'F'   /* 70 */
#define K_G           'G'   /* 71 */
#define K_H           'H'   /* 72 */
#define K_I           'I'   /* 73 */
#define K_J           'J'   /* 74 */
#define K_K           'K'   /* 75 */
#define K_L           'L'   /* 76 */
#define K_M           'M'   /* 77 */
#define K_N           'N'   /* 78 */
#define K_O           'O'   /* 79 */
#define K_P           'P'   /* 80 */
#define K_Q           'Q'   /* 81 */
#define K_R           'R'   /* 82 */
#define K_S           'S'   /* 83 */
#define K_T           'T'   /* 84 */
#define K_U           'U'   /* 85 */
#define K_V           'V'   /* 86 */
#define K_W           'W'   /* 87 */
#define K_X           'X'   /* 88 */
#define K_Y           'Y'   /* 89 */
#define K_Z           'Z'   /* 90 */
#define K_bracketleft '['   /* 91 */
#define K_backslash   '\\'  /* 92 */
#define K_bracketright ']'  /* 93 */
#define K_circum      '^'   /* 94 */
#define K_underscore  '_'   /* 95 */
#define K_grave       '`'   /* 96 */
#define K_a           'a'   /* 97 (0x61) */
#define K_b           'b'   /* 98 */
#define K_c           'c'   /* 99 */
#define K_d           'd'   /* 100 */
#define K_e           'e'   /* 101 */
#define K_f           'f'   /* 102 */
#define K_g           'g'   /* 103 */
#define K_h           'h'   /* 104 */
#define K_i           'i'   /* 105 */
#define K_j           'j'   /* 106 */
#define K_k           'k'   /* 107 */
#define K_l           'l'   /* 108 */
#define K_m           'm'   /* 109 */
#define K_n           'n'   /* 110 */
#define K_o           'o'   /* 111 */
#define K_p           'p'   /* 112 */
#define K_q           'q'   /* 113 */
#define K_r           'r'   /* 114 */
#define K_s           's'   /* 115 */
#define K_t           't'   /* 116 */
#define K_u           'u'   /* 117 */
#define K_v           'v'   /* 118 */
#define K_w           'w'   /* 119 */
#define K_x           'x'   /* 120 */
#define K_y           'y'   /* 121 */
#define K_z           'z'   /* 122 */
#define K_braceleft   '{'   /* 123 */
#define K_bar         '|'   /* 124 */
#define K_braceright  '}'   /* 125 */
#define K_tilde       '~'   /* 126 (0x7E) */

/* Printable ASCii keys */

#define iup_isprint(_c) ((_c) > 31 && (_c) < 127)

/* also define the escape sequences that have keys associated */

#define K_BS     '\b'       /* 8 */
#define K_TAB    '\t'       /* 9 */
#define K_LF     '\n'       /* 10 (0x0A) not a real key, is a combination of CR with a modifier, just to document */
#define K_CR     '\r'       /* 13 (0x0D) */

/* backward compatible definitions */

#define  K_quoteleft   K_grave
#define  K_quoteright  K_apostrophe
#define  isxkey        iup_isXkey

/* IUP Extended Key Codes, range start at 128      */

#define iup_isXkey(_c)      ((_c) >= 128)

/* These use the same definition as X11 and GDK.
   This also means that any X11 or GDK definition can also be used. */

#define K_PAUSE    0xFF13
#define K_ESC      0xFF1B
#define K_HOME     0xFF50           
#define K_LEFT     0xFF51
#define K_UP       0xFF52
#define K_RIGHT    0xFF53
#define K_DOWN     0xFF54 
#define K_PGUP     0xFF55
#define K_PGDN     0xFF56
#define K_END      0xFF57
#define K_MIDDLE   0xFF0B
#define K_Print    0xFF61 
#define K_INS      0xFF63
#define K_Menu     0xFF67
#define K_DEL      0xFFFF
#define K_F1       0xFFBE
#define K_F2       0xFFBF
#define K_F3       0xFFC0
#define K_F4       0xFFC1
#define K_F5       0xFFC2
#define K_F6       0xFFC3
#define K_F7       0xFFC4
#define K_F8       0xFFC5
#define K_F9       0xFFC6
#define K_F10      0xFFC7
#define K_F11      0xFFC8
#define K_F12      0xFFC9

/* no Shift/Ctrl/Alt */
#define K_LSHIFT   0xFFE1
#define K_RSHIFT   0xFFE2
#define K_LCTRL    0xFFE3
#define K_RCTRL    0xFFE4
#define K_LALT     0xFFE9
#define K_RALT     0xFFEA

#define K_NUM      0xFF7F
#define K_SCROLL   0xFF14
#define K_CAPS     0xFFE5

/* Also, these are the same as the Latin-1 definition */

#define K_ccedilla  0x00E7
#define K_Ccedilla  0x00C7
#define K_acute     0x00B4  /* no Shift/Ctrl/Alt */
#define K_diaeresis 0x00A8

/******************************************************/
/* Modifiers use last 4 bits. Since IUP 3.9           */
/* These modifiers definitions are specific to IUP    */
/******************************************************/

#define iup_isShiftXkey(_c) ((_c) & 0x10000000)
#define iup_isCtrlXkey(_c)  ((_c) & 0x20000000)
#define iup_isAltXkey(_c)   ((_c) & 0x40000000)
#define iup_isSysXkey(_c)   ((_c) & 0x80000000)

#define iup_XkeyBase(_c)  ((_c) & 0x0FFFFFFF)
#define iup_XkeyShift(_c) ((_c) | 0x10000000)   /* Shift  */
#define iup_XkeyCtrl(_c)  ((_c) | 0x20000000)   /* Ctrl   */
#define iup_XkeyAlt(_c)   ((_c) | 0x40000000)   /* Alt    */
#define iup_XkeySys(_c)   ((_c) | 0x80000000)   /* Sys (Win or Apple) */

/* These definitions are here for backward compatibility 
   and to simplify some key combination usage.
   But since IUP 3.9, modifiers can be combined with any key
   and they can be mixed together. */

#define K_sHOME    iup_XkeyShift(K_HOME   )
#define K_sUP      iup_XkeyShift(K_UP     )
#define K_sPGUP    iup_XkeyShift(K_PGUP   )
#define K_sLEFT    iup_XkeyShift(K_LEFT   )
#define K_sMIDDLE  iup_XkeyShift(K_MIDDLE )
#define K_sRIGHT   iup_XkeyShift(K_RIGHT  )
#define K_sEND     iup_XkeyShift(K_END    )
#define K_sDOWN    iup_XkeyShift(K_DOWN   )
#define K_sPGDN    iup_XkeyShift(K_PGDN   )
#define K_sINS     iup_XkeyShift(K_INS    )
#define K_sDEL     iup_XkeyShift(K_DEL    )
#define K_sSP      iup_XkeyShift(K_SP     )
#define K_sTAB     iup_XkeyShift(K_TAB    )
#define K_sCR      iup_XkeyShift(K_CR     )
#define K_sBS      iup_XkeyShift(K_BS     )
#define K_sPAUSE   iup_XkeyShift(K_PAUSE  )
#define K_sESC     iup_XkeyShift(K_ESC    )
#define K_sF1      iup_XkeyShift(K_F1     )
#define K_sF2      iup_XkeyShift(K_F2     )
#define K_sF3      iup_XkeyShift(K_F3     )
#define K_sF4      iup_XkeyShift(K_F4     )
#define K_sF5      iup_XkeyShift(K_F5     )
#define K_sF6      iup_XkeyShift(K_F6     )
#define K_sF7      iup_XkeyShift(K_F7     )
#define K_sF8      iup_XkeyShift(K_F8     )
#define K_sF9      iup_XkeyShift(K_F9     )
#define K_sF10     iup_XkeyShift(K_F10    )
#define K_sF11     iup_XkeyShift(K_F11    )
#define K_sF12     iup_XkeyShift(K_F12    )
#define K_sPrint   iup_XkeyShift(K_Print  )
#define K_sMenu    iup_XkeyShift(K_Menu   )

#define K_cHOME     iup_XkeyCtrl(K_HOME    )
#define K_cUP       iup_XkeyCtrl(K_UP      )
#define K_cPGUP     iup_XkeyCtrl(K_PGUP    )
#define K_cLEFT     iup_XkeyCtrl(K_LEFT    )
#define K_cMIDDLE   iup_XkeyCtrl(K_MIDDLE  )
#define K_cRIGHT    iup_XkeyCtrl(K_RIGHT   )
#define K_cEND      iup_XkeyCtrl(K_END     )
#define K_cDOWN     iup_XkeyCtrl(K_DOWN    )
#define K_cPGDN     iup_XkeyCtrl(K_PGDN    )
#define K_cINS      iup_XkeyCtrl(K_INS     )
#define K_cDEL      iup_XkeyCtrl(K_DEL     )
#define K_cSP       iup_XkeyCtrl(K_SP      )
#define K_cTAB      iup_XkeyCtrl(K_TAB     )
#define K_cCR       iup_XkeyCtrl(K_CR      )
#define K_cBS       iup_XkeyCtrl(K_BS      )
#define K_cPAUSE    iup_XkeyCtrl(K_PAUSE   )
#define K_cESC      iup_XkeyCtrl(K_ESC     )
#define K_cCcedilla iup_XkeyCtrl(K_Ccedilla)
#define K_cF1       iup_XkeyCtrl(K_F1      )
#define K_cF2       iup_XkeyCtrl(K_F2      )
#define K_cF3       iup_XkeyCtrl(K_F3      )
#define K_cF4       iup_XkeyCtrl(K_F4      )
#define K_cF5       iup_XkeyCtrl(K_F5      )
#define K_cF6       iup_XkeyCtrl(K_F6      )
#define K_cF7       iup_XkeyCtrl(K_F7      )
#define K_cF8       iup_XkeyCtrl(K_F8      )
#define K_cF9       iup_XkeyCtrl(K_F9      )
#define K_cF10      iup_XkeyCtrl(K_F10     )
#define K_cF11      iup_XkeyCtrl(K_F11     )
#define K_cF12      iup_XkeyCtrl(K_F12     )
#define K_cPrint    iup_XkeyCtrl(K_Print   )
#define K_cMenu     iup_XkeyCtrl(K_Menu    )

#define K_mHOME     iup_XkeyAlt(K_HOME    )
#define K_mUP       iup_XkeyAlt(K_UP      )
#define K_mPGUP     iup_XkeyAlt(K_PGUP    )
#define K_mLEFT     iup_XkeyAlt(K_LEFT    )
#define K_mMIDDLE   iup_XkeyAlt(K_MIDDLE  )
#define K_mRIGHT    iup_XkeyAlt(K_RIGHT   )
#define K_mEND      iup_XkeyAlt(K_END     )
#define K_mDOWN     iup_XkeyAlt(K_DOWN    )
#define K_mPGDN     iup_XkeyAlt(K_PGDN    )
#define K_mINS      iup_XkeyAlt(K_INS     )
#define K_mDEL      iup_XkeyAlt(K_DEL     )
#define K_mSP       iup_XkeyAlt(K_SP      )
#define K_mTAB      iup_XkeyAlt(K_TAB     )
#define K_mCR       iup_XkeyAlt(K_CR      )
#define K_mBS       iup_XkeyAlt(K_BS      )
#define K_mPAUSE    iup_XkeyAlt(K_PAUSE   )
#define K_mESC      iup_XkeyAlt(K_ESC     )
#define K_mCcedilla iup_XkeyAlt(K_Ccedilla)
#define K_mF1       iup_XkeyAlt(K_F1      )
#define K_mF2       iup_XkeyAlt(K_F2      )
#define K_mF3       iup_XkeyAlt(K_F3      )
#define K_mF4       iup_XkeyAlt(K_F4      )
#define K_mF5       iup_XkeyAlt(K_F5      )
#define K_mF6       iup_XkeyAlt(K_F6      )
#define K_mF7       iup_XkeyAlt(K_F7      )
#define K_mF8       iup_XkeyAlt(K_F8      )
#define K_mF9       iup_XkeyAlt(K_F9      )
#define K_mF10      iup_XkeyAlt(K_F10     )
#define K_mF11      iup_XkeyAlt(K_F11     )
#define K_mF12      iup_XkeyAlt(K_F12     )
#define K_mPrint    iup_XkeyAlt(K_Print   )
#define K_mMenu     iup_XkeyAlt(K_Menu    )

#define K_yHOME     iup_XkeySys(K_HOME    )
#define K_yUP       iup_XkeySys(K_UP      )
#define K_yPGUP     iup_XkeySys(K_PGUP    )
#define K_yLEFT     iup_XkeySys(K_LEFT    )
#define K_yMIDDLE   iup_XkeySys(K_MIDDLE  )
#define K_yRIGHT    iup_XkeySys(K_RIGHT   )
#define K_yEND      iup_XkeySys(K_END     )
#define K_yDOWN     iup_XkeySys(K_DOWN    )
#define K_yPGDN     iup_XkeySys(K_PGDN    )
#define K_yINS      iup_XkeySys(K_INS     )
#define K_yDEL      iup_XkeySys(K_DEL     )
#define K_ySP       iup_XkeySys(K_SP      )
#define K_yTAB      iup_XkeySys(K_TAB     )
#define K_yCR       iup_XkeySys(K_CR      )
#define K_yBS       iup_XkeySys(K_BS      )
#define K_yPAUSE    iup_XkeySys(K_PAUSE   )
#define K_yESC      iup_XkeySys(K_ESC     )
#define K_yCcedilla iup_XkeySys(K_Ccedilla)
#define K_yF1       iup_XkeySys(K_F1      )
#define K_yF2       iup_XkeySys(K_F2      )
#define K_yF3       iup_XkeySys(K_F3      )
#define K_yF4       iup_XkeySys(K_F4      )
#define K_yF5       iup_XkeySys(K_F5      )
#define K_yF6       iup_XkeySys(K_F6      )
#define K_yF7       iup_XkeySys(K_F7      )
#define K_yF8       iup_XkeySys(K_F8      )
#define K_yF9       iup_XkeySys(K_F9      )
#define K_yF10      iup_XkeySys(K_F10     )
#define K_yF11      iup_XkeySys(K_F11     )
#define K_yF12      iup_XkeySys(K_F12     )
#define K_yPrint    iup_XkeySys(K_Print   )
#define K_yMenu     iup_XkeySys(K_Menu    )

#define K_sPlus         iup_XkeyShift(K_plus    )   
#define K_sComma        iup_XkeyShift(K_comma   )   
#define K_sMinus        iup_XkeyShift(K_minus   )   
#define K_sPeriod       iup_XkeyShift(K_period  )   
#define K_sSlash        iup_XkeyShift(K_slash   )   
#define K_sAsterisk     iup_XkeyShift(K_asterisk)
                        
#define K_cA     iup_XkeyCtrl(K_A)
#define K_cB     iup_XkeyCtrl(K_B)
#define K_cC     iup_XkeyCtrl(K_C)
#define K_cD     iup_XkeyCtrl(K_D)
#define K_cE     iup_XkeyCtrl(K_E)
#define K_cF     iup_XkeyCtrl(K_F)
#define K_cG     iup_XkeyCtrl(K_G)
#define K_cH     iup_XkeyCtrl(K_H)
#define K_cI     iup_XkeyCtrl(K_I)
#define K_cJ     iup_XkeyCtrl(K_J)
#define K_cK     iup_XkeyCtrl(K_K)
#define K_cL     iup_XkeyCtrl(K_L)
#define K_cM     iup_XkeyCtrl(K_M)
#define K_cN     iup_XkeyCtrl(K_N)
#define K_cO     iup_XkeyCtrl(K_O)
#define K_cP     iup_XkeyCtrl(K_P)
#define K_cQ     iup_XkeyCtrl(K_Q)
#define K_cR     iup_XkeyCtrl(K_R)
#define K_cS     iup_XkeyCtrl(K_S)
#define K_cT     iup_XkeyCtrl(K_T)
#define K_cU     iup_XkeyCtrl(K_U)
#define K_cV     iup_XkeyCtrl(K_V)
#define K_cW     iup_XkeyCtrl(K_W)
#define K_cX     iup_XkeyCtrl(K_X)
#define K_cY     iup_XkeyCtrl(K_Y)
#define K_cZ     iup_XkeyCtrl(K_Z)
#define K_c1     iup_XkeyCtrl(K_1)
#define K_c2     iup_XkeyCtrl(K_2)
#define K_c3     iup_XkeyCtrl(K_3)
#define K_c4     iup_XkeyCtrl(K_4)
#define K_c5     iup_XkeyCtrl(K_5)
#define K_c6     iup_XkeyCtrl(K_6)
#define K_c7     iup_XkeyCtrl(K_7)        
#define K_c8     iup_XkeyCtrl(K_8)         
#define K_c9     iup_XkeyCtrl(K_9)
#define K_c0     iup_XkeyCtrl(K_0)
#define K_cPlus         iup_XkeyCtrl(K_plus        )   
#define K_cComma        iup_XkeyCtrl(K_comma       )   
#define K_cMinus        iup_XkeyCtrl(K_minus       )   
#define K_cPeriod       iup_XkeyCtrl(K_period      )   
#define K_cSlash        iup_XkeyCtrl(K_slash       )   
#define K_cSemicolon    iup_XkeyCtrl(K_semicolon   ) 
#define K_cEqual        iup_XkeyCtrl(K_equal       )
#define K_cBracketleft  iup_XkeyCtrl(K_bracketleft )
#define K_cBracketright iup_XkeyCtrl(K_bracketright)
#define K_cBackslash    iup_XkeyCtrl(K_backslash   )
#define K_cAsterisk     iup_XkeyCtrl(K_asterisk    )

#define K_mA     iup_XkeyAlt(K_A)
#define K_mB     iup_XkeyAlt(K_B)
#define K_mC     iup_XkeyAlt(K_C)
#define K_mD     iup_XkeyAlt(K_D)
#define K_mE     iup_XkeyAlt(K_E)
#define K_mF     iup_XkeyAlt(K_F)
#define K_mG     iup_XkeyAlt(K_G)
#define K_mH     iup_XkeyAlt(K_H)
#define K_mI     iup_XkeyAlt(K_I)
#define K_mJ     iup_XkeyAlt(K_J)
#define K_mK     iup_XkeyAlt(K_K)
#define K_mL     iup_XkeyAlt(K_L)
#define K_mM     iup_XkeyAlt(K_M)
#define K_mN     iup_XkeyAlt(K_N)
#define K_mO     iup_XkeyAlt(K_O)
#define K_mP     iup_XkeyAlt(K_P)
#define K_mQ     iup_XkeyAlt(K_Q)
#define K_mR     iup_XkeyAlt(K_R)
#define K_mS     iup_XkeyAlt(K_S)
#define K_mT     iup_XkeyAlt(K_T)
#define K_mU     iup_XkeyAlt(K_U)
#define K_mV     iup_XkeyAlt(K_V)
#define K_mW     iup_XkeyAlt(K_W)
#define K_mX     iup_XkeyAlt(K_X)
#define K_mY     iup_XkeyAlt(K_Y)
#define K_mZ     iup_XkeyAlt(K_Z)
#define K_m1     iup_XkeyAlt(K_1)
#define K_m2     iup_XkeyAlt(K_2)
#define K_m3     iup_XkeyAlt(K_3)
#define K_m4     iup_XkeyAlt(K_4)
#define K_m5     iup_XkeyAlt(K_5)
#define K_m6     iup_XkeyAlt(K_6)
#define K_m7     iup_XkeyAlt(K_7)        
#define K_m8     iup_XkeyAlt(K_8)         
#define K_m9     iup_XkeyAlt(K_9)
#define K_m0     iup_XkeyAlt(K_0)
#define K_mPlus         iup_XkeyAlt(K_plus        )   
#define K_mComma        iup_XkeyAlt(K_comma       )   
#define K_mMinus        iup_XkeyAlt(K_minus       )   
#define K_mPeriod       iup_XkeyAlt(K_period      )   
#define K_mSlash        iup_XkeyAlt(K_slash       )   
#define K_mSemicolon    iup_XkeyAlt(K_semicolon   ) 
#define K_mEqual        iup_XkeyAlt(K_equal       )
#define K_mBracketleft  iup_XkeyAlt(K_bracketleft )
#define K_mBracketright iup_XkeyAlt(K_bracketright)
#define K_mBackslash    iup_XkeyAlt(K_backslash   )
#define K_mAsterisk     iup_XkeyAlt(K_asterisk    )

#define K_yA     iup_XkeySys(K_A)
#define K_yB     iup_XkeySys(K_B)
#define K_yC     iup_XkeySys(K_C)
#define K_yD     iup_XkeySys(K_D)
#define K_yE     iup_XkeySys(K_E)
#define K_yF     iup_XkeySys(K_F)
#define K_yG     iup_XkeySys(K_G)
#define K_yH     iup_XkeySys(K_H)
#define K_yI     iup_XkeySys(K_I)
#define K_yJ     iup_XkeySys(K_J)
#define K_yK     iup_XkeySys(K_K)
#define K_yL     iup_XkeySys(K_L)
#define K_yM     iup_XkeySys(K_M)
#define K_yN     iup_XkeySys(K_N)
#define K_yO     iup_XkeySys(K_O)
#define K_yP     iup_XkeySys(K_P)
#define K_yQ     iup_XkeySys(K_Q)
#define K_yR     iup_XkeySys(K_R)
#define K_yS     iup_XkeySys(K_S)
#define K_yT     iup_XkeySys(K_T)
#define K_yU     iup_XkeySys(K_U)
#define K_yV     iup_XkeySys(K_V)
#define K_yW     iup_XkeySys(K_W)
#define K_yX     iup_XkeySys(K_X)
#define K_yY     iup_XkeySys(K_Y)
#define K_yZ     iup_XkeySys(K_Z)
#define K_y1     iup_XkeySys(K_1)
#define K_y2     iup_XkeySys(K_2)
#define K_y3     iup_XkeySys(K_3)
#define K_y4     iup_XkeySys(K_4)
#define K_y5     iup_XkeySys(K_5)
#define K_y6     iup_XkeySys(K_6)
#define K_y7     iup_XkeySys(K_7)        
#define K_y8     iup_XkeySys(K_8)         
#define K_y9     iup_XkeySys(K_9)
#define K_y0     iup_XkeySys(K_0)
#define K_yPlus         iup_XkeySys(K_plus        )   
#define K_yComma        iup_XkeySys(K_comma       )   
#define K_yMinus        iup_XkeySys(K_minus       )   
#define K_yPeriod       iup_XkeySys(K_period      )   
#define K_ySlash        iup_XkeySys(K_slash       )   
#define K_ySemicolon    iup_XkeySys(K_semicolon   ) 
#define K_yEqual        iup_XkeySys(K_equal       )
#define K_yBracketleft  iup_XkeySys(K_bracketleft )
#define K_yBracketright iup_XkeySys(K_bracketright)
#define K_yBackslash    iup_XkeySys(K_backslash   )
#define K_yAsterisk     iup_XkeySys(K_asterisk    )


#endif

/** \file
 * \brief Callbacks, Attributes and Attribute Values definitions.    
 * Avoid using these definitions. Use the strings instead.
 *
 * See Copyright Notice in iup.h
 */
 
#ifndef __IUPDEF_H 
#define __IUPDEF_H

/* ATTENTION: these are OLD definitions and they are NOT updated anymore since IUP 3.0 */
/* Avoid using them, directly use the strings instead. */
/* Define __IUPDEF_H to avoid the inclusion of this header */

#define IUP_RUN            "RUN"
#define IUP_ENGLISH        "ENGLISH"
#define IUP_PORTUGUESE     "PORTUGUESE"
#define IUP_SBH            "SBH"
#define IUP_SBV            "SBV"

/************************************************************************/
/*                            Callbacks                                 */
/************************************************************************/

#define IUP_IDLE_ACTION    "IDLE_ACTION"

#define IUP_ACTION         "ACTION"
#define IUP_GETFOCUS_CB    "GETFOCUS_CB"
#define IUP_KILLFOCUS_CB   "KILLFOCUS_CB"
#define IUP_K_ANY          "K_ANY"
#define IUP_KEYPRESS_CB    "KEYPRESS_CB"
#define IUP_HELP_CB        "HELP_CB"

#define IUP_SCROLL_CB      "SCROLL_CB"
#define IUP_RESIZE_CB      "RESIZE_CB"
#define IUP_MOTION_CB      "MOTION_CB"
#define IUP_BUTTON_CB      "BUTTON_CB"
#define IUP_ENTERWINDOW_CB "ENTERWINDOW_CB"
#define IUP_LEAVEWINDOW_CB "LEAVEWINDOW_CB"
#define IUP_WHEEL_CB       "WHEEL_CB"

#define IUP_MASK_CB        "MASK_CB"
#define IUP_OPEN_CB        "OPEN_CB"
#define IUP_HIGHLIGHT_CB   "HIGHLIGHT_CB"
#define IUP_MENUCLOSE_CB   "MENUCLOSE_CB"

#define IUP_MAP_CB         "MAP_CB"
#define IUP_CLOSE_CB       "CLOSE_CB"
#define IUP_SHOW_CB        "SHOW_CB"

#define IUP_DROPFILES_CB   "DROPFILES_CB"
#define IUP_WOM_CB         "WOM_CB"

/************************************************************************/
/*                            Attributes                                */
/************************************************************************/

#define IUP_DIRECTION      "DIRECTION"
#define IUP_ACTIVE         "ACTIVE"
#define IUP_BGCOLOR        "BGCOLOR"
#define IUP_FRAMECOLOR     "FRAMECOLOR"
#define IUP_FGCOLOR        "FGCOLOR"
#define IUP_COLOR          "COLOR"
#define IUP_WID            "WID"
#define IUP_SIZE           "SIZE"
#define IUP_RASTERSIZE     "RASTERSIZE"
#define IUP_TITLE          "TITLE"
#define IUP_VALUE          "VALUE"
#define IUP_VISIBLE        "VISIBLE"
#define IUP_FONT           "FONT"
#define IUP_TIP            "TIP"
#define IUP_EXPAND         "EXPAND"
#define IUP_SEPARATOR      "SEPARATOR"

#define IUP_HOTSPOT        "HOTSPOT"
#define IUP_HEIGHT         "HEIGHT"
#define IUP_WIDTH          "WIDTH"

#define IUP_KEY            "KEY"

#define IUP_MULTIPLE       "MULTIPLE"
#define IUP_DROPDOWN       "DROPDOWN"
#define IUP_VISIBLE_ITEMS  "VISIBLE_ITEMS"

#define IUP_MARGIN         "MARGIN"
#define IUP_GAP            "GAP"
#define IUP_ALIGNMENT      "ALIGNMENT"

#define IUP_IMAGE          "IMAGE"
#define IUP_IMINACTIVE     "IMINACTIVE"
#define IUP_IMPRESS        "IMPRESS"
#define IUP_WIN_SAVEBITS   "WIN_SAVEBITS"

#define IUP_NC             "NC"
#define IUP_MASK           "MASK"

#define IUP_APPEND         "APPEND"
#define IUP_BORDER         "BORDER"

#define IUP_CARET          "CARET"
#define IUP_SELECTION      "SELECTION"
#define IUP_SELECTEDTEXT   "SELECTEDTEXT"
#define IUP_INSERT         "INSERT"

#define IUP_CONID          "CONID"
#define IUP_CURSOR         "CURSOR"

#define IUP_ICON           "ICON"
#define IUP_MENUBOX        "MENUBOX"
#define IUP_MINBOX         "MINBOX"
#define IUP_MAXBOX         "MAXBOX"
#define IUP_RESIZE         "RESIZE"
#define IUP_MENU           "MENU"
#define IUP_STARTFOCUS     "STARTFOCUS"
#define IUP_PARENTDIALOG   "PARENTDIALOG"
#define IUP_SHRINK         "SHRINK"
#define IUP_DEFAULTENTER   "DEFAULTENTER"
#define IUP_DEFAULTESC     "DEFAULTESC"
#define IUP_X              "X"
#define IUP_Y              "Y"
#define IUP_TOOLBOX        "TOOLBOX"
#define IUP_CONTROL        "CONTROL"
#define IUP_READONLY       "READONLY"

#define IUP_SCROLLBAR      "SCROLLBAR"
#define IUP_POSY           "POSY"
#define IUP_POSX           "POSX"
#define IUP_DX             "DX"
#define IUP_DY             "DY"
#define IUP_XMAX           "XMAX"
#define IUP_XMIN           "XMIN"
#define IUP_YMAX           "YMAX"
#define IUP_YMIN           "YMIN"

#define IUP_RED            "255 0 0"
#define IUP_GREEN          "0 255 0"
#define IUP_BLUE           "0 0 255"

#define IUP_MIN            "MIN"
#define IUP_MAX            "MAX"

#define IUP_TIME           "TIME"
#define IUP_DRAG           "DRAG"
#define IUP_DROP           "DROP"
#define IUP_REPAINT        "REPAINT"
#define IUP_TOPMOST        "TOPMOST"
#define IUP_CLIPCHILDREN   "CLIPCHILDREN"

#define IUP_DIALOGTYPE     "DIALOGTYPE"
#define IUP_FILE           "FILE"
#define IUP_MULTIPLEFILES  "MULTIPLEFILES"
#define IUP_FILTER         "FILTER"
#define IUP_FILTERUSED     "FILTERUSED"
#define IUP_FILTERINFO     "FILTERINFO"
#define IUP_EXTFILTER      "EXTFILTER"
#define IUP_DIRECTORY      "DIRECTORY"
#define IUP_ALLOWNEW       "ALLOWNEW"
#define IUP_NOOVERWRITEPROMPT "NOOVERWRITEPROMPT"
#define IUP_NOCHANGEDIR    "NOCHANGEDIR"
#define IUP_FILEEXIST      "FILEEXIST"
#define IUP_STATUS         "STATUS"

#define IUP_LOCKLOOP       "LOCKLOOP"
#define IUP_SYSTEM         "SYSTEM"
#define IUP_DRIVER         "DRIVER"
#define IUP_SCREENSIZE     "SCREENSIZE"
#define IUP_SYSTEMLANGUAGE "SYSTEMLANGUAGE"
#define IUP_COMPUTERNAME   "COMPUTERNAME"
#define IUP_USERNAME       "USERNAME"

#define IUP_OPEN "OPEN"
#define IUP_SAVE "SAVE"
#define IUP_DIR  "DIR"

#define IUP_HORIZONTAL     "HORIZONTAL"
#define IUP_VERTICAL       "VERTICAL"

/************************************************************************/
/*                       Attribute Values                               */
/************************************************************************/

#define IUP_YES       "YES"
#define IUP_NO        "NO"
#define IUP_ON        "ON"
#define IUP_OFF       "OFF"

#define IUP_ACENTER   "ACENTER"
#define IUP_ALEFT     "ALEFT"
#define IUP_ARIGHT    "ARIGHT"
#define IUP_ATOP      "ATOP"
#define IUP_ABOTTOM   "ABOTTOM"

#define IUP_NORTH     "NORTH"
#define IUP_SOUTH     "SOUTH"
#define IUP_WEST      "WEST"
#define IUP_EAST      "EAST"
#define IUP_NE        "NE"
#define IUP_SE        "SE"
#define IUP_NW        "NW"
#define IUP_SW        "SW"

#define IUP_FULLSCREEN "FULLSCREEN"
#define IUP_FULL      "FULL"
#define IUP_HALF      "HALF"
#define IUP_THIRD     "THIRD"
#define IUP_QUARTER   "QUARTER"
#define IUP_EIGHTH    "EIGHTH"

#define IUP_ARROW     "ARROW"
#define IUP_BUSY      "BUSY"
#define IUP_RESIZE_N  "RESIZE_N"
#define IUP_RESIZE_S  "RESIZE_S"
#define IUP_RESIZE_E  "RESIZE_E"
#define IUP_RESIZE_W  "RESIZE_W"
#define IUP_RESIZE_NE "RESIZE_NE"
#define IUP_RESIZE_NW "RESIZE_NW"
#define IUP_RESIZE_SE "RESIZE_SE"
#define IUP_RESIZE_SW "RESIZE_SW"
#define IUP_MOVE      "MOVE"
#define IUP_HAND      "HAND"
#define IUP_NONE      "NONE"
#define IUP_IUP       "IUP"
#define IUP_CROSS     "CROSS"
#define IUP_PEN       "PEN"
#define IUP_TEXT      "TEXT"
#define IUP_RESIZE_C  "RESIZE_C"
#define IUP_OPENHAND  "OPENHAND"

/************************************************************************/
/*                           Keys                                       */
/************************************************************************/

#define IUP_K_exclam            "K_exclam"
#define IUP_K_quotedbl          "K_quotedbl"
#define IUP_K_numbersign        "K_numbersign"
#define IUP_K_dollar            "K_dollar"
#define IUP_K_percent           "K_percent"
#define IUP_K_ampersand         "K_ampersand"
#define IUP_K_quoteright        "K_quoteright"
#define IUP_K_parentleft        "K_parentleft"
#define IUP_K_parentright       "K_parentright"
#define IUP_K_asterisk          "K_asterisk"
#define IUP_K_plus              "K_plus"
#define IUP_K_comma             "K_comma"
#define IUP_K_minus             "K_minus"
#define IUP_K_period            "K_period"
#define IUP_K_slash             "K_slash"
#define IUP_K_0                 "K_0"
#define IUP_K_1                 "K_1"
#define IUP_K_2                 "K_2"
#define IUP_K_3                 "K_3"
#define IUP_K_4                 "K_4"
#define IUP_K_5                 "K_5"
#define IUP_K_6                 "K_6"
#define IUP_K_7                 "K_7"
#define IUP_K_8                 "K_8"
#define IUP_K_9                 "K_9"
#define IUP_K_colon             "K_colon"
#define IUP_K_semicolon         "K_semicolon "
#define IUP_K_less              "K_less"
#define IUP_K_equal             "K_equal"
#define IUP_K_greater           "K_greater"
#define IUP_K_question          "K_question"
#define IUP_K_at                "K_at"
#define IUP_K_A                 "K_A"
#define IUP_K_B                 "K_B"
#define IUP_K_C                 "K_C"
#define IUP_K_D                 "K_D"
#define IUP_K_E                 "K_E"
#define IUP_K_F                 "K_F"
#define IUP_K_G                 "K_G"
#define IUP_K_H                 "K_H"
#define IUP_K_I                 "K_I"
#define IUP_K_J                 "K_J"
#define IUP_K_K                 "K_K"
#define IUP_K_L                 "K_L"
#define IUP_K_M                 "K_M"
#define IUP_K_N                 "K_N"
#define IUP_K_O                 "K_O"
#define IUP_K_P                 "K_P"
#define IUP_K_Q                 "K_Q"
#define IUP_K_R                 "K_R"
#define IUP_K_S                 "K_S"
#define IUP_K_T                 "K_T"
#define IUP_K_U                 "K_U"
#define IUP_K_V                 "K_V"
#define IUP_K_W                 "K_W"
#define IUP_K_X                 "K_X"
#define IUP_K_Y                 "K_Y"
#define IUP_K_Z                 "K_Z"
#define IUP_K_bracketleft       "K_bracketleft"
#define IUP_K_backslash         "K_backslash"
#define IUP_K_bracketright      "K_bracketright"
#define IUP_K_circum            "K_circum"
#define IUP_K_underscore        "K_underscore"
#define IUP_K_quoteleft         "K_quoteleft"
#define IUP_K_a                 "K_a"
#define IUP_K_b                 "K_b"
#define IUP_K_c                 "K_c"
#define IUP_K_d                 "K_d"
#define IUP_K_e                 "K_e"
#define IUP_K_f                 "K_f"
#define IUP_K_g                 "K_g"
#define IUP_K_h                 "K_h"
#define IUP_K_i                 "K_i"
#define IUP_K_j                 "K_j"
#define IUP_K_k                 "K_k"
#define IUP_K_l                 "K_l"
#define IUP_K_m                 "K_m"
#define IUP_K_n                 "K_n"
#define IUP_K_o                 "K_o"
#define IUP_K_p                 "K_p"
#define IUP_K_q                 "K_q"
#define IUP_K_r                 "K_r"
#define IUP_K_s                 "K_s"
#define IUP_K_t                 "K_t"
#define IUP_K_u                 "K_u"
#define IUP_K_v                 "K_v"
#define IUP_K_w                 "K_w"
#define IUP_K_x                 "K_x"
#define IUP_K_y                 "K_y"
#define IUP_K_z                 "K_z"
#define IUP_K_braceleft         "K_braceleft"
#define IUP_K_bar               "K_bar"
#define IUP_K_braceright        "K_braceright"
#define IUP_K_tilde             "K_tilde"

#define IUP_K_cA       "K_cA"
#define IUP_K_cB       "K_cB"
#define IUP_K_cC       "K_cC"
#define IUP_K_cD       "K_cD"
#define IUP_K_cE       "K_cE"
#define IUP_K_cF       "K_cF"
#define IUP_K_cG       "K_cG"
#define IUP_K_cJ       "K_cJ"
#define IUP_K_cK       "K_cK"
#define IUP_K_cL       "K_cL"
#define IUP_K_cN       "K_cN"
#define IUP_K_cO       "K_cO"
#define IUP_K_cP       "K_cP"
#define IUP_K_cQ       "K_cQ"
#define IUP_K_cR       "K_cR"
#define IUP_K_cS       "K_cS"
#define IUP_K_cT       "K_cT"
#define IUP_K_cU       "K_cU"
#define IUP_K_cV       "K_cV"
#define IUP_K_cW       "K_cW"
#define IUP_K_cX       "K_cX"
#define IUP_K_cY       "K_cY"
#define IUP_K_cZ       "K_cZ"
#define IUP_K_mA       "K_mA"
#define IUP_K_mB       "K_mB"
#define IUP_K_mC       "K_mC"
#define IUP_K_mD       "K_mD"
#define IUP_K_mE       "K_mE"
#define IUP_K_mF       "K_mF"
#define IUP_K_mG       "K_mG"
#define IUP_K_mH       "K_mH"
#define IUP_K_mI       "K_mI"
#define IUP_K_mJ       "K_mJ"
#define IUP_K_mK       "K_mK"
#define IUP_K_mL       "K_mL"
#define IUP_K_mM       "K_mM"
#define IUP_K_mN       "K_mN"
#define IUP_K_mO       "K_mO"
#define IUP_K_mP       "K_mP"
#define IUP_K_mQ       "K_mQ"
#define IUP_K_mR       "K_mR"
#define IUP_K_mS       "K_mS"
#define IUP_K_mT       "K_mT"
#define IUP_K_mU       "K_mU"
#define IUP_K_mV       "K_mV"
#define IUP_K_mW       "K_mW"
#define IUP_K_mX       "K_mX"
#define IUP_K_mY       "K_mY"
#define IUP_K_mZ       "K_mZ"
#define IUP_K_BS       "K_BS"
#define IUP_K_TAB      "K_TAB"
#define IUP_K_CR       "K_CR"
#define IUP_K_SP       "K_SP"
#define IUP_K_ESC      "K_ESC"
#define IUP_K_sCR      "K_sCR"
#define IUP_K_sTAB     "K_sTAB"
#define IUP_K_cTAB     "K_cTAB"
#define IUP_K_mTAB     "K_mTAB"
#define IUP_K_HOME     "K_HOME"
#define IUP_K_UP       "K_UP"
#define IUP_K_PGUP     "K_PGUP"
#define IUP_K_LEFT     "K_LEFT"
#define IUP_K_RIGHT    "K_RIGHT"
#define IUP_K_END      "K_END"
#define IUP_K_DOWN     "K_DOWN"
#define IUP_K_PGDN     "K_PGDN"
#define IUP_K_MIDDLE   "K_MIDDLE"
#define IUP_K_INS      "K_INS"
#define IUP_K_DEL      "K_DEL"
#define IUP_K_sHOME    "K_sHOME"
#define IUP_K_sUP      "K_sUP"
#define IUP_K_sPGUP    "K_sPGUP"
#define IUP_K_sLEFT    "K_sLEFT"
#define IUP_K_sRIGHT   "K_sRIGHT"
#define IUP_K_sEND     "K_sEND"
#define IUP_K_sDOWN    "K_sDOWN"
#define IUP_K_sPGDN    "K_sPGDN"
#define IUP_K_cHOME    "K_cHOME"
#define IUP_K_cPGUP    "K_cPGUP"
#define IUP_K_cLEFT    "K_cLEFT"
#define IUP_K_cRIGHT   "K_cRIGHT"
#define IUP_K_cEND     "K_cEND"
#define IUP_K_cPGDN    "K_cPGDN"
#define IUP_K_cUP      "K_cUP"
#define IUP_K_cDOWN    "K_cDOWN"
#define IUP_K_cMIDDLE  "K_cMIDDLE"
#define IUP_K_cINS     "K_cINS"
#define IUP_K_cDEL     "K_cDEL"
#define IUP_K_mHOME    "K_mHOME"
#define IUP_K_mPGUP    "K_mPGUP"
#define IUP_K_mLEFT    "K_mLEFT"
#define IUP_K_mRIGHT   "K_mRIGHT"
#define IUP_K_mEND     "K_mEND"
#define IUP_K_mPGDN    "K_mPGDN"
#define IUP_K_mUP      "K_mUP"
#define IUP_K_mDOWN    "K_mDOWN"
#define IUP_K_mINS     "K_mINS"
#define IUP_K_mDEL     "K_mDEL"
#define IUP_K_F1       "K_F1"
#define IUP_K_F2       "K_F2"
#define IUP_K_F3       "K_F3"
#define IUP_K_F4       "K_F4"
#define IUP_K_F5       "K_F5"
#define IUP_K_F6       "K_F6"
#define IUP_K_F7       "K_F7"
#define IUP_K_F8       "K_F8"
#define IUP_K_F9       "K_F9"
#define IUP_K_F10      "K_F10"
#define IUP_K_F11      "K_F11"
#define IUP_K_F12      "K_F12"
#define IUP_K_sF1      "K_sF1"
#define IUP_K_sF2      "K_sF2"
#define IUP_K_sF3      "K_sF3"
#define IUP_K_sF4      "K_sF4"
#define IUP_K_sF5      "K_sF5"
#define IUP_K_sF6      "K_sF6"
#define IUP_K_sF7      "K_sF7"
#define IUP_K_sF8      "K_sF8"
#define IUP_K_sF9      "K_sF9"
#define IUP_K_sF10     "K_sF10"
#define IUP_K_sF11     "K_sF11"
#define IUP_K_sF12     "K_sF12"
#define IUP_K_cF1      "K_cF1"
#define IUP_K_cF2      "K_cF2"
#define IUP_K_cF3      "K_cF3"
#define IUP_K_cF4      "K_cF4"
#define IUP_K_cF5      "K_cF5"
#define IUP_K_cF6      "K_cF6"
#define IUP_K_cF7      "K_cF7"
#define IUP_K_cF8      "K_cF8"
#define IUP_K_cF9      "K_cF9"
#define IUP_K_cF10     "K_cF10"
#define IUP_K_cF11     "K_cF11"
#define IUP_K_cF12     "K_cF12"
#define IUP_K_mF1      "K_mF1"
#define IUP_K_mF2      "K_mF2"
#define IUP_K_mF3      "K_mF3"
#define IUP_K_mF4      "K_mF4"
#define IUP_K_mF5      "K_mF5"
#define IUP_K_mF6      "K_mF6"
#define IUP_K_mF7      "K_mF7"
#define IUP_K_mF8      "K_mF8"
#define IUP_K_mF9      "K_mF9"
#define IUP_K_mF10     "K_mF10"
#define IUP_K_m1       "K_m1"
#define IUP_K_m2       "K_m2"
#define IUP_K_m3       "K_m3"
#define IUP_K_m4       "K_m4"
#define IUP_K_m5       "K_m5"
#define IUP_K_m6       "K_m6"
#define IUP_K_m7       "K_m7"
#define IUP_K_m8       "K_m8"
#define IUP_K_m9       "K_m9"
#define IUP_K_m0       "K_m0"

/************/
/* Colorbar */
/************/

#define IUP_NUM_PARTS  "NUM_PARTS"
#define IUP_NUM_CELLS "NUM_CELLS"
#define IUP_CELL "CELL"
#define IUP_PREVIEW_SIZE "PREVIEW_SIZE"
#define IUP_SHOW_PREVIEW "SHOW_PREVIEW"
#define IUP_SHOW_SECONDARY "SHOW_SECONDARY"
#define IUP_PRIMARY_CELL "PRIMARY_CELL"
#define IUP_SECONDARY_CELL "SECONDARY_CELL"
#define IUP_ORIENTATION  "ORIENTATION"
#define IUP_SQUARED  "SQUARED"
#define IUP_SHADOWED  "SHADOWED"
#define IUP_BUFFERIZE  "BUFFERIZE"
#define IUP_TRANSPARENCY  "TRANSPARENCY"
#define IUP_CELL_CB "CELL_CB"
#define IUP_EXTENDED_CB "EXTENDED_CB"
#define IUP_SELECT_CB "SELECT_CB"
#define IUP_SWITCH_CB "SWITCH_CB"
#define IUP_VERTICAL    "VERTICAL"
#define IUP_HORIZONTAL  "HORIZONTAL"

/************/
/* Cells    */
/************/

#define IUP_ALL  "ALL"
#define IUP_BOXED  "BOXED"
#define IUP_CLIPPED  "CLIPPED"
#define IUP_TRANSPARENT  "TRANSPARENT"
#define IUP_NON_SCROLLABLE_LINES  "NON_SCROLLABLE_LINES"
#define IUP_NON_SCROLLABLE_COLS  "NON_SCROLLABLE_COLS"
#define IUP_ORIGIN  "ORIGIN"
#define IUP_NO_COLOR  "NO_COLOR"
#define IUP_FIRST_LINE  "FIRST_LINE"
#define IUP_FIRST_COL  "FIRST_COL"
#define IUP_DOUBLE_BUFFER  "DOUBLE_BUFFER"
#define IUP_LIMITS  "LIMITS"
#define IUP_CANVAS  "CANVAS"
#define IUP_IMAGE_CANVAS  "IMAGE_CANVAS"
#define IUP_FULL_VISIBLE  "FULL_VISIBLE"
#define IUP_MOUSECLICK_CB "MOUSECLICK_CB"
#define IUP_MOUSEMOTION_CB "MOUSEMOTION_CB"
#define IUP_DRAW_CB "DRAW_CB"
#define IUP_WIDTH_CB "WIDTH_CB"
#define IUP_HEIGHT_CB "HEIGHT_CB"
#define IUP_NLINES_CB "NLINES_CB"
#define IUP_NCOLS_CB "NCOLS_CB"
#define IUP_HSPAN_CB "HSPAN_CB"
#define IUP_VSPAN_CB "VSPAN_CB"
#define IUP_SCROLLING_CB "SCROLLING_CB"

/*****************/
/* ColorBrowser  */
/*****************/

#define IUP_RGB "RGB"
#define IUP_CHANGE_CB "CHANGE_CB"
#define IUP_DRAG_CB "DRAG_CB"

/*****************/
/* Val           */
/*****************/

#define ICTL_MOUSEMOVE_CB "MOUSEMOVE_CB"
#define ICTL_BUTTON_PRESS_CB "BUTTON_PRESS_CB"
#define ICTL_BUTTON_RELEASE_CB "BUTTON_RELEASE_CB"
#define ICTL_HORIZONTAL "HORIZONTAL"
#define ICTL_VERTICAL "VERTICAL"
#define ICTL_SHOWTICKS "SHOWTICKS"

/*****************/
/* Tabs          */
/*****************/

#define ICTL_TOP "TOP"
#define ICTL_BOTTOM "BOTTOM"
#define ICTL_LEFT "LEFT"
#define ICTL_RIGHT "RIGHT"
#define ICTL_TABTYPE "TABTYPE"
#define ICTL_TABTITLE "TABTITLE"
#define ICTL_TABSIZE "TABSIZE"
#define ICTL_TABCHANGE_CB "TABCHANGE_CB"
#define ICTL_FONT "FONT"
#define ICTL_FONT_ACTIVE "FONT_ACTIVE"
#define ICTL_FONT_INACTIVE "FONT_INACTIVE"

/*****************/
/* Gauge         */
/*****************/

#define ICTL_SHOW_TEXT "SHOW_TEXT"
#define ICTL_DASHED "DASHED"
#define ICTL_MARGIN "MARGIN"
#define ICTL_TEXT "TEXT"

/*****************/
/* Dial          */
/*****************/

#define ICTL_DENSITY "DENSITY"
#define ICTL_HORIZONTAL "HORIZONTAL"
#define ICTL_VERTICAL "VERTICAL"
#define ICTL_CIRCULAR "CIRCULAR"
#define ICTL_UNIT "UNIT"

/*****************/
/* Matrix        */
/*****************/

#define IUP_ENTERITEM_CB   "ENTERITEM_CB"
#define IUP_LEAVEITEM_CB   "LEAVEITEM_CB"
#define IUP_EDITION_CB     "EDITION_CB"
#define IUP_CLICK_CB       "CLICK_CB"
#define IUP_DROP_CB        "DROP_CB"
#define IUP_DROPSELECT_CB  "DROPSELECT_CB"
#define IUP_DROPCHECK_CB   "DROPCHECK_CB"
#define IUP_SCROLL_CB      "SCROLL_CB"
#define IUP_VALUE_CB       "VALUE_CB"
#define IUP_VALUE_EDIT_CB  "VALUE_EDIT_CB"
#define IUP_FIELD_CB       "FIELD_CB"
#define IUP_RESIZEMATRIX   "RESIZEMATRIX"
#define IUP_ADDLIN         "ADDLIN"
#define IUP_ADDCOL         "ADDCOL"
#define IUP_DELLIN         "DELLIN"
#define IUP_DELCOL         "DELCOL"
#define IUP_NUMLIN         "NUMLIN"
#define IUP_NUMCOL         "NUMCOL"
#define IUP_NUMLIN_VISIBLE "NUMLIN_VISIBLE"
#define IUP_NUMCOL_VISIBLE "NUMCOL_VISIBLE"
#define IUP_MARKED         "MARKED"
#define IUP_WIDTHDEF       "WIDTHDEF"
#define IUP_HEIGHTDEF      "HEIGHTDEF"
#define IUP_AREA           "AREA"
#define IUP_MARK_MODE      "MARK_MODE"
#define IUP_LIN            "LIN"
#define IUP_COL            "COL"
#define IUP_LINCOL         "LINCOL"
#define IUP_CELL           "CELL"
#define IUP_EDIT_MODE      "EDIT_MODE"
#define IUP_FOCUS_CELL     "FOCUS_CELL"
#define IUP_ORIGIN         "ORIGIN"
#define IUP_REDRAW         "REDRAW"
#define IUP_PREVIOUSVALUE  "PREVIOUSVALUE"
#define IUP_MOUSEMOVE_CB   "MOUSEMOVE_CB"

/*****************/
/* Tree          */
/*****************/

#define IUP_ADDLEAF          "ADDLEAF"
#define IUP_ADDBRANCH        "ADDBRANCH"
#define IUP_DELNODE          "DELNODE"
#define IUP_IMAGELEAF        "IMAGELEAF"
#define IUP_IMAGEBRANCHCOLLAPSED "IMAGEBRANCHCOLLAPSED"
#define IUP_IMAGEBRANCHEXPANDED  "IMAGEBRANCHEXPANDED"
#define IUP_IMAGEEXPANDED     "IMAGEEXPANDED"
#define IUP_KIND             "KIND"
#define IUP_PARENT           "PARENT"
#define IUP_DEPTH            "DEPTH"
#define IUP_MARKED           "MARKED"
#define IUP_ADDEXPANDED      "ADDEXPANDED"
#define IUP_CTRL             "CTRL"
#define IUP_SHIFT            "SHIFT"
#define IUP_STATE            "STATE"
#define IUP_STARTING         "STARTING"
#define IUP_LEAF             "LEAF"
#define IUP_BRANCH           "BRANCH"
#define IUP_SELECTED         "SELECTED"
#define IUP_CHILDREN         "CHILDREN"
#define IUP_MARKED           "MARKED"
#define IUP_ROOT             "ROOT"
#define IUP_LAST             "LAST"
#define IUP_PGUP             "PGUP"
#define IUP_PGDN             "PGDN"
#define IUP_NEXT             "NEXT"
#define IUP_PREVIOUS         "PREVIOUS"
#define IUP_INVERT           "INVERT"
#define IUP_BLOCK            "BLOCK"
#define IUP_CLEARALL         "CLEARALL"
#define IUP_MARKALL          "MARKALL"
#define IUP_INVERTALL        "INVERTALL"
#define IUP_REDRAW           "REDRAW"
#define IUP_COLLAPSED        "COLLAPSED"
#define IUP_EXPANDED         "EXPANDED"
#define IUP_SELECTION_CB "SELECTION_CB"
#define IUP_BRANCHOPEN_CB    "BRANCHOPEN_CB"
#define IUP_BRANCHCLOSE_CB   "BRANCHCLOSE_CB"
#define IUP_RIGHTCLICK_CB    "RIGHTCLICK_CB"
#define IUP_EXECUTELEAF_CB   "EXECUTELEAF_CB"
#define IUP_RENAMENODE_CB    "RENAMENODE_CB"
#define IUP_IMGLEAF             "IMGLEAF"
#define IUP_IMGCOLLAPSED        "IMGCOLLAPSED"
#define IUP_IMGEXPANDED         "IMGEXPANDED"
#define IUP_IMGBLANK            "IMGBLANK"
#define IUP_IMGPAPER            "IMGPAPER"

#endif



#ifdef __cplusplus
extern "C" {
#endif


#define IUP_NAME "IUP - Portable User Interface"
#define IUP_DESCRIPTION	"Multi-platform Toolkit for Building Graphical User Interfaces"
#define IUP_COPYRIGHT "Copyright (C) 1994-2016 Tecgraf/PUC-Rio"
#define IUP_VERSION "3.20"         /* bug fixes are reported only by IupVersion functions */
#define IUP_VERSION_NUMBER 320000
#define IUP_VERSION_DATE "2016/09/30"  /* does not include bug fix releases */

typedef struct Ihandle_ Ihandle;
typedef int (*Icallback)(Ihandle*);

/************************************************************************/
/*                        Main API                                      */
/************************************************************************/

int       IupOpen          (int *argc, char ***argv);
void      IupClose         (void);
void      IupImageLibOpen  (void);

int       IupMainLoop      (void);
int       IupLoopStep      (void);
int       IupLoopStepWait  (void);
int       IupMainLoopLevel (void);
void      IupFlush         (void);
void      IupExitLoop      (void);

int       IupRecordInput(const char* filename, int mode);
int       IupPlayInput(const char* filename);

void      IupUpdate        (Ihandle* ih);
void      IupUpdateChildren(Ihandle* ih);
void      IupRedraw        (Ihandle* ih, int children);
void      IupRefresh       (Ihandle* ih);
void      IupRefreshChildren(Ihandle* ih);

int       IupExecute(const char *filename, const char* parameters);
int       IupExecuteWait(const char *filename, const char* parameters);
int       IupHelp(const char* url);

char*     IupLoad          (const char *filename);
char*     IupLoadBuffer    (const char *buffer);

char*     IupVersion       (void);
char*     IupVersionDate   (void);
int       IupVersionNumber (void);

void      IupSetLanguage   (const char *lng);
char*     IupGetLanguage   (void);
void      IupSetLanguageString(const char* name, const char* str);
void      IupStoreLanguageString(const char* name, const char* str);
char*     IupGetLanguageString(const char* name);
void      IupSetLanguagePack(Ihandle* ih);

void      IupDestroy      (Ihandle* ih);
void      IupDetach       (Ihandle* child);
Ihandle*  IupAppend       (Ihandle* ih, Ihandle* child);
Ihandle*  IupInsert       (Ihandle* ih, Ihandle* ref_child, Ihandle* child);
Ihandle*  IupGetChild     (Ihandle* ih, int pos);
int       IupGetChildPos  (Ihandle* ih, Ihandle* child);
int       IupGetChildCount(Ihandle* ih);
Ihandle*  IupGetNextChild (Ihandle* ih, Ihandle* child);
Ihandle*  IupGetBrother   (Ihandle* ih);
Ihandle*  IupGetParent    (Ihandle* ih);
Ihandle*  IupGetDialog    (Ihandle* ih);
Ihandle*  IupGetDialogChild(Ihandle* ih, const char* name);
int       IupReparent     (Ihandle* ih, Ihandle* new_parent, Ihandle* ref_child);

int       IupPopup         (Ihandle* ih, int x, int y);
int       IupShow          (Ihandle* ih);
int       IupShowXY        (Ihandle* ih, int x, int y);
int       IupHide          (Ihandle* ih);
int       IupMap           (Ihandle* ih);
void      IupUnmap         (Ihandle *ih);

void      IupResetAttribute(Ihandle *ih, const char* name);
int       IupGetAllAttributes(Ihandle* ih, char** names, int n);
Ihandle*  IupSetAtt(const char* handle_name, Ihandle* ih, const char* name, ...);
Ihandle*  IupSetAttributes (Ihandle* ih, const char *str);
char*     IupGetAttributes (Ihandle* ih);

void      IupSetAttribute   (Ihandle* ih, const char* name, const char* value);
void      IupSetStrAttribute(Ihandle* ih, const char* name, const char* value);
void      IupSetStrf        (Ihandle* ih, const char* name, const char* format, ...);
void      IupSetInt         (Ihandle* ih, const char* name, int value);
void      IupSetFloat       (Ihandle* ih, const char* name, float value);
void      IupSetDouble      (Ihandle* ih, const char* name, double value);
void      IupSetRGB         (Ihandle *ih, const char* name, unsigned char r, unsigned char g, unsigned char b);

char*     IupGetAttribute(Ihandle* ih, const char* name);
int       IupGetInt      (Ihandle* ih, const char* name);
int       IupGetInt2     (Ihandle* ih, const char* name);
int       IupGetIntInt   (Ihandle *ih, const char* name, int *i1, int *i2);
float     IupGetFloat    (Ihandle* ih, const char* name);
double    IupGetDouble(Ihandle* ih, const char* name);
void      IupGetRGB      (Ihandle *ih, const char* name, unsigned char *r, unsigned char *g, unsigned char *b);

void  IupSetAttributeId(Ihandle *ih, const char* name, int id, const char *value);
void  IupSetStrAttributeId(Ihandle *ih, const char* name, int id, const char *value);
void  IupSetStrfId(Ihandle *ih, const char* name, int id, const char* format, ...);
void  IupSetIntId(Ihandle* ih, const char* name, int id, int value);
void  IupSetFloatId(Ihandle* ih, const char* name, int id, float value);
void  IupSetDoubleId(Ihandle* ih, const char* name, int id, double value);
void  IupSetRGBId(Ihandle *ih, const char* name, int id, unsigned char r, unsigned char g, unsigned char b);

char*  IupGetAttributeId(Ihandle *ih, const char* name, int id);
int    IupGetIntId(Ihandle *ih, const char* name, int id);
float  IupGetFloatId(Ihandle *ih, const char* name, int id);
double IupGetDoubleId(Ihandle *ih, const char* name, int id);
void   IupGetRGBId(Ihandle *ih, const char* name, int id, unsigned char *r, unsigned char *g, unsigned char *b);

void  IupSetAttributeId2(Ihandle* ih, const char* name, int lin, int col, const char* value);
void  IupSetStrAttributeId2(Ihandle* ih, const char* name, int lin, int col, const char* value);
void  IupSetStrfId2(Ihandle* ih, const char* name, int lin, int col, const char* format, ...);
void  IupSetIntId2(Ihandle* ih, const char* name, int lin, int col, int value);
void  IupSetFloatId2(Ihandle* ih, const char* name, int lin, int col, float value);
void  IupSetDoubleId2(Ihandle* ih, const char* name, int lin, int col, double value);
void  IupSetRGBId2(Ihandle *ih, const char* name, int lin, int col, unsigned char r, unsigned char g, unsigned char b);

char*  IupGetAttributeId2(Ihandle* ih, const char* name, int lin, int col);
int    IupGetIntId2(Ihandle* ih, const char* name, int lin, int col);
float  IupGetFloatId2(Ihandle* ih, const char* name, int lin, int col);
double IupGetDoubleId2(Ihandle* ih, const char* name, int lin, int col);
void   IupGetRGBId2(Ihandle *ih, const char* name, int lin, int col, unsigned char *r, unsigned char *g, unsigned char *b);

void      IupSetGlobal  (const char* name, const char* value);
void      IupSetStrGlobal(const char* name, const char* value);
char*     IupGetGlobal  (const char* name);

Ihandle*  IupSetFocus     (Ihandle* ih);
Ihandle*  IupGetFocus     (void);
Ihandle*  IupPreviousField(Ihandle* ih);  
Ihandle*  IupNextField    (Ihandle* ih);

Icallback IupGetCallback (Ihandle* ih, const char *name);
Icallback IupSetCallback (Ihandle* ih, const char *name, Icallback func);
Ihandle*  IupSetCallbacks(Ihandle* ih, const char *name, Icallback func, ...);

Icallback IupGetFunction(const char *name);
Icallback IupSetFunction(const char *name, Icallback func);

Ihandle*  IupGetHandle    (const char *name);
Ihandle*  IupSetHandle    (const char *name, Ihandle* ih);
int       IupGetAllNames  (char** names, int n);
int       IupGetAllDialogs(char** names, int n);
char*     IupGetName      (Ihandle* ih);

void      IupSetAttributeHandle(Ihandle* ih, const char* name, Ihandle* ih_named);
Ihandle*  IupGetAttributeHandle(Ihandle* ih, const char* name);

char*     IupGetClassName(Ihandle* ih);
char*     IupGetClassType(Ihandle* ih);
int       IupGetAllClasses(char** names, int n);
int       IupGetClassAttributes(const char* classname, char** names, int n);
int       IupGetClassCallbacks(const char* classname, char** names, int n);
void      IupSaveClassAttributes(Ihandle* ih);
void      IupCopyClassAttributes(Ihandle* src_ih, Ihandle* dst_ih);
void      IupSetClassDefaultAttribute(const char* classname, const char *name, const char* value);
int       IupClassMatch(Ihandle* ih, const char* classname);

Ihandle*  IupCreate (const char *classname);
Ihandle*  IupCreatev(const char *classname, void* *params);
Ihandle*  IupCreatep(const char *classname, void *first, ...);

/************************************************************************/
/*                        Elements                                      */
/************************************************************************/

Ihandle*  IupFill       (void);
Ihandle*  IupRadio      (Ihandle* child);
Ihandle*  IupVbox       (Ihandle* child, ...);
Ihandle*  IupVboxv      (Ihandle* *children);
Ihandle*  IupZbox       (Ihandle* child, ...);
Ihandle*  IupZboxv      (Ihandle* *children);
Ihandle*  IupHbox       (Ihandle* child,...);
Ihandle*  IupHboxv      (Ihandle* *children);

Ihandle*  IupNormalizer (Ihandle* ih_first, ...);
Ihandle*  IupNormalizerv(Ihandle* *ih_list);

Ihandle*  IupCbox       (Ihandle* child, ...);
Ihandle*  IupCboxv      (Ihandle* *children);
Ihandle*  IupSbox       (Ihandle *child);
Ihandle*  IupSplit      (Ihandle* child1, Ihandle* child2);
Ihandle*  IupScrollBox  (Ihandle* child);
Ihandle*  IupGridBox    (Ihandle* child, ...);
Ihandle*  IupGridBoxv   (Ihandle **children);
Ihandle*  IupExpander   (Ihandle *child);
Ihandle*  IupDetachBox  (Ihandle *child);
Ihandle*  IupBackgroundBox(Ihandle *child);

Ihandle*  IupFrame      (Ihandle* child);
Ihandle*  IupFlatFrame  (Ihandle* child);

Ihandle*  IupImage      (int width, int height, const unsigned char *pixmap);
Ihandle*  IupImageRGB   (int width, int height, const unsigned char *pixmap);
Ihandle*  IupImageRGBA  (int width, int height, const unsigned char *pixmap);

Ihandle*  IupItem       (const char* title, const char* action);
Ihandle*  IupSubmenu    (const char* title, Ihandle* child);
Ihandle*  IupSeparator  (void);
Ihandle*  IupMenu       (Ihandle* child,...);
Ihandle*  IupMenuv      (Ihandle* *children);

Ihandle*  IupButton     (const char* title, const char* action);
Ihandle*  IupCanvas     (const char* action);
Ihandle*  IupDialog     (Ihandle* child);
Ihandle*  IupUser       (void);
Ihandle*  IupLabel      (const char* title);
Ihandle*  IupList       (const char* action);
Ihandle*  IupText       (const char* action);
Ihandle*  IupMultiLine  (const char* action);
Ihandle*  IupToggle     (const char* title, const char* action);
Ihandle*  IupTimer      (void);
Ihandle*  IupClipboard  (void);
Ihandle*  IupProgressBar(void);
Ihandle*  IupVal        (const char *type);
Ihandle*  IupTabs       (Ihandle* child, ...);
Ihandle*  IupTabsv      (Ihandle* *children);
Ihandle*  IupTree       (void);
Ihandle*  IupLink       (const char* url, const char* title);
Ihandle*  IupFlatButton (const char* title);
Ihandle*  IupAnimatedLabel(Ihandle* animation);
Ihandle*  IupDatePick   (void);
Ihandle*  IupCalendar   (void);

/* Old controls, use SPIN attribute of IupText */
Ihandle*  IupSpin       (void);
Ihandle*  IupSpinbox    (Ihandle* child);


/************************************************************************/
/*                      Utilities                                       */
/************************************************************************/

/* String compare utility */
int IupStringCompare(const char* str1, const char* str2, int casesensitive, int lexicographic);

/* IupImage utility */
int IupSaveImageAsText(Ihandle* ih, const char* file_name, const char* format, const char* name);

/* IupText and IupScintilla utilities */
void  IupTextConvertLinColToPos(Ihandle* ih, int lin, int col, int *pos);
void  IupTextConvertPosToLinCol(Ihandle* ih, int pos, int *lin, int *col);

/* IupText, IupList, IupTree, IupMatrix and IupScintilla utility */
int   IupConvertXYToPos(Ihandle* ih, int x, int y);

/* OLD names, kept for backward compatibility, will never be removed. */
void IupStoreGlobal(const char* name, const char* value);
void IupStoreAttribute(Ihandle* ih, const char* name, const char* value);
void IupSetfAttribute(Ihandle* ih, const char* name, const char* format, ...);
void IupStoreAttributeId(Ihandle *ih, const char* name, int id, const char *value);
void IupSetfAttributeId(Ihandle *ih, const char* name, int id, const char* f, ...);
void IupStoreAttributeId2(Ihandle* ih, const char* name, int lin, int col, const char* value);
void IupSetfAttributeId2(Ihandle* ih, const char* name, int lin, int col, const char* format, ...);

/* IupTree utilities */
int   IupTreeSetUserId(Ihandle* ih, int id, void* userid);
void* IupTreeGetUserId(Ihandle* ih, int id);
int   IupTreeGetId(Ihandle* ih, void *userid);
void  IupTreeSetAttributeHandle(Ihandle* ih, const char* name, int id, Ihandle* ih_named);


/************************************************************************/
/*                      Pre-defined dialogs                           */
/************************************************************************/

Ihandle* IupFileDlg(void);
Ihandle* IupMessageDlg(void);
Ihandle* IupColorDlg(void);
Ihandle* IupFontDlg(void);
Ihandle* IupProgressDlg(void);

int  IupGetFile(char *arq);
void IupMessage(const char *title, const char *msg);
void IupMessagef(const char *title, const char *format, ...);
int  IupAlarm(const char *title, const char *msg, const char *b1, const char *b2, const char *b3);
int  IupScanf(const char *format, ...);
int  IupListDialog(int type, const char *title, int size, const char** list,
                   int op, int max_col, int max_lin, int* marks);
int  IupGetText(const char* title, char* text, int maxsize);
int  IupGetColor(int x, int y, unsigned char* r, unsigned char* g, unsigned char* b);

typedef int (*Iparamcb)(Ihandle* dialog, int param_index, void* user_data);
int IupGetParam(const char* title, Iparamcb action, void* user_data, const char* format,...);
int IupGetParamv(const char* title, Iparamcb action, void* user_data, const char* format, int param_count, int param_extra, void** param_data);
Ihandle* IupParam(const char* format);
Ihandle*  IupParamBox(Ihandle* child, ...);
Ihandle*  IupParamBoxv(Ihandle* *children);

Ihandle* IupLayoutDialog(Ihandle* dialog);
Ihandle* IupElementPropertiesDialog(Ihandle* elem);


#ifdef __cplusplus
}
#endif

/************************************************************************/
/*                   Common Flags and Return Values                     */
/************************************************************************/
#define IUP_ERROR     1
#define IUP_NOERROR   0
#define IUP_OPENED   -1
#define IUP_INVALID  -1
#define IUP_INVALID_ID -10


/************************************************************************/
/*                   Callback Return Values                             */
/************************************************************************/
#define IUP_IGNORE    -1
#define IUP_DEFAULT   -2
#define IUP_CLOSE     -3
#define IUP_CONTINUE  -4

/************************************************************************/
/*           IupPopup and IupShowXY Parameter Values                    */
/************************************************************************/
#define IUP_CENTER        0xFFFF  /* 65535 */
#define IUP_LEFT          0xFFFE  /* 65534 */
#define IUP_RIGHT         0xFFFD  /* 65533 */
#define IUP_MOUSEPOS      0xFFFC  /* 65532 */
#define IUP_CURRENT       0xFFFB  /* 65531 */
#define IUP_CENTERPARENT  0xFFFA  /* 65530 */
#define IUP_TOP       IUP_LEFT
#define IUP_BOTTOM    IUP_RIGHT

/************************************************************************/
/*               SHOW_CB Callback Values                                */
/************************************************************************/
enum{IUP_SHOW, IUP_RESTORE, IUP_MINIMIZE, IUP_MAXIMIZE, IUP_HIDE};

/************************************************************************/
/*               SCROLL_CB Callback Values                              */
/************************************************************************/
enum{IUP_SBUP,   IUP_SBDN,    IUP_SBPGUP,   IUP_SBPGDN,    IUP_SBPOSV, IUP_SBDRAGV, 
     IUP_SBLEFT, IUP_SBRIGHT, IUP_SBPGLEFT, IUP_SBPGRIGHT, IUP_SBPOSH, IUP_SBDRAGH};

/************************************************************************/
/*               Mouse Button Values and Macros                         */
/************************************************************************/
#define IUP_BUTTON1   '1'
#define IUP_BUTTON2   '2'
#define IUP_BUTTON3   '3'
#define IUP_BUTTON4   '4'
#define IUP_BUTTON5   '5'

#define iup_isshift(_s)    (_s[0]=='S')
#define iup_iscontrol(_s)  (_s[1]=='C')
#define iup_isbutton1(_s)  (_s[2]=='1')
#define iup_isbutton2(_s)  (_s[3]=='2')
#define iup_isbutton3(_s)  (_s[4]=='3')
#define iup_isdouble(_s)   (_s[5]=='D')
#define iup_isalt(_s)      (_s[6]=='A')
#define iup_issys(_s)      (_s[7]=='Y')
#define iup_isbutton4(_s)  (_s[8]=='4')
#define iup_isbutton5(_s)  (_s[9]=='5')

/* Old definitions for backward compatibility */
#define isshift     iup_isshift
#define iscontrol   iup_iscontrol
#define isbutton1   iup_isbutton1
#define isbutton2   iup_isbutton2
#define isbutton3   iup_isbutton3
#define isdouble    iup_isdouble
#define isalt       iup_isalt
#define issys       iup_issys
#define isbutton4   iup_isbutton4
#define isbutton5   iup_isbutton5


/************************************************************************/
/*                      Pre-Defined Masks                               */
/************************************************************************/
#define IUP_MASK_FLOAT       "[+/-]?(/d+/.?/d*|/./d+)"
#define IUP_MASK_UFLOAT            "(/d+/.?/d*|/./d+)"
#define IUP_MASK_EFLOAT      "[+/-]?(/d+/.?/d*|/./d+)([eE][+/-]?/d+)?"
#define IUP_MASK_FLOATCOMMA  "[+/-]?(/d+/,?/d*|/,/d+)"
#define IUP_MASK_UFLOATCOMMA       "(/d+/,?/d*|/,/d+)"
#define IUP_MASK_INT          "[+/-]?/d+"
#define IUP_MASK_UINT               "/d+"

/* Old definitions for backward compatibility */
#define IUPMASK_FLOAT     IUP_MASK_FLOAT
#define IUPMASK_UFLOAT    IUP_MASK_UFLOAT
#define IUPMASK_EFLOAT    IUP_MASK_EFLOAT
#define IUPMASK_INT	      IUP_MASK_INT
#define IUPMASK_UINT      IUP_MASK_UINT


/************************************************************************/
/*                   IupGetParam Callback situations                    */
/************************************************************************/
#define IUP_GETPARAM_BUTTON1 -1
#define IUP_GETPARAM_INIT    -2
#define IUP_GETPARAM_BUTTON2 -3
#define IUP_GETPARAM_BUTTON3 -4
#define IUP_GETPARAM_CLOSE   -5
#define IUP_GETPARAM_OK     IUP_GETPARAM_BUTTON1
#define IUP_GETPARAM_CANCEL IUP_GETPARAM_BUTTON2
#define IUP_GETPARAM_HELP   IUP_GETPARAM_BUTTON3


/************************************************************************/
/*                   Record Input Modes                                 */
/************************************************************************/
enum {IUP_RECBINARY, IUP_RECTEXT};


/************************************************************************/
/*              Replacement for the WinMain in Windows,                 */
/*        this allows the application to start from "main".             */
/*        Used only for Watcom.                                         */
/************************************************************************/
#if defined (__WATCOMC__)
#ifdef __cplusplus
extern "C" {
int IupMain (int argc, char** argv); /* In C++ we have to declare the prototype */
}
#endif
#define main IupMain /* this is the trick for Watcom and MetroWerks */
#endif

/******************************************************************************
* Copyright (C) 1994-2016 Tecgraf/PUC-Rio.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#endif
#include <poll.h>

int IupLoopPrepare(struct pollfd* fds, int* nfds, int* timeout);
int IupLoopCheck(struct pollfd* fds, int nfds);
void IupLoopDispatch();

/************************************************************************/
/*                Watch Callback Return Values                          */
/************************************************************************/
#define IUP_CONTINUE_WATCH   1
#define IUP_REMOVE_WATCH     0

/**
 * Callback used by IupLoopAddWatch. Functions of this type are called when a watched
 * file descriptor (fd) becomes ready. The `revents` argument contains the events that
 * actually occured, just like the revents field in struct pollfd (of the poll() function).
 */
typedef int (*IWatchCallback)(int fd, short revents);

/**
 * Watches a file descriptor for the specified events (POLLIN, POLLOUT, etc. see poll() man page).
 * In case the event happens the `fd_ready_cb` callback is executed.
 * 
 * Returns an identifier that can be used to remove the watch with the IupLoopRemoveWatch() function.
 */
int IupLoopAddWatch(int fd, short events, IWatchCallback fd_ready_cb);

/**
 * Removes a watch added with IupLoopAddWatch(). The `watch_id` parameter has to be the value returned
 * by the IupLoopAddWatch() function.
 */
void IupLoopRemoveWatch(int watch_id);
/* stb_image - v2.13 - public domain image loader - http://nothings.org/stb_image.h
                                     no warranty implied; use at your own risk

   Do this:
      #define STB_IMAGE_IMPLEMENTATION
   before you include this file in *one* C or C++ file to create the implementation.

   // i.e. it should look like this:
   #include ...
   #include ...
   #include ...
   #define STB_IMAGE_IMPLEMENTATION
   #include "stb_image.h"

   You can #define STBI_ASSERT(x) before the #include to avoid using assert.h.
   And #define STBI_MALLOC, STBI_REALLOC, and STBI_FREE to avoid using malloc,realloc,free


   QUICK NOTES:
      Primarily of interest to game developers and other people who can
          avoid problematic images and only need the trivial interface

      JPEG baseline & progressive (12 bpc/arithmetic not supported, same as stock IJG lib)
      PNG 1/2/4/8-bit-per-channel (16 bpc not supported)

      TGA (not sure what subset, if a subset)
      BMP non-1bpp, non-RLE
      PSD (composited view only, no extra channels, 8/16 bit-per-channel)

      GIF (*comp always reports as 4-channel)
      HDR (radiance rgbE format)
      PIC (Softimage PIC)
      PNM (PPM and PGM binary only)

      Animated GIF still needs a proper API, but here's one way to do it:
          http://gist.github.com/urraka/685d9a6340b26b830d49

      - decode from memory or through FILE (define STBI_NO_STDIO to remove code)
      - decode from arbitrary I/O callbacks
      - SIMD acceleration on x86/x64 (SSE2) and ARM (NEON)

   Full documentation under "DOCUMENTATION" below.


   Revision 2.00 release notes:

      - Progressive JPEG is now supported.

      - PPM and PGM binary formats are now supported, thanks to Ken Miller.

      - x86 platforms now make use of SSE2 SIMD instructions for
        JPEG decoding, and ARM platforms can use NEON SIMD if requested.
        This work was done by Fabian "ryg" Giesen. SSE2 is used by
        default, but NEON must be enabled explicitly; see docs.

        With other JPEG optimizations included in this version, we see
        2x speedup on a JPEG on an x86 machine, and a 1.5x speedup
        on a JPEG on an ARM machine, relative to previous versions of this
        library. The same results will not obtain for all JPGs and for all
        x86/ARM machines. (Note that progressive JPEGs are significantly
        slower to decode than regular JPEGs.) This doesn't mean that this
        is the fastest JPEG decoder in the land; rather, it brings it
        closer to parity with standard libraries. If you want the fastest
        decode, look elsewhere. (See "Philosophy" section of docs below.)

        See final bullet items below for more info on SIMD.

      - Added STBI_MALLOC, STBI_REALLOC, and STBI_FREE macros for replacing
        the memory allocator. Unlike other STBI libraries, these macros don't
        support a context parameter, so if you need to pass a context in to
        the allocator, you'll have to store it in a global or a thread-local
        variable.

      - Split existing STBI_NO_HDR flag into two flags, STBI_NO_HDR and
        STBI_NO_LINEAR.
            STBI_NO_HDR:     suppress implementation of .hdr reader format
            STBI_NO_LINEAR:  suppress high-dynamic-range light-linear float API

      - You can suppress implementation of any of the decoders to reduce
        your code footprint by #defining one or more of the following
        symbols before creating the implementation.

            STBI_NO_JPEG
            STBI_NO_PNG
            STBI_NO_BMP
            STBI_NO_PSD
            STBI_NO_TGA
            STBI_NO_GIF
            STBI_NO_HDR
            STBI_NO_PIC
            STBI_NO_PNM   (.ppm and .pgm)

      - You can request *only* certain decoders and suppress all other ones
        (this will be more forward-compatible, as addition of new decoders
        doesn't require you to disable them explicitly):

            STBI_ONLY_JPEG
            STBI_ONLY_PNG
            STBI_ONLY_BMP
            STBI_ONLY_PSD
            STBI_ONLY_TGA
            STBI_ONLY_GIF
            STBI_ONLY_HDR
            STBI_ONLY_PIC
            STBI_ONLY_PNM   (.ppm and .pgm)

         Note that you can define multiples of these, and you will get all
         of them ("only x" and "only y" is interpreted to mean "only x&y").

       - If you use STBI_NO_PNG (or _ONLY_ without PNG), and you still
         want the zlib decoder to be available, #define STBI_SUPPORT_ZLIB

      - Compilation of all SIMD code can be suppressed with
            #define STBI_NO_SIMD
        It should not be necessary to disable SIMD unless you have issues
        compiling (e.g. using an x86 compiler which doesn't support SSE
        intrinsics or that doesn't support the method used to detect
        SSE2 support at run-time), and even those can be reported as
        bugs so I can refine the built-in compile-time checking to be
        smarter.

      - The old STBI_SIMD system which allowed installing a user-defined
        IDCT etc. has been removed. If you need this, don't upgrade. My
        assumption is that almost nobody was doing this, and those who
        were will find the built-in SIMD more satisfactory anyway.

      - RGB values computed for JPEG images are slightly different from
        previous versions of stb_image. (This is due to using less
        integer precision in SIMD.) The C code has been adjusted so
        that the same RGB values will be computed regardless of whether
        SIMD support is available, so your app should always produce
        consistent results. But these results are slightly different from
        previous versions. (Specifically, about 3% of available YCbCr values
        will compute different RGB results from pre-1.49 versions by +-1;
        most of the deviating values are one smaller in the G channel.)

      - If you must produce consistent results with previous versions of
        stb_image, #define STBI_JPEG_OLD and you will get the same results
        you used to; however, you will not get the SIMD speedups for
        the YCbCr-to-RGB conversion step (although you should still see
        significant JPEG speedup from the other changes).

        Please note that STBI_JPEG_OLD is a temporary feature; it will be
        removed in future versions of the library. It is only intended for
        near-term back-compatibility use.


   Latest revision history:
      2.13  (2016-12-04) experimental 16-bit API, only for PNG so far; fixes
      2.12  (2016-04-02) fix typo in 2.11 PSD fix that caused crashes
      2.11  (2016-04-02) 16-bit PNGS; enable SSE2 in non-gcc x64
                         RGB-format JPEG; remove white matting in PSD;
                         allocate large structures on the stack; 
                         correct channel count for PNG & BMP
      2.10  (2016-01-22) avoid warning introduced in 2.09
      2.09  (2016-01-16) 16-bit TGA; comments in PNM files; STBI_REALLOC_SIZED
      2.08  (2015-09-13) fix to 2.07 cleanup, reading RGB PSD as RGBA
      2.07  (2015-09-13) partial animated GIF support
                         limited 16-bit PSD support
                         minor bugs, code cleanup, and compiler warnings

   See end of file for full revision history.


 ============================    Contributors    =========================

 Image formats                          Extensions, features
    Sean Barrett (jpeg, png, bmp)          Jetro Lauha (stbi_info)
    Nicolas Schulz (hdr, psd)              Martin "SpartanJ" Golini (stbi_info)
    Jonathan Dummer (tga)                  James "moose2000" Brown (iPhone PNG)
    Jean-Marc Lienher (gif)                Ben "Disch" Wenger (io callbacks)
    Tom Seddon (pic)                       Omar Cornut (1/2/4-bit PNG)
    Thatcher Ulrich (psd)                  Nicolas Guillemot (vertical flip)
    Ken Miller (pgm, ppm)                  Richard Mitton (16-bit PSD)
    urraka@github (animated gif)           Junggon Kim (PNM comments)
                                           Daniel Gibson (16-bit TGA)

 Optimizations & bugfixes
    Fabian "ryg" Giesen
    Arseny Kapoulkine

 Bug & warning fixes
    Marc LeBlanc            David Woo          Guillaume George   Martins Mozeiko
    Christpher Lloyd        Martin Golini      Jerry Jansson      Joseph Thomson
    Dave Moore              Roy Eltham         Hayaki Saito       Phil Jordan
    Won Chun                Luke Graham        Johan Duparc       Nathan Reed
    the Horde3D community   Thomas Ruf         Ronny Chevalier    Nick Verigakis
    Janez Zemva             John Bartholomew   Michal Cichon      svdijk@github
    Jonathan Blow           Ken Hamada         Tero Hanninen      Baldur Karlsson
    Laurent Gomila          Cort Stratton      Sergio Gonzalez    romigrou@github
    Aruelien Pocheville     Thibault Reuille   Cass Everitt       Matthew Gregan
    Ryamond Barbiero        Paul Du Bois       Engin Manap        snagar@github
    Michaelangel007@github  Oriol Ferrer Mesia socks-the-fox      Zelex@github
    Philipp Wiesemann       Josh Tobin         rlyeh@github       grim210@github
    Blazej Dariusz Roszkowski                  


LICENSE

This software is dual-licensed to the public domain and under the following
license: you are granted a perpetual, irrevocable license to copy, modify,
publish, and distribute this file as you see fit.

*/

#ifndef STBI_INCLUDE_STB_IMAGE_H
#define STBI_INCLUDE_STB_IMAGE_H

// DOCUMENTATION
//
// Limitations:
//    - no 16-bit-per-channel PNG
//    - no 12-bit-per-channel JPEG
//    - no JPEGs with arithmetic coding
//    - no 1-bit BMP
//    - GIF always returns *comp=4
//
// Basic usage (see HDR discussion below for HDR usage):
//    int x,y,n;
//    unsigned char *data = stbi_load(filename, &x, &y, &n, 0);
//    // ... process data if not NULL ...
//    // ... x = width, y = height, n = # 8-bit components per pixel ...
//    // ... replace '0' with '1'..'4' to force that many components per pixel
//    // ... but 'n' will always be the number that it would have been if you said 0
//    stbi_image_free(data)
//
// Standard parameters:
//    int *x                 -- outputs image width in pixels
//    int *y                 -- outputs image height in pixels
//    int *channels_in_file  -- outputs # of image components in image file
//    int desired_channels   -- if non-zero, # of image components requested in result
//
// The return value from an image loader is an 'unsigned char *' which points
// to the pixel data, or NULL on an allocation failure or if the image is
// corrupt or invalid. The pixel data consists of *y scanlines of *x pixels,
// with each pixel consisting of N interleaved 8-bit components; the first
// pixel pointed to is top-left-most in the image. There is no padding between
// image scanlines or between pixels, regardless of format. The number of
// components N is 'req_comp' if req_comp is non-zero, or *comp otherwise.
// If req_comp is non-zero, *comp has the number of components that _would_
// have been output otherwise. E.g. if you set req_comp to 4, you will always
// get RGBA output, but you can check *comp to see if it's trivially opaque
// because e.g. there were only 3 channels in the source image.
//
// An output image with N components has the following components interleaved
// in this order in each pixel:
//
//     N=#comp     components
//       1           grey
//       2           grey, alpha
//       3           red, green, blue
//       4           red, green, blue, alpha
//
// If image loading fails for any reason, the return value will be NULL,
// and *x, *y, *comp will be unchanged. The function stbi_failure_reason()
// can be queried for an extremely brief, end-user unfriendly explanation
// of why the load failed. Define STBI_NO_FAILURE_STRINGS to avoid
// compiling these strings at all, and STBI_FAILURE_USERMSG to get slightly
// more user-friendly ones.
//
// Paletted PNG, BMP, GIF, and PIC images are automatically depalettized.
//
// ===========================================================================
//
// Philosophy
//
// stb libraries are designed with the following priorities:
//
//    1. easy to use
//    2. easy to maintain
//    3. good performance
//
// Sometimes I let "good performance" creep up in priority over "easy to maintain",
// and for best performance I may provide less-easy-to-use APIs that give higher
// performance, in addition to the easy to use ones. Nevertheless, it's important
// to keep in mind that from the standpoint of you, a client of this library,
// all you care about is #1 and #3, and stb libraries do not emphasize #3 above all.
//
// Some secondary priorities arise directly from the first two, some of which
// make more explicit reasons why performance can't be emphasized.
//
//    - Portable ("ease of use")
//    - Small footprint ("easy to maintain")
//    - No dependencies ("ease of use")
//
// ===========================================================================
//
// I/O callbacks
//
// I/O callbacks allow you to read from arbitrary sources, like packaged
// files or some other source. Data read from callbacks are processed
// through a small internal buffer (currently 128 bytes) to try to reduce
// overhead.
//
// The three functions you must define are "read" (reads some bytes of data),
// "skip" (skips some bytes of data), "eof" (reports if the stream is at the end).
//
// ===========================================================================
//
// SIMD support
//
// The JPEG decoder will try to automatically use SIMD kernels on x86 when
// supported by the compiler. For ARM Neon support, you must explicitly
// request it.
//
// (The old do-it-yourself SIMD API is no longer supported in the current
// code.)
//
// On x86, SSE2 will automatically be used when available based on a run-time
// test; if not, the generic C versions are used as a fall-back. On ARM targets,
// the typical path is to have separate builds for NEON and non-NEON devices
// (at least this is true for iOS and Android). Therefore, the NEON support is
// toggled by a build flag: define STBI_NEON to get NEON loops.
//
// The output of the JPEG decoder is slightly different from versions where
// SIMD support was introduced (that is, for versions before 1.49). The
// difference is only +-1 in the 8-bit RGB channels, and only on a small
// fraction of pixels. You can force the pre-1.49 behavior by defining
// STBI_JPEG_OLD, but this will disable some of the SIMD decoding path
// and hence cost some performance.
//
// If for some reason you do not want to use any of SIMD code, or if
// you have issues compiling it, you can disable it entirely by
// defining STBI_NO_SIMD.
//
// ===========================================================================
//
// HDR image support   (disable by defining STBI_NO_HDR)
//
// stb_image now supports loading HDR images in general, and currently
// the Radiance .HDR file format, although the support is provided
// generically. You can still load any file through the existing interface;
// if you attempt to load an HDR file, it will be automatically remapped to
// LDR, assuming gamma 2.2 and an arbitrary scale factor defaulting to 1;
// both of these constants can be reconfigured through this interface:
//
//     stbi_hdr_to_ldr_gamma(2.2f);
//     stbi_hdr_to_ldr_scale(1.0f);
//
// (note, do not use _inverse_ constants; stbi_image will invert them
// appropriately).
//
// Additionally, there is a new, parallel interface for loading files as
// (linear) floats to preserve the full dynamic range:
//
//    float *data = stbi_loadf(filename, &x, &y, &n, 0);
//
// If you load LDR images through this interface, those images will
// be promoted to floating point values, run through the inverse of
// constants corresponding to the above:
//
//     stbi_ldr_to_hdr_scale(1.0f);
//     stbi_ldr_to_hdr_gamma(2.2f);
//
// Finally, given a filename (or an open file or memory block--see header
// file for details) containing image data, you can query for the "most
// appropriate" interface to use (that is, whether the image is HDR or
// not), using:
//
//     stbi_is_hdr(char *filename);
//
// ===========================================================================
//
// iPhone PNG support:
//
// By default we convert iphone-formatted PNGs back to RGB, even though
// they are internally encoded differently. You can disable this conversion
// by by calling stbi_convert_iphone_png_to_rgb(0), in which case
// you will always just get the native iphone "format" through (which
// is BGR stored in RGB).
//
// Call stbi_set_unpremultiply_on_load(1) as well to force a divide per
// pixel to remove any premultiplied alpha *only* if the image file explicitly
// says there's premultiplied data (currently only happens in iPhone images,
// and only if iPhone convert-to-rgb processing is on).
//


#ifndef STBI_NO_STDIO
#include <stdio.h>
#endif // STBI_NO_STDIO

#define STBI_VERSION 1

enum
{
   STBI_default = 0, // only used for req_comp

   STBI_grey       = 1,
   STBI_grey_alpha = 2,
   STBI_rgb        = 3,
   STBI_rgb_alpha  = 4
};

typedef unsigned char stbi_uc;
typedef unsigned short stbi_us;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef STB_IMAGE_STATIC
#define STBIDEF static
#else
#define STBIDEF extern
#endif

//////////////////////////////////////////////////////////////////////////////
//
// PRIMARY API - works on images of any type
//

//
// load image by filename, open file, or memory buffer
//

typedef struct
{
   int      (*read)  (void *user,char *data,int size);   // fill 'data' with 'size' bytes.  return number of bytes actually read
   void     (*skip)  (void *user,int n);                 // skip the next 'n' bytes, or 'unget' the last -n bytes if negative
   int      (*eof)   (void *user);                       // returns nonzero if we are at end of file/data
} stbi_io_callbacks;

////////////////////////////////////
//
// 8-bits-per-channel interface
//

STBIDEF stbi_uc *stbi_load               (char              const *filename,           int *x, int *y, int *channels_in_file, int desired_channels);
STBIDEF stbi_uc *stbi_load_from_memory   (stbi_uc           const *buffer, int len   , int *x, int *y, int *channels_in_file, int desired_channels);
STBIDEF stbi_uc *stbi_load_from_callbacks(stbi_io_callbacks const *clbk  , void *user, int *x, int *y, int *channels_in_file, int desired_channels);

#ifndef STBI_NO_STDIO
STBIDEF stbi_uc *stbi_load_from_file   (FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
// for stbi_load_from_file, file pointer is left pointing immediately after image
#endif

////////////////////////////////////
//
// 16-bits-per-channel interface
//

STBIDEF stbi_us *stbi_load_16(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
#ifndef STBI_NO_STDIO
STBIDEF stbi_us *stbi_load_from_file_16(FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
#endif
// @TODO the other variants

////////////////////////////////////
//
// float-per-channel interface
//
#ifndef STBI_NO_LINEAR
   STBIDEF float *stbi_loadf                 (char const *filename,           int *x, int *y, int *channels_in_file, int desired_channels);
   STBIDEF float *stbi_loadf_from_memory     (stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
   STBIDEF float *stbi_loadf_from_callbacks  (stbi_io_callbacks const *clbk, void *user, int *x, int *y,  int *channels_in_file, int desired_channels);

   #ifndef STBI_NO_STDIO
   STBIDEF float *stbi_loadf_from_file  (FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
   #endif
#endif

#ifndef STBI_NO_HDR
   STBIDEF void   stbi_hdr_to_ldr_gamma(float gamma);
   STBIDEF void   stbi_hdr_to_ldr_scale(float scale);
#endif // STBI_NO_HDR

#ifndef STBI_NO_LINEAR
   STBIDEF void   stbi_ldr_to_hdr_gamma(float gamma);
   STBIDEF void   stbi_ldr_to_hdr_scale(float scale);
#endif // STBI_NO_LINEAR

// stbi_is_hdr is always defined, but always returns false if STBI_NO_HDR
STBIDEF int    stbi_is_hdr_from_callbacks(stbi_io_callbacks const *clbk, void *user);
STBIDEF int    stbi_is_hdr_from_memory(stbi_uc const *buffer, int len);
#ifndef STBI_NO_STDIO
STBIDEF int      stbi_is_hdr          (char const *filename);
STBIDEF int      stbi_is_hdr_from_file(FILE *f);
#endif // STBI_NO_STDIO


// get a VERY brief reason for failure
// NOT THREADSAFE
STBIDEF const char *stbi_failure_reason  (void);

// free the loaded image -- this is just free()
STBIDEF void     stbi_image_free      (void *retval_from_stbi_load);

// get image dimensions & components without fully decoding
STBIDEF int      stbi_info_from_memory(stbi_uc const *buffer, int len, int *x, int *y, int *comp);
STBIDEF int      stbi_info_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *comp);

#ifndef STBI_NO_STDIO
STBIDEF int      stbi_info            (char const *filename,     int *x, int *y, int *comp);
STBIDEF int      stbi_info_from_file  (FILE *f,                  int *x, int *y, int *comp);

#endif



// for image formats that explicitly notate that they have premultiplied alpha,
// we just return the colors as stored in the file. set this flag to force
// unpremultiplication. results are undefined if the unpremultiply overflow.
STBIDEF void stbi_set_unpremultiply_on_load(int flag_true_if_should_unpremultiply);

// indicate whether we should process iphone images back to canonical format,
// or just pass them through "as-is"
STBIDEF void stbi_convert_iphone_png_to_rgb(int flag_true_if_should_convert);

// flip the image vertically, so the first pixel in the output array is the bottom left
STBIDEF void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);

// ZLIB client - used by PNG, available for other purposes

STBIDEF char *stbi_zlib_decode_malloc_guesssize(const char *buffer, int len, int initial_size, int *outlen);
STBIDEF char *stbi_zlib_decode_malloc_guesssize_headerflag(const char *buffer, int len, int initial_size, int *outlen, int parse_header);
STBIDEF char *stbi_zlib_decode_malloc(const char *buffer, int len, int *outlen);
STBIDEF int   stbi_zlib_decode_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);

STBIDEF char *stbi_zlib_decode_noheader_malloc(const char *buffer, int len, int *outlen);
STBIDEF int   stbi_zlib_decode_noheader_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);


#ifdef __cplusplus
}
#endif

//
//
////   end header file   /////////////////////////////////////////////////////
#endif // STBI_INCLUDE_STB_IMAGE_H
/* stb_image_resize - v0.91 - public domain image resizing
   by Jorge L Rodriguez (@VinoBS) - 2014
   http://github.com/nothings/stb

   Written with emphasis on usability, portability, and efficiency. (No
   SIMD or threads, so it be easily outperformed by libs that use those.)
   Only scaling and translation is supported, no rotations or shears.
   Easy API downsamples w/Mitchell filter, upsamples w/cubic interpolation.

   COMPILING & LINKING
      In one C/C++ file that #includes this file, do this:
         #define STB_IMAGE_RESIZE_IMPLEMENTATION
      before the #include. That will create the implementation in that file.

   QUICKSTART
      stbir_resize_uint8(      input_pixels , in_w , in_h , 0,
                               output_pixels, out_w, out_h, 0, num_channels)
      stbir_resize_float(...)
      stbir_resize_uint8_srgb( input_pixels , in_w , in_h , 0,
                               output_pixels, out_w, out_h, 0,
                               num_channels , alpha_chan  , 0)
      stbir_resize_uint8_srgb_edgemode(
                               input_pixels , in_w , in_h , 0, 
                               output_pixels, out_w, out_h, 0, 
                               num_channels , alpha_chan  , 0, STBIR_EDGE_CLAMP)
                                                            // WRAP/REFLECT/ZERO

   FULL API
      See the "header file" section of the source for API documentation.

   ADDITIONAL DOCUMENTATION

      SRGB & FLOATING POINT REPRESENTATION
         The sRGB functions presume IEEE floating point. If you do not have
         IEEE floating point, define STBIR_NON_IEEE_FLOAT. This will use
         a slower implementation.

      MEMORY ALLOCATION
         The resize functions here perform a single memory allocation using
         malloc. To control the memory allocation, before the #include that
         triggers the implementation, do:

            #define STBIR_MALLOC(size,context) ...
            #define STBIR_FREE(ptr,context)   ...

         Each resize function makes exactly one call to malloc/free, so to use
         temp memory, store the temp memory in the context and return that.

      ASSERT
         Define STBIR_ASSERT(boolval) to override assert() and not use assert.h

      OPTIMIZATION
         Define STBIR_SATURATE_INT to compute clamp values in-range using
         integer operations instead of float operations. This may be faster
         on some platforms.

      DEFAULT FILTERS
         For functions which don't provide explicit control over what filters
         to use, you can change the compile-time defaults with

            #define STBIR_DEFAULT_FILTER_UPSAMPLE     STBIR_FILTER_something
            #define STBIR_DEFAULT_FILTER_DOWNSAMPLE   STBIR_FILTER_something

         See stbir_filter in the header-file section for the list of filters.

      NEW FILTERS
         A number of 1D filter kernels are used. For a list of
         supported filters see the stbir_filter enum. To add a new filter,
         write a filter function and add it to stbir__filter_info_table.

      PROGRESS
         For interactive use with slow resize operations, you can install
         a progress-report callback:

            #define STBIR_PROGRESS_REPORT(val)   some_func(val)

         The parameter val is a float which goes from 0 to 1 as progress is made.

         For example:

            static void my_progress_report(float progress);
            #define STBIR_PROGRESS_REPORT(val) my_progress_report(val)

            #define STB_IMAGE_RESIZE_IMPLEMENTATION
            #include "stb_image_resize.h"

            static void my_progress_report(float progress)
            {
               printf("Progress: %f%%\n", progress*100);
            }

      MAX CHANNELS
         If your image has more than 64 channels, define STBIR_MAX_CHANNELS
         to the max you'll have.

      ALPHA CHANNEL
         Most of the resizing functions provide the ability to control how
         the alpha channel of an image is processed. The important things
         to know about this:

         1. The best mathematically-behaved version of alpha to use is
         called "premultiplied alpha", in which the other color channels
         have had the alpha value multiplied in. If you use premultiplied
         alpha, linear filtering (such as image resampling done by this
         library, or performed in texture units on GPUs) does the "right
         thing". While premultiplied alpha is standard in the movie CGI
         industry, it is still uncommon in the videogame/real-time world.

         If you linearly filter non-premultiplied alpha, strange effects
         occur. (For example, the average of 1% opaque bright green
         and 99% opaque black produces 50% transparent dark green when
         non-premultiplied, whereas premultiplied it produces 50%
         transparent near-black. The former introduces green energy
         that doesn't exist in the source image.)

         2. Artists should not edit premultiplied-alpha images; artists
         want non-premultiplied alpha images. Thus, art tools generally output
         non-premultiplied alpha images.

         3. You will get best results in most cases by converting images
         to premultiplied alpha before processing them mathematically.

         4. If you pass the flag STBIR_FLAG_ALPHA_PREMULTIPLIED, the
         resizer does not do anything special for the alpha channel;
         it is resampled identically to other channels. This produces
         the correct results for premultiplied-alpha images, but produces
         less-than-ideal results for non-premultiplied-alpha images.

         5. If you do not pass the flag STBIR_FLAG_ALPHA_PREMULTIPLIED,
         then the resizer weights the contribution of input pixels
         based on their alpha values, or, equivalently, it multiplies
         the alpha value into the color channels, resamples, then divides
         by the resultant alpha value. Input pixels which have alpha=0 do
         not contribute at all to output pixels unless _all_ of the input
         pixels affecting that output pixel have alpha=0, in which case
         the result for that pixel is the same as it would be without
         STBIR_FLAG_ALPHA_PREMULTIPLIED. However, this is only true for
         input images in integer formats. For input images in float format,
         input pixels with alpha=0 have no effect, and output pixels
         which have alpha=0 will be 0 in all channels. (For float images,
         you can manually achieve the same result by adding a tiny epsilon
         value to the alpha channel of every image, and then subtracting
         or clamping it at the end.)

         6. You can suppress the behavior described in #5 and make
         all-0-alpha pixels have 0 in all channels by #defining
         STBIR_NO_ALPHA_EPSILON.

         7. You can separately control whether the alpha channel is
         interpreted as linear or affected by the colorspace. By default
         it is linear; you almost never want to apply the colorspace.
         (For example, graphics hardware does not apply sRGB conversion
         to the alpha channel.)

   ADDITIONAL CONTRIBUTORS
      Sean Barrett: API design, optimizations
         
   REVISIONS
      0.91 (2016-04-02) fix warnings; fix handling of subpixel regions
      0.90 (2014-09-17) first released version

   LICENSE

     This software is dual-licensed to the public domain and under the following
     license: you are granted a perpetual, irrevocable license to copy, modify,
     publish, and distribute this file as you see fit.

   TODO
      Don't decode all of the image data when only processing a partial tile
      Don't use full-width decode buffers when only processing a partial tile
      When processing wide images, break processing into tiles so data fits in L1 cache
      Installable filters?
      Resize that respects alpha test coverage
         (Reference code: FloatImage::alphaTestCoverage and FloatImage::scaleAlphaToCoverage:
         https://code.google.com/p/nvidia-texture-tools/source/browse/trunk/src/nvimage/FloatImage.cpp )
*/

#ifndef STBIR_INCLUDE_STB_IMAGE_RESIZE_H
#define STBIR_INCLUDE_STB_IMAGE_RESIZE_H

#ifdef _MSC_VER
typedef unsigned char  stbir_uint8;
typedef unsigned short stbir_uint16;
typedef unsigned int   stbir_uint32;
#else
#include <stdint.h>
typedef uint8_t  stbir_uint8;
typedef uint16_t stbir_uint16;
typedef uint32_t stbir_uint32;
#endif

#ifdef STB_IMAGE_RESIZE_STATIC
#define STBIRDEF static
#else
#ifdef __cplusplus
#define STBIRDEF extern "C"
#else
#define STBIRDEF extern
#endif
#endif


//////////////////////////////////////////////////////////////////////////////
//
// Easy-to-use API:
//
//     * "input pixels" points to an array of image data with 'num_channels' channels (e.g. RGB=3, RGBA=4)
//     * input_w is input image width (x-axis), input_h is input image height (y-axis)
//     * stride is the offset between successive rows of image data in memory, in bytes. you can
//       specify 0 to mean packed continuously in memory
//     * alpha channel is treated identically to other channels.
//     * colorspace is linear or sRGB as specified by function name
//     * returned result is 1 for success or 0 in case of an error.
//       #define STBIR_ASSERT() to trigger an assert on parameter validation errors.
//     * Memory required grows approximately linearly with input and output size, but with
//       discontinuities at input_w == output_w and input_h == output_h.
//     * These functions use a "default" resampling filter defined at compile time. To change the filter,
//       you can change the compile-time defaults by #defining STBIR_DEFAULT_FILTER_UPSAMPLE
//       and STBIR_DEFAULT_FILTER_DOWNSAMPLE, or you can use the medium-complexity API.

STBIRDEF int stbir_resize_uint8(     const unsigned char *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                           unsigned char *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                     int num_channels);

STBIRDEF int stbir_resize_float(     const float *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                           float *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                     int num_channels);


// The following functions interpret image data as gamma-corrected sRGB. 
// Specify STBIR_ALPHA_CHANNEL_NONE if you have no alpha channel,
// or otherwise provide the index of the alpha channel. Flags value
// of 0 will probably do the right thing if you're not sure what
// the flags mean.

#define STBIR_ALPHA_CHANNEL_NONE       -1

// Set this flag if your texture has premultiplied alpha. Otherwise, stbir will
// use alpha-weighted resampling (effectively premultiplying, resampling,
// then unpremultiplying).
#define STBIR_FLAG_ALPHA_PREMULTIPLIED    (1 << 0)
// The specified alpha channel should be handled as gamma-corrected value even
// when doing sRGB operations.
#define STBIR_FLAG_ALPHA_USES_COLORSPACE  (1 << 1)

STBIRDEF int stbir_resize_uint8_srgb(const unsigned char *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                           unsigned char *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                     int num_channels, int alpha_channel, int flags);


typedef enum
{
    STBIR_EDGE_CLAMP   = 1,
    STBIR_EDGE_REFLECT = 2,
    STBIR_EDGE_WRAP    = 3,
    STBIR_EDGE_ZERO    = 4,
} stbir_edge;

// This function adds the ability to specify how requests to sample off the edge of the image are handled.
STBIRDEF int stbir_resize_uint8_srgb_edgemode(const unsigned char *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                                    unsigned char *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                              int num_channels, int alpha_channel, int flags,
                                              stbir_edge edge_wrap_mode);

//////////////////////////////////////////////////////////////////////////////
//
// Medium-complexity API
//
// This extends the easy-to-use API as follows:
//
//     * Alpha-channel can be processed separately
//       * If alpha_channel is not STBIR_ALPHA_CHANNEL_NONE
//         * Alpha channel will not be gamma corrected (unless flags&STBIR_FLAG_GAMMA_CORRECT)
//         * Filters will be weighted by alpha channel (unless flags&STBIR_FLAG_ALPHA_PREMULTIPLIED)
//     * Filter can be selected explicitly
//     * uint16 image type
//     * sRGB colorspace available for all types
//     * context parameter for passing to STBIR_MALLOC

typedef enum
{
    STBIR_FILTER_DEFAULT      = 0,  // use same filter type that easy-to-use API chooses
    STBIR_FILTER_BOX          = 1,  // A trapezoid w/1-pixel wide ramps, same result as box for integer scale ratios
    STBIR_FILTER_TRIANGLE     = 2,  // On upsampling, produces same results as bilinear texture filtering
    STBIR_FILTER_CUBICBSPLINE = 3,  // The cubic b-spline (aka Mitchell-Netrevalli with B=1,C=0), gaussian-esque
    STBIR_FILTER_CATMULLROM   = 4,  // An interpolating cubic spline
    STBIR_FILTER_MITCHELL     = 5,  // Mitchell-Netrevalli filter with B=1/3, C=1/3
} stbir_filter;

typedef enum
{
    STBIR_COLORSPACE_LINEAR,
    STBIR_COLORSPACE_SRGB,

    STBIR_MAX_COLORSPACES,
} stbir_colorspace;

// The following functions are all identical except for the type of the image data

STBIRDEF int stbir_resize_uint8_generic( const unsigned char *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                               unsigned char *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                         int num_channels, int alpha_channel, int flags,
                                         stbir_edge edge_wrap_mode, stbir_filter filter, stbir_colorspace space, 
                                         void *alloc_context);

STBIRDEF int stbir_resize_uint16_generic(const stbir_uint16 *input_pixels  , int input_w , int input_h , int input_stride_in_bytes,
                                               stbir_uint16 *output_pixels , int output_w, int output_h, int output_stride_in_bytes,
                                         int num_channels, int alpha_channel, int flags,
                                         stbir_edge edge_wrap_mode, stbir_filter filter, stbir_colorspace space, 
                                         void *alloc_context);

STBIRDEF int stbir_resize_float_generic( const float *input_pixels         , int input_w , int input_h , int input_stride_in_bytes,
                                               float *output_pixels        , int output_w, int output_h, int output_stride_in_bytes,
                                         int num_channels, int alpha_channel, int flags,
                                         stbir_edge edge_wrap_mode, stbir_filter filter, stbir_colorspace space, 
                                         void *alloc_context);



//////////////////////////////////////////////////////////////////////////////
//
// Full-complexity API
//
// This extends the medium API as follows:
//
//       * uint32 image type
//     * not typesafe
//     * separate filter types for each axis
//     * separate edge modes for each axis
//     * can specify scale explicitly for subpixel correctness
//     * can specify image source tile using texture coordinates

typedef enum
{
    STBIR_TYPE_UINT8 ,
    STBIR_TYPE_UINT16,
    STBIR_TYPE_UINT32,
    STBIR_TYPE_FLOAT ,

    STBIR_MAX_TYPES
} stbir_datatype;

STBIRDEF int stbir_resize(         const void *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                         void *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                   stbir_datatype datatype,
                                   int num_channels, int alpha_channel, int flags,
                                   stbir_edge edge_mode_horizontal, stbir_edge edge_mode_vertical, 
                                   stbir_filter filter_horizontal,  stbir_filter filter_vertical,
                                   stbir_colorspace space, void *alloc_context);

STBIRDEF int stbir_resize_subpixel(const void *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                         void *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                   stbir_datatype datatype,
                                   int num_channels, int alpha_channel, int flags,
                                   stbir_edge edge_mode_horizontal, stbir_edge edge_mode_vertical, 
                                   stbir_filter filter_horizontal,  stbir_filter filter_vertical,
                                   stbir_colorspace space, void *alloc_context,
                                   float x_scale, float y_scale,
                                   float x_offset, float y_offset);

STBIRDEF int stbir_resize_region(  const void *input_pixels , int input_w , int input_h , int input_stride_in_bytes,
                                         void *output_pixels, int output_w, int output_h, int output_stride_in_bytes,
                                   stbir_datatype datatype,
                                   int num_channels, int alpha_channel, int flags,
                                   stbir_edge edge_mode_horizontal, stbir_edge edge_mode_vertical, 
                                   stbir_filter filter_horizontal,  stbir_filter filter_vertical,
                                   stbir_colorspace space, void *alloc_context,
                                   float s0, float t0, float s1, float t1);
// (s0, t0) & (s1, t1) are the top-left and bottom right corner (uv addressing style: [0, 1]x[0, 1]) of a region of the input image to use.

//
//
////   end header file   /////////////////////////////////////////////////////
#endif // STBIR_INCLUDE_STB_IMAGE_RESIZE_H
/* stb_image_write - v1.02 - public domain - http://nothings.org/stb/stb_image_write.h
   writes out PNG/BMP/TGA images to C stdio - Sean Barrett 2010-2015
                                     no warranty implied; use at your own risk

   Before #including,

       #define STB_IMAGE_WRITE_IMPLEMENTATION

   in the file that you want to have the implementation.

   Will probably not work correctly with strict-aliasing optimizations.

ABOUT:

   This header file is a library for writing images to C stdio. It could be
   adapted to write to memory or a general streaming interface; let me know.

   The PNG output is not optimal; it is 20-50% larger than the file
   written by a decent optimizing implementation. This library is designed
   for source code compactness and simplicity, not optimal image file size
   or run-time performance.

BUILDING:

   You can #define STBIW_ASSERT(x) before the #include to avoid using assert.h.
   You can #define STBIW_MALLOC(), STBIW_REALLOC(), and STBIW_FREE() to replace
   malloc,realloc,free.
   You can define STBIW_MEMMOVE() to replace memmove()

USAGE:

   There are four functions, one for each image file format:

     int stbi_write_png(char const *filename, int w, int h, int comp, const void *data, int stride_in_bytes);
     int stbi_write_bmp(char const *filename, int w, int h, int comp, const void *data);
     int stbi_write_tga(char const *filename, int w, int h, int comp, const void *data);
     int stbi_write_hdr(char const *filename, int w, int h, int comp, const float *data);

   There are also four equivalent functions that use an arbitrary write function. You are
   expected to open/close your file-equivalent before and after calling these:

     int stbi_write_png_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data, int stride_in_bytes);
     int stbi_write_bmp_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);
     int stbi_write_tga_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);
     int stbi_write_hdr_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const float *data);

   where the callback is:
      void stbi_write_func(void *context, void *data, int size);

   You can define STBI_WRITE_NO_STDIO to disable the file variant of these
   functions, so the library will not use stdio.h at all. However, this will
   also disable HDR writing, because it requires stdio for formatted output.

   Each function returns 0 on failure and non-0 on success.

   The functions create an image file defined by the parameters. The image
   is a rectangle of pixels stored from left-to-right, top-to-bottom.
   Each pixel contains 'comp' channels of data stored interleaved with 8-bits
   per channel, in the following order: 1=Y, 2=YA, 3=RGB, 4=RGBA. (Y is
   monochrome color.) The rectangle is 'w' pixels wide and 'h' pixels tall.
   The *data pointer points to the first byte of the top-left-most pixel.
   For PNG, "stride_in_bytes" is the distance in bytes from the first byte of
   a row of pixels to the first byte of the next row of pixels.

   PNG creates output files with the same number of components as the input.
   The BMP format expands Y to RGB in the file format and does not
   output alpha.

   PNG supports writing rectangles of data even when the bytes storing rows of
   data are not consecutive in memory (e.g. sub-rectangles of a larger image),
   by supplying the stride between the beginning of adjacent rows. The other
   formats do not. (Thus you cannot write a native-format BMP through the BMP
   writer, both because it is in BGR order and because it may have padding
   at the end of the line.)

   HDR expects linear float data. Since the format is always 32-bit rgb(e)
   data, alpha (if provided) is discarded, and for monochrome data it is
   replicated across all three channels.

   TGA supports RLE or non-RLE compressed data. To use non-RLE-compressed
   data, set the global variable 'stbi_write_tga_with_rle' to 0.

CREDITS:

   PNG/BMP/TGA
      Sean Barrett
   HDR
      Baldur Karlsson
   TGA monochrome:
      Jean-Sebastien Guay
   misc enhancements:
      Tim Kelsey
   TGA RLE
      Alan Hickman
   initial file IO callback implementation
      Emmanuel Julien
   bugfixes:
      github:Chribba
      Guillaume Chereau
      github:jry2
      github:romigrou
      Sergio Gonzalez
      Jonas Karlsson
      Filip Wasil
      Thatcher Ulrich
      
LICENSE

This software is dual-licensed to the public domain and under the following
license: you are granted a perpetual, irrevocable license to copy, modify,
publish, and distribute this file as you see fit.

*/

#ifndef INCLUDE_STB_IMAGE_WRITE_H
#define INCLUDE_STB_IMAGE_WRITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef STB_IMAGE_WRITE_STATIC
#define STBIWDEF static
#else
#define STBIWDEF extern
extern int stbi_write_tga_with_rle;
#endif

#ifndef STBI_WRITE_NO_STDIO
STBIWDEF int stbi_write_png(char const *filename, int w, int h, int comp, const void  *data, int stride_in_bytes);
STBIWDEF int stbi_write_bmp(char const *filename, int w, int h, int comp, const void  *data);
STBIWDEF int stbi_write_tga(char const *filename, int w, int h, int comp, const void  *data);
STBIWDEF int stbi_write_hdr(char const *filename, int w, int h, int comp, const float *data);
#endif

typedef void stbi_write_func(void *context, void *data, int size);

STBIWDEF int stbi_write_png_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data, int stride_in_bytes);
STBIWDEF int stbi_write_bmp_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);
STBIWDEF int stbi_write_tga_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);
STBIWDEF int stbi_write_hdr_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const float *data);

#ifdef __cplusplus
}
#endif

#endif//INCLUDE_STB_IMAGE_WRITE_H
