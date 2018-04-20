/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:10:09 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 15:10:10 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <stdio.h>

# include <mach/mach.h>
# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <net/if.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "net/if.h"
# include <sys/sysctl.h>
# include <ifaddrs.h>
# include <net/if_dl.h>
# include <math.h>

# include <sys/ioctl.h>
# include <unistd.h>
# include <limits.h>

class IMonitorModule
{
public:

	virtual std::string		getData(const std::string &str) const = 0;
	virtual void			update() = 0;

};

#endif
