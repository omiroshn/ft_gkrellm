/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:18:49 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 17:18:50 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
	private:
	std::string _ip;

	public:
	Network(Network const &){};	
	Network & operator=(Network const &){return *this;};		
	~Network(){};		
	Network();
	std::string getData(const std::string &) const;
	void update();
};

#endif

