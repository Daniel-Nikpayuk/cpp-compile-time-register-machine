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

#include<cstdio>

/***********************************************************************************************************************/

#include"include.hpp"

	using namespace machine_space;

#include"testing/unit_lists.hpp"
//#include"case-studies/0_factorial.hpp"
//#include"case-studies/1_fibonacci.hpp"
#include"case-studies/2_filter.hpp"

/***********************************************************************************************************************/

	using utype = unsigned long long;
	using stype =   signed long long;

/***********************************************************************************************************************/

	template<typename T>
	constexpr T square(T x) { return x*x; }

//	constexpr auto func	= do_compose
//				<
//					square<int>,
//					square<int>,
//					multiply_by<int, 2>,
//					add_by<int, 1>
//				>;

	constexpr auto func	= n_safe_do_compose
				<
					add_by<int, 1>,
					multiply_by<int, 3>,
					_id_,
					square<int>
				>;

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%d\n", func(utype(5)));

	//	printf("%llu\n", r_factorial<utype(5)>);

		return 0;
	}

