/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:15:45 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/15 15:15:46 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OS.hpp"

OS::OS(){};

std::string OS::getData(const std::string &type) const
{
	char buffer[256];
	FILE*    in;
	std::string ret;
	std::stringstream ss;
	if (type == "name")
	{
		in = popen("sw_vers | grep ProductName", "r");
		while (fgets(buffer, sizeof(buffer), in) != NULL)
       		ss << buffer;
       	pclose(in);
 		return ss.str();
	}
	else if (type == "version")
	{
		in = popen("sw_vers | grep ProductVersion", "r");
		while (fgets(buffer, sizeof(buffer), in) != NULL)
       		ss << buffer;
       	pclose(in);
 		return ss.str();
	}
	else if (type == "build")
	{
		in = popen("sw_vers | grep Build", "r");
		while (fgets(buffer, sizeof(buffer), in) != NULL)
       		ss << buffer;
       	pclose(in);
 		return ss.str();
	}	
	else
		return ("No OS data to show. :(");
}

void OS::update()
{
	return ;
}
