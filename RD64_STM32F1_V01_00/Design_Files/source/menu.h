/** \file menu.h ******************************************************
*
* Project: MAXREFDES64#
* Filename: menu.h
* Description:	This module contains all the functions used to
*								generate the menus and menu options used to run the
*								MAXREFDES64 example firmware.
*
* Revision History:
*\n 10/07/2014 Rev 01.00 MG Initial release.
*\n
*
* --------------------------------------------------------------------
*
* This code follows the following naming conventions:
*
*\n char							ch_pmod_value
*\n char (array)			s_pmod_string[16]
*\n float							f_pmod_value
*\n int								n_pmod_value
*\n int (array)				an_pmod_value[16]
*\n u16								u_pmod_value
*\n u16 (array)				au_pmod_value[16]
*\n u8								uch_pmod_value
*\n u8 (array)				auch_pmod_buffer[16]
*\n unsigned int			un_pmod_value
*\n int *							pun_pmod_value
*
* ------------------------------------------------------------------------- */
/*
* Copyright (C) 2012 Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED PRODUCTS BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated Products
* shall not be used except as stated in the Maxim Integrated Products
* Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products retains all ownership rights.
*
***************************************************************************/

#ifndef MENU_H_
#define MENU_H_

#include "stm32f10x.h"
#include "stdio.h"

#define MAIN_MENU 								0              	//!< // Menu state machine state
#define WAIT_KEYPRESS 						1             	//!< // Menu state machine state
#define CONTINUOUS_READ_MENU 			2								//!< // Menu state machine state
#define SINGLE_READ_MENU					3								//!< // Menu state machine state

#define KEYPRESS_ARROW_UP 240       //!< Assign up-arrow an extended ascii code which won't be used elsewhere
#define KEYPRESS_ARROW_DOWN 241     //!< Assign up-arrow an extended ascii code which won't be used elsewhere
#define KEYPRESS_ARROW_LEFT 242     //!< Assign up-arrow an extended ascii code which won't be used elsewhere
#define KEYPRESS_ARROW_RIGHT 243    //!< Assign up-arrow an extended ascii code which won't be used elsewhere
#define KEYPRESS_END 244            //!< Assign up-arrow an extended ascii code which won't be used elsewhere

// Function Prototypes
void maxim_menu_cls(void);
void maxim_menu_print_maxim_banner(void);
void maxim_menu_print_maxim_banner_big(void);
void maxim_menu_print_prompt(void);
uint8_t maxim_menu_retrieve_keypress(void);
void maxim_menu_print_main_menu(void);
void maxim_menu_print_configuration_description(void);
void maxim_menu_print_output_data_description(void);


#endif /* MENU_H_ */
