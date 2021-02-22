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

// restore (0-16):

/***********************************************************************************************************************/

// 0:

	// doesn't exist.

/***********************************************************************************************************************/

// 1:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_1>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 2:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_2>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 3:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_3>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 4:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_4>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 5:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_5>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 6:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_6>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 7:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_7>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 8:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_8>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 9:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_9>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, R8, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 10:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_10>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 11:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_11>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 12:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_12>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 13:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_13>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 14:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_14>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

/***********************************************************************************************************************/

// 15:

	template
	<
		auto d, auto c, auto l, auto m,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto V, auto... Vs
	>
	constexpr auto machine(void(*)(auto_map<RI::restore_15>*))
	{
		return machine
		<
			d-1, c, l, m,
			V, R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, Vs...

		>(U_value_V<size_type(RI::replace_0 + c(l)(m)(2))>);
	}

