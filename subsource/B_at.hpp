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

// at [0-16):

/***********************************************************************************************************************/

// 0:

	template
	<
		auto V0, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(0)>*)) { return V0; }

/***********************************************************************************************************************/

// 1:

	template
	<
		auto V0, auto V1, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(1)>*)) { return V1; }

/***********************************************************************************************************************/

// 2:

	template
	<
		auto V0, auto V1, auto V2, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(2)>*)) { return V2; }

/***********************************************************************************************************************/

// 3:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(3)>*)) { return V3; }

/***********************************************************************************************************************/

// 4:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(4)>*)) { return V4; }

/***********************************************************************************************************************/

// 5:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(5)>*)) { return V5; }

/***********************************************************************************************************************/

// 6:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(6)>*)) { return V6; }

/***********************************************************************************************************************/

// 7:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(7)>*)) { return V7; }

/***********************************************************************************************************************/

// 8:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(8)>*)) { return V8; }

/***********************************************************************************************************************/

// 9:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(9)>*)) { return V9; }

/***********************************************************************************************************************/

// 10:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(10)>*)) { return V10; }

/***********************************************************************************************************************/

// 11:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(11)>*)) { return V11; }

/***********************************************************************************************************************/

// 12:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(12)>*)) { return V12; }

/***********************************************************************************************************************/

// 13:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto V13, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(13)>*)) { return V13; }

/***********************************************************************************************************************/

// 14:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto V13, auto V14, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(14)>*)) { return V14; }

/***********************************************************************************************************************/

// 15:

	template
	<
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto V13, auto V14, auto V15, auto... Vs
	>
	constexpr auto at(void(*)(auto_pack<index_type(15)>*)) { return V15; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list at [0-16):

	template<index_type pos, template<auto...> class ListName, auto... Vs>
	constexpr auto list_at(void(*)(ListName<Vs...>*))
	{
		return at<Vs...>(U_value_V<pos>);
	}

