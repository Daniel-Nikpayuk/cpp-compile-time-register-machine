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

#ifndef _3_VARIADIC_MACHINES_HPP
#define _3_VARIADIC_MACHINES_HPP

// variadic machines:

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

// stop (optimized):

		// doesn't update the heaps.

	template<>
	struct machine<MN::stop>
	{
		using nn			= BD;
		static constexpr auto nc	= pop_contr<MN::first>;

		template<CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto pos	= n::pos(c, i, j);		// single call
			constexpr depth_type nj	= block_max_index2(pos);	// single call
			constexpr depth_type ni	= pos + nj;			// single call

			return MACHINE(nn, nc, d, ni, nj)(Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack):

/***********************************************************************************************************************/

// pop:

	template<>
	struct machine<MN::pop>
	{
		using nn			= BD;
		static constexpr auto nc	= pop_contr<>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// push:

	template<>
	struct machine<MN::push>
	{
		using nn			= BD;
		static constexpr auto nc	= push_contr<>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// fold:

	template<>
	struct machine<MN::fold>
	{
		using nn			= BD;
		static constexpr auto nc	= fold_contr<>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// roll:

	template<>
	struct machine<MN::roll>
	{
		using nn			= BD;
		static constexpr auto nc	= roll_contr<>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack to heap):

/***********************************************************************************************************************/

// copy stack to heap zero:

	template<>
	struct machine<MN::copy_s0_to_h0>
	{
		template<CONTR_PARAMS, auto V0, auto... Vs, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)
		{
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

				V0, Vs...

			>(U_pack_Vs<Ws..., V0>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move stack to heap zero:

	template<>
	struct machine<MN::move_s_to_h0>
	{
		using nn			= BD;
		static constexpr auto nc	= move_s_to_h0_contr<>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move stack to heap one:

	template<>
	struct machine<MN::move_s_to_h1>
	{
		using nn			= BD;
		static constexpr auto nc	= move_s_to_h1_contr<>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (heap to stack):

/***********************************************************************************************************************/

// copy heap zero to stack front:

	template<>
	struct machine<MN::copy_h0_to_sf>
	{
		template<CONTR_PARAMS, auto... Vs, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)
		{
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

				Ws..., Vs...

			>(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// copy heap one to stack front:

	template<>
	struct machine<MN::copy_h1_to_sf>
	{
		template
		<
			CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)
		{
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

				Ws..., Vs...

			>(FIXED_HEAP_ARGS, Hs...);
		}
	};

/***********************************************************************************************************************/

// move heap zero to stack front:

	template<>
	struct machine<MN::move_h0_to_sf>
	{
		template<CONTR_PARAMS, auto... Vs, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)
		{
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

				Ws..., Vs...

			>(U_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move heap one to stack front:

	template<>
	struct machine<MN::move_h1_to_sf>
	{
		template
		<
			CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)
		{
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

				Ws..., Vs...

			>(H0, U_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// unary apply move heap zero to stack front:

	template<>
	struct machine<MN::apply1_move_h0_to_sf>
	{
		template<CONTR_PARAMS, auto... Vs, auto op, auto arg, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<op, arg>*), Heaps... Hs)
		{
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

				op(arg), Vs...

			>(U_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary apply move heap zero to stack front:

	template<>
	struct machine<MN::apply2_move_h0_to_sf>
	{
		template
		<
			CONTR_PARAMS, auto... Vs,
			auto op, auto arg1, auto arg2, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<op, arg1, arg2>*), Heaps... Hs)
		{
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

				op(arg1, arg2), Vs...

			>(U_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// locus:

	using vl_type = depth_type(*)(index_type);

		// pack length is stored as the initial value.

	template<depth_type... Vs>
	constexpr vl_type v_locus = f_array<depth_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// controller:

	using vc_type = index_type(*)(index_type);

	struct VC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type length (vc_type c) { return c(size); }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr vc_type v_controller = f_array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// dispatch:

	struct VD
	{

		// applications:

			static constexpr index_type pos(vc_type c, index_type i, vl_type j) { return j(i); }

		// iterators:

			// name:

				static constexpr index_type next_name(vc_type c, depth_type d, index_type i, vl_type j)
				{
					if (d == 0)	return MN::pause;
					else 		return c(i+1);
				}

			// note:

				static constexpr index_type (*next_note)(vc_type, depth_type, index_type, vl_type) =
					MD::template default_next_note<vc_type, depth_type, index_type, vl_type>;

			// depth:

				static constexpr depth_type (*next_depth)(depth_type) =
					MD::template default_next_depth<depth_type>;

			// index1:

				static constexpr index_type next_index1(vc_type c, depth_type d, index_type i, vl_type j)
				{
					if (d == 0)	return i;
					else 		return i+1;
				}

			// index2:

				static constexpr vl_type (*next_index2)(vc_type, depth_type, index_type, vl_type) =
					MD::template default_next_index2<vc_type, depth_type, index_type, vl_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// copy sn to h0:

	template<index_type cont = MN::pass>
	constexpr auto copy_sn_to_h0_contr = v_controller
	<
		MN::move_s_to_h1, MN::copy_s0_to_h0, MN::move_h1_to_sf, cont
	>;

	template<depth_type obj>
	constexpr auto copy_sn_to_h0_locus = v_locus
	<
		obj, zero, zero, zero
	>;

/***********************************************************************************************************************/

// move sn to h0:

	template<index_type cont = MN::pass>
	constexpr auto move_sn_to_h0_contr = v_controller
	<
		MN::move_s_to_h1, MN::move_s_to_h0, MN::move_h1_to_sf, cont
	>;

	template<depth_type obj>
	constexpr auto move_sn_to_h0_locus = v_locus
	<
		obj, one, zero, zero
	>;

/***********************************************************************************************************************/

// erase stack position:

	template<index_type cont = MN::pass>
	constexpr auto erase_sn_contr = v_controller
	<
		MN::move_s_to_h0, MN::pop_2_n, MN::move_h0_to_sf, cont
	>;

	template<depth_type pos>
	constexpr auto erase_sn_locus = v_locus
	<
		pos, zero, zero, zero
	>;

/***********************************************************************************************************************/

// insert heap zero to stack position:

	template<index_type cont = MN::pass>
	constexpr auto insert_h0_to_sn_contr = v_controller
	<
		MN::move_s_to_h1, MN::move_h0_to_sf, MN::move_h1_to_sf, cont
	>;

	template<depth_type pos>
	constexpr auto insert_h0_to_sn_locus = v_locus
	<
		pos, zero, zero, zero
	>;

/***********************************************************************************************************************/

// replace heap zero to stack position:

	template<index_type cont = MN::pass>
	constexpr auto replace_h0_to_sn_contr = v_controller
	<
		MN::move_s_to_h1, MN::pop_2_n, MN::move_h0_to_sf, MN::move_h1_to_sf, cont
	>;

	template<depth_type pos>
	constexpr auto replace_h0_to_sn_locus = v_locus
	<
		pos, zero, zero, zero, zero
	>;

/***********************************************************************************************************************/

// unary apply replace heap zero to stack position:

	template<index_type cont = MN::pass>
	constexpr auto apply1_replace_h0_to_sn_contr = v_controller
	<
		MN::move_s_to_h1, MN::pop_2_n, MN::apply1_move_h0_to_sf, MN::move_h1_to_sf, cont
	>;

	template<depth_type pos>
	constexpr auto apply1_replace_h0_to_sn_locus = v_locus
	<
		pos, zero, zero, zero, zero
	>;

/***********************************************************************************************************************/

// binary apply replace heap zero to stack position:

	template<index_type cont = MN::pass>
	constexpr auto apply2_replace_h0_to_sn_contr = v_controller
	<
		MN::move_s_to_h1, MN::pop_2_n, MN::apply2_move_h0_to_sf, MN::move_h1_to_sf, cont
	>;

	template<depth_type pos>
	constexpr auto apply2_replace_h0_to_sn_locus = v_locus
	<
		pos, zero, zero, zero, zero
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

