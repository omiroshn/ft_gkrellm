/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:10:18 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 15:10:18 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

# include "DateModule.hpp"
# include "CPU.hpp"
# include "Host.hpp"
# include "RAM.hpp"
# include "Network.hpp"
# include "Disk.hpp"
# include "OS.hpp"

class IMonitorDisplay
{
public:
	virtual void go(void) = 0;
	virtual DateModule const& getDate(void) const = 0;
	virtual CPU const& getCPU(void) const = 0;
	virtual Host const& getHost(void) const = 0;
	virtual RAM const& getRAM(void) const = 0;
	virtual Network const& getNetwork(void) const = 0;
	virtual Disk const& getDisk(void) const = 0;
	virtual OS const& getOS(void) const = 0;
	virtual void displayHDD(void) = 0;
	virtual void displayCPU(void) = 0;
	virtual void displayRAM(void) = 0;
	virtual void displayNET(void) = 0;
	virtual void displayTime(void) = 0;
	virtual void displayUser(void) = 0;
	virtual void displayOS(void) = 0;
};

#endif
