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

#ifndef _6_NEAR_LINEAR_MACHINES_HPP
#define _6_NEAR_LINEAR_MACHINES_HPP

// near linear machines:

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

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// lift:

	template<>
	struct machine<MN::lift>
	{
		using nn			= DD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = call_contr<n::appl(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// stem:

	template<>
	struct machine<MN::stem>
	{
		using nn			= DD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = jump_contr<n::cond(c, i, j), n::appl2(c, i, j), n::appl1(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// costem:

	template<>
	struct machine<MN::costem>
	{
		using nn			= DD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = jump_contr<n::cond(c, i, j), n::appl1(c, i, j), n::appl2(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// cycle (optimized):

	// refactored into the controller iterator.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/

// applications:

	// inherits from machine applications:

		using na_type	= ma_type;
		using NA	= MA;

/***********************************************************************************************************************/

// continuation passing functors:

	using np_type = na_type(*)(index_type);

	struct NP
	{
		// members:

			static constexpr index_type size		= 0;
			static constexpr index_type name		= 1;

			static constexpr index_type appl		= 2;

			static constexpr index_type cond		= 2;
			static constexpr index_type appl1		= 3;
			static constexpr index_type appl2		= 4;

		// constants:

			static constexpr na_type lift			= m_application<MN::lift, zero>;
			static constexpr na_type stem			= m_application<MN::stem, zero>;
			static constexpr na_type halt			= m_application<MN::halt, zero>;
			static constexpr na_type cycle			= m_application<MN::cycle, zero>;

		// procedures:

			static constexpr index_type length(np_type n)	{ return n(size)(NA::size); }
	};

		// pack length is stored as the initial value.

	template<na_type... Vs>
	constexpr np_type n_continuation = f_array<na_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

	// syntactic sugar:

		template<na_type N>
		constexpr np_type n_lift = n_continuation<NP::lift, N>;

		template<na_type P, na_type B, na_type N>
		constexpr np_type n_stem = n_continuation<NP::stem, P, B, N>;

		template<na_type B>
		constexpr np_type n_halt = n_continuation<NP::halt, B>;

		constexpr np_type n_cycle = n_continuation<NP::cycle>;

/***********************************************************************************************************************/

// controller:

	using nc_type = np_type(*)(index_type);

	struct NC
	{
		// members:

			static constexpr index_type size	= 0;

		// procedures:

			static constexpr index_type length(nc_type c) { return c(size)(NP::size)(NA::size); }
	};

		// pack length is stored as the initial value.

	template<np_type... Vs>
	constexpr nc_type n_controller = f_array
		<np_type, f_array<na_type, f_array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/

// dispatch:

	struct ND
	{
		// applications:

			static constexpr auto appl(nc_type c, index_type i, index_type) { return c(i)(NP::appl); }

			static constexpr auto cond(nc_type c, index_type i, index_type) { return c(i)(NP::cond); }
			static constexpr auto appl1(nc_type c, index_type i, index_type) { return c(i)(NP::appl1); }
			static constexpr auto appl2(nc_type c, index_type i, index_type) { return c(i)(NP::appl2); }

		// iterators:

			// name:

				static constexpr index_type next_name(nc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0) return MN::pause;

					index_type name = c(i+1)(NP::name)(NA::name);

					if (name != MN::cycle)	return name;
					else			return c(one)(NP::name)(NA::name);
				}

			// note:

				static constexpr index_type (*next_note)(nc_type, depth_type, index_type, index_type) =
					MD::template default_next_note<nc_type, depth_type, index_type, index_type>;

			// depth:

				static constexpr depth_type (*next_depth)(depth_type) =
					MD::template default_next_depth<depth_type>;

			// index1:

				static constexpr index_type next_index1(nc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0) return i;

					index_type name = c(i+1)(NP::name)(NA::name);

					if (name != MN::cycle)	return i+1;
					else			return one;
				}

			// index2:

				static constexpr index_type (*next_index2)(nc_type, depth_type, index_type, index_type) =
					MD::template default_next_index2<nc_type, depth_type, index_type, index_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

