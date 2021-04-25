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
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = copy_sn_to_h0_locus<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
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
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = move_sn_to_h0_locus<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
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
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = erase_sn_locus<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
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

// rotate stack position:

	template<>
	struct machine<MN::rotate_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= rotate_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = rotate_sn_locus<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_rotate_stack_position(1, 0, 0);
		define_permutatic_machine_rotate_stack_position(2, 1, 1);
		define_permutatic_machine_rotate_stack_position(3, 2, 1);
		define_permutatic_machine_rotate_stack_position(4, 3, 1);
		define_permutatic_machine_rotate_stack_position(5, 4, 1);
		define_permutatic_machine_rotate_stack_position(6, 5, 1);
		define_permutatic_machine_rotate_stack_position(7, 6, 1);
		define_permutatic_machine_rotate_stack_position(8, 7, 1);

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
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = insert_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
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
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
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
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = apply1_replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
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
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = apply2_replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
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

// unary compel replace heap zero to stack position:

	template<>
	struct machine<MN::compel1_replace_h0_to_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= compel1_replace_h0_to_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = compel1_replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(1, 0, 0);
		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(2, 1, 1);
		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(3, 2, 1);
		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(4, 3, 1);
		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(5, 4, 1);
		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(6, 5, 1);
		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(7, 6, 1);
		define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(8, 7, 1);

/***********************************************************************************************************************/

// binary compel replace heap zero to stack position:

	template<>
	struct machine<MN::compel2_replace_h0_to_sn>
	{
		using nn			= VD;
		static constexpr auto nc	= compel2_replace_h0_to_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = compel2_replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(1, 0, 0);
		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(2, 1, 1);
		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(3, 2, 1);
		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(4, 3, 1);
		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(5, 4, 1);
		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(6, 5, 1);
		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(7, 6, 1);
		define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(8, 7, 1);

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
					else return c(i+1)(PA::note);
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

	template<depth_type pos, pa_type cont = pass<>>
	constexpr auto erase_contr = p_controller
	<
		erase_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// insert:

	template<depth_type pos, depth_type obj, pa_type cont = pass<>>
	constexpr auto insert_contr = p_controller
	<
		copy_sn_to_h0<obj>,
		insert_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// replace:

	template<depth_type pos, depth_type obj, pa_type cont = pass<>>
	constexpr auto replace_contr = p_controller
	<
		copy_sn_to_h0<obj>,
		replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// unary apply replace:

	template<depth_type pos, depth_type op, depth_type arg, pa_type cont = pass<>>
	constexpr auto apply1_replace_contr = p_controller
	<
		copy_sn_to_h0<op>,
		copy_sn_to_h0<arg>,
		apply1_replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// binary apply replace:

	template<depth_type pos, depth_type op, depth_type arg1, depth_type arg2, pa_type cont = pass<>>
	constexpr auto apply2_replace_contr = p_controller
	<
		copy_sn_to_h0<op>,
		copy_sn_to_h0<arg1>,
		copy_sn_to_h0<arg2>,
		apply2_replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// unary compel replace:

	template<depth_type pos, depth_type op, depth_type arg, pa_type cont = pass<>>
	constexpr auto compel1_replace_contr = p_controller
	<
		copy_sn_to_h0<op>,
		copy_sn_to_h0<arg>,
		compel1_replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/

// binary compel replace:

	template<depth_type pos, depth_type op, depth_type arg1, depth_type arg2, pa_type cont = pass<>>
	constexpr auto compel2_replace_contr = p_controller
	<
		copy_sn_to_h0<op>,
		copy_sn_to_h0<arg1>,
		copy_sn_to_h0<arg2>,
		compel2_replace_h0_to_sn<pos>,

		cont
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/

// pack erase:

	template<auto d, auto pos, auto... Vs>
	constexpr auto f_pack_erase()
	{
		constexpr auto c = erase_contr<pos, pack<>>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto... Vs>
	constexpr auto pack_erase = f_pack_erase<d, pos, Vs...>();

/***********************************************************************************************************************/

// pack insert:

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto f_pack_insert()
	{
		constexpr auto c = insert_contr<pos, obj, pack<>>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto pack_insert = f_pack_insert<d, pos, obj, Vs...>();

/***********************************************************************************************************************/

// pack replace:

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto f_pack_replace()
	{
		constexpr auto c = replace_contr<pos, obj, pack<>>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto obj, auto... Vs>
	constexpr auto pack_replace = f_pack_replace<d, pos, obj, Vs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

