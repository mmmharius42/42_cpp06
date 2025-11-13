/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:42:15 by mpapin            #+#    #+#             */
/*   Updated: 2025/11/13 15:55:38 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base();
};

class A: public Base
{};

class B: public Base
{};

class C: public Base
{};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif