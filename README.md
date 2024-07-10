# COM example in C++ with MITRE Technique T1546.015 realization

This repository contains the implementation of a 32-bit COM DLL component in C++ for Windows architectures. It is designed to provide a practical example of creating and using COM components, which are rare resources in C++.

## Project Overview

The INT-22 project demonstrates the creation and usage of a 32-bit COM DLL component. This project serves as a valuable resource for understanding COM programming in C++.

## Setup and Usage

### Building the Project

1. **Compile the DLL**:
    - Set up the project to compile as a dynamic library (DLL).
    - Define the preprocessor for 32-bit architecture and disable deprecated function warnings.
    - Specify the module definition file for the linker.
![image](https://github.com/vvard3u/COM-IN-CPP/assets/125309323/b15d3240-08e6-4afd-a3cd-9e761ded16e3)
![image](https://github.com/vvard3u/COM-IN-CPP/assets/125309323/fb8c4403-e6d3-4109-84f4-6f81ca29d934)
![image](https://github.com/vvard3u/COM-IN-CPP/assets/125309323/c621ae2e-2926-444d-95b7-208336efb7a4)

2. **Register the COM Object**:
    ```shell
    regsvr32 INT-22.dll
    ```

3. **Client Setup**:
    - Compile the client as an executable (EXE).
    - Run the client to verify the COM object functionality. A message box should appear.

### Modifying the DLL

1. **Edit Method**:
    Replace the method in `T1546_015` class with:
    ```cpp
    HRESULT STDMETHODCALLTYPE T1546_015::malActivity(void)
    {
        std::string title = "Wow, did it really work???";
        std::string msg = "Yes, now u see it:)";
        MessageBoxA(0, msg.c_str(), title.c_str(), MB_OKCANCEL);
        return S_OK;
    }
    ```

2. **Recompile the DLL** with the above changes.

3. **Run Malicious Script**: Execute a Python script specifying the path to the modified COM DLL.

4. **Test the Client**: Launch the client again. The new message and title should appear in the message box.


## License

This project is licensed under the MIT License. See the LICENSE file for details.

