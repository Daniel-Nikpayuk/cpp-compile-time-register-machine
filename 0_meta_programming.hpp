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

// template metaprogramming:

/*
	S   - variadic_value				(typename)
	T   - type					(typename)
	U   - type_map					(constexpr auto)
	V   - value					(constexpr auto)

	G   - template<typename> class
	F   - template<auto> class

	E   - template<typename, typename> class
	D   - template<typename, auto> class
	C   - template<auto, typename> class
	B   - template<auto, auto> class
*/

/***********************************************************************************************************************/

namespace meta_programming
{

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	constexpr void _na_()						{ }	// (not an auto)
	struct _nt_							{ };	// (not a typename)
	template<auto...> using _NA_					= _nt_;	// (not an auto template)
	template<typename...> using _NT_				= _nt_;	// (not a typename template)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto category:

/***********************************************************************************************************************/

// typename to auto (functor):

	template<typename T>
	using type_cache = T(*)();

	template<typename T>			// Unsafe to use directly,
	constexpr void type_map(T) { }		// as T cannot equal void.
						// use U_type_T instead:

	template<typename T>
	constexpr auto type_cache_to_map(void(*)(T(*)()))
	{
		return type_map<T*>;
	}

	template<typename T>
	constexpr auto type_cache_to_map(void(*)(T&(*)()))
	{
		return type_map<T&>;
	}

	template<typename T>								// This implementation was chosen
	constexpr auto U_type_T = type_cache_to_map(type_map<type_cache<T>>);		// as it simplifies the special
											// case when T == void.

	template<typename T>				// T_decltype(_type)_T:
	using T_decltype_T				= decltype(U_type_T<T>);

	template<auto V>				// U_(type_)decltype_V:
	constexpr auto U_decltype_V	 		= U_type_T<decltype(V)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename category:

/***********************************************************************************************************************/

// auto to typename recovery:

	template<typename> struct pattern_match_type_map;

	template<typename T>
	struct pattern_match_type_map<void(*)(T*)>
	{
		using type = T;
	};

	template<typename T>
	struct pattern_match_type_map<void(*)(T&)>
	{
		using type = T&;
	};

		// Use the fast version when possible.
		// (when T has an empty constructor/destructor)

	template<auto TMap>
	using T_type_U = typename pattern_match_type_map<decltype(TMap)>::type;

	//

	template<typename T>
	constexpr T type_init() { return { }; }

	template<typename T>
	constexpr auto type_map_to_cache(void(*)(T*))
	{
		return type_init<T>;
	}

	template<typename T>
	constexpr auto type_map_to_cache(void(*)(T&))
	{
		return type_init<T&>;
	}

	template<auto TMap>
	using T_fast_type_U = decltype(type_map_to_cache(TMap)());

/***********************************************************************************************************************/

	template<auto> struct auto_map { };

	template<auto V>
	using auto_cache_type = void(*)(auto_map<V>*);

	template<auto V>							// optimized because we know
	constexpr auto_cache_type<V> U_value_V = type_map<auto_map<V>*>;	// auto_map<V> is not a reference.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity type:

/***********************************************************************************************************************/

	template<typename T1, typename T2>
	constexpr bool V_is_equal_UxU(void(*)(T1), void(*)(T2))	// Unsafe to use directly,
		{ return false; }

	template<typename T>
	constexpr bool V_is_equal_UxU(void(*)(T), void(*)(T))	// Use the following instead:
		{ return true; }

	//

	template<auto TMap1, auto TMap2>
	constexpr bool V_equal_UxU = V_is_equal_UxU(TMap1, TMap2);

	template<auto TMap1, auto TMap2>
	constexpr bool V_not_equal_UxU = ! V_is_equal_UxU(TMap1, TMap2);

	//

	template<typename T1, typename T2>
	constexpr bool V_equal_TxT = V_is_equal_UxU(U_type_T<T1>, U_type_T<T2>);

	template<typename T1, typename T2>
	constexpr bool V_not_equal_TxT = ! V_is_equal_UxU(U_type_T<T1>, U_type_T<T2>);

	//

	template<auto V1, auto V2>
	constexpr bool V_equal_VxV = V_is_equal_UxU(U_value_V<V1>, U_value_V<V2>);		// optimized

	template<auto V1, auto V2>
	constexpr bool V_not_equal_VxV = ! V_is_equal_UxU(U_value_V<V1>, U_value_V<V2>);	// optimized

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identifiers (convenience aliases):

/***********************************************************************************************************************/

	constexpr auto U_void						= U_type_T<void>;
	constexpr auto U_char_ptr					= U_type_T<char*>;

	//

	template<typename T> constexpr bool V_equals_void		= V_equal_UxU<U_type_T<T>, U_void>;
	template<typename T> constexpr bool V_equals_char_ptr		= V_equal_UxU<U_type_T<T>, U_char_ptr>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

	template<auto...> struct auto_list	{ };
	template<auto...> struct alt_list	{ };

/***********************************************************************************************************************/

// at (fast tracking) [0-15):

	template
	<
		typename T,
		auto V0, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(0)>)) { return V0; }

	template
	<
		typename T,
		auto V0, auto V1, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(1)>)) { return V1; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(2)>)) { return V2; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(3)>)) { return V3; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(4)>)) { return V4; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(5)>)) { return V5; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(6)>)) { return V6; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(7)>)) { return V7; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(8)>)) { return V8; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(9)>)) { return V9; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(10)>)) { return V10; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(11)>)) { return V11; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(12)>)) { return V12; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto V13, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(13)>)) { return V13; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto V13, auto V14, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(14)>)) { return V14; }

	template
	<
		typename T,
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,
		auto V8, auto V9, auto V10, auto V11, auto V12, auto V13, auto V14, auto V15, auto... Vs
	>
	constexpr auto at(void(*)(auto_map<T(15)>)) { return V15; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

