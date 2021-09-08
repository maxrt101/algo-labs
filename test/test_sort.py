import subprocess
import unittest

EXECUTABLE = './bin/sort'
METHODS = ['quick', 'merge', 'heap']

def arr_to_str(arr):
    result = ''
    for i in arr:
        result += str(i) + ','
    return result

class TestSort(unittest.TestCase):
    def test_sort(self):
        arr = [1,4,2,8,0]
        sorted_arr = [0,1,2,4,8]

        for method in METHODS:
            result = subprocess.run([EXECUTABLE, method, 'asc', arr_to_str(arr)], stdout=subprocess.PIPE)
            result_lines = result.stdout.decode('utf-8').split('\n')
            self.assertEqual(result_lines[-2][:-1], ' '.join([str(x) for x in sorted_arr]))

    def test_asc_asc(self):
        arr = [0,1,2,4,8]

        for method in METHODS:
            result = subprocess.run([EXECUTABLE, method, 'asc', arr_to_str(arr)], stdout=subprocess.PIPE)
            result_lines = result.stdout.decode('utf-8').split('\n')
            self.assertEqual(result_lines[-2][:-1], ' '.join([str(x) for x in arr]))
    
    def test_desc_asc(self):
        arr = [0,1,2,4,8]
        sorted_arr = [8,4,2,1,0]

        for method in METHODS:
            result = subprocess.run([EXECUTABLE, method, 'desc', arr_to_str(arr)], stdout=subprocess.PIPE)
            result_lines = result.stdout.decode('utf-8').split('\n')
            self.assertEqual(result_lines[-2][:-1], ' '.join([str(x) for x in sorted_arr]))

    def test_asc_desc(self):
        arr = [8,4,2,1,0]
        sorted_arr = [0,1,2,4,8]

        for method in METHODS:
            result = subprocess.run([EXECUTABLE, method, 'asc', arr_to_str(arr)], stdout=subprocess.PIPE)
            result_lines = result.stdout.decode('utf-8').split('\n')
            self.assertEqual(result_lines[-2][:-1], ' '.join([str(x) for x in sorted_arr]))

    def test_desc_desc(self):
        arr = [8,4,2,1,0]

        for method in METHODS:
            result = subprocess.run([EXECUTABLE, method, 'desc', arr_to_str(arr)], stdout=subprocess.PIPE)
            result_lines = result.stdout.decode('utf-8').split('\n')
            self.assertEqual(result_lines[-2][:-1], ' '.join([str(x) for x in arr]))

