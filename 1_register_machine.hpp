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

// register machine:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace register_machine
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	using size_type = unsigned char;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// f array:

	template<typename Type, Type... Vs>
	constexpr Type f_array(size_type pos)
	{
		constexpr Type array[] = { Vs... };

		return array[pos];
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

// register:

		// I would prefer to implement these as enums, but I don't know how
		// to get gcc/clang to pattern match the register machine when I do.

	struct RI
	{
		static constexpr size_type stop			=  0;
		static constexpr size_type pause		=  1;
		static constexpr size_type start		=  2;
		static constexpr size_type u_branch		=  3;

		static constexpr size_type b_branch		=  4;
		static constexpr size_type l_goto		=  5;
		static constexpr size_type r_goto		=  6;
		static constexpr size_type assign		=  7;

		static constexpr size_type save			=  8;
		static constexpr size_type restore		=  9;
		static constexpr size_type u_apply		= 10;
		static constexpr size_type b_apply		= 11;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type assign_0		= 12;
		static constexpr size_type assign_1		= 13;
		static constexpr size_type assign_2		= 14;
		static constexpr size_type assign_3		= 15;

		static constexpr size_type assign_4		= 16;
		static constexpr size_type assign_5		= 17;
		static constexpr size_type assign_6		= 18;
		static constexpr size_type assign_7		= 19;

		static constexpr size_type assign_8		= 20;
		static constexpr size_type assign_9		= 21;
		static constexpr size_type assign_10		= 22;
		static constexpr size_type assign_11		= 23;

		static constexpr size_type assign_12		= 24;
		static constexpr size_type assign_13		= 25;
		static constexpr size_type assign_14		= 26;
		static constexpr size_type assign_15		= 27;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type save_0		= 28;
		static constexpr size_type save_1		= 29;
		static constexpr size_type save_2		= 30;
		static constexpr size_type save_3		= 31;

		static constexpr size_type save_4		= 32;
		static constexpr size_type save_5		= 33;
		static constexpr size_type save_6		= 34;
		static constexpr size_type save_7		= 35;

		static constexpr size_type save_8		= 36;
		static constexpr size_type save_9		= 37;
		static constexpr size_type save_10		= 38;
		static constexpr size_type save_11		= 39;

		static constexpr size_type save_12		= 40;
		static constexpr size_type save_13		= 41;
		static constexpr size_type save_14		= 42;
		static constexpr size_type save_15		= 43;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type replace_0		= 44;
		static constexpr size_type replace_1		= 45;
		static constexpr size_type replace_2		= 46;
		static constexpr size_type replace_3		= 47;

		static constexpr size_type replace_4		= 48;
		static constexpr size_type replace_5		= 49;
		static constexpr size_type replace_6		= 50;
		static constexpr size_type replace_7		= 51;

		static constexpr size_type replace_8		= 52;
		static constexpr size_type replace_9		= 53;
		static constexpr size_type replace_10		= 54;
		static constexpr size_type replace_11		= 55;

		static constexpr size_type replace_12		= 56;
		static constexpr size_type replace_13		= 57;
		static constexpr size_type replace_14		= 58;
		static constexpr size_type replace_15		= 59;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type restore_0		= 60;
		static constexpr size_type restore_1		= 61;
		static constexpr size_type restore_2		= 62;
		static constexpr size_type restore_3		= 63;

		static constexpr size_type restore_4		= 64;
		static constexpr size_type restore_5		= 65;
		static constexpr size_type restore_6		= 66;
		static constexpr size_type restore_7		= 67;

		static constexpr size_type restore_8		= 68;
		static constexpr size_type restore_9		= 69;
		static constexpr size_type restore_10		= 70;
		static constexpr size_type restore_11		= 71;

		static constexpr size_type restore_12		= 72;
		static constexpr size_type restore_13		= 73;
		static constexpr size_type restore_14		= 74;
		static constexpr size_type restore_15		= 75;

		static constexpr size_type r_size		= 76;
	};

/***********************************************************************************************************************/

// instruction:

	using instr_type = size_type(*)(size_type);

		// pack length is stored as the initial value.

	template<size_type... Vs>
	constexpr instr_type instruction = f_array<size_type, sizeof...(Vs), Vs...>;

	constexpr size_type instr_length(instr_type i) { return i(0); }

/***********************************************************************************************************************/

// label:

	using label_type = instr_type(*)(size_type);

		// pack length is stored as the initial value.

	template<instr_type... Vs>
	constexpr label_type label = f_array<instr_type, f_array<size_type, sizeof...(Vs)>, Vs...>;

	constexpr size_type label_length(label_type l) { return l(0)(0); }

/***********************************************************************************************************************/

// controller:

	using contr_type = label_type(*)(size_type);

		// pack length is stored as the initial value.

	template<label_type... Vs>
	constexpr contr_type controller = f_array
		<label_type, f_array<instr_type, f_array<size_type, sizeof...(Vs)>>, Vs...>;

	constexpr size_type contr_length(contr_type c)	{ return c(0)(0)(0); }
	constexpr size_type reg_size(contr_type c)	{ return c(contr_length(c))(1)(2); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller iteration:

	// Assumes the final controller label is the halt instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

/***********************************************************************************************************************/

	template
	<
		auto stop_next   , auto pause_next   , auto branch_next ,
		auto l_goto_next , auto r_goto_next  , auto assign_next ,
		auto save_next   , auto restore_next , auto label_next  , auto instr_next
	>
	constexpr size_type next(size_type d, contr_type c, size_type l, size_type m, size_type n, bool is_branch)
	{
		if	(!bool(d))			return pause_next   (c, l, m);
		else if	(l == contr_length(c))		return stop_next    (c, l, m);
		else if (is_branch)			return branch_next  (c, l, m);
		else if	(c(l)(m)(1) == RI::l_goto)	return l_goto_next  (c, l, m);
		else if (c(l)(m)(1) == RI::r_goto)	return r_goto_next  (c, n, m);
		else if (c(l)(m)(1) == RI::assign)	return assign_next  (c, l, m);
		else if (c(l)(m)(1) == RI::save)	return save_next    (c, l, m);
		else if (c(l)(m)(1) == RI::restore)	return restore_next (c, l, m);
		else if (m == label_length(c(l)))	return label_next   (c, l, m);
		else					return instr_next   (c, l, m);
	}

/***********************************************************************************************************************/

// next c:

	constexpr size_type stop_c      (contr_type c, size_type l, size_type m) { return RI::stop;                    }
	constexpr size_type pause_c     (contr_type c, size_type l, size_type m) { return RI::pause;                   }
	constexpr size_type branch_c    (contr_type c, size_type l, size_type m) { return c( c(l)(m)(2) )(1)(1);       }
	constexpr size_type (*l_goto_c) (contr_type c, size_type l, size_type m) = branch_c                            ;
	constexpr size_type r_goto_c    (contr_type c, size_type l, size_type m) { return c(l)(1)(1);                  }

		// dispatch optimization requires RI enum consecutive constraint:

	constexpr size_type assign_c    (contr_type c, size_type l, size_type m) { return RI::assign_0  + c(l)(m)(2);  }
	constexpr size_type save_c      (contr_type c, size_type l, size_type m) { return RI::save_0    + reg_size(c); }
	constexpr size_type restore_c   (contr_type c, size_type l, size_type m) { return RI::restore_0 + reg_size(c); }

	constexpr size_type label_c     (contr_type c, size_type l, size_type m) { return c(l+1)(1)(1);                }
	constexpr size_type instr_c     (contr_type c, size_type l, size_type m) { return c(l)(m+1)(1);                }

	//

	constexpr size_type next_c(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_br = false)
	{
		return next
		<
			stop_c, pause_c, branch_c, l_goto_c, r_goto_c,
			assign_c, save_c, restore_c, label_c, instr_c

		>(d, c, l, m, n, is_br);
	}

/***********************************************************************************************************************/

// next l:

	constexpr size_type stop_l       (contr_type c, size_type l, size_type m)	{ return l;          }
	constexpr size_type (*pause_l)   (contr_type c, size_type l, size_type m)	= stop_l             ;
	constexpr size_type branch_l     (contr_type c, size_type l, size_type m)	{ return c(l)(m)(2); }
	constexpr size_type (*l_goto_l)  (contr_type c, size_type l, size_type m)	= branch_l           ;
	constexpr size_type (*r_goto_l)  (contr_type c, size_type l, size_type m)	= stop_l             ;
	constexpr size_type (*assign_l)  (contr_type c, size_type l, size_type m)	= stop_l             ;
	constexpr size_type (*save_l)    (contr_type c, size_type l, size_type m)	= stop_l             ;
	constexpr size_type (*restore_l) (contr_type c, size_type l, size_type m)	= stop_l             ;
	constexpr size_type label_l      (contr_type c, size_type l, size_type m)	{ return l+1;        }
	constexpr size_type (*instr_l)   (contr_type c, size_type l, size_type m)	= stop_l             ;

	//

	constexpr size_type next_l(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_br = false)
	{
		return next
		<
			stop_l, pause_l, branch_l, l_goto_l, r_goto_l,
			assign_l, save_l, restore_l, label_l, instr_l

		>(d, c, l, m, n, is_br);
	}

/***********************************************************************************************************************/

// next m:

	constexpr size_type stop_m       (contr_type c, size_type l, size_type m)	{ return m;   }
	constexpr size_type (*pause_m)   (contr_type c, size_type l, size_type m)	= stop_m      ;
	constexpr size_type branch_m     (contr_type c, size_type l, size_type m)	{ return 1;   }
	constexpr size_type (*l_goto_m)  (contr_type c, size_type l, size_type m)	= branch_m    ;
	constexpr size_type (*r_goto_m)  (contr_type c, size_type l, size_type m)	= branch_m    ;
	constexpr size_type (*assign_m)  (contr_type c, size_type l, size_type m)	= stop_m      ;
	constexpr size_type (*save_m)    (contr_type c, size_type l, size_type m)	= stop_m      ;
	constexpr size_type (*restore_m) (contr_type c, size_type l, size_type m)	= stop_m      ;
	constexpr size_type (*label_m)   (contr_type c, size_type l, size_type m)	= branch_m    ;
	constexpr size_type instr_m      (contr_type c, size_type l, size_type m)	{ return m+1; }

	//

	constexpr size_type next_m(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_br = false)
	{
		return next
		<
			stop_m, pause_m, branch_m, l_goto_m, r_goto_m,
			assign_m, save_m, restore_m, label_m, instr_m

		>(d, c, l, m, n, is_br);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register machine:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - control
	// l  - label index
	// m  - instruction index
	// Rs - registers

/***********************************************************************************************************************/

// declarations:

	// core:

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::stop>*));

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::pause>*));

			template<auto d, auto c, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::start>*));

	// predicates:

		// branch:

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::u_branch>*));

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::b_branch>*));

	// operators:

		// goto:

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::l_goto>*));

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::r_goto>*));

		// assign [0-16):

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_0>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_1>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_2>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_3>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_4>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_5>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_6>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_7>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_8>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_9>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_10>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_11>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_12>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_13>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_14>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::assign_15>*));

		// save [0-16):

			template
			<
				auto d, auto c, auto l, auto m,
				auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_0>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_1>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_2>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_3>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_4>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_5>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_6>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_7>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_8>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_9>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_10>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_11>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_12>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_13>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_14>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::save_15>*));

		// replace [0-16):

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_0>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_1>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_2>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_3>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_4>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_5>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_6>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_7>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_8>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_9>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_10>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_11>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_12>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_13>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_14>*));

			template
			<
				auto d, auto c, auto l, auto m, auto V,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto R15, auto... Rs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::replace_15>*));

		// restore (0-16):

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_1>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_2>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_3>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_4>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_5>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_6>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_7>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_8>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_9>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_10>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_11>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_12>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_13>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_14>*));

			template
			<
				auto d, auto c, auto l, auto m,
				auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7,
				auto R8, auto R9, auto R10, auto R11, auto R12, auto R13, auto R14, auto V, auto... Vs
			>
			constexpr auto register_machine(void(*)(auto_map<RI::restore_15>*));

		// apply:

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::u_apply>*));

			template<auto d, auto c, auto l, auto m, auto... Rs>
			constexpr auto register_machine(void(*)(auto_map<RI::b_apply>*));

/***********************************************************************************************************************/

// core:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::stop>*))
	{
		return type_map<auto_list<Rs...>>;
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::pause>*))
	{
		return type_map<alt_list<c, l, m, Rs...>>;
	}

	template<auto d, auto c, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::start>*))
	{
		constexpr size_type one = 1;

		return register_machine<d-1, c, one, one, Rs...>(U_value_V<c(1)(1)(1)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// branch:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::u_branch>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto test		= at<size_type, Rs...>(U_value_V<i(3)>);
		constexpr auto a		= at<size_type, Rs...>(U_value_V<i(4)>);
		constexpr bool is_br		= test(a);

		return register_machine
			<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_value_V<next_c(d, c, l, m, 0, is_br)>);
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::b_branch>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto test		= at<size_type, Rs...>(U_value_V<i(3)>);
		constexpr auto a1		= at<size_type, Rs...>(U_value_V<i(4)>);
		constexpr auto a2		= at<size_type, Rs...>(U_value_V<i(5)>);
		constexpr bool is_br		= test(a1, a2);

		return register_machine
			<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_value_V<next_c(d, c, l, m, 0, is_br)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/

// l_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::l_goto>*))
	{
		return register_machine<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_value_V<next_c(d, c, l, m)>);
	}

/***********************************************************************************************************************/

// r_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::r_goto>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto r		= at<size_type, Rs...>(U_value_V<i(2)>);

		return register_machine
			<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_value_V<next_c(d, c, l, m, r)>);
	}

/***********************************************************************************************************************/

// assign [0-16):

	#include"fast_track/A_assign.hpp"

/***********************************************************************************************************************/

// save [0-16):

	#include"fast_track/B_save.hpp"

/***********************************************************************************************************************/

// replace [0-16):

		// prerequisite for restore, apply:

	#include"fast_track/C_replace.hpp"

/***********************************************************************************************************************/

// restore [0-16):

	#include"fast_track/D_restore.hpp"

/***********************************************************************************************************************/

// apply:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::u_apply>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto op		= at<size_type, Rs...>(U_value_V<i(3)>);
		constexpr auto a		= at<size_type, Rs...>(U_value_V<i(4)>);
		constexpr bool V		= op(a);

		return register_machine<d-1, c, l, m, V, Rs...>(U_value_V<RI::replace_0 + c(l)(m)(2)>);
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::b_apply>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto op		= at<size_type, Rs...>(U_value_V<i(3)>);
		constexpr auto a1		= at<size_type, Rs...>(U_value_V<i(4)>);
		constexpr auto a2		= at<size_type, Rs...>(U_value_V<i(5)>);
		constexpr bool V		= op(a1, a2);

		return register_machine<d-1, c, l, m, V, Rs...>(U_value_V<RI::replace_0 + c(l)(m)(2)>);
	}

/***********************************************************************************************************************/

// fold [2^0-2^9):

//	#include"fast_track/E_fold.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

