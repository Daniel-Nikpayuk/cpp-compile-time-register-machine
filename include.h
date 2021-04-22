/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of cpp_near_linear_function_space.
**
** cpp_near_linear_function_space is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** cpp_near_linear_function_space is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with cpp_near_linear_function_space.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#ifndef INCLUDE_H
#define INCLUDE_H

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// meta programming:

	#include"0_meta_programming.hpp"

/***********************************************************************************************************************/

// machine-space:

	#include"1_machine_declarations.hpp"

	#include"define_macros.hpp"

		#include"2_block_machines.hpp"
		#include"3_variadic_machines.hpp"
		#include"4_permutatic_machines.hpp"
		#include"5_distributic_machines.hpp"
		#include"6_near_linear_machines.hpp"
		#include"7_register_machines.hpp"

	#include"undef_macros.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

