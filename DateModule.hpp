/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:10:26 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 15:10:27 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEMODULE_HPP
#define DATEMODULE_HPP

#include "IMonitorModule.hpp"

class DateModule : public IMonitorModule
{
private:
	std::string date;
	std::string ttime;
public:
	DateModule();
	DateModule(const DateModule &cpy);
	DateModule& operator=(const DateModule &cpy);
	~DateModule();
	void	update();
	std::string		getData(const std::string &type) const;
};

#endif
