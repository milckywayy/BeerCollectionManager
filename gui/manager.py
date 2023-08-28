from config import *
import platform
import ctypes


system = platform.system()

if system == "Windows":
    dll_path = WINDOWS_DLL_PATH
elif system == "Linux":
    dll_path = LINUX_DLL_PATH
else:
    raise Exception("Unsupported operating system: " + system)

manager = ctypes.CDLL(dll_path)
