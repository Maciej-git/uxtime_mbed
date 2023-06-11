import ctypes

cfunctions = ctypes.CDLL("/workspaces/119167650/uxtime/tests/uxtime_c.so")

# Test function uxtime2date
def test_uxtime2date():
    f = cfunctions.uxtime2date

    # Set the return type to pointer
    f.restype = ctypes.POINTER(ctypes.c_char)
    cstring_pointer = f(984248127)
    str = ctypes.c_char_p.from_buffer(cstring_pointer)

    # Set expected date
    c_date = b'10 Mar 2001 19:15:27'
    assert str.value == c_date

# Test of date_t2uxtime fuction is not reliable due to ctypes time_t issue.
# Need to fix!
"""
def test_date_t2uxtime():
    f = cfunctions.date_t2uxtime

    # C time_t issue with ctypes!
    f.restype = ctypes.c_long

    class Date_t(ctypes.Structure):
        _fields_ = [
            ("Hour", ctypes.c_uint8),
            ("Minutes", ctypes.c_uint8),
            ("Seconds", ctypes.c_uint8),
            ("Day", ctypes.c_uint8),
            ("Month", ctypes.c_uint8),
            ("Year", ctypes.c_uint16)
        ]

    date = Date_t(19,15,27,10,2,2001)
    assert f(date) == 984248127
"""

def test_uxtime2day():
    f = cfunctions.uxtime2day
    assert f(984248127) == 6

def test_count_days():
    f = cfunctions.count_days
    f.restype = ctypes.c_float
    assert f(984248127, 984334527) == 1.0000






