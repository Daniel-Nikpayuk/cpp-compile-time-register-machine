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

// instruction declarations:

		// I would prefer to implement these as enums, but I don't know how
		// to get gcc/clang to pattern match the register machine when I do.

	struct RI
	{
		static constexpr index_type stop		=  0;
		static constexpr index_type pause		=  1;
		static constexpr index_type start		=  2;
		static constexpr index_type u_branch		=  3;

		static constexpr index_type b_branch		=  4;
		static constexpr index_type l_goto		=  5;
		static constexpr index_type r_goto		=  6;
		static constexpr index_type l_assign		=  7;
		static constexpr index_type r_assign		=  8;

		static constexpr index_type save		=  9;
		static constexpr index_type replace		= 10;
		static constexpr index_type restore		= 11;
		static constexpr index_type u_apply		= 12;
		static constexpr index_type b_apply		= 13;

		static constexpr index_type r_size		= 14;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine declarations:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// core:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_pair<RI::stop, index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_pair<RI::pause, index_type(0)>*));

		template<auto d, auto c, auto... Rs>
		constexpr auto machine(void(*)(auto_pair<RI::start, index_type(0)>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	// branch:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_pair<RI::u_branch, index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_pair<RI::b_branch, index_type(0)>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// goto:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_pair<RI::l_goto, index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto machine(void(*)(auto_pair<RI::r_goto, index_type(0)>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// l_assign [0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(0)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(1)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(2)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(3)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(4)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(5)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(6)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(7)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(8)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(9)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(10)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(11)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(12)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(13)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(14)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::l_assign, index_type(15)>*));

/***********************************************************************************************************************/

	// r_assign [0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(0)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(1)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(2)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(3)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(4)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(5)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(6)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(7)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(8)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(9)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(10)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(11)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(12)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(13)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(14)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::r_assign, index_type(15)>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// save [0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(0)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(1)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(2)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(3)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(4)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(5)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(6)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(7)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(8)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(9)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(10)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(11)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(12)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(13)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(14)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::save, index_type(15)>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// replace [0-16):

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(0)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(1)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(2)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(3)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(4)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(5)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(6)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(7)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(8)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(9)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(10)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(11)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(12)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(13)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(14)>*));

		template
		<
			auto d, auto c, auto l, auto m, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::replace, index_type(15)>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// restore (0-16):

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(1)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(2)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(3)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(4)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(5)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(6)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(7)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(8)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(9)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(10)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(11)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(12)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(13)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(14)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto V, auto... Vs
		>
		constexpr auto machine(void(*)(auto_pair<RI::restore, index_type(15)>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// u_apply:

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(0)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(1)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(2)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(3)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(4)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(5)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(6)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(7)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(8)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(9)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(10)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(11)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(12)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(13)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(14)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::u_apply, index_type(15)>*));

	// b_apply:

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(0)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(1)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(2)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(3)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(4)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(5)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(6)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(7)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(8)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(9)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(10)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(11)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(12)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(13)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(14)>*));

		template
		<
			auto d, auto c, auto l, auto m,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
			auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
		>
		constexpr auto machine(void(*)(auto_pair<RI::b_apply, index_type(15)>*));

