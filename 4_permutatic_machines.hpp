/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of cpp_linear_function_space.
**
** cpp_linear_function_space is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** cpp_linear_function_space is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with cpp_linear_function_space.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#ifndef _4_PERMUTATIC_MACHINES_HPP
#define _4_PERMUTATIC_MACHINES_HPP

// permutatic machines:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace machine_space
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// internals:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// copy stack position to heap zero:

	template<>
	struct machine<MN::copy_sn_to_h0>
	{
		using nn			= VD;
		static constexpr auto nc	= copy_sn_to_h0_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			typename Heap0, typename Heap1, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = copy_sn_to_h0_locus<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(H0, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_copy_stack_position_to_heap_zero(1, 0);
		define_permutatic_machine_copy_stack_position_to_heap_zero(2, 1);
		define_permutatic_machine_copy_stack_position_to_heap_zero(3, 2);
		define_permutatic_machine_copy_stack_position_to_heap_zero(4, 3);
		define_permutatic_machine_copy_stack_position_to_heap_zero(5, 4);
		define_permutatic_machine_copy_stack_position_to_heap_zero(6, 5);
		define_permutatic_machine_copy_stack_position_to_heap_zero(7, 6);
		define_permutatic_machine_copy_stack_position_to_heap_zero(8, 7);

/***********************************************************************************************************************/

// move stack position to heap zero:

	template<>
	struct machine<MN::move_sn_to_h0>
	{
		using nn			= VD;
		static constexpr auto nc	= move_sn_to_h0_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			typename Heap0, typename Heap1, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = move_sn_to_h0_locus<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(H0, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_move_stack_position_to_heap_zero(1, 0, 0);
		define_permutatic_machine_move_stack_position_to_heap_zero(2, 1, 1);
		define_permutatic_machine_move_stack_position_to_heap_zero(3, 2, 1);
		define_permutatic_machine_move_stack_position_to_heap_zero(4, 3, 1);
		define_permutatic_machine_move_stack_position_to_heap_zero(5, 4, 1);
		define_permutatic_machine_move_stack_position_to_heap_zero(6, 5, 1);
		define_permutatic_machine_move_stack_position_to_heap_zero(7, 6, 1);
		define_permutatic_machine_move_stack_position_to_heap_zero(8, 7, 1);

/***********************************************************************************************************************/

// erase stack position:

	template<>
	struct machine<MN::erase_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= erase_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			typename Heap0, typename Heap1, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = erase_sn_locus<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(H0, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_erase_stack_position(1, 0, 0);
		define_permutatic_machine_erase_stack_position(2, 1, 1);
		define_permutatic_machine_erase_stack_position(3, 2, 1);
		define_permutatic_machine_erase_stack_position(4, 3, 1);
		define_permutatic_machine_erase_stack_position(5, 4, 1);
		define_permutatic_machine_erase_stack_position(6, 5, 1);
		define_permutatic_machine_erase_stack_position(7, 6, 1);
		define_permutatic_machine_erase_stack_position(8, 7, 1);

/***********************************************************************************************************************/

// insert heap zero to stack position:

	template<>
	struct machine<MN::insert_h0_to_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= insert_h0_to_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			typename Heap0, typename Heap1, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = insert_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(H0, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_insert_heap_zero_to_stack_position(1, 0, 0);
		define_permutatic_machine_insert_heap_zero_to_stack_position(2, 1, 1);
		define_permutatic_machine_insert_heap_zero_to_stack_position(3, 2, 1);
		define_permutatic_machine_insert_heap_zero_to_stack_position(4, 3, 1);
		define_permutatic_machine_insert_heap_zero_to_stack_position(5, 4, 1);
		define_permutatic_machine_insert_heap_zero_to_stack_position(6, 5, 1);
		define_permutatic_machine_insert_heap_zero_to_stack_position(7, 6, 1);
		define_permutatic_machine_insert_heap_zero_to_stack_position(8, 7, 1);

/***********************************************************************************************************************/

// replace heap zero to stack position:

	template<>
	struct machine<MN::replace_h0_to_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= replace_h0_to_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			typename Heap0, typename Heap1, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(H0, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_replace_heap_zero_to_stack_position(1, 0, 0);
		define_permutatic_machine_replace_heap_zero_to_stack_position(2, 1, 1);
		define_permutatic_machine_replace_heap_zero_to_stack_position(3, 2, 1);
		define_permutatic_machine_replace_heap_zero_to_stack_position(4, 3, 1);
		define_permutatic_machine_replace_heap_zero_to_stack_position(5, 4, 1);
		define_permutatic_machine_replace_heap_zero_to_stack_position(6, 5, 1);
		define_permutatic_machine_replace_heap_zero_to_stack_position(7, 6, 1);
		define_permutatic_machine_replace_heap_zero_to_stack_position(8, 7, 1);

/***********************************************************************************************************************/

// unary apply replace heap zero to stack position:

	template<>
	struct machine<MN::apply1_replace_h0_to_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= apply1_replace_h0_to_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			typename Heap0, typename Heap1, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = apply1_replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(H0, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(1, 0, 0);
		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(2, 1, 1);
		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(3, 2, 1);
		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(4, 3, 1);
		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(5, 4, 1);
		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(6, 5, 1);
		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(7, 6, 1);
		define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(8, 7, 1);

/***********************************************************************************************************************/

// binary apply replace heap zero to stack position:

	template<>
	struct machine<MN::apply2_replace_h0_to_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= apply2_replace_h0_to_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			typename Heap0, typename Heap1, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = apply2_replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(H0, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(1, 0, 0);
		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(2, 1, 1);
		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(3, 2, 1);
		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(4, 3, 1);
		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(5, 4, 1);
		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(6, 5, 1);
		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(7, 6, 1);
		define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(8, 7, 1);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// application:

	// inherits from machine applications:

		using pa_type	= ma_type;
		using PA	= MA;

		template<index_type... Vs>
		constexpr pa_type p_application = m_application<Vs...>;

	// syntactic sugar:

		template<index_type Name, index_type Note, index_type... Args>
		constexpr pa_type p_call = p_application<Name, Note, Args...>;

		constexpr pa_type p_pack = p_application<MN::pack, zero>;

		template<index_type Pos>
		constexpr pa_type p_stop = p_application<MN::stop, zero, Pos>;

		template<index_type note = zero>
		constexpr pa_type p_pass = p_application<MN::pass, note>;

		//

		template<depth_type pos>
		constexpr pa_type p_copy_sn_to_h0 = p_application<MN::copy_sn_to_h0, zero, pos>;

		template<depth_type pos>
		constexpr pa_type p_move_sn_to_h0 = p_application<MN::move_sn_to_h0, zero, pos>;

		template<depth_type pos>
		constexpr pa_type p_erase_sn = p_application<MN::erase_sn, zero, pos>;

		template<depth_type pos>
		constexpr pa_type p_insert_h0_to_sn = p_application<MN::insert_h0_to_sn, zero, pos>;

		template<depth_type pos>
		constexpr pa_type p_replace_h0_to_sn = p_application<MN::replace_h0_to_sn, zero, pos>;

		//

		template<depth_type pos>
		constexpr pa_type p_apply1_replace_h0_to_sn = p_application<MN::apply1_replace_h0_to_sn, zero, pos>;

		template<depth_type pos>
		constexpr pa_type p_apply2_replace_h0_to_sn = p_application<MN::apply2_replace_h0_to_sn, zero, pos>;

/***********************************************************************************************************************/

// controller:

	using pc_type = pa_type(*)(index_type);

	struct PC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type length (pc_type c) { return c(size)(PA::size); }
	};

		// pack length is stored as the initial value.

	template<pa_type... Vs>
	constexpr pc_type p_controller = f_array<pa_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/

// dispatch:

	struct PD
	{
		// applications:

			static constexpr index_type size (pc_type c, index_type i, index_type) { return c(i)(PA::size); }
			static constexpr index_type name (pc_type c, index_type i, index_type) { return c(i)(PA::name); }
			static constexpr index_type note (pc_type c, index_type i, index_type) { return c(i)(PA::note); }
			static constexpr index_type pos  (pc_type c, index_type i, index_type) { return c(i)(PA::pos ); }

		// predicates:

			static constexpr bool is_permutatic(index_type name)
			{
				return	(name == MN::copy_sn_to_h0)		||
					(name == MN::erase_sn)			||
					(name == MN::insert_h0_to_sn)		||
					(name == MN::replace_h0_to_sn)		||
					(name == MN::apply1_replace_h0_to_sn)	||
					(name == MN::apply2_replace_h0_to_sn)	;
			}

		// iterators:

			// name:

				static constexpr index_type next_name(pc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0)	return MN::pause;
					else 		return c(i+1)(PA::name);
				}

			// note:

				static constexpr index_type next_note(pc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0) return zero;

					pa_type a = c(i+1);

					if (is_permutatic(a(PA::name)))
					{
						depth_type pos = a(PA::pos);

						return (pos < eight) ? pos+1 : zero;
					}
					else return a(PA::note);
				}

			// depth:

				static constexpr depth_type (*next_depth)(depth_type) =
					MD::template default_next_depth<depth_type>;

			// index1:

				static constexpr index_type next_index1(pc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0)	return i;
					else 		return i+1;
				}

			// index2:

				static constexpr index_type (*next_index2)(pc_type, depth_type, index_type, index_type) =
					MD::template default_next_index2<pc_type, depth_type, index_type, index_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// erase:

	template<depth_type pos, pa_type cont = p_pass<>>
	constexpr auto erase_contr = p_controller
	<
		p_erase_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// insert:

	template<depth_type pos, depth_type obj, pa_type cont = p_pass<>>
	constexpr auto insert_contr = p_controller
	<
		p_copy_sn_to_h0<obj>,
		p_insert_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// replace:

	template<depth_type pos, depth_type obj, pa_type cont = p_pass<>>
	constexpr auto replace_contr = p_controller
	<
		p_copy_sn_to_h0<obj>,
		p_replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// unary apply replace:

	template<depth_type pos, depth_type op, depth_type arg, pa_type cont = p_pass<>>
	constexpr auto apply1_replace_contr = p_controller
	<
		p_copy_sn_to_h0<op>,
		p_copy_sn_to_h0<arg>,
		p_apply1_replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// binary apply replace:

	template<depth_type pos, depth_type op, depth_type arg1, depth_type arg2, pa_type cont = p_pass<>>
	constexpr auto apply2_replace_contr = p_controller
	<
		p_copy_sn_to_h0<op>,
		p_copy_sn_to_h0<arg1>,
		p_copy_sn_to_h0<arg2>,
		p_apply2_replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack erase:

	template<auto d, auto pos, auto... Vs>
	constexpr auto f_pack_erase()
	{
		constexpr auto c = erase_contr<pos, p_pack>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto... Vs>
	constexpr auto pack_erase = machine_trampoline<d>(f_pack_erase<d, pos, Vs...>());

/***********************************************************************************************************************/

// list erase:

	template<depth_type d, index_type pos, auto... Vs>
	constexpr auto f_list_erase(void(*)(auto_pack<Vs...>*))
	{
		return pack_erase<d, pos, Vs...>;
	}

	template<typename List, index_type pos, depth_type depth = 500>
	constexpr auto list_erase = f_list_erase<depth, pos>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack insert:

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto f_pack_insert()
	{
		constexpr auto c = insert_contr<pos, obj, p_pack>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto pack_insert = machine_trampoline<d>(f_pack_insert<d, pos, obj, Vs...>());

/***********************************************************************************************************************/

// list insert:

	template<depth_type d, index_type pos, index_type obj, auto... Vs>
	constexpr auto f_list_insert(void(*)(auto_pack<Vs...>*))
	{
		return pack_insert<d, pos, obj, Vs...>;
	}

	template<typename List, index_type pos, index_type obj, depth_type depth = 500>
	constexpr auto list_insert = f_list_insert<depth, pos, obj>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack replace:

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto f_pack_replace()
	{
		constexpr auto c = replace_contr<pos, obj, p_pack>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto pack_replace = machine_trampoline<d>(f_pack_replace<d, pos, obj, Vs...>());

/***********************************************************************************************************************/

// list replace:

	template<depth_type d, index_type pos, index_type obj, auto... Vs>
	constexpr auto f_list_replace(void(*)(auto_pack<Vs...>*))
	{
		return pack_replace<d, pos, obj, Vs...>;
	}

	template<typename List, index_type pos, index_type obj, depth_type depth = 500>
	constexpr auto list_replace = f_list_replace<depth, pos, obj>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack apply1:

	template<auto d, auto pos, auto op, auto arg, auto... Vs>
	constexpr auto f_pack_apply1()
	{
		constexpr auto c = apply1_replace_contr<pos, op, arg, p_pack>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto op, auto arg, auto... Vs>
	constexpr auto pack_apply1 = machine_trampoline<d>(f_pack_apply1<d, pos, op, arg, Vs...>());

/***********************************************************************************************************************/

// list apply1:

	template<depth_type d, index_type pos, index_type op, index_type arg, auto... Vs>
	constexpr auto f_list_apply1(void(*)(auto_pack<Vs...>*))
	{
		return pack_apply1<d, pos, op, arg, Vs...>;
	}

	template<typename List, index_type pos, index_type op, index_type arg, depth_type depth = 500>
	constexpr auto list_apply1 = f_list_apply1<depth, pos, op, arg>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack apply2:

	template<auto d, auto pos, auto op, auto arg1, auto arg2, auto... Vs>
	constexpr auto f_pack_apply2()
	{
		constexpr auto c = apply2_replace_contr<pos, op, arg1, arg2, p_pack>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto op, auto arg1, auto arg2, auto... Vs>
	constexpr auto pack_apply2 = machine_trampoline<d>(f_pack_apply2<d, pos, op, arg1, arg2, Vs...>());

/***********************************************************************************************************************/

// list apply2:

	template<depth_type d, index_type pos, index_type op, index_type arg1, index_type arg2, auto... Vs>
	constexpr auto f_list_apply2(void(*)(auto_pack<Vs...>*))
	{
		return pack_apply2<d, pos, op, arg1, arg2, Vs...>;
	}

	template<typename List, index_type pos, index_type op, index_type arg1, index_type arg2, depth_type depth = 500>
	constexpr auto list_apply2 = f_list_apply2<depth, pos, op, arg1, arg2>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

