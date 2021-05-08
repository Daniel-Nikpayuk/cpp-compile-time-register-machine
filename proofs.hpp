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

// proofs:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// nesting depth:

/***********************************************************************************************************************/

/*
	Theorem:

	The total nesting depth of any given machine---given its initial depth d---is at least d(d+2).
*/

/*
	Proof:

	There are two versions of machince_trampoline: The one that halts, and the one that recurses.
	The one that recurses calls trampoline_next which then calls machine_trampoline again.
	This is to say each iteration calls two functions, hence a nesting depth decrement of two.

	Now, without total loss of generality assume d is even, so d = 2n, then our total nesting depth is:

		2n + 2n-2 + 2n-4 + ... + 2

		= 2(n + n-1 + ... + 1)

		= n(n+1)

		= d(d+2)/4

	QED.
*/

/*
	Comments:

	I say *at least* because there is a finite number of additional depths required, for example when calling
	MN::apply, MN::compel machines.

	Also, the default depth is d = 500, so the default total depth is 250(251) = 62 750.
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// macros:

/***********************************************************************************************************************/

// fold:

/*
	The block fold macro pattern is derived from the following pattern:

		2^0 -	op(val, V0),
		2^1 -	op(op(val, V0), V1),
		2^2 -	op(op(op(op(val, V0), V1), V2), V3),
		2^3 -	op(op(op(op(op(op(op(op(val, V0), V1), V2), V3), V4), V5), V6), V7),

	Spacing things out, we get:

		2^0 -	op(                         val,    V0),
		2^1 -	op(op(                      val,    V0), V1),
		2^2 -	op(op(op(op(                val,    V0), V1), V2), V3),
		2^3 -	op(op(op(op(op(op(op(op(    val,    V0), V1), V2), V3), V4), V5), V6), V7),
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

