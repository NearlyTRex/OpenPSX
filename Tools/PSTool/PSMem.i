%module PSMem

%{
#include "Include/Main.h"
%}

%include "Constants.i"

%inline %{
typedef unsigned long UINT32;
%}

class PSMem
{
public:
	// Constructor
	PSMem(char* DB);

	// Destructor
	~PSMem();
	
	// Public methods
	UINT32 LoadByte(const UINT32 Address);
	UINT32 LoadByteUnsigned(const UINT32 Address);
	UINT32 LoadHalfword(const UINT32 Address);
	UINT32 LoadHalfwordUnsigned(const UINT32 Address);
	UINT32 LoadWord(const UINT32 Address);
	void LoadWordLeft(const UINT32 Address, UINT32 Register);
	void LoadWordRight(const UINT32 Address, UINT32 Register);
	UINT32 LoadWordToCOP0(const UINT32 Address);
	UINT32 LoadWordToCOP2(const UINT32 Address);
	void StoreByte(const UINT32 Address, const UINT32 Register);
	void StoreHalfword(const UINT32 Address, const UINT32 Register);
	void StoreWord(const UINT32 Address, const UINT32 Register);
	void StoreWordLeft(const UINT32 Address, const UINT32 Register);
	void StoreWordRight(const UINT32 Address, const UINT32 Register);
	void StoreWordFromCOP0(const UINT32 Address, const UINT32 Register);
	void StoreWordFromCOP2(const UINT32 Address, const UINT32 Register);
	void Copy(const UINT32 Start, const UINT32 End, const UINT32 Dest);
	void ImportBIOS(const char* BIOS);
	void ImportEXE(const char* EXE);
	void Export(const char* SFile, const UINT32 Start, const UINT32 End);
	void Backup(const char* SFile);
	void Restore(const char* SFile);
	void ResetMem(void);

};
