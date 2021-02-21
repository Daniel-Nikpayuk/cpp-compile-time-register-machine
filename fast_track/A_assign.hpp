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

// assign [0-15):

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_0>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto r		= at<size_type, Rs...>(U_value_V<i(3)>);

		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_1>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_2>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_3>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_4>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_5>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_6>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_7>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_8>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_9>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_10>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_11>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_12>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_13>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_14>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

	template
	<
		auto d, auto c, auto l, auto m, auto V,
		auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
		auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
	>
	constexpr auto register_machine(void(*)(auto_map<RI::assign_15>*))
	{
		return register_machine
		<
			d-1, c, next_l(c, l, m), next_m(c, l, m),
			R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, V, Rs...

		>(U_value_V<next_c(c, l, m)>);
	}

