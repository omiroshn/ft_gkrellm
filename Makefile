# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/14 14:59:51 by omiroshn          #+#    #+#              #
#    Updated: 2018/04/14 14:59:52 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

FILES = main \
		DateModule \
		CPU \
		RAM \
		Ncurses \
		SDL \
		Host \
		Network \
		Disk \
		OS

HDRS =  IMonitorModule.hpp \
		IMonitorDisplay.hpp \
		DateModule.hpp \
		Ncurses.hpp \
		SDL.hpp \
		Host.hpp \
		Network.hpp \
		Disk.hpp \
		OS.hpp

INCLUDES =	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
				
FRAMEWORKS =	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

SRC = $(addsuffix .cpp, $(FILES))

OBJ = $(addsuffix .o, $(FILES))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(OBJ) -o $(NAME) -lncurses $(FRAMEWORKS)

%.o: %.cpp $(HDRS)
	clang++ -o $@ $(FLAGS) $(INCLUDES) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
