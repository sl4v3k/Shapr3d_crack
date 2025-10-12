# Shapr3d 5.961.9619.0 #b1239753

Starting from 5.603.6875.0 #40c93214 version, there is new way of patching. Previous hole is patched by Shapr3D team.
But there are still several ways to unlock trial version.  
The materials and information here are guides how patch Shapr3d executable to remove trial limitations, all is for study and educational purpose.

# Method (Thanks to 5six2JZ TomTom)

Please Follow Each Step Carefully

* Download and install Visual Studio 2019 Redistributables. I installed version: 16.9, architecture: x64, Release Date: 3/2/2021.
* After Visual Studio 2019 is installed, reboot your computer.
* In your Window Security > Virus & threat protection, Turn off all protections (optional, this is only if patcher is detected as virus)
* Go to sl4v3k repo folder x64/Release and click on the link: Shapr3D-inmemory-patcher-2.exe. **DO NOT RIGHT-CLICK ON THE LINK AND SELECT Save Link As... (This was my mistake because by right-click and saving the patcher-2.exe file, the browser will download a patcher-2.exe that will not work. You will get these errors: Cant Run on this PC or incompatibility with 64-bit versions of Windows.
* Therefore, if you just LEFT click on the Shapr3D-inmemory-patcher-2.exe link, you will then see the Code and Blame Tab. Click the Download Raw File icon to the right of your screen to download the working Shapr3D-inmemory-patcher-2.exe file
* Now, go to your C drive and create a new folder, name it patch (directory will be C:\patch)
* Place the Shapr3D-inmemory-patcher-2.exe you just downloded inside C:\patch
* Open Shapr3d app and Leave this app open
* Open Command Prompt (CMD) Run as Administrator
* Type: cd\ (Enter Key)
* Type: cd\patch (Enter Key)
* Type: Shapr3D-inmemory-patcher-2.exe (Enter Key)
* If you see Shapr found!, then you know the patch has been applied.
* Close the Command Prompt
* Enjoy!
* Note that from version 5.961.9619.0 You have to open one of the free project to refresh the view state!!

# VC Redistributables

Do not forget install Visual Studio 2019 Redistributables from Microsoft.

# Automatic updates

Do not forget disable automatic updates of Microsoft Store applicatios because update may happen without notification and break the patch.
