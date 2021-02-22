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

// machine declarations:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// core:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::stop>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::pause>*));

		template<auto d, auto c, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::start>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	// branch:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::u_branch>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::b_branch>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// goto:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::l_goto>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::r_goto>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// l_assign [0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_0>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_1>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_2>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_3>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_4>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_5>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_6>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_7>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_8>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_9>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_10>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_11>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_12>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_13>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_14>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::l_assign_15>*));

/***********************************************************************************************************************/

	// r_assign [0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_0>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_1>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_2>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_3>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_4>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_5>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_6>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_7>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_8>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_9>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_10>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_11>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_12>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_13>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_14>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::r_assign_15>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// save [0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_0>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_1>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_2>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_3>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_4>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_5>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_6>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_7>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_8>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_9>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_10>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_11>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_12>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_13>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_14>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::save_15>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// replace [0-16):

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_0>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_1>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_2>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_3>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_4>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_5>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_6>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_7>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_8>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_9>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_10>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_11>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_12>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_13>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_14>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_map<RI::replace_15>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// restore (0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_1>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_2>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_3>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_4>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_5>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_6>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_7>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_8>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_9>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_10>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_11>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_12>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_13>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_14>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_map<RI::restore_15>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// apply:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::u_apply>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_map<RI::b_apply>*));

