/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of cpp_compile_time_register_machine.
**
** cpp_compile_time_register_machine is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** cpp_compile_time_register_machine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with cpp_compile_time_register_machine.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#ifndef _9_FUNCTION_TYPE_HPP
#define _9_FUNCTION_TYPE_HPP

// function type:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace function_space
{
	using namespace machine_space;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out type:

	template<typename OutType, typename... InTypes>
	constexpr auto f_out_type(OutType(*f)(InTypes...))
	{
		return U_type_T<OutType>;
	}

	template<auto f>
	using out_type = T_type_U<f_out_type(f)>;

/***********************************************************************************************************************/

// in type:

	template<auto depth, auto pos, typename OutType, typename... InTypes>
	constexpr auto f_in_type(OutType(*f)(InTypes...))
	{
		return pack_at<depth, pos, U_type_T<InTypes>...>;
	}

	template<auto f, depth_type pos = 0, depth_type depth = 500>
	using in_type = T_type_U<f_in_type<depth, pos>(f)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

