/*
** koalanurse.c for koalanurse in /home/moulin_c/rendu/piscine_cpp_d06/ex02
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan 12 16:47:57 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 09:45:02 2015 Galdan MOULINNEUF
*/

#include	<iostream>
#include	<fstream>
#include	<string>
#include	"koalanurse.h"
#include	"sickkoala.h"

KoalaNurse::KoalaNurse(int ID)
{
  this->working = false;
  this->id = ID;
}

void		KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
  patient->takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string report)
{
  size_t	pos;
  char		chara;
  std::string drug;
  std::string patient;
  std::ifstream fd(report.c_str(), std::ios::in);


  if (fd)
    {
      if ((pos = report.find_last_of(".")) != std::string::npos)
  	{
  	  patient.insert(0, report.c_str(), pos);
  	  if (report.compare(pos, 7, ".report") == 0)
  	    {
  	      while (fd.get(chara))
  	  	drug.push_back(chara);
  	      std::cout << "Nurse " << this->id << ": Kreog ! Il faut donner un " << drug << " a Mr." << patient << " !" << std::endl;
  	    }
  	}
    }
  return (drug);
}

void		KoalaNurse::timeCheck()
{
  if (!this->working)
    {
      this->working = true;
      std::cout << "Nurse " << this->id << ": Je commence le travail !" << std::endl;
    }
  else
    {
      this->working = false;
      std::cout << "Nurse " << this->id << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
    }
}

int		KoalaNurse::getID()
{
  return (this->id);
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse " << this->id << ": Enfin un peu de repos !" << std::endl;
}
