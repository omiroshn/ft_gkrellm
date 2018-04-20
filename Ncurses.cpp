/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin 42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:53:59 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/14 16:54:01 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
	_host = Host();
	_cpu = CPU();
	_ram = RAM();
	_date = DateModule();
	_net = Network();
	_disk = Disk();
	_os = OS();
	_active = 0;
	srand(time(0));
	std::cout << "\033[8,60;220t";
	initscr();
	cbreak();
	clear();
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	erase();
	keypad(stdscr,TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	noecho();	
	refresh();		
}

Ncurses::~Ncurses() { }

void Ncurses::printFrame()
{
	int i = -1;
	int j;
	while (++i <= 32)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, 20, "|");
		mvprintw(i, 100, "|");
		if (i % 4 == 0)
		{
			j = 1;
			while (j < 20)
				mvprintw(i, j++, "-");
		}
	}
}

void Ncurses::printList()
{
	if (_active == 0)
	{
		attron(COLOR_PAIR(2));
		mvprintw(2, 2, "##HOST##");
		attroff(COLOR_PAIR(2));
	}
	else
		mvprintw(2, 2, "HOST");
	if (_active == 1)
	{
		attron(COLOR_PAIR(2));		
		mvprintw(6, 2, "##TIME##");
		attroff(COLOR_PAIR(2));
	}
	else		
		mvprintw(6, 2, "TIME");
	if (_active == 2)
	{
		attron(COLOR_PAIR(2));	
		mvprintw(10, 2, "##CPU##");
		attroff(COLOR_PAIR(2));
	}
	else	
		mvprintw(10, 2, "CPU");
	if (_active == 3)
	{
		attron(COLOR_PAIR(2));	
		mvprintw(14, 2, "##RAM##");
		attroff(COLOR_PAIR(2));
	}
	else
		mvprintw(14, 2, "RAM");	
	if (_active == 4)
	{
		attron(COLOR_PAIR(2));			
		mvprintw(18, 2, "##NETWORK##");
		attroff(COLOR_PAIR(2));		
	}
	else
		mvprintw(18, 2, "NETWORK");
	if (_active == 5)
	{
		attron(COLOR_PAIR(2));	
		mvprintw(22, 2, "##DISK##");
		attroff(COLOR_PAIR(2));	
	}
	else
		mvprintw(22, 2, "DISK");	
	if (_active == 6)
	{
		attron(COLOR_PAIR(2));	
		mvprintw(26, 2, "##OS##");
		attroff(COLOR_PAIR(2));	
	}
	else
		mvprintw(26, 2, "OS");
	if (_active == 7)
	{
		attron(COLOR_PAIR(2));	
		mvprintw(30, 2, "##YOUR ADS HERE##");
		attroff(COLOR_PAIR(2));	

	}
	else
		mvprintw(30, 2, "YOUR ADS HERE");
}

void Ncurses::printData()
{
	std::string cpu;
	std::string buff;
	int find;
	int i;
	if (_active == 0)
	{
		attron(COLOR_PAIR(4));		
		mvprintw(1, 30, _host.getData("host").c_str());
		mvprintw(2, 30, _host.getData("user").c_str());
		attroff(COLOR_PAIR(4));
		displayUser();
	}
	else if (_active == 1) // time
	{
		_date.update();
		attron(COLOR_PAIR(4));
		mvwaddstr(stdscr, 2, 30, _date.getData("data").c_str());
		mvwaddstr(stdscr, 3, 30, _date.getData("time").c_str());
		attroff(COLOR_PAIR(4));		
		displayTime();
	}
	else if (_active == 2) // CPU
	{
		i = 0;
		cpu = _cpu.getData("cpu");
		find = cpu.find(" sys");
		buff = cpu.substr(find + 6, 2);
		try
		{
			find = stoi(buff);			
		}
		catch (std::exception & e)
		{
			find = 50;
		}
		find = 100 - find;
		attron(COLOR_PAIR(4));		
		mvwaddstr(stdscr, 2, 28, "<-");
		while (find > 0)
		{
			mvwaddstr(stdscr, 2, 30 + i++, "#");
			find = find - 2;
		}
		mvwaddstr(stdscr, 2, 80, "->");		
		mvwaddstr(stdscr, 1, 30, cpu.c_str());
		attroff(COLOR_PAIR(4));
		displayCPU();
	}
	else if (_active == 3) // RAM
	{
		attron(COLOR_PAIR(4));
		mvwaddstr(stdscr, 2, 30, _ram.getData("ram").c_str());
		attroff(COLOR_PAIR(4));
		displayRAM();
	}
	else if (_active == 4) // Net
	{
		attron(COLOR_PAIR(4));
		mvwaddstr(stdscr, 2, 30, _net.getData("net").c_str());
		attroff(COLOR_PAIR(4));
		displayNET();
	}
	else if (_active == 5) // Disk
	{
		attron(COLOR_PAIR(4));
		mvwaddstr(stdscr, 2, 30, _disk.getData("disk").c_str());
		attroff(COLOR_PAIR(4));
		displayHDD();
	}
	else if (_active == 6) // OS
	{
		attron(COLOR_PAIR(4));
		mvwaddstr(stdscr, 2, 30, _os.getData("name").c_str());
		mvwaddstr(stdscr, 3, 30, _os.getData("version").c_str());
		mvwaddstr(stdscr, 4, 30, _os.getData("build").c_str());
		attroff(COLOR_PAIR(4));	
		displayOS();
	}
	else if (_active == 7) // ADS
	{
		if (rand() % 2 == 0)
			displayCat1();
		else
			displayCat2();
	}
}

void Ncurses::go() 
{
	int ch = 1;
	srand(time(0));
	timeout(100);
	curs_set(0);
	keypad(stdscr, true);
	while (true)
	{
		clear();
		printList();
		printData();
		printFrame();		
		ch = getch();
		if (ch == 27)
			break;
		else if (ch == 258 && _active < 7)
				_active++;
		else if (ch == 259 && _active > 0)
				_active--;			
		refresh();
		usleep(1000);
	}	
	endwin();
	system("reset");
}

DateModule const& Ncurses::getDate(void) const {
	return this->_date;
}

CPU const& Ncurses::getCPU(void) const {
	return this->_cpu;
}

Host const& Ncurses::getHost(void) const {
	return this->_host;
}

RAM const& Ncurses::getRAM(void) const {
	return this->_ram;
}

Network const& Ncurses::getNetwork(void) const {
	return this->_net;
}

Disk const& Ncurses::getDisk(void) const {
	return this->_disk;
}

OS const& Ncurses::getOS(void) const {
	return this->_os;
}

void Ncurses::displayHDD(void)
{
	mvprintw(4, 22, "                                    #/,*/(**/&                               ");
	mvprintw(5, 22, "                                  ***,        .,*****(                       ");
	mvprintw(6, 22, "                                **#(//*#&  &&&&&&&, ,,****/                  ");
	mvprintw(7, 22, "                              ** W WWWWWW&&&&&&&&&&&&&WWWWW ,,,,,*,*,#       ");
	mvprintw(8, 22, "                            /WWWWWWWWW&&&&&&&&&&&&&&&WWWWWWWW# .......#W..   ");
	mvprintw(9, 22, "                          #.WWWWWWW&&&&&&&&&&&&&&WWWWWWWWWWW###,....... .    ");
	mvprintw(10, 22, "                        &*WWWWWWW&&&&&&&&(W&&WWWWWWWWWWWWW######,....  .&   ");
	mvprintw(11, 22, "                       **(WWWW&&&&&&&&&&&&(W/WWWW/W&WWW########(,....,,     ");
	mvprintw(12, 22, "                     /W,, &&&&&&&&&&&&&&WWWWWWWWW#*,########((((,.. ,,      ");
	mvprintw(13, 22, "                   ,    ,W&&&&&&&&&&&&W.#/&WWWW,(.######((((((((..,,        ");
	mvprintw(14, 22, "                 (  (&&  ,&&&&&&&&WWWWWWWWW#########(((((((((//..,,         ");
	mvprintw(15, 22, "               # /*&&&&W((W/&&WWWWWWWWW########((((((((((((//..(,W          ");
	mvprintw(16, 22, "              .*( .&&&&&&&/   WWWWW##########(((((((((((//*..,((            ");
	mvprintw(17, 22, "            .(W&&&&&&&&&/ *#((/(WW&&&W&(W&W(##&WW&(/#(.,.&,..#/             ");
	mvprintw(18, 22, "          ,  #W&&&&&&&&&.,(#/((#W&&&&&W*/#(/,WWWWWWW/.(/ .,,,               ");
	mvprintw(19, 22, "        &*,,.#WWWW&&&&&&&// .,..    .WWWWWWWWWWWWW.(*/*,..,,                ");
	mvprintw(20, 22, "       ( ,.,  .(WWW&&&&&&&&&W*WWWWWWWWWWWWWWWWW...*..,*,,,(                 ");
	mvprintw(21, 22, "       &.,,,,. ,,.. ,,W&&&&&  .WWWWW*.........,,,,.,.,,,,                   ");
	mvprintw(22, 22, "           &,,,,,,, .*,, .,/. ,/./((WW#((((,,,,,,,,,..,/                    ");
	mvprintw(23, 22, "                  /,,,,,,. **,, (#((#(((/##W,,.,,,,.,,                      ");
	mvprintw(24, 22, "                       &*,,,,,, .**,/((((#(/(  ,,, ,*                       ");
	mvprintw(25, 22, "                              /,,,,,*. **,**,#/#.*/                         ");
	mvprintw(26, 22, "                                   &*,,,,**. *  ,#&                         ");
	mvprintw(27, 22, "                                          /,,,,,&                           ");
}

void Ncurses::displayCPU(void)
{
	mvprintw(4, 22, "                                &(/**/((((((((/**##                         ");
	mvprintw(5, 22, "                          &&#//*/((#((((((((((((/***&                       ");
	mvprintw(6, 22, "                     #//**/(((((((((##############/**/#                     ");
	mvprintw(7, 22, "                #/***/((((((((((((##################//*(#                   ");
	mvprintw(8, 22, "         #/(/**/((((((((((((##################((/#####/**(/                 ");
	mvprintw(9, 22, "      #**/(((((((((((((#(################(#####&(((#####***/&               ");
	mvprintw(10, 22, "   &***((((((((((((################(((##(((#####&(((#####/**(/             ");
	mvprintw(11, 22, "   #***#######################(((((#&&(((###((####/(((######//*//          ");
	mvprintw(12, 22, "    (***#######################((/####((/###&((((((###########/**#(        ");
	mvprintw(13, 22, " &///****(###########(((#########(((##(#######& &###############/**//      ");
	mvprintw(14, 22, "  ##(/*/**/########((((####&######(((#############################/**(/&   ");
	mvprintw(15, 22, "  &*#((//**/#######/((#######/######################################/*//   ");
	mvprintw(16, 22, "   #/(//*/***########(((###((########################################*//#  ");
	mvprintw(17, 22, "   &#/,//***#######& ##(((((###################################/***/#WWWWW ");
	mvprintw(18, 22, "    &#/#((//***################################################(,***///,   ");
	mvprintw(19, 22, "     &&(/*,///**###########################################,***////**..#   ");
	mvprintw(20, 22, "      &#*##(/(/**######################################***/*///*..*#(##&   ");
	mvprintw(21, 22, "       &**,*//**#&&&&&&########################&(,***///**. ####*/ .&      ");
	mvprintw(22, 22, "        &#/(((/**#&&&&&&&&&&&&&&###########&(,****///,./(##*,(..//*&       ");
	mvprintw(23, 22, "          &(**,*//***&&&&&&&&&&&&&&&&&#&&#*,*/*///,.*/(#*,/(.,///          ");
	mvprintw(24, 22, "            &&(#&&&((***(WWWW&,***////***  ###&(,. *###&&                  ");
	mvprintw(25, 22, "              #&**((//******////*,..###&*,, .(###&&                        ");
	mvprintw(26, 22, "               &/,//*//((/////,,**##/,//. /(/(#&&                          ");
	mvprintw(27, 22, "                 &####/*,,,,,...,&#*.*/*.##&&                              ");
	mvprintw(28, 22, "                    &&##F#(///((((/. /##&&                                 ");	
	mvprintw(29, 22, "                          &&&&&&&&&&                                       ");
}

void Ncurses::displayRAM(void)
{
	mvprintw(6, 22, "                                                   ...                      ");
	mvprintw(7, 22, "                                             ..,(#/(###(.                   ");
	mvprintw(8, 22, "                                        ..,((*.*/////.##,.                  ");
	mvprintw(9, 22, "                                  ..,/(*,,.,,,,*********,(,...              ");
	mvprintw(10, 22, "                            ..,/(*.,****////*.,,,,,,,,,,,,,,##(,           ");
	mvprintw(11, 22, "                       ..,*/*.**,,*,,,*********.,,............/,.          ");
	mvprintw(12, 22, "                 ..,*/*.,****////**..*,,,,,,,,,,,...*         .,#####,.    ");
	mvprintw(13, 22, "           ...*/,.,/*,,*,,,**********,.,,..........   ,*  *,*/##&(((/((.   ");
	mvprintw(14, 22, "     ...,*,.,****/////**,,*,,,,,,,,,,,,...,.         ,,(/(#/#&&@@#/,,,,.   ");
	mvprintw(15, 22, "  .,*////,*,,,************..*............  ../  .//,/(#&&&&@@(/,,,,...     ");
	mvprintw(16, 22, "  .#///////,*,,,,,,,,,,,,,,,...*            ,*///##&&&&/#(*,,,,,.          ");
	mvprintw(17, 22, "   ..(/,,,*//*.*.................,/    ,/,,/(#&&/#@@#/*,,,,...             ");
	mvprintw(18, 22, "      ......*(***./....           .,,,////&&&@@@(*,,,,,..                  ");
	mvprintw(19, 22, "           .,******./.        */,,*/(/,,,((/(/**,,,,..                     ");
	mvprintw(20, 22, "           ./#(,,,*/**,#**#/,*/##&&&&@@/.,(///*,..                         ");
	mvprintw(21, 22, "            ../,,,*/((****/#&&#*&@@#*,,,.  ...                             ");
	mvprintw(22, 22, "                   .***#&&&&@@&(*,,,,,,..                                  ");
	mvprintw(23, 22, "                   .(#/*/&@(**,,,,,,..                                     ");
	mvprintw(24, 22, "                   .,###((//**,,..                                         ");
	mvprintw(25, 22, "                     ../((/,..                                             ");
	mvprintw(26, 22, "                        ..                                                 ");
}
 
void Ncurses::displayNET(void)
{
	mvprintw(4, 28, "                   @@@@@@@@@@@@@@@@@                    ");
	mvprintw(5, 28, "              @@@@@@@@@@@@@@@@@@@@@@@@@@@               ");
	mvprintw(6, 28, "           @@@@@@@  @@@@@@@@@@@@@@   @@@@@@@            ");
	mvprintw(7, 28, "         @@@@@@   @@@@@  @@@@  @@@@@    %@@@@@          ");
	mvprintw(8, 28, "       @@@@@     @@@@    @@@@    @@@@      @@@@@        ");
	mvprintw(9, 28, "     @@@@@      @@@@     @@@@     @@@@@      @@@@@      ");
	mvprintw(10, 28, "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ");
	mvprintw(11, 28, "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ");
	mvprintw(12, 28, "  @@@@       @@@@       @@@@        @@@@        @@@@   ");
	mvprintw(13, 28, "                                                       ");
	mvprintw(14, 28, "  @@   @@@@   @@    @@@   @@@   @@@    @@   @@@@   @@  ");
	mvprintw(15, 28, "  @@@ @@@@@  @@@     @@  @@ @@  @@     @@@ @@@@@& @@@  ");
	mvprintw(16, 28, "   @@ @@  @@@@@      @@@@@   @@@@       @@ @@  @@ @@   ");
	mvprintw(17, 28, "    @@@    @@@        @@@@   @@@@        @@@    @@@    ");
	mvprintw(18, 28, "                                                       ");
	mvprintw(19, 28, "  @@@@        @@@@       @@@@        @@@@        @@@@  ");
	mvprintw(20, 28, "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ");
	mvprintw(21, 28, "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ");
	mvprintw(22, 28, "     @@@@@      @@@@     @@@@     @@@@@      @@@@@     ");
	mvprintw(23, 28, "       @@@@@     @@@@    @@@@    @@@@      @@@@@       ");
	mvprintw(24, 28, "         @@@@@@   @@@@@  @@@@  @@@@@    @@@@@@         ");
	mvprintw(25, 28, "           @@@@@@@  @@@@@@@@@@@@@@   @@@@@@@           ");
	mvprintw(26, 28, "              @@@@@@@@@@@@@@@@@@@@@@@@@@@              ");
	mvprintw(27, 28, "                   @@@@@@@@@@@@@@@@@                   ");
}

void Ncurses::displayTime(void)
{
	mvprintw(4, 32, "                  @@@@@@@@@@@@@@@@                      ");
	mvprintw(5, 32, "              @@@(      ,@&      (@@@                   ");
	mvprintw(6, 32, "           @@*          ,@&  .       *@@                ");
	mvprintw(7, 32, "        @@.   @*        ,@& @@      @.  .@@             ");
	mvprintw(8, 32, "      @@       @(       ,@&*@,    .@       @@           ");
	mvprintw(9, 32, "     @.                    @@               .@@         ");
	mvprintw(10, 32, "   @@                      @&                 @@       ");
	mvprintw(11, 32, "  @@ #@@,                 #@              .@@( @@      ");
	mvprintw(12, 32, " @@                       @@                    @@     ");
	mvprintw(13, 32, "@@                       *@#                     @@    ");
	mvprintw(14, 32, "@&                       @@                      &@    ");
	mvprintw(15, 32, "@.                       @@                      .@    ");
	mvprintw(16, 32, "@ *******              #@@@@@@@@@@@@@@    ******* @    ");
	mvprintw(17, 32, "@.                                               .@    ");
	mvprintw(18, 32, "@&                                               &@    ");
	mvprintw(19, 32, "@@                                               @@    ");
	mvprintw(20, 32, " @@     ,.                                #     @@     ");
	mvprintw(21, 32, "  @& @@@                                   /@@.&@      ");
	mvprintw(22, 32, "   @@                                         @@       ");
	mvprintw(23, 32, "    @@                                       @@        ");
	mvprintw(24, 32, "      @@       @*       ,@&        @.      @@          ");
	mvprintw(25, 32, "        @@    @.        ,@&         @*   @@            ");
	mvprintw(26, 32, "          @@@.          ,@&          .@@               ");
	mvprintw(27, 32, "              @@@,      ,@&      ,@@@                  ");
	mvprintw(28, 32, "                  @@@@@@@@@@@@@@@@                     ");
}

void Ncurses::displayUser(void)
{
	mvprintw(4, 32, "      ,;MMMM..                                      ");
	mvprintw(5, 32, "   ,;:MM.MMMMM.                                     ");
	mvprintw(6, 32, ",;.MM::M.MMMMMM:                                    ");
	mvprintw(7, 32, "**::.;'MMMMMMMMM                                    ");
	mvprintw(8, 32, "       ----MMMMM;                                   ");
	mvprintw(9, 32, "           ':MMMM.                                  ");
	mvprintw(10, 32, "            :MMMM;.                                ");
	mvprintw(11, 32, "              MMMMMM;...                           ");
	mvprintw(12, 32, "              MMMMMMMMMMMMM;.;..                   ");
	mvprintw(13, 32, "              MMMMMMMMMMMMMMMMMMM...               ");
	mvprintw(14, 32, "              MMMMMM:MMMMMMMMMMMMMMM;...       ..: ");
	mvprintw(15, 32, "              MMMMMM;MMMMMMMMMMMMM:MMMMMMM:MMMM:M  ");
	mvprintw(16, 32, "              :MMMMMM:MMMMMMMMMMMMMMM.:::;:::;;:'  ");
	mvprintw(17, 32, "              ':MMMMMMM:MMMM:;MM:M;.MMM:';::M:'    ");
	mvprintw(18, 32, "               ':MMMMMM;M;;MM;::M;;::::;MM:""      ");
	mvprintw(19, 32, "                 'MMMMMMMM;M;:::MMMMMMMMMM*        ");
	mvprintw(20, 32, "                  ''MMMMMMMMMMMMMMMMMMMMM*         ");
	mvprintw(21, 32, "                     ':MMMMMMMMMMMMMMMM*'          ");
	mvprintw(22, 32, "                       '':MMMMMMMMMMM*'            ");
	mvprintw(23, 32, "                          *:MMMMMM**               ");
	mvprintw(24, 32, "                             :                     ");
	mvprintw(25, 32, "                            ::                     ");
	mvprintw(26, 32, "                       ,..;.M'                     ");
	mvprintw(27, 32, "                      ,;;MM:|                      ");	
	mvprintw(28, 32, "                        '-'                        ");
}

void Ncurses::displayOS(void)
{
	mvprintw(7, 42,  "                      /&          ");
	mvprintw(8, 42,  "                  &&&&&           ");
	mvprintw(9, 42,  "                *&&&&&,           ");
	mvprintw(10, 42, "                &&&&&             ");
	mvprintw(11, 42, "               ,%/                ");
	mvprintw(12, 42, "     /&&&&&&&&*  *&&&&&&&&&/      ");
	mvprintw(13, 42, "   &&&&&&&&&&&&&&&&&&&&&&&&&&&    ");
	mvprintw(14, 42, "  &&&&&&&&&&&&&&&&&&&&&&&&&&      ");
	mvprintw(15, 42, " &&&&&&&&&&&&&&&&&&&&&&&&&&       ");
	mvprintw(16, 42, "/&&&&&&&&&&&&&&&&&&&&&&&&&        ");
	mvprintw(17, 42, "#&&&&&&&&&&&&&&&&&&&&&&&&&        ");
	mvprintw(18, 42, "(&&&&&&&&&&&&&&&&&&&&&&&&&*       ");
	mvprintw(19, 42, " &&&&&&&&&&&&&&&&&&&&&&&&&&.      ");
	mvprintw(20, 42, " %&&&&&&&&&&&&&&&&&&&&&&&&&&&     ");
	mvprintw(21, 42, "  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&   ");
	mvprintw(22, 42, "   &&&&&&&&&&&&&&&&&&&&&&&&&&&    ");
	mvprintw(23, 42, "    &&&&&&&&&&&&&&&&&&&&&&&&&     ");
	mvprintw(24, 42, "     (&&&&&&&&&&&&&&&&&&&&&*      ");
	mvprintw(25, 42, "       (&&&&&&*   *&&&&&          ");
}

void Ncurses::displayCat1(void)
{
	mvprintw(12, 42, "         .       .        ");
	mvprintw(13, 42, "         \\`-\"'\"-'/     ");
	mvprintw(14, 42, "          } 6 6 {         ");
	mvprintw(15, 42, "         =.  Y  ,=        ");
	mvprintw(16, 42, "           /^^^\\  .      ");
	mvprintw(17, 42, "          /     \\  )     ");
	mvprintw(18, 42, "     zaz (  )-(  )/       ");
	mvprintw(19, 42, "          ""   ""         ");
}

void Ncurses::displayCat2(void)
{
	mvprintw(12, 42, "          .       .         ");
	mvprintw(13, 42, "          \\`-\"'\"-'/      ");
	mvprintw(14, 42, "           } 6 6 {          ");
	mvprintw(15, 42, "          =.  Y  ,=         ");
	mvprintw(16, 42, "        (\"\"-'***`-\"\")   ");
	mvprintw(17, 42, "         `-/     \\-'       ");
	mvprintw(18, 42, "     zaz  (  )-(  )==='     ");
	mvprintw(19, 42, "           \"\"   \"\"      ");
}



 
