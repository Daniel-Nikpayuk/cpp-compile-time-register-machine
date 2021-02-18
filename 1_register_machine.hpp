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

	struct RI
	{
		enum : size_type { assign = 0, test, l_branch, r_branch, l_goto, r_goto, save, restore };
		enum : size_type
		{
			apply = restore + 1	,

			apply_2_0 = restore + 1	, apply_2_1	, apply_2_2	, apply_2_3	,
			apply_2_4		, apply_2_5	, apply_2_6	, apply_2_7	, apply_2_8
		};
	};

/***********************************************************************************************************************/

// template:

	struct TI
	{
		enum : size_type
		{
			stop = 0	, start		, pause		,

			replace_0	, replace_1	, replace_2	, replace_3	,
			replace_4	, replace_5	, replace_6	, replace_7	,

			dimension
		};
	};

/***********************************************************************************************************************/

// instruction:

	using instruction_type = size_type(*)(size_type);

		// pack length is stored as the initial value.

	template<size_type... Vs>
	constexpr instruction_type instruction = f_array<size_type, sizeof...(Vs), Vs...>;

	constexpr size_type instruction_length(instruction_type i) { return i(0); }

/***********************************************************************************************************************/

// label:

	using label_type = instruction_type(*)(size_type);

		// pack length is stored as the initial value.

	template<instruction_type... Vs>
	constexpr label_type label = f_array<instruction_type, f_array<size_type, sizeof...(Vs)>, Vs...>;

	constexpr size_type label_length(label_type l) { return l(0)(0); }

/***********************************************************************************************************************/

// controller:

	using controller_type = label_type(*)(size_type);

		// pack length is stored as the initial value.

	template<label_type... Vs>
	constexpr controller_type controller = f_array
		<label_type, f_array<instruction_type, f_array<size_type, sizeof...(Vs)>>, Vs...>;

	constexpr size_type controller_length(controller_type c) { return c(0)(0)(0); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// iterators:

		// assumes the final controller label is the halt instruction.

/***********************************************************************************************************************/

/*
	template
	<
		auto pause_next, auto stop_next,
		auto lgoto_next, auto rgoto_next,
		auto lbranch_next, auto rbranch_next,
		auto label_next, auto instr_next
	>
	constexpr size_type next(size_type d, controller_type c, size_type m, size_type n, bool branch = false)
	{
		bool d_break		= !bool(d);
		bool c_break		= !d_break && (m == controller_length(c));
		bool m_break		= !d_break && !c_break && (n == label_length(c(m)));
		bool is_l_branch	= !d_break && !c_break && !m_break && (c(m)(n)(1) == RI::l_goto);
		bool is_r_branch	= !d_break && !c_break && !m_break && (c(m)(n)(1) == RI::r_goto);
		bool is_l_goto		= !d_break && !c_break && !m_break && (c(m)(n)(1) == RI::l_goto);
		bool is_r_goto		= !d_break && !c_break && !m_break && (c(m)(n)(1) == RI::r_goto);

		return (d_break ? pause_next			:
			c_break ? stop_next			:
			m_break ?

				(is_l_branch ? l_branch_next	:
				 is_r_branch ? r_branch_next	:
				 is_l_goto   ? l_goto_next	:
				 is_r_goto   ? r_goto_next	:
					       label_next)	:

				(is_l_branch ? l_branch_next	:
				 is_r_branch ? r_branch_next	:
				 is_l_goto   ? l_goto_next	:
				 is_r_goto   ? r_goto_next	:
					       instr_next))	(c, m, n);
	}
*/

/***********************************************************************************************************************/

// next c:

/*
	constexpr size_type pn_c(controller_type c, size_type m, size_type n)	{ return TI::pause;		}
	constexpr size_type sn_c(controller_type c, size_type m, size_type n)	{ return TI::stop;		}
	constexpr size_type gn_c(controller_type c, size_type m, size_type n)	{ return c( c(m)(n)(1) )(1)(1);	}
	constexpr size_type bn_c(controller_type c, size_type m, size_type n)	{ return c( c(m)(n)(5) )(1)(1);	}
	constexpr size_type ln_c(controller_type c, size_type m, size_type n)	{ return c(m+1)(1)(1);		}
	constexpr size_type in_c(controller_type c, size_type m, size_type n)	{ return c(m)(n+1)(1);		}

	constexpr size_type (*next_c)(size_type, controller_type, size_type, size_type, bool)	= next
		<pn_c, sn_c, gn_c, bn_c, ln_c, in_c>;
*/

/***********************************************************************************************************************/

// next m:

/*
	constexpr size_type pn_m(controller_type c, size_type m, size_type n)	{ return m;		}
	constexpr size_type sn_m(controller_type c, size_type m, size_type n)	{ return m;		}
	constexpr size_type gn_m(controller_type c, size_type m, size_type n)	{ return c(m)(n)(1);	}
	constexpr size_type bn_m(controller_type c, size_type m, size_type n)	{ return c(m)(n)(5);	}
	constexpr size_type ln_m(controller_type c, size_type m, size_type n)	{ return m+1;		}
	constexpr size_type in_m(controller_type c, size_type m, size_type n)	{ return m;		}

	constexpr size_type (*next_m)(size_type, controller_type, size_type, size_type, bool)	= next
		<pn_m, sn_m, gn_m, bn_m, ln_m, in_m>;
*/

/***********************************************************************************************************************/

// next n:

/*
	constexpr size_type pn_n(controller_type c, size_type m, size_type n)	{ return n; }
	constexpr size_type sn_n(controller_type c, size_type m, size_type n)	{ return n; }
	constexpr size_type gn_n(controller_type c, size_type m, size_type n)	{ return 1; }
	constexpr size_type bn_n(controller_type c, size_type m, size_type n)	{ return 1; }
	constexpr size_type ln_n(controller_type c, size_type m, size_type n)	{ return 1; }
	constexpr size_type in_n(controller_type c, size_type m, size_type n)	{ return n+1; }

	constexpr size_type (*next_n)(size_type, controller_type, size_type, size_type, bool)	= next
		<pn_n, sn_n, gn_n, bn_n, ln_n, in_n>;
*/

/***********************************************************************************************************************/

// instruction accessors:

/*
	constexpr size_type rm_replace(control_type control, size_type m, size_type n)
	{
		return control(label)(index)(1);
	}

	template<control_type control, size_type m, size_type n>
	using rm_op = T_type_U<control(label)(index)(0)>;

	template<control_type control, size_type m, size_type n>
	constexpr size_type rm_arg1 = control(label)(index)(1);

	template<control_type control, size_type m, size_type n>
	constexpr size_type rm_arg1 = control(label)(index)(2);
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register machine:

/***********************************************************************************************************************/

// apply:

/*
	template<typename Op, auto arg1, auto arg2>
	constexpr auto binary_apply = Op::template result<arg1, arg2>;
*/

/***********************************************************************************************************************/

// at:

/*
	template<size_type> struct at;

	template<>
	struct at<0>
	{
		template<auto R0, auto... Rs>
		static constexpr auto result = R0;
	};

	template<>
	struct at<1>
	{
		template<auto R0, auto R1, auto... Rs>
		static constexpr auto result = R1;
	};

	template<>
	struct at<2>
	{
		template<auto R0, auto R1, auto R2, auto... Rs>
		static constexpr auto result = R2;
	};

	template<>
	struct at<3>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto... Rs>
		static constexpr auto result = R3;
	};

	template<>
	struct at<4>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs>
		static constexpr auto result = R4;
	};

	template<>
	struct at<5>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs>
		static constexpr auto result = R5;
	};

	template<>
	struct at<6>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs>
		static constexpr auto result = R6;
	};

	template<>
	struct at<7>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs>
		static constexpr auto result = R7;
	};
*/

/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - control
	// m  - label index
	// n  - instruction index
	// Rs - registers

/*
	template<auto d, auto c, auto m, auto n, auto... Rs>
	constexpr auto register_machine(void(*)(auto_list<TI::stop>))
	{
		return type_map<auto_list<Rs...>>;
	}

	template<auto d, auto c, auto m, auto n, auto... Rs>
	constexpr auto register_machine(void(*)(auto_list<TI::pause>))
	{
		return type_map<alt_list<c, m, n, Rs...>>;
	}

	template<auto d, auto c, auto m, auto n, auto... Rs>
	constexpr auto register_machine(void(*)(auto_list<TI::start>))
	{
		return register_machine<d-1, c, m, n, Rs...>(U_value_V<next_c(d, c, m, n)>);
	}
*/

/***********************************************************************************************************************/

// replace:

/*
	template<>
	struct register_machine<TI::replace_0>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_1>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_2>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_3>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_4>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_5>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, R4, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_6>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, R4, R5, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_7>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, R4, R5, R6, V, Rs...>;
	};
*/

/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// operators:

/*
	template<>
	struct register_machine<TI::binary_apply>
	{
		template<auto d, auto c, auto m, auto n, auto... Rs>
		using result = typename register_machine
		<
			rm_replace(c, m, n)

		>::template result
		<
			d-1, c, label(m), index(n),

			binary_apply
			<
				rm_op<c, label, index>,
				rm_arg1<c, label, index>,
				rm_arg2<c, label, index>
			>,

			Rs...
		>;
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

