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

// replace [0-16):

/***********************************************************************************************************************/

// 0:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(0)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 1:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(1)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(2)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 3:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(3)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 4:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(4)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 5:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(5)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 6:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(6)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 7:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(7)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 8:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(8)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 9:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(9)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 10:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(10)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 11:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(11)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 12:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(12)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 13:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(13)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 14:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(14)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 15:

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<RI::replace, index_type(15)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine
		<
			d-1, c, next_l(d, c, l, m), next_m(d, c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, V, Rs...

		>(U_pair_V<j(1), next_k(c, j)>);
	}

