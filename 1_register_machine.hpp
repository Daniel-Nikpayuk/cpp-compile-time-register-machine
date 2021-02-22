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

// at [0-16):

	#include"subsource/A_at.hpp"

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
		static constexpr size_type l_assign		=  7;
		static constexpr size_type r_assign		=  8;

		static constexpr size_type save			=  9;
		static constexpr size_type restore		= 10;
		static constexpr size_type u_apply		= 11;
		static constexpr size_type b_apply		= 12;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type l_assign_0		= 13;
		static constexpr size_type l_assign_1		= 14;
		static constexpr size_type l_assign_2		= 15;
		static constexpr size_type l_assign_3		= 16;

		static constexpr size_type l_assign_4		= 17;
		static constexpr size_type l_assign_5		= 18;
		static constexpr size_type l_assign_6		= 19;
		static constexpr size_type l_assign_7		= 20;

		static constexpr size_type l_assign_8		= 21;
		static constexpr size_type l_assign_9		= 22;
		static constexpr size_type l_assign_10		= 23;
		static constexpr size_type l_assign_11		= 24;

		static constexpr size_type l_assign_12		= 25;
		static constexpr size_type l_assign_13		= 26;
		static constexpr size_type l_assign_14		= 27;
		static constexpr size_type l_assign_15		= 28;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type r_assign_0		= 29;
		static constexpr size_type r_assign_1		= 30;
		static constexpr size_type r_assign_2		= 31;
		static constexpr size_type r_assign_3		= 32;

		static constexpr size_type r_assign_4		= 33;
		static constexpr size_type r_assign_5		= 34;
		static constexpr size_type r_assign_6		= 35;
		static constexpr size_type r_assign_7		= 36;

		static constexpr size_type r_assign_8		= 37;
		static constexpr size_type r_assign_9		= 38;
		static constexpr size_type r_assign_10		= 39;
		static constexpr size_type r_assign_11		= 40;

		static constexpr size_type r_assign_12		= 41;
		static constexpr size_type r_assign_13		= 42;
		static constexpr size_type r_assign_14		= 43;
		static constexpr size_type r_assign_15		= 44;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type save_0		= 45;
		static constexpr size_type save_1		= 46;
		static constexpr size_type save_2		= 47;
		static constexpr size_type save_3		= 48;

		static constexpr size_type save_4		= 49;
		static constexpr size_type save_5		= 50;
		static constexpr size_type save_6		= 51;
		static constexpr size_type save_7		= 52;

		static constexpr size_type save_8		= 53;
		static constexpr size_type save_9		= 54;
		static constexpr size_type save_10		= 55;
		static constexpr size_type save_11		= 56;

		static constexpr size_type save_12		= 57;
		static constexpr size_type save_13		= 58;
		static constexpr size_type save_14		= 59;
		static constexpr size_type save_15		= 60;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type replace_0		= 61;
		static constexpr size_type replace_1		= 62;
		static constexpr size_type replace_2		= 63;
		static constexpr size_type replace_3		= 64;

		static constexpr size_type replace_4		= 65;
		static constexpr size_type replace_5		= 66;
		static constexpr size_type replace_6		= 67;
		static constexpr size_type replace_7		= 68;

		static constexpr size_type replace_8		= 69;
		static constexpr size_type replace_9		= 70;
		static constexpr size_type replace_10		= 71;
		static constexpr size_type replace_11		= 72;

		static constexpr size_type replace_12		= 73;
		static constexpr size_type replace_13		= 74;
		static constexpr size_type replace_14		= 75;
		static constexpr size_type replace_15		= 76;

		// dispatch optimizations require these to be consecutive:, 

		static constexpr size_type restore_0		= 77;
		static constexpr size_type restore_1		= 78;
		static constexpr size_type restore_2		= 79;
		static constexpr size_type restore_3		= 80;

		static constexpr size_type restore_4		= 81;
		static constexpr size_type restore_5		= 82;
		static constexpr size_type restore_6		= 83;
		static constexpr size_type restore_7		= 84;

		static constexpr size_type restore_8		= 85;
		static constexpr size_type restore_9		= 86;
		static constexpr size_type restore_10		= 87;
		static constexpr size_type restore_11		= 88;

		static constexpr size_type restore_12		= 89;
		static constexpr size_type restore_13		= 90;
		static constexpr size_type restore_14		= 91;
		static constexpr size_type restore_15		= 92;

		static constexpr size_type r_size		= 93;
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

	//

	constexpr size_type reg_size(contr_type c)
	{
		label_type l = c(contr_length(c));

		return l(label_length(l))(2);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller iteration:

	// Assumes the final controller label is the halt instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

/***********************************************************************************************************************/

	template
	<
		auto stop_next   , auto pause_next  , auto branch_next ,
		auto l_goto_next , auto r_goto_next , auto label_next  , auto instr_next
	>
	constexpr auto next(size_type d, contr_type c, size_type l, size_type m, size_type n, bool is_branch)
	{
		if	(!bool(d))			return pause_next   (c, l, m);
		else if	(l == contr_length(c))		return stop_next    (c, l, m);
		else if (is_branch)			return branch_next  (c, l, m);
		else if	(c(l)(m)(1) == RI::l_goto)	return l_goto_next  (c, l, m);
		else if (c(l)(m)(1) == RI::r_goto)	return r_goto_next  (c, n, m);
		else if (m == label_length(c(l)))	return label_next   (c, l, m);
		else					return instr_next   (c, l, m);
	}

/***********************************************************************************************************************/

// next c:

	constexpr instr_type stop_c      (contr_type c, size_type l, size_type m) { return instruction<RI::stop>;  }
	constexpr instr_type pause_c     (contr_type c, size_type l, size_type m) { return instruction<RI::pause>; }
	constexpr instr_type branch_c    (contr_type c, size_type l, size_type m) { return c( c(l)(m)(2) )(1);     }
	constexpr instr_type (*l_goto_c) (contr_type c, size_type l, size_type m) = branch_c                       ;
	constexpr instr_type r_goto_c    (contr_type c, size_type l, size_type m) { return c(l)(1);                }
	constexpr instr_type label_c     (contr_type c, size_type l, size_type m) { return c(l+1)(1);              }
	constexpr instr_type instr_c     (contr_type c, size_type l, size_type m) { return c(l)(m+1);              }

	// dispatch optimization requires RI enum consecutive constraint:

	constexpr size_type next_c(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_br = false)
	{
		instr_type i = next<stop_c, pause_c,
			branch_c, l_goto_c, r_goto_c, label_c, instr_c>(d, c, l, m, n, is_br);

		if (i(1) == RI::l_assign)	return RI::l_assign_0 + i(2);
		else if (i(1) == RI::r_assign)	return RI::r_assign_0 + i(2);
		else if (i(1) == RI::save)	return RI::save_0     + reg_size(c);
		else if (i(1) == RI::restore)	return RI::restore_0  + reg_size(c);
		else				return i(1);
	}

/***********************************************************************************************************************/

// next l:

	constexpr size_type stop_l       (contr_type c, size_type l, size_type m)	{ return l;          }
	constexpr size_type (*pause_l)   (contr_type c, size_type l, size_type m)	= stop_l             ;
	constexpr size_type branch_l     (contr_type c, size_type l, size_type m)	{ return c(l)(m)(2); }
	constexpr size_type (*l_goto_l)  (contr_type c, size_type l, size_type m)	= branch_l           ;
	constexpr size_type (*r_goto_l)  (contr_type c, size_type l, size_type m)	= stop_l             ;
	constexpr size_type label_l      (contr_type c, size_type l, size_type m)	{ return l+1;        }
	constexpr size_type (*instr_l)   (contr_type c, size_type l, size_type m)	= stop_l             ;

	//

	constexpr size_type next_l(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_br = false)
	{
		return next<stop_l, pause_l,
			branch_l, l_goto_l, r_goto_l, label_l, instr_l>(d, c, l, m, n, is_br);
	}

/***********************************************************************************************************************/

// next m:

	constexpr size_type stop_m       (contr_type c, size_type l, size_type m)	{ return m;   }
	constexpr size_type (*pause_m)   (contr_type c, size_type l, size_type m)	= stop_m      ;
	constexpr size_type branch_m     (contr_type c, size_type l, size_type m)	{ return 1;   }
	constexpr size_type (*l_goto_m)  (contr_type c, size_type l, size_type m)	= branch_m    ;
	constexpr size_type (*r_goto_m)  (contr_type c, size_type l, size_type m)	= branch_m    ;
	constexpr size_type (*label_m)   (contr_type c, size_type l, size_type m)	= branch_m    ;
	constexpr size_type instr_m      (contr_type c, size_type l, size_type m)	{ return m+1; }

	//

	constexpr size_type next_m(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_br = false)
	{
		return next<stop_m, pause_m,
			branch_m, l_goto_m, r_goto_m, label_m, instr_m>(d, c, l, m, n, is_br);
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

// machine declarations:

	#include"subsource/B_machine.hpp"

/***********************************************************************************************************************/

// core:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::stop>*))
	{
		return type_map<auto_list<Rs...>*>;
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::pause>*))
	{
		return type_map<alt_list<l, m, Rs...>*>; // temporary for debugging.
	//	return type_map<alt_list<c, l, m, Rs...>*>;
	}

	template<auto d, auto c, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::start>*))
	{
		return machine<d-1, c, 1, 1, Rs...>(U_value_V<c(1)(1)(1)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// branch:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::u_branch>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto test		= at<Rs...>(U_value_V<i(3)>);
		constexpr auto a		= at<Rs...>(U_value_V<i(4)>);
		constexpr bool is_br		= test(a);

		return machine
			<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_value_V<next_c(d, c, l, m, 0, is_br)>);
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::b_branch>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto test		= at<Rs...>(U_value_V<i(3)>);
		constexpr auto a1		= at<Rs...>(U_value_V<i(4)>);
		constexpr auto a2		= at<Rs...>(U_value_V<i(5)>);
		constexpr bool is_br		= test(a1, a2);

		return machine
			<d-1, c, next_l(d, c, l, m, 0, is_br),
				next_m(d, c, l, m, 0, is_br), Rs...>(U_value_V<next_c(d, c, l, m, 0, is_br)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/

// l_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::l_goto>*))
	{
		return machine<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_value_V<next_c(d, c, l, m)>);
	}

/***********************************************************************************************************************/

// r_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::r_goto>*))
	{
		constexpr auto r = at<Rs...>(U_value_V<c(l)(m)(2)>);

		return machine
			<d-1, c, next_l(d, c, l, m, r), next_m(d, c, l, m, r), Rs...>(U_value_V<next_c(d, c, l, m, r)>);
	}

/***********************************************************************************************************************/

// l_assign [0-16):

	#include"subsource/C_l_assign.hpp"

/***********************************************************************************************************************/

// r_assign [0-16):

	#include"subsource/D_r_assign.hpp"

/***********************************************************************************************************************/

// save [0-16):

	#include"subsource/E_save.hpp"

/***********************************************************************************************************************/

// replace [0-16):

		// prerequisite for restore, apply:

	#include"subsource/F_replace.hpp"

/***********************************************************************************************************************/

// restore [0-16):

	#include"subsource/G_restore.hpp"

/***********************************************************************************************************************/

// apply:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::u_apply>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto op		= at<Rs...>(U_value_V<i(3)>);
		constexpr auto a		= at<Rs...>(U_value_V<i(4)>);
		constexpr auto V		= op(a);

		return machine<d-1, c, l, m, V, Rs...>(U_value_V<size_type(RI::replace_0 + i(2))>);
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_map<RI::b_apply>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto op		= at<Rs...>(U_value_V<i(3)>);
		constexpr auto a1		= at<Rs...>(U_value_V<i(4)>);
		constexpr auto a2		= at<Rs...>(U_value_V<i(5)>);
		constexpr auto V		= op(a1, a2);

		return machine<d-1, c, l, m, V, Rs...>(U_value_V<size_type(RI::replace_0 + i(2))>);
	}

/***********************************************************************************************************************/

// fold [2^0-2^9):

//	#include"subsource/H_fold.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

