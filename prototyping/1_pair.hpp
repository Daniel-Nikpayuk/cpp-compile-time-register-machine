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

// pair (experimental):

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	using pair_type = depth_type const *;

	struct MInd
	{
		static constexpr index_type depth	= 0;
		static constexpr index_type index	= 1;
	};

	template<depth_type x, depth_type y>
	constexpr depth_type pair[] = { x, y };

//	template<depth_type x, depth_type y>
//	constexpr pair_type pair = f_array<depth_type, x, y>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

