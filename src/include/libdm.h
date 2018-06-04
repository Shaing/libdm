/*
  ==============================================================================

    libdm.h
    Created: 14 Mar 2018 14:16:14am
    Author:  allen_huang

  ==============================================================================
*/

#ifndef LIB_DM_H_INCLUDED
#define LIB_DM_H_INCLUDED
#define DMVER "0.0.1"

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

namespace idm
{

	inline void coutSPDRPCODE()
	{

		/*
		#define SPDRP_DEVICEDESC                  (0x00000000)  // DeviceDesc (R/W)
		#define SPDRP_HARDWAREID                  (0x00000001)  // HardwareID (R/W)
		#define SPDRP_COMPATIBLEIDS               (0x00000002)  // CompatibleIDs (R/W)
		#define SPDRP_UNUSED0                     (0x00000003)  // unused
		#define SPDRP_SERVICE                     (0x00000004)  // Service (R/W)
		#define SPDRP_UNUSED1                     (0x00000005)  // unused
		#define SPDRP_UNUSED2                     (0x00000006)  // unused
		#define SPDRP_CLASS                       (0x00000007)  // Class (R--tied to ClassGUID)
		#define SPDRP_CLASSGUID                   (0x00000008)  // ClassGUID (R/W)
		#define SPDRP_DRIVER                      (0x00000009)  // Driver (R/W)
		#define SPDRP_CONFIGFLAGS                 (0x0000000A)  // ConfigFlags (R/W)
		#define SPDRP_MFG                         (0x0000000B)  // Mfg (R/W)
		#define SPDRP_FRIENDLYNAME                (0x0000000C)  // FriendlyName (R/W)
		#define SPDRP_LOCATION_INFORMATION        (0x0000000D)  // LocationInformation (R/W)
		#define SPDRP_PHYSICAL_DEVICE_OBJECT_NAME (0x0000000E)  // PhysicalDeviceObjectName (R)
		#define SPDRP_CAPABILITIES                (0x0000000F)  // Capabilities (R)
		#define SPDRP_UI_NUMBER                   (0x00000010)  // UiNumber (R)
		#define SPDRP_UPPERFILTERS                (0x00000011)  // UpperFilters (R/W)
		#define SPDRP_LOWERFILTERS                (0x00000012)  // LowerFilters (R/W)
		#define SPDRP_BUSTYPEGUID                 (0x00000013)  // BusTypeGUID (R)
		#define SPDRP_LEGACYBUSTYPE               (0x00000014)  // LegacyBusType (R)
		#define SPDRP_BUSNUMBER                   (0x00000015)  // BusNumber (R)
		#define SPDRP_ENUMERATOR_NAME             (0x00000016)  // Enumerator Name (R)
		#define SPDRP_SECURITY                    (0x00000017)  // Security (R/W, binary form)
		#define SPDRP_SECURITY_SDS                (0x00000018)  // Security (W, SDS form)
		#define SPDRP_DEVTYPE                     (0x00000019)  // Device Type (R/W)
		#define SPDRP_EXCLUSIVE                   (0x0000001A)  // Device is exclusive-access (R/W)
		#define SPDRP_CHARACTERISTICS             (0x0000001B)  // Device Characteristics (R/W)
		#define SPDRP_ADDRESS                     (0x0000001C)  // Device Address (R)
		#define SPDRP_UI_NUMBER_DESC_FORMAT       (0X0000001D)  // UiNumberDescFormat (R/W)
		#define SPDRP_DEVICE_POWER_DATA           (0x0000001E)  // Device Power Data (R)
		#define SPDRP_REMOVAL_POLICY              (0x0000001F)  // Removal Policy (R)
		#define SPDRP_REMOVAL_POLICY_HW_DEFAULT   (0x00000020)  // Hardware Removal Policy (R)
		#define SPDRP_REMOVAL_POLICY_OVERRIDE     (0x00000021)  // Removal Policy Override (RW)
		#define SPDRP_INSTALL_STATE               (0x00000022)  // Device Install State (R)
		#define SPDRP_LOCATION_PATHS              (0x00000023)  // Device Location Paths (R)
		#define SPDRP_BASE_CONTAINERID            (0x00000024)  // Base ContainerID (R)
		#define SPDRP_MAXIMUM_PROPERTY            (0x00000025)  // Upper bound on ordinals
		*/

		std::cout << "\
			 SPDRP_DEVICEDESC                  (0x00000000)  // DeviceDesc (R/W)\n\
			 SPDRP_HARDWAREID                  (0x00000001)  // HardwareID (R/W)\n\
			 SPDRP_COMPATIBLEIDS               (0x00000002)  // CompatibleIDs (R/W)\n\
			 SPDRP_UNUSED0                     (0x00000003)  // unused\n\
			 SPDRP_SERVICE                     (0x00000004)  // Service (R/W)\n\
			 SPDRP_UNUSED1                     (0x00000005)  // unused\n\
			 SPDRP_UNUSED2                     (0x00000006)  // unused\n\
			 SPDRP_CLASS                       (0x00000007)  // Class (R--tied to ClassGUID)\n\
			 SPDRP_CLASSGUID                   (0x00000008)  // ClassGUID (R/W)\n\
			 SPDRP_DRIVER                      (0x00000009)  // Driver (R/W)\n\
			 SPDRP_CONFIGFLAGS                 (0x0000000A)  // ConfigFlags (R/W)\n\
			 SPDRP_MFG                         (0x0000000B)  // Mfg (R/W)\n\
			 SPDRP_FRIENDLYNAME                (0x0000000C)  // FriendlyName (R/W)\n\
			 SPDRP_LOCATION_INFORMATION        (0x0000000D)  // LocationInformation (R/W)\n\
			 SPDRP_PHYSICAL_DEVICE_OBJECT_NAME (0x0000000E)  // PhysicalDeviceObjectName (R)\n\
			 SPDRP_CAPABILITIES                (0x0000000F)  // Capabilities (R)\n\
			 SPDRP_UI_NUMBER                   (0x00000010)  // UiNumber (R)\n\
			 SPDRP_UPPERFILTERS                (0x00000011)  // UpperFilters (R/W)\n\
			 SPDRP_LOWERFILTERS                (0x00000012)  // LowerFilters (R/W)\n\
			 SPDRP_BUSTYPEGUID                 (0x00000013)  // BusTypeGUID (R)\n\
			 SPDRP_LEGACYBUSTYPE               (0x00000014)  // LegacyBusType (R)\n\
			 SPDRP_BUSNUMBER                   (0x00000015)  // BusNumber (R)\n\
			 SPDRP_ENUMERATOR_NAME             (0x00000016)  // Enumerator Name (R)\n\
			 SPDRP_SECURITY                    (0x00000017)  // Security (R/W, binary form)\n\
			 SPDRP_SECURITY_SDS                (0x00000018)  // Security (W, SDS form)\n\
			 SPDRP_DEVTYPE                     (0x00000019)  // Device Type (R/W)\n\
			 SPDRP_EXCLUSIVE                   (0x0000001A)  // Device is exclusive-access (R/W)\n\
			 SPDRP_CHARACTERISTICS             (0x0000001B)  // Device Characteristics (R/W)\n\
			 SPDRP_ADDRESS                     (0x0000001C)  // Device Address (R)\n\
			 SPDRP_UI_NUMBER_DESC_FORMAT       (0X0000001D)  // UiNumberDescFormat (R/W)\n\
			 SPDRP_DEVICE_POWER_DATA           (0x0000001E)  // Device Power Data (R)\n\
			 SPDRP_REMOVAL_POLICY              (0x0000001F)  // Removal Policy (R)\n\
			 SPDRP_REMOVAL_POLICY_HW_DEFAULT   (0x00000020)  // Hardware Removal Policy (R)\n\
			 SPDRP_REMOVAL_POLICY_OVERRIDE     (0x00000021)  // Removal Policy Override (RW)\n\
			 SPDRP_INSTALL_STATE               (0x00000022)  // Device Install State (R)\n\
			 SPDRP_LOCATION_PATHS              (0x00000023)  // Device Location Paths (R)\n\
			 SPDRP_BASE_CONTAINERID            (0x00000024)  // Base ContainerID (R)\n\
			 SPDRP_MAXIMUM_PROPERTY            (0x00000025)  // Upper bound on ordinals\n"
			<< std::endl;

	}

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
				std::cout << devPathAndProInfo[i].first << "|" << devPathAndProInfo[i].second << std::endl;
			}
		}
		
		std::vector<std::pair<std::string, std::string>>&& getDevPathAndProInfo(){ return std::move(devPathAndProInfo); }

	private:
		std::vector<std::pair<std::string, std::string>> devPathAndProInfo;

		void clearList()
		{
			devPathAndProInfo.clear();
		}
	};

}


#endif  // LIB_DM_H_INCLUDED
