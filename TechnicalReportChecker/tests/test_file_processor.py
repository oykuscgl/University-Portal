import unittest
from modules.file_processor import process_file

class TestFileProcessor(unittest.TestCase):
    def test_process_file(self):
        # Test dosyası ve beklenen sonuçlar
        test_file = "test.docx"
        corrected_file, error_report = process_file(test_file)
        self.assertIsNotNone(corrected_file)
        self.assertIsNotNone(error_report)

if __name__ == '__main__':
    unittest.main()