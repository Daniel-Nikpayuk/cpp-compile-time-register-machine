/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of cpp_near_linear_function_space.
**
** cpp_near_linear_function_space is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** cpp_near_linear_function_space is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with cpp_near_linear_function_space.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#ifndef _2_BLOCK_MACHINES_HPP
#define _2_BLOCK_MACHINES_HPP

// block machines:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace machine_space
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// first:

	template<>
	struct machine<MN::first>
	{
		template<CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return V0;
		}
	};

/***********************************************************************************************************************/

// rest:

	template<>
	struct machine<MN::rest>
	{
		template<CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_pack_Vs<Vs...>;
		}
	};

/***********************************************************************************************************************/

// pack:

	template<>
	struct machine<MN::pack>
	{
		template<CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_pack_Vs<Vs...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// debuggers:

/***********************************************************************************************************************/

// depth:

	template<>
	struct machine<MN::depth>
	{
		template<CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return d;
		}
	};

/***********************************************************************************************************************/

// dump:

	template<>
	struct machine<MN::dump>
	{
		template<CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto un = U_type_T<n>;
			constexpr auto rp = U_pack_Vs<un, c, i, j, Vs...>;

			return U_pack_Vs<rp, U_type_T<T_pretype_T<Heaps>>...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// pause:

	template<>
	struct machine<MN::pause>
	{
		template<CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto un = U_type_T<n>;
			constexpr auto rp = U_pack_Vs<un, c, i, j, Vs...>;

			return U_alt_pack_Vs<rp, U_type_T<T_pretype_T<Heaps>>...>;
		}
	};

/***********************************************************************************************************************/

// pass:

	template<>
	struct machine<MN::pass>
	{
		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, auto un, auto nc, auto ni, auto nj, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, void(*H2)(auto_pack<un, nc, ni, nj>*), Heaps... Hs)
		{
			using nn = T_type_U<un>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack):

/***********************************************************************************************************************/

// pop (2^N):

	define_block_machine_pop(0);
	define_block_machine_pop(1);
	define_block_machine_pop(2);
	define_block_machine_pop(3);
	define_block_machine_pop(4);
	define_block_machine_pop(5);
	define_block_machine_pop(6);
	define_block_machine_pop(7);
	define_block_machine_pop(8);
	define_block_machine_pop(9);

/***********************************************************************************************************************/

// push (2^N):

	define_block_machine_push(0);
	define_block_machine_push(1);
	define_block_machine_push(2);
	define_block_machine_push(3);
	define_block_machine_push(4);
	define_block_machine_push(5);
	define_block_machine_push(6);
	define_block_machine_push(7);
	define_block_machine_push(8);
	define_block_machine_push(9);

/***********************************************************************************************************************/

// fold (2^N):

	define_block_machine_fold(0);
	define_block_machine_fold(1);
	define_block_machine_fold(2);
	define_block_machine_fold(3);
	define_block_machine_fold(4);
	define_block_machine_fold(5);
	define_block_machine_fold(6);
	define_block_machine_fold(7);
	define_block_machine_fold(8);
//	define_block_machine_fold(9); // clang: bracket nesting level defaults to a maximum of 256

	template<>
	struct machine<MN::fold_2_n, nine>
	{
		template<CONTR_PARAMS, auto V, _2_9_auto_Vs, auto... Vs, auto op, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<op>*), Heaps... Hs)
		{
			constexpr auto val = _2_8_ops  V,  _2_8_op_Vs;

			return machine
			<
				n::next_name(c, d, i, j),
				n::next_note(c, d, i, j)

			>::template result
			<
				n, c,

				n::next_depth(d),
				n::next_index1(c, d, i, j),
				n::next_index2(c, d, i, j),

				_2_8_ops  val,  _upper_512_op_Vs, Vs...

			>(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// roll (2^N):

	define_block_machine_roll(0);
	define_block_machine_roll(1);
	define_block_machine_roll(2);
	define_block_machine_roll(3);
	define_block_machine_roll(4);
	define_block_machine_roll(5);
	define_block_machine_roll(6);
	define_block_machine_roll(7);
	define_block_machine_roll(8);
	define_block_machine_roll(9);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack to heap):

/***********************************************************************************************************************/

// stack to heap zero (2^N):

	define_block_machine_move_stack_to_heap_zero(0);
	define_block_machine_move_stack_to_heap_zero(1);
	define_block_machine_move_stack_to_heap_zero(2);
	define_block_machine_move_stack_to_heap_zero(3);
	define_block_machine_move_stack_to_heap_zero(4);
	define_block_machine_move_stack_to_heap_zero(5);
	define_block_machine_move_stack_to_heap_zero(6);
	define_block_machine_move_stack_to_heap_zero(7);
	define_block_machine_move_stack_to_heap_zero(8);
	define_block_machine_move_stack_to_heap_zero(9);

/***********************************************************************************************************************/

// stack to heap one (2^N):

	define_block_machine_move_stack_to_heap_one(0);
	define_block_machine_move_stack_to_heap_one(1);
	define_block_machine_move_stack_to_heap_one(2);
	define_block_machine_move_stack_to_heap_one(3);
	define_block_machine_move_stack_to_heap_one(4);
	define_block_machine_move_stack_to_heap_one(5);
	define_block_machine_move_stack_to_heap_one(6);
	define_block_machine_move_stack_to_heap_one(7);
	define_block_machine_move_stack_to_heap_one(8);
	define_block_machine_move_stack_to_heap_one(9);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

	using bc_type = index_type(*)(index_type);

	struct BC
	{
		// members:

			static constexpr index_type size = 0;
			static constexpr index_type name = 1;
			static constexpr index_type cont = 2;

		// procedures:

			static constexpr index_type length (bc_type c) { return c(size); }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr bc_type b_controller = f_array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// dispatch:

	constexpr index_type block_max_note(depth_type n)
	{
		return	(n >= _2_9) ? 9 :
			(n >= _2_8) ? 8 :
			(n >= _2_7) ? 7 :
			(n >= _2_6) ? 6 :
			(n >= _2_5) ? 5 :
			(n >= _2_4) ? 4 :
			(n >= _2_3) ? 3 :
			(n >= _2_2) ? 2 :
			(n >= _2_1) ? 1 : 0 ;
	}

	constexpr depth_type block_max_index2(depth_type n)
	{
		return	(n >= _2_9) ? _2_9 :
			(n >= _2_8) ? _2_8 :
			(n >= _2_7) ? _2_7 :
			(n >= _2_6) ? _2_6 :
			(n >= _2_5) ? _2_5 :
			(n >= _2_4) ? _2_4 :
			(n >= _2_3) ? _2_3 :
			(n >= _2_2) ? _2_2 :
			(n >= _2_1) ? _2_1 :
			(n >= _2_0) ? _2_0 : 0 ;
	}

	struct BD
	{
		// iterators:

			// name:

				static constexpr index_type next_name(bc_type c, depth_type d, depth_type i, depth_type j)
				{
					if (d == 0)	return MN::pause;	// assumes i >= j, next i := i - j
					else if (i > j)	return c(BC::name);	// implies next i > 0
					else 		return c(BC::cont);	// otherwise next i == 0
				}

			// note:

				static constexpr index_type next_note(bc_type c, depth_type d, depth_type i, depth_type j)
				{
					if (d == 0)	return zero;
					else		return block_max_note(i - j);
				}

			// depth:

				static constexpr depth_type (*next_depth)(depth_type) =
					MD::template default_next_depth<depth_type>;

			// index1:

				static constexpr depth_type next_index1(bc_type c, depth_type d, depth_type i, depth_type j)
				{
					if (d == 0)	return i;
					else 		return i - j;
				}

			// index2:

				static constexpr depth_type next_index2(bc_type c, depth_type d, depth_type i, depth_type j)
				{
					if (d == 0)	return j;
					else		return block_max_index2(i - j);
				}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// pop:

	template<index_type cont = MN::pass>
	constexpr auto pop_contr = b_controller<MN::pop_2_n, cont>;

/***********************************************************************************************************************/

// push:

	template<index_type cont = MN::pass>
	constexpr auto push_contr = b_controller<MN::push_2_n, cont>;

/***********************************************************************************************************************/

// fold:

	template<index_type cont = MN::pass>
	constexpr auto fold_contr = b_controller<MN::fold_2_n, cont>;

/***********************************************************************************************************************/

// roll:

	template<index_type cont = MN::pass>
	constexpr auto roll_contr = b_controller<MN::roll_2_n, cont>;

/***********************************************************************************************************************/

// pop stack to heap zero:

	template<index_type cont = MN::pass>
	constexpr auto move_s_to_h0_contr = b_controller<MN::move_2_n_s_to_h0, cont>;

/***********************************************************************************************************************/

// pop stack to heap one:

	template<index_type cont = MN::pass>
	constexpr auto move_s_to_h1_contr = b_controller<MN::move_2_n_s_to_h1, cont>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/

// pack at:

	template<auto d, auto n, auto... Vs>
	constexpr auto f_pack_at()
	{
		constexpr auto c	= pop_contr<MN::first>;
		constexpr depth_type j	= block_max_index2(n);
		constexpr depth_type i	= n + j;

		return machine_start<BD, c, d, i, j, Vs...>();
	}

	template<auto d, auto n, auto... Vs>
	constexpr auto pack_at = f_pack_at<d, n, Vs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

