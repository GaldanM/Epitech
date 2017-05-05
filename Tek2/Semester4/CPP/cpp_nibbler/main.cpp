//
// main.cpp for main in /home/ounajj_k/rendu/cpp_nibbler
// 
// Made by Khaled Ounajjar
// Login   <ounajj_k@epitech.net>
// 
// Started on  Sun Apr  5 22:11:51 2015 Khaled Ounajjar
// Last update Sun Apr  5 22:18:41 2015 Khaled Ounajjar
//

#include            <iostream>
#include            <cstdlib>
#include            "Game.h"
#include            "DLLoader.h"
#include            "ILibsDisplay.h"

void		        launch_game(int argc, char **argv)
{
  Game              game(strtoul(argv[1], 0, 0), strtoul(argv[2], 0, 0), argc, argv);
  DLLoader          lib_to_load(argv[3], game);
  ILibsDisplay      *obj = lib_to_load.getInstance();

  obj->startGame(game);
}

int		            main(int argc, char **argv, char **envp)
{
  if (!envp[0])
    {
      std::cout << "Wrong environment" << std::endl;
      return (-1);
    }
  if (argc == 4)
    {
      try
      {
        launch_game(argc, argv);
      }
      catch (const std::exception &e)
      {
        std::cout << e.what() << std::endl;
        return (-1);
      }
    }
  else
    std::cerr << "Usage : ./nibbler [WIDTH] [HEIGHT] [LIB_TO_LOAD.so]" << std::endl;
  return (0);
}
