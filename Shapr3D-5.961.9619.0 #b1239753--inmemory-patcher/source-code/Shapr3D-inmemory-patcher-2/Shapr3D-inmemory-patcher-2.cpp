// Shapr3D-inmemory-patcher-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <shlwapi.h>

using namespace std;
// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

HANDLE PrintProcessNameAndID(DWORD processID, const wchar_t* name)
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
        PROCESS_VM_READ,
        FALSE, processID);

    // Get the process name.

    if (NULL != hProcess)
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
            &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, szProcessName,
                sizeof(szProcessName) / sizeof(TCHAR));
        }
    }

    // Print the process name and identifier.

    //_tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);
    if (szProcessName[0] == 'S' && szProcessName[6] == 'D' && szProcessName[7] == '.')
    {
        if (hProcess)
            CloseHandle(hProcess);
        hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, processID);
        if (!hProcess)
            return NULL;
        return hProcess;
    }

    //if (!wcscmp(szProcessName, name))
    //{
    //    _tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);
    //    return hProcess;
    //}

    // Release the handle to the process.
    if (hProcess)
        CloseHandle(hProcess);
    return NULL;
}



DWORD_PTR GetProcessBaseAddress(HANDLE processHandle)
{
    DWORD_PTR   baseAddress = 0;
    //HANDLE      processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    HMODULE* moduleArray;
    LPBYTE      moduleArrayBytes;
    DWORD       bytesRequired;
    TCHAR szModName[MAX_PATH];

    if (processHandle)
    {
        if (EnumProcessModules(processHandle, NULL, 0, &bytesRequired))
        {
            if (bytesRequired)
            {
                moduleArrayBytes = (LPBYTE)LocalAlloc(LPTR, bytesRequired);

                if (moduleArrayBytes)
                {
                    unsigned int moduleCount = bytesRequired / sizeof(HMODULE);
                    moduleArray = (HMODULE*)moduleArrayBytes;

                    if (EnumProcessModules(processHandle, moduleArray, bytesRequired, &bytesRequired))
                    {
                        baseAddress = (DWORD_PTR)moduleArray[0];
                        printf("%016llx\n", baseAddress);


                        for (int i = 0; i < moduleCount; i++)
                        {
                            
                            //memset((void*)szModName, 0, MAX_PATH);

                            if (GetModuleFileNameEx(processHandle, moduleArray[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
                            {
                                int len = wcslen(szModName);
                                if (szModName[len - 5] == 'D' && szModName[len - 1] == 'l')
                                {
                                    //_tprintf(TEXT("%s -> 0x%016llx\n"), szModName, moduleArray[i]);
                                    return (DWORD_PTR)moduleArray[i];
                                }
                            }
                        }


                    }
                    LocalFree(moduleArrayBytes);
                }
            }
        }
     //   CloseHandle(processHandle);
    }

    return baseAddress;
}


int main(void)
{
    // Get the list of process identifiers.
    HANDLE shaprh = NULL;
    DWORD pid = 0;

    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    {
        printf("EnumProcesses error!\n");
        return 1;
    }


    // Calculate how many process identifiers were returned.

    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.

    for (i = 0; i < cProcesses; i++)
    {
        if (aProcesses[i] != 0)
        {
            shaprh = PrintProcessNameAndID(aProcesses[i], L"Shapr3D.exe");
            if (shaprh != NULL)
            {
                pid = GetProcessId(shaprh);
                printf("Shapr found!\n");
                break;
            }
        }
    }
    if (shaprh)
    {
        byte* shapr3d_dll_base_addr = (byte*)GetProcessBaseAddress(shaprh);
        printf("Shapr3D.dll base addr -> %016llx\n", (unsigned long long)shapr3d_dll_base_addr);
        LPBYTE ptrAddress = new byte[6];
        SIZE_T bytes_written = 0;
        DWORD oldprotect;

        //5.961.9619.0 #b1239753
        //1825291BF
        VirtualProtectEx(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x2520000), 0x10000, PAGE_EXECUTE_READWRITE, &oldprotect);
        ptrAddress[0] = 0xe9;
        ptrAddress[1] = 0x7c;
        ptrAddress[2] = 0x02;
        ptrAddress[3] = 0x00;
        ptrAddress[4] = 0x00;
        ptrAddress[5] = 0x90;

        if (!WriteProcessMemory(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x25291BF), (LPCVOID)ptrAddress, 6, &bytes_written))
        {
            printf("WriteProcessMemory failed! error code -> 0x%08x\n", GetLastError());
        }
        else
            printf("WriteProcessMemory success! -> %08llx bytes written.\n", bytes_written);

        //18252944A
        ptrAddress[0] = 0xba;
        ptrAddress[1] = 0x0c;

        if (!WriteProcessMemory(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x252944A), (LPCVOID)ptrAddress, 2, &bytes_written))
        {
            printf("WriteProcessMemory failed! error code -> 0x%08x\n", GetLastError());
        }
        else
            printf("WriteProcessMemory success! -> %08llx bytes written.\n", bytes_written);

        VirtualProtectEx(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x2520000), 0x10000, oldprotect, &oldprotect);




        //1818889E0
        VirtualProtectEx(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x1880000), 0x10000, PAGE_EXECUTE_READWRITE, &oldprotect);
        ptrAddress[0] = 0x32;
        ptrAddress[1] = 0xc0;
        ptrAddress[2] = 0xfe;
        ptrAddress[3] = 0xc0;
        ptrAddress[4] = 0xc3;

        if (!WriteProcessMemory(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x18889E0), (LPCVOID)ptrAddress, 5, &bytes_written))
        {
            printf("WriteProcessMemory failed! error code -> 0x%08x\n", GetLastError());
        }
        else
            printf("WriteProcessMemory success! -> %08llx bytes written.\n", bytes_written);
        VirtualProtectEx(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x1880000), 0x10000, oldprotect, &oldprotect);

        //182518270
        VirtualProtectEx(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x2510000), 0x10000, PAGE_EXECUTE_READWRITE, &oldprotect);
        ptrAddress[0] = 0x48;
        ptrAddress[1] = 0x33;
        ptrAddress[2] = 0xc0;

        if (!WriteProcessMemory(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x2518270), (LPCVOID)ptrAddress, 3, &bytes_written))
        {
            printf("WriteProcessMemory failed! error code -> 0x%08x\n", GetLastError());
        }
        else
            printf("WriteProcessMemory success! -> %08llx bytes written.\n", bytes_written);


        //1825182A7
        ptrAddress[0] = 0x90;
        ptrAddress[1] = 0x90;
        ptrAddress[2] = 0x90;
        ptrAddress[3] = 0x90;
        ptrAddress[4] = 0x90;
        ptrAddress[5] = 0x90;

        if (!WriteProcessMemory(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x25182A7), (LPCVOID)ptrAddress, 6, &bytes_written))
        {
            printf("WriteProcessMemory failed! error code -> 0x%08x\n", GetLastError());
        }
        else
            printf("WriteProcessMemory success! -> %08llx bytes written.\n", bytes_written);


        VirtualProtectEx(shaprh, (LPVOID)(shapr3d_dll_base_addr + 0x2510000), 0x10000, oldprotect, &oldprotect);

    }
    else
        printf("Shapr NOT found! Is not running!\n");


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
