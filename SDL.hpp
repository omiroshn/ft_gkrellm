/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:02:08 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 18:02:09 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HPP
#define SDL_HPP

# define WIDTH 600
# define HEIGHT 1000

# define FONTS_FOLDER "resources/fonts/"

# include <signal.h>
# include <SDL2/SDL.h>
# include <OpenCL/opencl.h>
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"

# include "IMonitorDisplay.hpp"

class SDL : public IMonitorDisplay
{
private:
	SDL_Window			*window1;
	SDL_Window			*window2;
	SDL_Window			*window3;
	SDL_Window			*window4;
	SDL_Window			*window5;
	SDL_Window			*window6;
	SDL_Window			*window7;

	SDL_Surface			*screen1;
	SDL_Surface			*screen2;
	SDL_Surface			*screen3;
	SDL_Surface			*screen4;
	SDL_Surface			*screen5;
	SDL_Surface			*screen6;
	SDL_Surface			*screen7;

	SDL_Surface			*date;
	SDL_Surface			*ttime;
	SDL_Surface			*cpu;
	SDL_Surface			*ram;
	SDL_Surface			*user;
	SDL_Surface			*host;
	SDL_Surface			*net;
	SDL_Surface			*disk;
	SDL_Surface			*OSname;
	SDL_Surface			*OSversion;
	SDL_Surface			*OSbuild;

	SDL_Surface			*picture[7];

	TTF_Font			*ttf;
	TTF_Font			*ttf2;

	DateModule			dateModule;
	CPU					cpuModule;
	Host				hostModule;
	Network				networkModule;
	RAM					ramModule;
	Disk				diskModule;
	OS					osModule;

	SDL(const SDL &cpy);
	SDL& operator=(const SDL &cpy);
public:
	SDL();
	~SDL();
	void	go(void);
	void	lsync(void);
	void	displayHDD(void);
	void	displayCPU(void);
	void	displayRAM(void);
	void	displayNET(void);
	void	displayTime(void);
	void	displayUser(void);
	void	displayOS(void);

	DateModule const& getDate(void) const;
	CPU const& getCPU(void) const;
	Host const& getHost(void) const;
	RAM const& getRAM(void) const;
	Network const& getNetwork(void) const;
	Disk const& getDisk(void) const;
	OS const& getOS(void) const;
};

#endif
