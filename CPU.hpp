/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:44:28 by dbuy              #+#    #+#             */
/*   Updated: 2018/04/14 15:44:30 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
#define CPU_HPP

#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
public:
	CPU(CPU const &);	
	CPU& operator=(CPU const &);	
	CPU();
	~CPU();
	std::string		getData(const std::string &type) const;
	void			update();
};

#endif

