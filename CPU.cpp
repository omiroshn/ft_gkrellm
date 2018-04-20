/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:44:24 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 15:44:26 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPU.hpp"

CPU::CPU() {}

CPU::~CPU() {}

CPU::CPU(const CPU &cpy) {
	*this = cpy;
}

CPU& CPU::operator=(const CPU &) 
{
	return (*this);
}

std::string CPU::getData(const std::string &type) const
{
	char buffer[256];
	FILE*    in;
	std::string ret;
	std::stringstream ss;
	if (type == "cpu")
	{
		in = popen("top -l 1 | head -n 10 | grep CPU", "r");
		while (fgets(buffer, sizeof(buffer), in) != NULL)
       		ss << buffer;
       	pclose(in);
 		return ss.str();
	}
	else
		return ("No data to show. :(");
}

void CPU::update()
{

}

