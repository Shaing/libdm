/*
  ==============================================================================

    libdm.h
    Created: 14 Mar 2018 14:16:14am
    Author:  allen_huang

  ==============================================================================
*/

#ifndef LIB_DM_H_INCLUDED
#define LIB_DM_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <setupapi.h>
#include <initguid.h>
#include <usbiodef.h>
#pragma comment(lib, "setupapi.lib")

#if __cplusplus > 199711L
	#define Cpp11
#else
	#ifdef _MSC_VER
	 	#if _MSC_VER == 1900
			#define Cpp11
		#else
			#define Cpp98
		#endif
	#else
		#define Cpp98
	#endif 
#endif

class DEVMAN
{
public:
	DEVMAN(){}
	~DEVMAN() {}

	void listDeviceRegPro(const int& property, const void* guidInterface, const char* devType, const unsigned int& flags);
	inline void coutList() const
	{
		for(std::vector<std::pair<std::string, std::string>>::size_type i = 0; i < devPathAndProInfo.size(); ++i)
		{
			std::cout << devPathAndProInfo[i].first << " | " << devPathAndProInfo[i].second << std::endl;
		}
	}

private:
	std::vector<std::pair<std::string, std::string>> devPathAndProInfo;

	void clearList()
	{
		devPathAndProInfo.clear();
	}
};


#endif  // LIB_DM_H_INCLUDED
