/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:20:55 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 16:20:57 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAM.hpp"

RAM::RAM() {}

RAM::~RAM() { }

RAM::RAM(const RAM &cpy) {
	*this = cpy;
}

RAM& RAM::operator=(RAM const &) 
{
	return (*this);
}

std::string RAM::getData(const std::string &type) const
{
	char buffer[256];
	FILE*    in;
	std::string ret;
	std::stringstream ss;
	if (type == "ram")
	{
		in = popen("top -l 1 | head -n 10 | grep PhysMem", "r");
		while (fgets(buffer, sizeof(buffer), in) != NULL)
			ss << buffer;
		pclose(in);
		return ss.str();
	}
	else
		return ("No ram data to show. :(");
}

void RAM::update()
{

}
