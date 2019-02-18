/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:06:15 by vkryvono          #+#    #+#             */
/*   Updated: 2018/08/17 13:47:44 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

/*
** Macros for mlx_hook function
*/

# define NOEVENTMASK 0L
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)
# define ENTERWINDOWMASK (1L<<4)
# define LEAVEWINDOWMASK (1L<<5)
# define POINTERMOTIONMASK (1L<<6)
# define POINTERMOTIONHINTMASK (1L<<7)
# define BUTTON1MOTIONMASK (1L<<8)
# define BUTTON2MOTIONMASK (1L<<9)
# define BUTTON3MOTIONMASK (1L<<10)
# define BUTTON4MOTIONMASK (1L<<11)
# define BUTTON5MOTIONMASK (1L<<12)
# define BUTTONMOTIONMASK (1L<<13)
# define KEYMAPSTATEMASK (1L<<14)
# define EXPOSUREMASK (1L<<15)
# define VISIBILITYCHANGEMASK (1L<<16)
# define STRUCTURENOTIFYMASK (1L<<17)
# define RESIZEREDIRECTMASK (1L<<18)
# define SUBSTRUCTURENOTIFYMASK (1L<<19)
# define SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define FOCUSCHANGEMASK (1L<<21)
# define PROPERTYCHANGEMASK (1L<<22)
# define COLORMAPCHANGEMASK (1L<<23)
# define OWNERGRABBUTTONMASK (1L<<24)

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24

/*
** Mouse button keycodes
*/

# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7

/*
** Keyboard keys
*/

# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define NUM_KEY_0		82
# define NUM_KEY_1		83
# define NUM_KEY_2		84
# define NUM_KEY_3		85
# define NUM_KEY_4		86
# define NUM_KEY_5		87
# define NUM_KEY_6		88
# define NUM_KEY_7		89
# define NUM_KEY_8		91
# define NUM_KEY_9		92
# define NUM_KEY_PLUS	69
# define NUM_KEY_MINUS	78

# define KEY_ESC		53

# define KEY_A			0
# define KEY_B			11
# define KEY_C			8
# define KEY_D			2
# define KEY_E			14
# define KEY_F			3
# define KEY_G			5
# define KEY_H			4
# define KEY_I			34
# define KEY_J			38
# define KEY_K			40
# define KEY_L			37
# define KEY_M			46
# define KEY_N			45
# define KEY_O			31
# define KEY_P			35
# define KEY_Q			12
# define KEY_R			15
# define KEY_S			1
# define KEY_T			17
# define KEY_U			32
# define KEY_V			9
# define KEY_W			13
# define KEY_X			7
# define KEY_Y			16
# define KEY_Z			6

# define KEY_0			29
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_5			23
# define KEY_6			22
# define KEY_7			26
# define KEY_8			28
# define KEY_9			25
# define KEY_PLUS		24
# define KEY_MINUS		27
# define KEY_LESS		43
# define KEY_MORE		47

/*
** Functions keys, you might use fn key to use them
** I didn't find the F11_KEY value
*/

# define F1_KEY 122
# define F2_KEY 120
# define F3_KEY 99
# define F4_KEY 118
# define F5_KEY 96
# define F6_KEY 97
# define F7_KEY 98
# define F8_KEY 100
# define F9_KEY 101
# define F10_KEY 109
# define F11_KEY
# define F12_KEY 111
# define F13_KEY 105
# define F14_KEY 107
# define F15_KEY 113
# define F16_KEY 106
# define F17_KEY 64
# define F18_KEY 79
# define F19_KEY 80

/*
** Special keys
** CL_KEY is the caps lock key
** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
** LOPT_KEY and ROPT_KEY are the left option and right option keys
** LCMD_KEY and RCMD_KEY are the left command and right command keys
** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
** RTN_KEY is the return key
** EJ_KEY is the eject key and doesn't react
** PUP_KEY and PDOWN_KEY are the page up and page down keys
** CLR_KEY is the clear key
*/

# define ESC_KEY 53
# define TAB_KEY 48
# define CL_KEY 272
# define LSFT_KEY 257
# define LCTRL_KEY 256
# define LOPT_KEY 261
# define LCMD_KEY 259
# define LDEL_KEY 51
# define RTN_KEY 36
# define RSFT_KEY 258
# define RCTRL_KEY 269
# define ROPT_KEY 262
# define RCMD_KEY 260
# define EJ_KEY
# define FN_KEY 279
# define RDEL_KEY 117
# define HOME_KEY 115
# define END_KEY 119
# define PUP_KEY 116
# define PDOWN_KEY 121
# define CLR_KEY 71

/*
** Special characters
** SP_KEY is the space ( ) key
** BQ_KEY is the back quote (`) and tilde (~) key
** MN_KEY is the minus (-) and underscore (_) key
** PL_KEY is the plus (+) and equal (=) key
** SBO_KEY is the square bracket opening ([) and brace opening ({) key
** SBC_KEY is the square bracket closing (]) and brace closing (}) key
** BSL_KEY is the backslash (\) and pipe (|) key
** SC_KEY is the semicolon (;) and colon (:) key
** SQ_KEY is the simple quote (') and double quote (") key
** CM_KEY is the comma (,) and angle bracket opening (<) key
** PT_KEY is the point (.) and angle bracket closing (>) key
** SL_KEY is the slash (/) and question mark (?) key
*/

# define SP_KEY 49
# define BQ_KEY 50
# define MN_KEY 27
# define PL_KEY 24
# define SBO_KEY 33
# define SBC_KEY 30
# define BSL_KEY 42
# define SC_KEY 41
# define SQ_KEY 39
# define CM_KEY 43
# define PT_KEY 47
# define SL_KEY 44

#endif
