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

#ifndef _1_MACHINE_DECLARATIONS_HPP
#define _1_MACHINE_DECLARATIONS_HPP

// machine declarations:

	// nesting depth policy:

		// It is assumed each function nesting depth is chosen to be less than the compiler's nesting depth.
		// This is to say that in practice there should be small buffer of nesting depths/calls available.

		// Consequences: If d == 0 during a given machine call,

		// A) It is able to call the next machine. In turn the iterators will
		//    dispatch it to MN::pause which does not require any further depths.

		// B) It is able to call single depth functions within its scope.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace machine_space
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// constexpr monad (design):

//		template<>
//		struct machine<MN::(((name))), (((note)))>
//		{
//			template
//			<
//				// stack:

//					typename n, auto c, auto d, auto i, auto j, auto... Vs,

//				// heap:

//					typename... Heaps
//			>
//			static constexpr auto result(Heaps... Hs)
//			{
//				return machine
//				<
//					n::next_name(c, d, i, j),
//					n::next_note(c, d, i, j)

//				>::template result
//				<
//					n, c,

//					n::next_depth(d),
//					n::next_index1(c, d, i, j),
//					n::next_index2(c, d, i, j),

//					Vs...	// The behaviour of each
//						// machine is such that it
//				>(Hs...);	// mutates these packs.
//			}
//		};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	using index_type 		= unsigned char;
	using depth_type 		= unsigned short;

/***********************************************************************************************************************/

// constants:

	// [0-10]:

		constexpr index_type zero	=   0;
		constexpr index_type one	=   1;
		constexpr index_type two	=   2;
		constexpr index_type three	=   3;
		constexpr index_type four	=   4;
		constexpr index_type five	=   5;
		constexpr index_type six	=   6;
		constexpr index_type seven	=   7;
		constexpr index_type eight	=   8;
		constexpr index_type nine	=   9;
		constexpr index_type ten	=  10;

	// [2^0-2^9]:

		constexpr depth_type _2_0	=   1;
		constexpr depth_type _2_1	=   2;
		constexpr depth_type _2_2	=   4;
		constexpr depth_type _2_3	=   8;
		constexpr depth_type _2_4	=  16;
		constexpr depth_type _2_5	=  32;
		constexpr depth_type _2_6	=  64;
		constexpr depth_type _2_7	= 128;
		constexpr depth_type _2_8	= 256;
		constexpr depth_type _2_9	= 512;

/***********************************************************************************************************************/

// function array:

	template<typename Type, Type... Vs>
	constexpr Type f_array(index_type pos)
	{
		constexpr Type array[] = { Vs... };

		return array[pos];
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine:

	template<index_type, index_type = 0> struct machine;

/***********************************************************************************************************************/

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

// names:

	struct MN
	{
		// abstract:

			// passers:

				static constexpr index_type id				=  0;

		// block:

			// halters:

				static constexpr index_type pause			=  1;

				static constexpr index_type first			=  2;
				static constexpr index_type rest			=  3;
				static constexpr index_type pack			=  4;

			// debuggers:

				static constexpr index_type depth			=  5;
				static constexpr index_type dump			=  6;

			// interoperability:

				static constexpr index_type pass			=  7;

			// passers:

				// stack -> stack:

				static constexpr index_type pop_2_n			=  8;
				static constexpr index_type push_2_n			=  9;
				static constexpr index_type fold_2_n			= 10;
				static constexpr index_type roll_2_n			= 11;

				// stack -> heap:

				static constexpr index_type move_2_n_s_to_h0		= 12;
				static constexpr index_type move_2_n_s_to_h1		= 13;

		// variadic:

			// halters:

				static constexpr index_type stop			= 14;

			// passers:

				// stack -> stack:

				static constexpr index_type pop				= 15;
				static constexpr index_type push			= 16;

				static constexpr index_type fold_s0			= 17;
				static constexpr index_type roll_s0			= 18;

				// stack -> heap:

				static constexpr index_type copy_s0_to_h0		= 19;

				static constexpr index_type move_s_to_h0		= 20;
				static constexpr index_type move_s_to_h1		= 21;

				// heap -> stack:

				static constexpr index_type copy_h0_to_sf		= 22;
				static constexpr index_type copy_h1_to_sf		= 23;

				static constexpr index_type move_h0_to_sf		= 24;
				static constexpr index_type move_h1_to_sf		= 25;

				static constexpr index_type apply1_move_h0_to_sf	= 26;
				static constexpr index_type apply2_move_h0_to_sf	= 27;

				static constexpr index_type compel1_move_h0_to_sf	= 28;
				static constexpr index_type compel2_move_h0_to_sf	= 29;

		// permutatic:

			// passers:

				static constexpr index_type copy_sn_to_h0		= 30;
				static constexpr index_type move_sn_to_h0		= 31;

				static constexpr index_type erase_sn			= 32;
				static constexpr index_type rotate_sn			= 33;
				static constexpr index_type insert_h0_to_sn		= 34;
				static constexpr index_type replace_h0_to_sn		= 35;

				static constexpr index_type apply1_replace_h0_to_sn	= 36;
				static constexpr index_type apply2_replace_h0_to_sn	= 37;

				static constexpr index_type compel1_replace_h0_to_sn	= 38;
				static constexpr index_type compel2_replace_h0_to_sn	= 39;

		// distributic:

			// passers:

				static constexpr index_type erase			= 40;
				static constexpr index_type insert			= 41;
				static constexpr index_type replace			= 42;

				static constexpr index_type fold			= 43;
				static constexpr index_type roll			= 44;

				static constexpr index_type apply			= 45;
				static constexpr index_type compel			= 46;

				static constexpr index_type test			= 47;
				static constexpr index_type check			= 48;

				static constexpr index_type jump			= 49;

		// near linear:

			// halters:

				static constexpr index_type halt			= 50;

			// passers:

				static constexpr index_type lift			= 51;
				static constexpr index_type stem			= 52;
				static constexpr index_type costem			= 53;
				static constexpr index_type cycle			= 54;

		// register:

			// passers:

				static constexpr index_type assign			= 55;

				static constexpr index_type branch			= 56;
				static constexpr index_type go_to_s0			= 57;
				static constexpr index_type go_to			= 58;

				static constexpr index_type save			= 59;
				static constexpr index_type restore			= 60;

		// reflection:

			// sizes:

				static constexpr index_type reg_size			= 61;
	};

/***********************************************************************************************************************/

// applications:

	using ma_type = index_type(*)(index_type);

	struct MA
	{
		// notes:

			static constexpr index_type unary	= 0;
			static constexpr index_type binary	= 1;

		// members:

			static constexpr index_type size	= 0;
			static constexpr index_type name	= 1;
			static constexpr index_type note	= 2;
			static constexpr index_type pos		= 3;

			// assignments:

			static constexpr index_type obj		= 4;

			// applications:

			static constexpr index_type op		= 4;
			static constexpr index_type arg		= 5;
			static constexpr index_type arg1	= 5;
			static constexpr index_type arg2	= 6;

			// predications:

			static constexpr index_type pred	= 3;
			static constexpr index_type input	= 4;
			static constexpr index_type input1	= 4;
			static constexpr index_type input2	= 5;

		// procedures:

			static constexpr index_type length(ma_type a) { return a(size); }
			static constexpr index_type arity(index_type args) { return (args == 1) ? unary : binary; }
			static constexpr index_type patch(depth_type pos) { return (pos < eight) ? pos+1 : zero; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr ma_type m_application = f_array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// dispatch:

	struct MD
	{
		// notes:

			static constexpr index_type contr = 0;
			static constexpr index_type regtr = 1;

		// iterators:

			template<typename d_type>
			static constexpr d_type default_next_depth(d_type d)
			{
				if (d > 0)	return d-1;
				else 		return d;
			}

			template<typename c_type, typename d_type, typename i_type, typename j_type>
			static constexpr index_type default_next_note(c_type, d_type d, i_type, j_type)
			{
				return zero;
			}

			template<typename c_type, typename d_type, typename i_type, typename j_type>
			static constexpr j_type default_next_index2(c_type, d_type, i_type, j_type j)
			{
				return j;
			}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pair (experimental):

/***********************************************************************************************************************/

	using pair_type = depth_type const *;

	struct MInd
	{
		static constexpr index_type depth	= 0;
		static constexpr index_type index	= 1;
	};

	template<depth_type x, depth_type y>
	constexpr depth_type pair[] = { x, y };

//	template<depth_type x, depth_type y>
//	constexpr pair_type pair = f_array<depth_type, x, y>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// abstract:

/***********************************************************************************************************************/

// id:

	template<>
	struct machine<MN::id>
	{
		template<CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return MACHINE(n, c, d, i, j)(Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampolining:

/***********************************************************************************************************************/

// trampoline:

	template<auto d, typename T>
	constexpr auto machine_trampoline(T v) { return v; }

	template<auto d, auto RPack, auto... Hs>
	constexpr auto machine_trampoline(void(*)(alt_pack<RPack, Hs...>*));

	// helper (unpacks stack):

		template<auto d, auto un, auto c, auto i, auto j, auto... Vs, typename... Heaps>
		constexpr auto trampoline_next(void(*)(auto_pack<un, c, i, j, Vs...>*), Heaps... Hs)
		{
			using n = T_type_U<un>;

			return machine_trampoline<d-2>(MACHINE(n, c, d, i, j)(Hs...));
		}

	template<auto d, auto RPack, auto... Hs>
	constexpr auto machine_trampoline(void(*)(alt_pack<RPack, Hs...>*))
	{
		static_assert(bool(d), "machine trampolining nesting depth exceeded.");

		return trampoline_next<d>(RPack, Hs...);
	}

/***********************************************************************************************************************/

// start:

	template<CONTR_PARAMS, auto... Vs, typename... Heaps>
	constexpr auto machine_start()
	{
		return machine_trampoline<d>(MACHINE(n, c, d, i, j)(U_pack_Vs<>, U_pack_Vs<>));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

