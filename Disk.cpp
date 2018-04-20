/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:35:07 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/15 11:35:09 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Disk.hpp"

Disk::Disk(){};

std::string Disk::getData(const std::string &type) const
{
	char buffer[256];
	FILE*    in;
	std::string ret;
	std::stringstream ss;
	if (type == "disk")
	{
		in = popen("top -l 1 | head -n 10 | grep Disk", "r");
		while (fgets(buffer, sizeof(buffer), in) != NULL)
       		ss << buffer;
       	pclose(in);
 		return ss.str();
	}
	else
		return ("No Disk data to show. :(");
}

void Disk::update()
{
	return ;
}
