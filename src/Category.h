#pragma once 
#include "Product.h"
#include "Input.h"
#include "Output.h"
#include "Factory.h"
#include "FileManager.h"
#include <vector>
#include <memory>

struct Category
{
	Category(Factory *BFact);
	std::shared_ptr<FileManager>pLoad;
	std::shared_ptr<Input>pIn;
	std::shared_ptr<Output>pOut;
	
};