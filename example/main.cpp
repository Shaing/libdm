#include "libdm.h"
#pragma comment(lib, "libdm_win32.lib")
#define IDMVER "0.0.1"
using namespace std;

enum IDMPARA
{
	DISK = 1,
	USB,
	PCI,
	ALL,
};

namespace
{
	void run(const IDMPARA& which)
	{
		idm::DEVMAN dm;
		for(int i = 0; i < 26; ++i)
		{
			cout << "{SPDRP_CODE : " << i << "}\n";
			switch(which)
			{
				case 1:
					cout << "[DISK]" << endl;
					dm.listDeviceRegPro(i, (void*)&GUID_DEVINTERFACE_DISK, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
					dm.coutList();
					break;
				case 2:
					cout << "[USB]" << endl;
					dm.listDeviceRegPro(i, (void*)&GUID_DEVINTERFACE_USB_DEVICE, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
					dm.coutList();
					break;
				case 3:
					cout << "[PCI]" << endl;
					dm.listDeviceRegPro(i, NULL , "PCI", (DIGCF_PRESENT | DIGCF_ALLCLASSES));
					dm.coutList();
					break;
				case 4 : default:
					cout << "[DISK]" << endl;
					dm.listDeviceRegPro(i, (void*)&GUID_DEVINTERFACE_DISK, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
					dm.coutList();
					cout << "[USB]" << endl;
					dm.listDeviceRegPro(i, (void*)&GUID_DEVINTERFACE_USB_DEVICE, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
					dm.coutList();
					cout << "[PCI]" << endl;
					dm.listDeviceRegPro(i, NULL , "PCI", (DIGCF_PRESENT | DIGCF_ALLCLASSES));
					dm.coutList();
					break;
			}
		}
	}

	void run(const IDMPARA& which, const int& whichSpdrp)
{
	if(whichSpdrp < 27)
	{
		idm::DEVMAN dm;
		cout << "{SPDRP_CODE : " << whichSpdrp << "}\n";
		switch(which)
		{
		case 1:
			cout << "[DISK]" << endl;
			dm.listDeviceRegPro(whichSpdrp, (void*)&GUID_DEVINTERFACE_DISK, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
			dm.coutList();
			break;
		case 2:
			cout << "[USB]" << endl;
			dm.listDeviceRegPro(whichSpdrp, (void*)&GUID_DEVINTERFACE_USB_DEVICE, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
			dm.coutList();
			break;
		case 3:
			cout << "[PCI]" << endl;
			dm.listDeviceRegPro(whichSpdrp, NULL, "PCI", (DIGCF_PRESENT | DIGCF_ALLCLASSES));
			dm.coutList();
			break;
		case 4: default:
			cout << "[DISK]" << endl;
			dm.listDeviceRegPro(whichSpdrp, (void*)&GUID_DEVINTERFACE_DISK, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
			dm.coutList();
			cout << "[USB]" << endl;
			dm.listDeviceRegPro(whichSpdrp, (void*)&GUID_DEVINTERFACE_USB_DEVICE, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
			dm.coutList();
			cout << "[PCI]" << endl;
			dm.listDeviceRegPro(whichSpdrp, NULL, "PCI", (DIGCF_PRESENT | DIGCF_ALLCLASSES));
			dm.coutList();
			break;
		}
	}
	else
		cout << "It's not SPDRP CODE!" << endl;
}

	const char* getVer(){ return IDMVER; }
}


int main(int argc, char* argv[])
{
	cout << unitbuf;
	string sargv;
	if(argc == 2)
	{
		sargv = argv[1];
		if(sargv == "-l")
			idm::coutSPDRPCODE();
		else if(sargv == "-v")
			cout << getVer() << endl;

	}
	else if(argc == 3)
	{
		sargv = argv[1];
		if(sargv == "-p")
		{
			sargv = argv[2];
			if(sargv == "D") run(IDMPARA::DISK);
			else if(sargv == "U") run(IDMPARA::USB);
			else if(sargv == "P") run(IDMPARA::PCI);
			else if(sargv == "A") run(IDMPARA::ALL);
		}
	}
	else if(argc == 4)
	{
		sargv = argv[1];
		if(sargv == "-ps")
		{
			sargv = argv[2];
			int whichSpdrp = atoi(argv[3]); 
			if(sargv == "D") run(IDMPARA::DISK, whichSpdrp);
			else if(sargv == "U") run(IDMPARA::USB, whichSpdrp);
			else if(sargv == "P") run(IDMPARA::PCI, whichSpdrp);
			else if(sargv == "A") run(IDMPARA::ALL, whichSpdrp);
		}
	}
	else
	{
		cout << "Usage:\n";
		cout << " idm [-v : get version]" << endl;
		cout << " idm [-l : list SPDRPCODE]" << endl;
		cout << " idm [-p : print SPDRPCODE propert][D:DISK | U:USB | P:PCI | A:ALL]" << endl;
		cout << " idm [-ps : specify SPDRPCODE propert][D:DISK | U:USB | P:PCI | A:ALL][SPDRPCODE(DEC)]" << endl;
		cout << "Example:\n";
		cout << " idm -ps D 1, specify DISK SODROCIDE:HardwareID" << endl;
	}

	return 0;
}