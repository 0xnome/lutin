import os

DIRECTORY = "etatsGeneres"
LAST_NUM_CLASS = 44
TEMPLATE_CPP ="""#include "Etat{{NUM}}.h"

bool Etat{{NUM}}::transition(Automate* automate, Symbole* s)
{
   switch (*s){
//       case SYMBOLE:
//			return true;
		default:
           return false;
   }
}
"""
CPP_FILENAME = "Etat{{NUM}}.cpp"

TEMPLATE_H ="""#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat{{NUM}}: public EtatDefaut
{
public:
    Etat{{NUM}}() : EtatDefaut("E{{NUM}}")
    { }
    bool transition(Automate* automate, Symbole* s);
};
"""
H_FILENAME = "Etat{{NUM}}.h"

for i in range(0,LAST_NUM_CLASS+1):
	cpp = TEMPLATE_CPP.replace("{{NUM}}",str(i))
	cpp_filename = CPP_FILENAME.replace("{{NUM}}",str(i))
	h = TEMPLATE_H.replace("{{NUM}}",str(i))
	h_filename = H_FILENAME.replace("{{NUM}}",str(i))

	if not os.path.exists(DIRECTORY):
		os.makedirs(DIRECTORY)

	cpp_filename = os.path.join(DIRECTORY,cpp_filename)
	h_filename = os.path.join(DIRECTORY,h_filename)

	print(cpp_filename)
	with open(cpp_filename,"w+") as f:
		f.write(cpp)

	print(h_filename)
	with open(h_filename,"w+") as f:
		f.write(h)