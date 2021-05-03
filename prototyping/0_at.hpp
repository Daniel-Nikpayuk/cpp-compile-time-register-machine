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

// at:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// Q: How is nesting depth effected?

/***********************************************************************************************************************/

	using index_type = unsigned char;
	using depth_type = unsigned short;

	struct Dsp
	{
		static constexpr index_type return_first	= 0;
		static constexpr index_type drop_first		= 1;
	};

/***********************************************************************************************************************/

// version 0:

	template<index_type> struct at_struct_v0;

	template<>
	struct at_struct_v0<Dsp::return_first>
	{
		template<auto n, auto V, auto... Vs>
		static constexpr auto result = V;
	};

	template<>
	struct at_struct_v0<Dsp::drop_first>
	{
		template<auto n, auto V, auto... Vs>
		static constexpr auto result = at_struct_v0<bool(n)>::template result<n-1, Vs...>;
	};

	template<auto n, auto... Vs>
	constexpr auto at_unpack_v0(void(*)(auto_pack<Vs...>*))
	{
		return at_struct_v0<bool(n)>::template result<n, Vs...>;
	}

	template<typename List, depth_type n>
	constexpr auto at_v0 = at_unpack_v0<n>(U_type_T<List>);

/***********************************************************************************************************************/

// version 1:

	template<index_type> struct at_struct_v1;

	template<>
	struct at_struct_v1<Dsp::return_first>
	{
		template<auto n, auto V, auto... Vs>
		static constexpr auto machine()
		{
			return V;
		}
	};

	template<>
	struct at_struct_v1<Dsp::drop_first>
	{
		template<auto n, auto V, auto... Vs>
		static constexpr auto machine()
		{
			return at_struct_v1<bool(n)>::template machine<n-1, Vs...>();
		}
	};

	template<auto n, auto... Vs>
	constexpr auto at_unpack_v1(void(*)(auto_pack<Vs...>*))
	{
		return at_struct_v1<bool(n)>::template machine<n, Vs...>();
	}

	template<typename List, depth_type n>
	constexpr auto at_v1 = at_unpack_v1<n>(U_type_T<List>);

/***********************************************************************************************************************/

// version 2:

	template<auto n, auto V, auto... Vs>
	constexpr auto at_machine_v2(void(*)(auto_pack<Dsp::return_first>*))
	{
		return V;
	}

	template<auto n, auto V, auto... Vs>
	constexpr auto at_machine_v2(void(*)(auto_pack<Dsp::drop_first>*))
	{
		return at_machine_v2<n-1, Vs...>(U_value_V<index_type(n != 0)>);
	}

	template<auto n, auto... Vs>
	constexpr auto at_unpack_v2(void(*)(auto_pack<Vs...>*))
	{
		return at_machine_v2<n, Vs...>(U_value_V<index_type(n != 0)>);
	}

	template<typename List, depth_type n>
	constexpr auto at_v2 = at_unpack_v2<n>(U_type_T<List>);

/***********************************************************************************************************************/

	// results (list length == 1000 ; n == 500 ; return == 3):

// version 0:							// version 1:
                                                                        
	// gcc nesting depth: 900                               	// gcc nesting depth: 900
	// clang nesting depth: 900                             	// clang nesting depth: 500
                                                                
//		gcc compile time:	gcc run time:           //		gcc compile time:	gcc run time:
//		                                                //		                        
//		real	0m3.969s        real	0m0.001s        //		real	0m2.495s        real	0m0.002s
//		user	0m3.557s        user	0m0.001s        //		user	0m2.291s        user	0m0.002s
//		sys	0m0.268s        sys	0m0.000s        //		sys	0m0.199s        sys	0m0.000s
//		                                                //		                        
//		clang compile time:     clang run time:         //		clang compile time:     clang run time:
//		                                                //		                        
//		real	0m4.950s        real	0m0.001s        //		real	0m5.145s        real	0m0.002s
//		user	0m4.649s        user	0m0.001s        //		user	0m4.905s        user	0m0.000s
//		sys	0m0.245s        sys	0m0.000s        //		sys	0m0.217s        sys	0m0.001s

// version 2:

	// gcc nesting depth: 900
	// clang nesting depth: 500

//		gcc compile time:	gcc run time:
//		                        
//		real	0m3.903s        real	0m0.002s
//		user	0m3.650s        user	0m0.002s
//		sys	0m0.233s        sys	0m0.000s
//		                        
//		clang compile time:     clang run time:
//		                        
//		real	0m9.277s        real	0m0.001s
//		user	0m8.913s        user	0m0.000s
//		sys	0m0.337s        sys	0m0.001s

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

