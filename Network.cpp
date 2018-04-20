/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:18:45 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 17:18:46 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Network.hpp"

Network::Network(){};

std::string Network::getData(const std::string &type) const
{
	char	buffer[256];
	FILE*	in;
	std::string ret;
	std::stringstream ss;
	if (type == "net")
	{
		in = popen("top -l 1 | head -n 10 | grep Network", "r");
		while (fgets(buffer, sizeof(buffer), in) != NULL)
			ss << buffer;
		pclose(in);
		return ss.str();
	}
	else
		return ("No Network data to show. :(");
}

void Network::update()
{
	return ;
}