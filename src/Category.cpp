#include "Category.h"

Category::Category(Factory *BFact)
{
	if (BFact)
	{

		pIn.reset(BFact->CreateInput());
		pOut.reset(BFact->CreateOutput());
		pLoad.reset(BFact->CreateLoader());
	}
}