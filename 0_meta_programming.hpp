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

#ifndef _0_META_PROGRAMMING_HPP
#define _0_META_PROGRAMMING_HPP

// template metaprogramming:

/*
	S   - variadic_value				(typename)
	T   - type					(typename)
	U   - type_map					(constexpr auto)
	V   - value					(constexpr auto)

	B   - template<typename...> class
	C   - template<auto...> class
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
	using safe_type = T(*)();

	template<typename T>			// Unsafe to use directly,
	constexpr void type_map(T) { }		// as T cannot equal void.
						// use U_type_T instead:

	template<typename T>
	constexpr auto safe_type_to_map(void(*)(T(*)()))
	{
		return type_map<T*>;
	}

	template<typename T>
	constexpr auto safe_type_to_map(void(*)(T&(*)()))
	{
		return type_map<T&>;
	}

	template<typename T>								// This implementation was chosen
	constexpr auto U_type_T = safe_type_to_map(type_map<safe_type<T>>);		// as it simplifies the special
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

	template<typename> struct pattern_match_map_type;

	template<typename T>
	struct pattern_match_map_type<void(*)(T*)>
	{
		using pretype = T;
	};

	template<typename T>
	struct pattern_match_map_type<void(*)(T&)>
	{
		using pretype = T&;
	};

		// Use the fast version when possible.
		// (when T has an empty constructor/destructor)

	template<typename T>
	using T_pretype_T = typename pattern_match_map_type<T>::pretype;

	template<auto TMap>
	using T_type_U = typename pattern_match_map_type<decltype(TMap)>::pretype;

	//

	template<typename T>
	constexpr T type_map_to_init_type(void(*)(T*))
	{
		return { };
	}

	template<auto TMap>
	using T_fast_type_U = decltype(type_map_to_init_type(TMap));	// Does not work with type references.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomic functions:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	template<typename T> constexpr bool equal(T a1, T a2)				{ return (a1 == a2); }
	template<typename T> constexpr bool not_equal(T a1, T a2)			{ return (a1 != a2); }
	template<typename T> constexpr bool less_than(T a1, T a2)			{ return (a1 < a2); }
	template<typename T> constexpr bool less_than_or_equal(T a1, T a2)		{ return (a1 <= a2); }
	template<typename T> constexpr bool greater_than(T a1, T a2)			{ return (a1 > a2); }
	template<typename T> constexpr bool greater_than_or_equal(T a1, T a2)		{ return (a1 >= a2); }

	template<typename T, T V> constexpr bool is_value(T a)				{ return (a == V); }
	template<typename T, T V> constexpr bool not_value(T a)				{ return (a != V); }
	template<typename T, T V> constexpr bool is_less_than(T a)			{ return (a < V); }
	template<typename T, T V> constexpr bool is_less_than_or_equal(T a)		{ return (a <= V); }
	template<typename T, T V> constexpr bool is_greater_than(T a)			{ return (a > V); }
	template<typename T, T V> constexpr bool is_greater_than_or_equal(T a)		{ return (a >= V); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constants:

/***********************************************************************************************************************/

	template<typename T, T V> constexpr T constant()				{ return V; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arithmetic operators:

/***********************************************************************************************************************/

	template<typename T> constexpr T add(T a1, T a2)				{ return a1 + a2; }
	template<typename T> constexpr T subtract(T a1, T a2)				{ return a1 - a2; }
	template<typename T> constexpr T multiply(T a1, T a2)				{ return a1 * a2; }
	template<typename T> constexpr T divide(T a1, T a2)				{ return a1 / a2; }
	template<typename T> constexpr T modulo(T a1, T a2)				{ return a1 % a2; }

	template<typename T, T V> constexpr T add_by(T a)				{ return a + V; }
	template<typename T, T V> constexpr T subtract_by(T a)				{ return a - V; }
	template<typename T, T V> constexpr T multiply_by(T a)				{ return a * V; }
	template<typename T, T V> constexpr T divide_by(T a)				{ return a / V; }
	template<typename T, T V> constexpr T modulo_by(T a)				{ return a % V; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// comparative operators:

/***********************************************************************************************************************/

	template<typename T> constexpr T max(T a1, T a2)				{ return a1 > a2 ? a1 : a2; }
	template<typename T> constexpr T min(T a1, T a2)				{ return a1 < a2 ? a1 : a2; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// auto:

	template<auto...> struct auto_pack				{ };
	template<auto...> struct alt_pack				{ };

	template<auto... Vs>						// optimized because we know
	constexpr auto U_pack_Vs = type_map<auto_pack<Vs...>*>;		// auto_pack<Vs...> is not a reference.

	template<auto... Vs>						// optimized because we know
	constexpr auto U_alt_pack_Vs = type_map<alt_pack<Vs...>*>;	// alt_pack<Vs...> is not a reference.

/***********************************************************************************************************************/

// is auto map:

	template<typename T>
	constexpr bool V_is_auto_map_V(T)
		{ return false; }

	template<auto... Vs>
	constexpr bool V_is_auto_map_V(void(*)(auto_pack<Vs...>*))
		{ return true; }

/***********************************************************************************************************************/

// is auto pack:

	template<typename T>
	constexpr bool V_is_auto_pack_U(void(*)(T))			// Unsafe to use directly,
		{ return false; }

	template<auto... Vs>
	constexpr bool V_is_auto_pack_U(void(*)(auto_pack<Vs...>*))	// Use the following instead:
		{ return true; }

	//

	template<typename T>
	constexpr bool V_is_auto_pack_T = V_is_auto_pack_U(U_type_T<T>);

/***********************************************************************************************************************/

// is alt map:

	template<typename T>
	constexpr bool V_is_alt_map_V(T)
		{ return false; }

	template<auto... Vs>
	constexpr bool V_is_alt_map_V(void(*)(alt_pack<Vs...>*))
		{ return true; }

/***********************************************************************************************************************/

// is alt pack:

	template<typename T>
	constexpr bool V_is_alt_pack_U(void(*)(T))			// Unsafe to use directly,
		{ return false; }

	template<auto... Vs>
	constexpr bool V_is_alt_pack_U(void(*)(alt_pack<Vs...>*))	// Use the following instead:
		{ return true; }

	//

	template<typename T>
	constexpr bool V_is_alt_pack_T = V_is_alt_pack_U(U_type_T<T>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// template:

	template<template<auto...> class...> struct template_pack	{ };

	template<template<auto...> class... Cs>				// optimized because we know
	constexpr auto U_pack_Cs = type_map<template_pack<Cs...>*>;	// auto_pack<Vs...> is not a reference.

/***********************************************************************************************************************/

// is template map:

	template<typename T>
	constexpr bool V_is_template_map_V(T)
		{ return false; }

	template<template<auto...> class... Cs>
	constexpr bool V_is_template_map_V(void(*)(template_pack<Cs...>*))
		{ return true; }

/***********************************************************************************************************************/

// is template pack:

	template<typename T>
	constexpr bool V_is_template_pack_U(void(*)(T))				// Unsafe to use directly,
		{ return false; }

	template<template<auto...> class... Cs>
	constexpr bool V_is_template_pack_U(void(*)(template_pack<Cs...>*))	// Use the following instead:
		{ return true; }

	//

	template<typename T>
	constexpr bool V_is_template_pack_T = V_is_template_pack_U(U_type_T<T>);

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
	constexpr bool V_equal_TxT = V_is_equal_UxU(type_map<safe_type<T1>>, type_map<safe_type<T2>>);

	template<typename T1, typename T2>
	constexpr bool V_not_equal_TxT = ! V_is_equal_UxU(type_map<safe_type<T1>>, type_map<safe_type<T2>>);

	//

	template<auto V1, auto V2>
	constexpr bool V_equal_VxV = V_is_equal_UxU(U_pack_Vs<V1>, U_pack_Vs<V2>);		// optimized

	template<auto V1, auto V2>
	constexpr bool V_not_equal_VxV = ! V_is_equal_UxU(U_pack_Vs<V1>, U_pack_Vs<V2>);	// optimized

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identifiers (convenience aliases):

/***********************************************************************************************************************/

	constexpr auto U_void						= U_type_T<void>;
	constexpr auto U_char_ptr					= U_type_T<char*>;

	//

	template<typename T> constexpr bool V_equals_void		= V_equal_TxT<T, void>;
	template<typename T> constexpr bool V_equals_char_ptr		= V_equal_TxT<T, char*>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pointers:

	template<typename T>
	constexpr bool V_is_pointer_U(void(*)(T))		// Unsafe to use directly,
		{ return false; }

	template<typename T>
	constexpr bool V_is_pointer_U(void(*)(T*(*)()))		// Use the following instead:
		{ return true; }

	//

	template<typename T>
	constexpr bool V_is_pointer_T = V_is_pointer_U(type_map<safe_type<T>>);	// optimized

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// references:

	template<typename T>
	constexpr bool V_is_reference_U(void(*)(T))		// Unsafe to use directly,
		{ return false; }

	template<typename T>
	constexpr bool V_is_reference_U(void(*)(T&(*)()))	// Use the following instead:
		{ return true; }

	//

	template<typename T>
	constexpr bool V_is_reference_T = V_is_reference_U(type_map<safe_type<T>>);	// optimized

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

