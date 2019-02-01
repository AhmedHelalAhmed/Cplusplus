#include <iostream>
#include "Mark.h"

using namespace std;

Mark::Mark(int arabic, int math, int english)
{
   /*
      cout<<"this is mark constructor";
      cout <<arabic<<endl;
      cout <<math<<endl;
      cout <<english<<endl;
   */

  this->arabic=arabic;
  this->math=math;
  this->english=english;
  
}

Mark::Mark()
{

}



int Mark::getMath()
{
   return this->math;
}

int Mark::getArabic()
{
   return this->arabic;
}


int Mark::getEnglish()
{
   return this->english;
}

bool Mark::isPass()
{
   return (this->math>=50&&this->arabic>=50&&this->english>=50);
}

