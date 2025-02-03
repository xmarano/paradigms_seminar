import unittest
import subprocess
import os
import time
from pathlib import Path
import signal
import glob

class Colors:
    GREEN = "\033[1m\033[32m"
    RED = "\033[1m\033[31m"
    RESET = "\033[0m"

class SystemMonitorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print(f"\n{Colors.GREEN}Compiling program...{Colors.RESET}")
        try:
            subprocess.run(["make", "re", "CXXFLAGS=-std=c++11"], check=True, capture_output=True)
            print(f"{Colors.GREEN}Compilation successful{Colors.RESET}")
        except subprocess.CalledProcessError as e:
            print(f"{Colors.RED}Compilation failed:{Colors.RESET}")
            print(e.stderr.decode())
            exit(1)
        
        os.makedirs("tmp", exist_ok=True)
        
    def setUp(self):
        for file in Path("tmp").glob("*_tmp.txt"):
            try:
                file.unlink()
            except:
                pass

    def test_display_modes(self):
        """Test if the SFML display executable exists"""
        print(f"\n{Colors.GREEN}Testing if SFML display executable exists...{Colors.RESET}")
    
        sfml_executable = Path("SFML/sfmldisplay")
        self.assertTrue(sfml_executable.exists(), "SFML display executable should be present")

    def test_invalid_arguments(self):
        """Test program behavior with invalid arguments"""
        print(f"\n{Colors.GREEN}Testing invalid arguments...{Colors.RESET}")
        
        result = subprocess.run(["./MyGKrellm"], capture_output=True, text=True)
        self.assertEqual(result.returncode, 1)
        self.assertIn("Usage:", result.stderr)

        result = subprocess.run(["./MyGKrellm", "-invalid"], capture_output=True, text=True)
        self.assertEqual(result.returncode, 1)
        self.assertIn("Usage:", result.stderr)

    def test_tmp_file_creation(self):
        """Test if program creates and manages temporary files correctly"""
        print(f"\n{Colors.GREEN}Testing temporary file management...{Colors.RESET}")
        
        process = subprocess.Popen(["./MyGKrellm", "-ncurses"],
                                 stdout=subprocess.PIPE,
                                 stderr=subprocess.PIPE)
        time.sleep(0.5)
        process.terminate()
        try:
            process.wait(timeout=1)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()
        finally:
            if process.stdout:
                process.stdout.close()
            if process.stderr:
                process.stderr.close()

        self.assertTrue(os.path.exists("tmp"), "Temporary directory should be created")
        tmp_files = list(Path("tmp").glob("*_tmp.txt"))
        self.assertGreater(len(tmp_files), 0, "Temporary files should be created")

    @classmethod
    def tearDownClass(cls):
        print(f"\n{Colors.GREEN}Cleaning up...{Colors.RESET}")
        subprocess.run(["make", "fclean"], check=True)
        for file in Path("tmp").glob("*_tmp.txt"):
            try:
                file.unlink()
            except:
                pass
        try:
            os.rmdir("tmp")
        except:
            pass

if __name__ == "__main__":
    try:
        print(f"\n{Colors.GREEN}Starting test suite...{Colors.RESET}")
        unittest.main(verbosity=2)
    except KeyboardInterrupt:
        print(f"\n{Colors.RED}Tests interrupted by user{Colors.RESET}")
        try:
            subprocess.run(["pkill", "MyGKrellm"], check=False)
        except:
            pass
        subprocess.run(["make", "fclean"], check=True)
        exit(1)