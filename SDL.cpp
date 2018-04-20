/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:02:46 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 18:02:46 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.hpp"

SDL::SDL()
{
	struct sigaction action;
	sigaction(SIGINT, NULL, &action);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << SDL_GetError() << std::endl;
		exit (-1);
	}
	sigaction(SIGINT, &action, NULL);
	if (TTF_Init() < 0) {
		std::cout << (SDL_GetError()) << std::endl;
		exit (-1);
	}
	this->window1 = SDL_CreateWindow("Date Module", 0, 0, 1000, 400, SDL_WINDOW_ALLOW_HIGHDPI);
	this->window2 = SDL_CreateWindow("CPU Module", 0, 460, 1000, 400, SDL_WINDOW_ALLOW_HIGHDPI);
	this->window3 = SDL_CreateWindow("RAM Module", 1000, 0, 1000, 400, SDL_WINDOW_ALLOW_HIGHDPI);
	this->window4 = SDL_CreateWindow("Host Module", 0, 880, 1000, 400, SDL_WINDOW_ALLOW_HIGHDPI);
	this->window5 = SDL_CreateWindow("Network Module", 1000, 460, 1000, 400, SDL_WINDOW_ALLOW_HIGHDPI);
	this->window6 = SDL_CreateWindow("Disk Module", 1000, 880, 1000, 400, SDL_WINDOW_ALLOW_HIGHDPI);
	this->window7 = SDL_CreateWindow("OS Module", 2000, 0, 550, 400, SDL_WINDOW_ALLOW_HIGHDPI);
	if (!this->window1 || !this->window2 || !this->window3
		|| !this->window4 || !this->window5 || !this->window6 || !this->window7)
		exit(1);
	this->screen1 = SDL_GetWindowSurface(this->window1);
	this->screen2 = SDL_GetWindowSurface(this->window2);
	this->screen3 = SDL_GetWindowSurface(this->window3);
	this->screen4 = SDL_GetWindowSurface(this->window4);
	this->screen5 = SDL_GetWindowSurface(this->window5);
	this->screen6 = SDL_GetWindowSurface(this->window6);
	this->screen7 = SDL_GetWindowSurface(this->window7);

	if (!(this->picture[0] = IMG_Load("resources/images/spiral-clock.jpg"))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
	if (!(this->picture[1] = IMG_Load("resources/images/ram.jpg"))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
	if (!(this->picture[2] = IMG_Load("resources/images/cpu.jpg"))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
	if (!(this->picture[3] = IMG_Load("resources/images/network.jpg"))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
	if (!(this->picture[4] = IMG_Load("resources/images/host.jpg"))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
	if (!(this->picture[5] = IMG_Load("resources/images/disk.jpg"))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
	if (!(this->picture[6] = IMG_Load("resources/images/apple.png"))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}

	dateModule = DateModule();
	cpuModule = CPU();
	hostModule = Host();
	networkModule = Network();
	ramModule = RAM();
	diskModule = Disk();
	osModule = OS();

	if (!(this->ttf = TTF_OpenFont(FONTS_FOLDER"digital-7.ttf", 40))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
	if (!(this->ttf2 = TTF_OpenFont(FONTS_FOLDER"SFCartoonistHand-Bold.ttf", 40))) {
		std::cout << IMG_GetError() << std::endl;
		exit (-1);
	}
}

SDL::~SDL() {
	SDL_DestroyWindow(this->window1);
	SDL_DestroyWindow(this->window2);
	SDL_DestroyWindow(this->window3);
	SDL_DestroyWindow(this->window4);
	SDL_DestroyWindow(this->window5);
	SDL_DestroyWindow(this->window6);
	SDL_DestroyWindow(this->window7);
	TTF_CloseFont(this->ttf);
	TTF_CloseFont(this->ttf2);
	SDL_Quit();
}

void		SDL::displayTime(void)
{
	dateModule.update();
	this->ttime = TTF_RenderText_Solid(this->ttf, dateModule.getData("time").c_str(),
					(SDL_Color){255, 0, 0, 255});
	this->date = TTF_RenderText_Solid(this->ttf, dateModule.getData("data").c_str(),
					(SDL_Color){255, 0, 0, 255});
	SDL_Rect time_rect = { 10, 0, 0, 0 };
	SDL_Rect date_rect = { 10, this->ttime->h, 0, 0 };
	SDL_Rect pic = {0, 0, this->picture[0]->w / 2, this->picture[0]->h / 2};
	SDL_BlitScaled(this->picture[0], NULL, this->screen1, &pic);
	SDL_BlitSurface(this->ttime, NULL, this->screen1, &time_rect);
	SDL_BlitSurface(this->date, NULL, this->screen1, &date_rect);
	SDL_FreeSurface(this->ttime);
	SDL_FreeSurface(this->date);
}

void		SDL::displayCPU(void)
{
	this->cpu = TTF_RenderText_Solid(this->ttf, cpuModule.getData("cpu").c_str(),
					(SDL_Color){255, 0, 0, 255});
	SDL_Rect cpu_rect = { 10, 0, 0, 0};
	SDL_Rect pic = {100, 0, this->picture[2]->w / 2, this->picture[2]->h / 2};
	SDL_BlitScaled(this->picture[2], NULL, this->screen2, &pic);
	SDL_BlitSurface(this->cpu, NULL, this->screen2, &cpu_rect);
	SDL_FreeSurface(this->cpu);
}

void		SDL::displayRAM(void) {

	this->ram = TTF_RenderText_Solid(this->ttf, ramModule.getData("ram").c_str(),
					(SDL_Color){255, 0, 0, 255});
	SDL_Rect ram_rect = { 10, this->screen3->h - this->ram->h - 20, 0, 0};
	SDL_Rect pic = {0, -50, this->picture[1]->w / 3, this->picture[1]->h / 3};
	SDL_BlitScaled(this->picture[1], NULL, this->screen3, &pic);
	SDL_BlitSurface(this->ram, NULL, this->screen3, &ram_rect);
	SDL_FreeSurface(this->ram);
}

void		SDL::displayUser(void) {

	this->user = TTF_RenderText_Solid(this->ttf2, hostModule.getData("user").c_str(),
					(SDL_Color){255, 0, 0, 255});
	this->host = TTF_RenderText_Solid(this->ttf2, hostModule.getData("host").c_str(),
					(SDL_Color){255, 0, 0, 255});
	SDL_Rect user_rect = { 10, this->screen6->h - this->host->h - this->user->h - 20 , 0, 0};
	SDL_Rect host_rect = { 10, this->screen6->h - this->host->h - 20, 0, 0};
	SDL_Rect pic = {this->picture[4]->w / 4, 50, this->picture[4]->w / 2, this->picture[4]->h / 2};
	SDL_BlitScaled(this->picture[4], NULL, this->screen4, &pic);
	SDL_BlitSurface(this->user, NULL, this->screen4, &user_rect);
	SDL_BlitSurface(this->host, NULL, this->screen4, &host_rect);
	SDL_FreeSurface(this->user);
	SDL_FreeSurface(this->host);
}

void		SDL::displayNET(void) {

	this->net = TTF_RenderText_Solid(this->ttf, networkModule.getData("net").c_str(),
					(SDL_Color){255, 0, 0, 255});
	SDL_Rect net_rect = { 10, 0, 0, 0};
	SDL_Rect pic = {0, -150, this->picture[3]->w / 1.8, this->picture[3]->h / 1.8};
	SDL_BlitScaled(this->picture[3], NULL, this->screen5, &pic);
	SDL_BlitSurface(this->net, NULL, this->screen5, &net_rect);
	SDL_FreeSurface(this->net);
}

void		SDL::displayHDD(void) {

	this->disk = TTF_RenderText_Solid(this->ttf, diskModule.getData("disk").c_str(),
					(SDL_Color){255, 0, 0, 255});
	SDL_Rect disk_rect = { 10, this->screen6->h - this->disk->h - 20, 0, 0};
	SDL_Rect pic = {0, -150, this->picture[5]->w / 1.8, this->picture[5]->h / 1.8};
	SDL_BlitScaled(this->picture[5], NULL, this->screen6, &pic);
	SDL_BlitSurface(this->disk, NULL, this->screen6, &disk_rect);
	SDL_FreeSurface(this->disk);
}

void		SDL::displayOS(void) {
	this->OSname = TTF_RenderText_Solid(this->ttf2, osModule.getData("name").c_str(),
					(SDL_Color){255, 0, 0, 255});
	this->OSversion = TTF_RenderText_Solid(this->ttf2, osModule.getData("version").c_str(),
					(SDL_Color){255, 0, 0, 255});
	this->OSbuild = TTF_RenderText_Solid(this->ttf2, osModule.getData("build").c_str(),
					(SDL_Color){255, 0, 0, 255});
	SDL_Rect OSname_rect = { 10, this->screen7->h - this->OSbuild->h - this->OSname->h - this->OSname->h - 10, 0, 0};
	SDL_Rect OSversion_rect = { 10, this->screen7->h - this->OSbuild->h - this->OSname->h - 10, 0, 0};
	SDL_Rect OSbuild_rect = { 10, this->screen7->h - this->OSbuild->h - 10, 0, 0};
	SDL_Rect pic = {-120, -20, this->picture[6]->w / 1.5, this->picture[6]->h / 1.5};
	SDL_BlitScaled(this->picture[6], NULL, this->screen7, &pic);
	SDL_BlitSurface(this->OSname, NULL, this->screen7, &OSname_rect);
	SDL_BlitSurface(this->OSversion, NULL, this->screen7, &OSversion_rect);
	SDL_BlitSurface(this->OSbuild, NULL, this->screen7, &OSbuild_rect);
	SDL_FreeSurface(this->OSname);
	SDL_FreeSurface(this->OSversion);
	SDL_FreeSurface(this->OSbuild);
}

void	SDL::go() {
	SDL_Event	e;

	while (1)
	{
		while(SDL_PollEvent(&e))
		{
			if (e.window.event == SDL_WINDOWEVENT_CLOSE || (e.type == SDL_KEYDOWN &&
				e.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				return ;
		}
		bzero(screen1->pixels, screen1->w * screen1->h * 4);
		bzero(screen2->pixels, screen2->w * screen2->h * 4);
		bzero(screen3->pixels, screen3->w * screen3->h * 4);
		bzero(screen4->pixels, screen4->w * screen4->h * 4);
		bzero(screen5->pixels, screen5->w * screen5->h * 4);
		bzero(screen6->pixels, screen6->w * screen6->h * 4);
		bzero(screen7->pixels, screen7->w * screen7->h * 4);
		displayTime();
		displayCPU();
		displayRAM();
		displayUser();
		displayNET();
		displayHDD();
		displayOS();
		SDL_UpdateWindowSurface(this->window1);
		SDL_UpdateWindowSurface(this->window2);
		SDL_UpdateWindowSurface(this->window3);
		SDL_UpdateWindowSurface(this->window4);
		SDL_UpdateWindowSurface(this->window5);
		SDL_UpdateWindowSurface(this->window6);
		SDL_UpdateWindowSurface(this->window7);
	}
}

DateModule const& SDL::getDate(void) const {
	return this->dateModule;
}

CPU const& SDL::getCPU(void) const {
	return this->cpuModule;
}

Host const& SDL::getHost(void) const {
	return this->hostModule;
}

RAM const& SDL::getRAM(void) const {
	return this->ramModule;
}

Network const& SDL::getNetwork(void) const {
	return this->networkModule;
}

Disk const& SDL::getDisk(void) const {
	return this->diskModule;
}

OS const& SDL::getOS(void) const {
	return this->osModule;
}