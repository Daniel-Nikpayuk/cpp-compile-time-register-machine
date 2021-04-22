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
		// block:

			// halters:

				static constexpr index_type pause			=  0;

				static constexpr index_type first			=  1;
				static constexpr index_type rest			=  2;
				static constexpr index_type pack			=  3;

			// debuggers:

				static constexpr index_type depth			=  4;
				static constexpr index_type dump			=  5;

			// interoperability:

				static constexpr index_type pass			=  6;

			// passers:

				// stack -> stack:

				static constexpr index_type pop_2_n			=  7;
				static constexpr index_type push_2_n			=  8;
				static constexpr index_type fold_2_n			=  9;

				// stack -> heap:

				static constexpr index_type move_2_n_s_to_h0		= 10;
				static constexpr index_type move_2_n_s_to_h1		= 11;

		// variadic:

			// halters:

				static constexpr index_type stop			= 12;

			// passers:

				// stack -> stack:

				static constexpr index_type pop				= 13;
				static constexpr index_type push			= 14;
				static constexpr index_type fold			= 15;

				// stack -> heap:

				static constexpr index_type copy_s0_to_h0		= 16;

				static constexpr index_type move_s_to_h0		= 17;
				static constexpr index_type move_s_to_h1		= 18;

				// heap -> stack:

				static constexpr index_type copy_h0_to_sf		= 19;
				static constexpr index_type copy_h1_to_sf		= 20;

				static constexpr index_type move_h0_to_sf		= 21;
				static constexpr index_type move_h1_to_sf		= 22;

				static constexpr index_type apply1_move_h0_to_sf	= 23;
				static constexpr index_type apply2_move_h0_to_sf	= 24;

		// permutatic:

			// passers:

				static constexpr index_type copy_sn_to_h0		= 25;
				static constexpr index_type move_sn_to_h0		= 26;

				static constexpr index_type erase_sn			= 27;
				static constexpr index_type insert_h0_to_sn		= 28;
				static constexpr index_type replace_h0_to_sn		= 29;

				static constexpr index_type apply1_replace_h0_to_sn	= 30;
				static constexpr index_type apply2_replace_h0_to_sn	= 31;

		// distributic:

			// passers:

				static constexpr index_type erase			= 32;
				static constexpr index_type insert			= 33;
				static constexpr index_type replace			= 34;

				static constexpr index_type apply			= 35;
				static constexpr index_type test			= 36;
				static constexpr index_type jump			= 37;

		// near linear:

			// halters:

				static constexpr index_type halt			= 38;

			// passers:

				static constexpr index_type lift			= 39;
				static constexpr index_type stem			= 40;
				static constexpr index_type costem			= 41;
				static constexpr index_type cycle			= 42;

		// register:

			// passers:

				static constexpr index_type assign			= 43;

				static constexpr index_type branch			= 44;
				static constexpr index_type go_to_s0			= 45;
				static constexpr index_type go_to			= 46;

				static constexpr index_type save			= 47;
				static constexpr index_type restore			= 48;

		// reflection:

			// sizes:

				static constexpr index_type reg_size			= 49;
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

			static constexpr index_type test	= 3;
			static constexpr index_type input	= 4;
			static constexpr index_type input1	= 4;
			static constexpr index_type input2	= 5;

		// procedures:

			static constexpr index_type length(ma_type a) { return a(size); }
			static constexpr index_type arity(index_type args) { return (args == 1) ? unary : binary; }
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

}

#endif

