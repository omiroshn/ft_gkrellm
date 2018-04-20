/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disk.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:35:13 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/15 11:35:14 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_HPP
#define DISK_HPP
#include "IMonitorModule.hpp"

class Disk : public IMonitorModule
{
	private:
	std::string _ip;

	public:
	Disk(Disk const &){};	
	Disk & operator=(Disk const &){return *this;};		
	~Disk(){};		
	Disk();
	std::string getData(const std::string &) const;
	void update();
};

#endif
