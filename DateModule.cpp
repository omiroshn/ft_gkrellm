/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:10:35 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 15:10:35 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.hpp"

DateModule::DateModule() {
	this->update();
}

DateModule::DateModule(const DateModule &cpy) {
	*this = cpy;
}

DateModule& DateModule::operator=(const DateModule &cpy) {
	this->date = cpy.getData("data");
	this->ttime = cpy.getData("time");
	return (*this);
}

DateModule::~DateModule() { }

void	DateModule::update() {
	std::stringstream	ss;
	time_t t = time(0);
	struct tm *now = localtime(&t);
	ss << "Date: " << std::to_string(now->tm_mday) << "/"
				<< std::to_string(now->tm_mon + 1) << "/"
				<< std::to_string(now->tm_year + 1900);
	this->date = ss.str();
	ss.str(std::string());
	ss << "Time: " << std::to_string(now->tm_hour) + ":";
	if (now->tm_min <= 9)
		ss << "0" << std::to_string(now->tm_min) + ":";
	else
		ss << std::to_string(now->tm_min) + ":";
	if (now->tm_sec <= 9)
		ss << "0" << std::to_string(now->tm_sec);
	else
		ss << std::to_string(now->tm_sec);
	this->ttime = ss.str();
}

std::string		DateModule::getData(const std::string &type) const {
	if (type == "data")
		return this->date;
	else if (type == "time")
		return this->ttime;
	return ("No data to show. :(");
}
