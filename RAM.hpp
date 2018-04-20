/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:21:00 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 16:21:01 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
#define RAM_HPP
#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
private:
	std::string		ram;

public:
	RAM(RAM const &cpy);
	RAM& operator=(RAM const &cpy);	
	RAM();
	~RAM();
	std::string getData(const std::string &type) const;
	void		update();
};

#endif
