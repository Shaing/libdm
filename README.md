# libdm
- Windows device management wrapper using [SetupDi functions](https://docs.microsoft.com/zh-tw/windows-hardware/drivers/install/device-information-sets)
# build sample
- Clone https://github.com/Shaing/libdm.git
- Make sure [setupapi.lib](https://msdn.microsoft.com/en-us/library/windows/desktop/cc185682(v=vs.85).aspx) can be link
- If not above, find and add setupdi.lib to your project folder where project can link
# testing env
- Visual Studio 2015
- Windows 7 x64

