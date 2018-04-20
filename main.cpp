/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:21:55 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 17:21:56 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.hpp"
#include "Ncurses.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./ft_gkrellm [flag] [-h]" << std::endl;
		return (0);
	}
	else if (!strcmp(argv[1], "-h")) {
		std::cout << "sdl" << std::endl;
		std::cout << "ncurses" << std::endl;
	}
	else if (!strcmp(argv[1], "sdl")) {
		SDL sdl;
		sdl.go();
	}
	else if (!strcmp(argv[1], "ncurses")) {
		Ncurses ncurses;
		ncurses.go();
	}
	else
		std::cout << "Usage: ./ft_gkrellm [flag]" << std::endl;
	return (0);
}
