/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:00:09 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 18:00:11 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "IMonitorDisplay.hpp"
#include "Host.hpp"
#include "Network.hpp"
#include <ncurses.h>

class Ncurses : public IMonitorDisplay
{
private:
	int _active;
	Host _host;
	RAM _ram;
	CPU _cpu;
	Network _net;
	DateModule _date;
	Disk _disk;
	OS _os;
	Ncurses(const Ncurses &cpy);
	void printFrame();
	void printData();
	void printList();
	char *trm(char* trm);
	void displayHDD(void);
	void displayCPU(void);
	void displayRAM(void);
	void displayNET(void);
	void displayTime(void);
	void displayUser(void);
	void displayOS(void);
	void displayCat1(void);
	void displayCat2(void);

public:
	Ncurses& operator=(const Ncurses &cpy);
	Ncurses();
	~Ncurses();
	void go();
	DateModule const& getDate(void) const;
	CPU const& getCPU(void) const;
	Host const& getHost(void) const;
	RAM const& getRAM(void) const;
	Network const& getNetwork(void) const;
	Disk const& getDisk(void) const;
	OS const& getOS(void) const;
};

#endif
