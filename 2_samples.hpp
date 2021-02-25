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

// samples:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace samples
{
	using namespace register_machine;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// factorial:

/***********************************************************************************************************************/

	template
	<
		// registers:

			index_type cont		= 0,
			index_type val		= 1,
			index_type n		= 2,
			index_type eq		= 3,
			index_type sub		= 4,
			index_type mult		= 5,
			index_type c_1		= 6,

		// labels:

			index_type fact_loop	= 1,
			index_type after_fact	= 2,
			index_type base_case	= 3,
			index_type fact_done	= 4
	>
	static constexpr auto fact_contr = controller
	<
		label // fact loop:
		<
			instruction < RI::b_branch , base_case , eq         , n , c_1 >,
			instruction < RI::save     , cont                             >,
			instruction < RI::save     , n                                >,
			instruction < RI::b_apply  , n         , sub        , n , c_1 >,
			instruction < RI::l_assign , cont      , after_fact           >,
			instruction < RI::l_goto   , fact_loop                        >
		>,

		label // after fact:
		<
			instruction < RI::restore  , n                     >,
			instruction < RI::restore  , cont                  >,
			instruction < RI::b_apply  , val  , mult , n , val >,
			instruction < RI::r_goto   , cont                  >
		>,

		label // base case:
		<
			instruction < RI::r_assign , val  , c_1 >,
			instruction < RI::r_goto   , cont       >
		>,

		label // fact done:
		<
			instruction < RI::stop       >,
			instruction < RI::r_size , 7 >
		>
	>;

	template<auto n, depth_type depth = 500>
	constexpr auto factorial = list_at<1>(machine<depth, fact_contr<>, 4, 1, n,
		equal<decltype(n)>, subtract<decltype(n)>, multiply<decltype(n)>, 1>(U_pair_V<RI::start, index_type(0)>));

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

