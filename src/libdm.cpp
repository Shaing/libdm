/*
  ==============================================================================

    libdm.cpp
    Created: 14 Mar 2018 14:16:14am
    Author:  allen_huang

  ==============================================================================
*/

#include "libdm.h"
using std::pair;
using std::string;
using namespace idm;

void DEVMAN::listDeviceRegPro(const int& property, const void* guidInterface, const char* devType, const unsigned int& flags)
{
	clearList();
	HDEVINFO hDevInfo = 0;
	SP_DEVINFO_DATA DeviceInfoData;
	SP_DEVICE_INTERFACE_DATA DevInterfaceData;
	PSP_DEVICE_INTERFACE_DETAIL_DATA pDevDetail;

	unsigned long PropertyRegDataType = 0;
	unsigned char *pRegPropertyBuffer = 0;
	unsigned long RequiredLen, iDev = 0;
	BOOL  Status = false;

	GUID* g = (GUID *)guidInterface;
	pair<string, string> proPair;

	hDevInfo = SetupDiGetClassDevs(g, devType, NULL, flags);
	if(hDevInfo != INVALID_HANDLE_VALUE)
	{
		memset(&DeviceInfoData, 0, sizeof(SP_DEVINFO_DATA));
		DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

		pDevDetail = 0;
		DevInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

		for(iDev = 0; (Status = SetupDiEnumDeviceInfo(hDevInfo, iDev, &DeviceInfoData)); iDev++)
		{	
			proPair.first.clear();
			proPair.second.clear();
			if(g == NULL)
			{
				Status = SetupDiGetDeviceRegistryProperty(
															hDevInfo,
															&DeviceInfoData,
															SPDRP_CLASSGUID,
															&PropertyRegDataType,
															NULL,
															0,
															&RequiredLen
														  );
				if(RequiredLen != 0)
				{
					pRegPropertyBuffer = (PBYTE)malloc(RequiredLen);
					Status = SetupDiGetDeviceRegistryProperty(
						hDevInfo,//_In_       HDEVINFO DeviceInfoSet,
						&DeviceInfoData,//_In_       PSP_DEVINFO_DATA DeviceInfoData,
						SPDRP_CLASSGUID, //_In_       DWORD Property,
						&PropertyRegDataType,//_Out_opt_  PDWORD PropertyRegDataType,
						pRegPropertyBuffer,//_Out_opt_  PBYTE PropertyBuffer,
						RequiredLen, //_In_       DWORD PropertyBufferSize,
						&RequiredLen//_Out_opt_  PDWORD RequiredSize
					);
					free(pRegPropertyBuffer);
				}

				if(SetupDiCreateDeviceInterface(hDevInfo,
												&DeviceInfoData,
												&DeviceInfoData.ClassGuid,
												0L,
												0L,
												&DevInterfaceData))
				{
					RequiredLen = 0;
					Status = SetupDiGetDeviceInterfaceDetail(hDevInfo, &DevInterfaceData, NULL, 0, &RequiredLen, NULL);
					pDevDetail = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(RequiredLen);
					pDevDetail->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
					Status = SetupDiGetDeviceInterfaceDetail(hDevInfo, &DevInterfaceData, pDevDetail, RequiredLen, &RequiredLen, NULL);
					proPair.first = pDevDetail->DevicePath;
					free(pDevDetail);
				}
			}
			else
			{
				Status = SetupDiEnumDeviceInterfaces(hDevInfo, 0, g, iDev, &DevInterfaceData);
				RequiredLen = 0;
				Status = SetupDiGetDeviceInterfaceDetail(hDevInfo, &DevInterfaceData, NULL, 0, &RequiredLen, NULL);
				pDevDetail = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(RequiredLen);
				pDevDetail->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
				Status = SetupDiGetDeviceInterfaceDetail(hDevInfo, &DevInterfaceData, pDevDetail, RequiredLen, &RequiredLen, NULL);
				proPair.first = pDevDetail->DevicePath;
				free(pDevDetail);
			}

			RequiredLen = 0;
			Status = SetupDiGetDeviceRegistryProperty(
														hDevInfo,
														&DeviceInfoData,
														property,
														&PropertyRegDataType,
														NULL,
														0,
														&RequiredLen
													 );
			if(RequiredLen != 0)
			{
				pRegPropertyBuffer = (PBYTE)malloc(RequiredLen);
				Status = SetupDiGetDeviceRegistryProperty(
					hDevInfo,					//_In_       HDEVINFO DeviceInfoSet,
					&DeviceInfoData,			//_In_       PSP_DEVINFO_DATA DeviceInfoData,
					property,					//_In_       DWORD Property,
					&PropertyRegDataType,		//_Out_opt_  PDWORD PropertyRegDataType,
					pRegPropertyBuffer,			//_Out_opt_  PBYTE PropertyBuffer,
					RequiredLen,				//_In_       DWORD PropertyBufferSize,
					&RequiredLen				//_Out_opt_  PDWORD RequiredSize
				);
				proPair.second = (char*)pRegPropertyBuffer;
				free(pRegPropertyBuffer);
			}
			devPathAndProInfo.push_back(proPair);
		}
		SetupDiDestroyDeviceInfoList(hDevInfo);
	}
	else
	{
		proPair.first = "INVALID_HANDLE_VALUE";
		proPair.second = "INVALID_HANDLE_VALUE";
		devPathAndProInfo.push_back(proPair);
	}
	return;
}

