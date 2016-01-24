/***************************************************************************
* File: color_set.h                                                       
*
* Copyright 15/07/2012 UserX <userx.gnu@gmail.com>                             
*
* ENGLISH
*                                                                          
* This program is free software; you can redistribute it and/or modify     
* it under the terms of the GNU General Public License as published by     
* the Free Software Foundation; either version 2 of the License, or        
* (at your option) any later version.                                      
*
* This program is distributed in the hope that it will be useful,          
* but WITHOUT ANY WARRANTY; without even the implied warranty of           
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            
* GNU General Public License for more details.                             
*                                                                        
* You should have received a copy of the GNU General Public License        
* along with this program; if not, write to the Free Software              
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,               
* MA 02110-1301, USA.                                                      
*
*    
* PT-BR
*                                                                      
* Este programa é software livre; Você pode redistribuí-lo e/ou
* modificá-lo sob os termos da Licença Pública Geral do GNU (GPL) como                                                                        
* publicado pela Fundação de Software Livre (Free Software Foundation);
* tanto a versão 2 da Licença, ou (a seu critério) qualquer 
* versão posterior.
*
* Este programa é distribuído com a esperança de que o mesmo será
* útil, mas SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de
* COMERCIALIZAÇÃO ou ADEQUAÇÃO PARA UM PROPÓSITO PARTICULAR. Veja a
* Licença Pública Geral do GNU (GPL) para maiores detalhes.
*
* Você deveria ter recebido uma cópia da Licensa Pública Geral 
* do GNU (GPL) junto com este programa; Se não recebeu, escreva 
* para a Fundação de Software Livre (Free Software Foundation),
* Inc., 51 Rua Franklin, quinto andar, Boston, MA 02110-1301, EUA.
*
*
*
*
*
*

***************************************************************************/

// Terminal color and curses definition ::

#ifndef _COLOR_SET_H_
#define _COLOR_SET_H_

// Text Color ::
#define 	T_NULL	 "\033[0m"
#define 	T_RED	 "\033[1;31m"
#define		T_GREEN	 "\033[1;32m"
#define		T_YELL	 "\033[1;33m"
#define		T_BLUE	 "\033[1;34m"
#define		T_PURPLE "\033[1;35m"
#define		T_CYAN	 "\033[1;36m"
#define		T_WHITE	 "\033[1;37m"
#define		T_BLACK	 "\033[1;30m"	// last one, becouse black is not a true color, I think :: =-D

// Background Color ::
#define         B_RED    "\033[1;41m"
#define         B_GREEN  "\033[1;42m"
#define         B_YELL   "\033[1;43m"
#define         B_BLUE   "\033[1;44m"
#define         B_PURPLE "\033[1;45m"
#define         B_CYAN   "\033[1;46m"
#define         B_WHITE  "\033[1;47m"
#define         B_BLACK  "\033[1;40m"	// Again, black is the last one :: =-D

// Text Styles ::
#define 	NOTHING	 	"\033[1;00m"
#define 	BOLD	 	"\033[1;01m"
#define 	UNDERLINED	"\033[1;04m"
#define 	BLINK		"\033[1;05m"
#define 	REVERS		"\033[1;07m"
#define		OBFUSCATE	"\033[1;08m"

#endif /* _COLOR_SET_H_ */
