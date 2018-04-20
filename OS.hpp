/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:15:49 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/15 15:15:51 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OS_HPP
#define OS_HPP
#include "IMonitorModule.hpp"

class OS : public IMonitorModule
{
	private:
	std::string _ip;

	public:
	OS(OS const &){};	
	OS & operator=(OS const &){return *this;};		
	~OS(){};		
	OS();
	std::string getData(const std::string &) const;
	void update();
};

#endif