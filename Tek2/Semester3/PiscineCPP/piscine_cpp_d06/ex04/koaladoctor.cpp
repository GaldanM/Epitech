//
// koaladoctor.cpp for koaladoctor in /home/moulin_c/rendu/piscine_cpp_d06/ex04
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Mon Jan 12 20:44:44 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 07:19:08 2015 Galdan MOULINNEUF
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "koaladoctor.h"
#include "sickkoala.h"
#include "koalanurse.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
  this->working = false;
  std::cout << "Dr." << this->name << ": Je suis le Dr." << this->name << " ! Comment Kreoggez-vous ?" << std::endl;
}

void		KoalaDoctor::diagnose(SickKoala *patient)
{
  std::string	ext(".report");
  std::ofstream file;
  std::string	name = patient->getName() + ext;
  std::string	tab[5] = {"Buronzand", "Viagra", "Extasy", "Feuille d'eucalyptus", "mars"};
  int		nb_rand;

  std::cout << "Dr." << this->name << ": Alors qu'est-ce qui vous goerk Mr." << patient->getName() << " ?" << std::endl;
  patient->poke();
  file.open(name.c_str());
  nb_rand = random() % 5;
  file << tab[nb_rand];
  file.close();
}

void		KoalaDoctor::timeCheck(void)
{
  if (!this->working)
    {
      this->working = true;
      std::cout << "Dr." << this->name << ": Je commence le travail !" << std::endl;
    }
  else
    {
      this->working = false;
      std::cout << "Dr." << this->name << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
    }
}

KoalaDoctor::~KoalaDoctor()
{

}
