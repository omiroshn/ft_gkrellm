/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Host.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:22:00 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 15:22:01 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Host.hpp"

Host::Host()
{
	this->update();
}

Host::~Host(){}

Host::Host(const Host &cpy)
{
	*this = cpy;
}

Host& Host::operator=(const Host &cpy) 
{
	_user = cpy.getUser();
	_host = cpy.getHost();
	return (*this);
}

std::string Host::getUser() const
{
	return _user;
}

std::string Host::getHost() const
{
	return _host;
}

std::string Host::getData(const std::string & str) const
{

	std::string out("");        
	if (str.compare("user") == 0)
	{
		out = out.append("User: ");
		out = out.append(_user);
		return (out);
	}
	else if (str.compare("host") == 0)
	{
		out = out.append("Host: ");
		out = out.append(_host);
	}
	else
	{
		out = out.append("Error");
	}
	return (out);
}

void Host::update()
{
	char hostname[100];
	char username[100];
	gethostname(hostname, 100);
	getlogin_r(username, 100);
	_host = hostname;
	_user = username;
}