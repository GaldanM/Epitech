/*
** sickkoala.c for sickkoala in /home/moulin_c/rendu/piscine_cpp_d06/ex02
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan 12 13:47:57 2015 Galdan MOULINNEUF
// Last update Mon Jan 12 20:17:32 2015 Galdan MOULINNEUF
*/

#include	<fstream>
#include	"sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

void		SickKoala::poke()
{
  std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :'(" << std::endl;
}

bool		SickKoala::takeDrug(std::string drug)
{
  std::string	mars = ("MARS");
  std::string   buron = ("Buronzand");
  std::string	drug_maj;

  for (int i = 0; drug[i]; i++)
    drug_maj.push_back(std::toupper(drug[i]));
  if (drug_maj == mars)
    {
      std::cout << "Mr." << this->name << ": Mars, et ca kreog !" << std::endl;
      return (true);
    }
  if (drug == buron)
    {
      std::cout << "Mr." << this->name << ": Et la fatigue a fait son temps !" << std::endl;
      return (true);
    }
  else
    std::cout << "Mr." << this->name << ": Goerkreog !" << std::endl;
  return (false);
}

void		SickKoala::overDrive(std::string sentence)
{
  std::string	repl("Kreog !");
  size_t	pos;

  while ((pos = sentence.find(repl)) != std::string::npos)
    sentence.replace(pos, repl.size(), "1337 !");
  std::cout << "Mr." << this->name << ": " << sentence << std::endl;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}
