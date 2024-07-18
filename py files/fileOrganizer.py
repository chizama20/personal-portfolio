import os
import shutil
import logging
from pathlib import Path

logging.basicConfig(filename='file_organizer.log', level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s')

def organize_files(directory):
    try:
        for filename in os.listdir(directory):
            file_path = os.path.join(directory, filename)
            
            if os.path.isdir(file_path):
                continue
            
            file_extension = os.path.splitext(filename)[1][1:]
            
            extension_dir = os.path.join(directory, file_extension)
            if not os.path.exists(extension_dir):
                os.makedirs(extension_dir)
                logging.info(f'Created directory: {extension_dir}')
            
            shutil.move(file_path, os.path.join(extension_dir, filename))
            logging.info(f'Moved file {filename} to {extension_dir}')
    except Exception as e:
        logging.error(f'Error organizing files: {e}')

downloads_path = str(Path.home() / "Downloads")

organize_files(downloads_path)

