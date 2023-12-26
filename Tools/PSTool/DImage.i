%module DImage

%{
#include "Include/Main.h"
%}

%include "Constants.i"

class DImage {
	
public:
	// Constructor
	DImage();
	
	// Destructor
	~DImage();
	
	// Public methods
	void DecompileBIOS(const char* BIOS, const char* Outfile);
	void DecompileEXE(const char* EXE, const char* Outfile);
	void DecompileSF(const char* SF, const char* Outfile);

};
