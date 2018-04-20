/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Host.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:22:04 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 15:22:05 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOST_HPP
#define HOST_HPP

#include "IMonitorModule.hpp"

class Host : public IMonitorModule
{
	private:
	std::string _host;
	std::string _user;



	public:
	Host& operator=(Host const &);
	Host(Host const &);
	~Host();		
	Host();
	void update();

	std::string getUser() const;
	std::string getHost() const;
	std::string getData(const std::string & str) const;
};

#endif