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

// machine controllers:

	// I would prefer to implement indices as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	using index_type = unsigned char;
	using depth_type = unsigned short;

	struct MH // machine hierarchy
	{
		static constexpr index_type variadic_machine		= 0;
		static constexpr index_type near_linear_machine		= 1;
		static constexpr index_type register_machine		= 2;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// s array:

	struct array_struct
	{
		template<typename Type, Type... Vs>
		static constexpr Type array[] = { Vs... };
	};

	template<typename Type, Type... Vs>
	constexpr auto s_array = array_struct::array<Type, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// locus:

	using v_loc_type = depth_type const*;

		// pack length is stored as the initial value.

	template<depth_type... Vs>
	constexpr v_loc_type v_locus = array_struct::array<depth_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// controller:

	using v_ctr_type = index_type const*;

	struct VCtr
	{
		static constexpr index_type size			=  0;

		static constexpr index_type length(v_ctr_type c)	{ return c[size]; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr v_ctr_type v_controller = array_struct::array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear:

/***********************************************************************************************************************/

// applications:

	using nl_appl_type = index_type const*;

	struct NLAppl
	{
		static constexpr index_type size				=  0;

		// registers:

		static constexpr index_type name				=  1;

		static constexpr index_type reg					=  2;
		static constexpr index_type op					=  3;
		static constexpr index_type arg					=  4;
		static constexpr index_type arg1				=  4;
		static constexpr index_type arg2				=  5;

		// procedures:

		static constexpr index_type length	(nl_appl_type i)	{ return i[size]     ; }
		static constexpr bool is_unary		(nl_appl_type i)	{ return i[size] == 4; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr nl_appl_type nl_application = array_struct::array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// continuation passing functors:

	using nl_cont_type = nl_appl_type const*;

	struct NLCont
	{
		static constexpr index_type size			=  0;

		// registers:

		static constexpr index_type name			=  1;
		static constexpr index_type appl			=  2;
		static constexpr index_type pred			=  2;
		static constexpr index_type appl1			=  3;
		static constexpr index_type appl2			=  4;

		// procedures:

		static constexpr index_type length(nl_cont_type l)	{ return l[size][size]; }
	};

		// pack length is stored as the initial value.

	template<nl_appl_type... Vs>
	constexpr nl_cont_type nl_continuation = array_struct::array
	<
		nl_appl_type, array_struct::array<index_type, sizeof...(Vs)>, Vs...
	>;

/***********************************************************************************************************************/

// controller:

	using nl_ctr_type = nl_cont_type const*;

	struct NLCtr
	{
		static constexpr index_type size			=  0;

		static constexpr index_type length(nl_ctr_type c)	{ return c[size][size][size]; }
	};

		// pack length is stored as the initial value.

	template<nl_cont_type... Vs>
	constexpr nl_ctr_type nl_controller = array_struct::array
	<
		nl_cont_type, array_struct::array
		<
			nl_appl_type, array_struct::array<index_type, sizeof...(Vs)>

		>, Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register:

/***********************************************************************************************************************/

// instructions:

	using r_inst_type = index_type const*;

	struct RInst
	{
		static constexpr index_type size			=  0;
		static constexpr index_type name			=  1;
		static constexpr index_type value			=  2;

		static constexpr index_type length(r_inst_type i)	{ return i[size]; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr r_inst_type r_instruction = array_struct::array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// labels:

	using r_lbl_type = r_inst_type const*;

	struct RLbl
	{
		static constexpr index_type size			=  0;
		static constexpr index_type first			=  1;

		static constexpr index_type length	(r_lbl_type l)	{ return l[size][size] ; }
		static constexpr r_inst_type last  	(r_lbl_type l)	{ return l[length(l)]  ; }
	};

		// pack length is stored as the initial value.

	template<r_inst_type... Vs>
	constexpr r_lbl_type label = array_struct::array
	<
		r_inst_type, array_struct::array<index_type, sizeof...(Vs)>, Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

	using r_ctr_type = r_lbl_type const*;

	struct RCtr
	{
		static constexpr index_type size			=  0;

		static constexpr index_type length	(r_ctr_type c)	{ return c[size][size][size]               ; }
		static constexpr r_lbl_type last  	(r_ctr_type c)	{ return c[length(c)]                      ; }
		static constexpr index_type reg_size	(r_ctr_type c)	{ return RLbl::last(last(c))[RInst::value] ; }
	};

		// pack length is stored as the initial value.

	template<r_lbl_type... Vs>
	constexpr r_ctr_type controller = array_struct::array
	<
		r_lbl_type, array_struct::array
		<
			r_inst_type, array_struct::array<index_type, sizeof...(Vs)>

		>, Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fast tracking:

/***********************************************************************************************************************/

// constants:

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

// dispatches:

	using _2_n_dispatch_type				= index_type(*)(depth_type);

	constexpr index_type _2_0_dispatch(depth_type n)	{ return (n >= _2_0) ?  1 :                0; }
	constexpr index_type _2_1_dispatch(depth_type n)	{ return (n >= _2_1) ?  2 : _2_0_dispatch(n); }
	constexpr index_type _2_2_dispatch(depth_type n)	{ return (n >= _2_2) ?  3 : _2_1_dispatch(n); }
	constexpr index_type _2_3_dispatch(depth_type n)	{ return (n >= _2_3) ?  4 : _2_2_dispatch(n); }
	constexpr index_type _2_4_dispatch(depth_type n)	{ return (n >= _2_4) ?  5 : _2_3_dispatch(n); }
	constexpr index_type _2_5_dispatch(depth_type n)	{ return (n >= _2_5) ?  6 : _2_4_dispatch(n); }
	constexpr index_type _2_6_dispatch(depth_type n)	{ return (n >= _2_6) ?  7 : _2_5_dispatch(n); }
	constexpr index_type _2_7_dispatch(depth_type n)	{ return (n >= _2_7) ?  8 : _2_6_dispatch(n); }
	constexpr index_type _2_8_dispatch(depth_type n)	{ return (n >= _2_8) ?  9 : _2_7_dispatch(n); }
	constexpr index_type _2_9_dispatch(depth_type n)	{ return (n >= _2_9) ? 10 : _2_8_dispatch(n); }

	constexpr _2_n_dispatch_type get_dispatch(depth_type n)
	{
		return	(n >= _2_9) ? _2_9_dispatch :
			(n >= _2_8) ? _2_8_dispatch :
			(n >= _2_7) ? _2_7_dispatch :
			(n >= _2_6) ? _2_6_dispatch :
			(n >= _2_5) ? _2_5_dispatch :
			(n >= _2_4) ? _2_4_dispatch :
			(n >= _2_3) ? _2_3_dispatch :
			(n >= _2_2) ? _2_2_dispatch :
			(n >= _2_1) ? _2_1_dispatch : _2_0_dispatch ;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// depth:

	constexpr depth_type fast_track_depth(depth_type d)
	{
		depth_type count = 2; // offset to include transitions.

		while (bool(d))
		{
			count += (d % 2);
			d >>= 1;
		}

		return count;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

