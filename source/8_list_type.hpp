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

#ifndef _8_LIST_TYPE_HPP
#define _8_LIST_TYPE_HPP

// list type:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace list_space
{
	using namespace machine_space;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine methods:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list at:

	template<depth_type d, depth_type pos, template<auto...> class ListName, auto... Vs>
	constexpr auto f_list_at(void(*)(ListName<Vs...>*))
	{
		return pack_at<d, pos, Vs...>;
	}

	template<typename List, depth_type pos, depth_type depth = 500>
	constexpr auto list_at = f_list_at<depth, pos>(U_type_T<List>);

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

