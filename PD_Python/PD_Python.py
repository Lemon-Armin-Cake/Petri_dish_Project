import ctypes
PT_Library = ctypes.CDLL('./PD_Library_New/x64/Debug/PD_Library_New.dll')

PT_Library.generate_medium.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_int]
PT_Library.generate_medium.restype = ctypes.c_void_p
PT_Library.get_a.argtypes = [ctypes.c_void_p]
PT_Library.get_a.restype = ctypes.c_float
PT_Library.get_b.argtypes = [ctypes.c_void_p]
PT_Library.get_b.restype = ctypes.c_float
PT_Library.get_p.argtypes = [ctypes.c_void_p]
PT_Library.get_p.restype = ctypes.c_int
PT_Library.dispose_Growth_medium.argtypes = [ctypes.c_void_p]
PT_Library.dispose_Growth_medium.restype = None

PT_Library.create_bacterium.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float, ctypes.c_int, ctypes.c_float, ctypes.c_float, ctypes.c_int]
PT_Library.create_bacterium.restype = ctypes.c_void_p
PT_Library.get_x.argtypes = [ctypes.c_void_p]
PT_Library.get_x.restype = ctypes.c_float
PT_Library.get_y.argtypes = [ctypes.c_void_p]
PT_Library.get_y.restype = ctypes.c_float
PT_Library.get_q.argtypes = [ctypes.c_void_p]
PT_Library.get_q.restype = ctypes.c_float
PT_Library.get_n.argtypes = [ctypes.c_void_p]
PT_Library.get_n.restype = ctypes.c_int
PT_Library.get_s.argtypes = [ctypes.c_void_p]
PT_Library.get_s.restype = ctypes.c_float
PT_Library.get_v.argtypes = [ctypes.c_void_p]
PT_Library.get_v.restype = ctypes.c_float
PT_Library.get_status.argtypes = [ctypes.c_void_p]
PT_Library.get_status.restype = ctypes.c_int
PT_Library.dispose_Bacterium.argtypes = [ctypes.c_void_p]
PT_Library.dispose_Bacterium.restype = None



a = float(input("Enter the lenght of Petri dish"))
b = float(input("Enter the wight of Petri dish"))
try:
 (b < 0)
except:
    print("It's incorrect parament!")
p = int(input("Enter the number of particles"))

# For the current version of the program to work you should use next parametres: 20, 10, 36
G1 = PT_Library.generate_medium(a, b, p)
size_a = PT_Library.get_a(G1)
print ("a = ", size_a)
size_b = PT_Library.get_b(G1)
print ("b = ", size_b)
number_of_particles = PT_Library.get_p(G1)
print ("p = ", number_of_particles)
print()

B1 = PT_Library.create_bacterium(2, 3, 1.56, 0, 2, 2, 1 )
orientation = PT_Library.get_q(B1)
print ("B1 orientation = ", orientation)
status = PT_Library.get_status(B1)
print ("B1 orientation = ", status)

PT_Library.dispose_Growth_medium(G1)
PT_Library.dispose_Bacterium(B1)
