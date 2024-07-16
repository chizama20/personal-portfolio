import os
import shutil
import logging
from pathlib import Path

# Set up logging
logging.basicConfig(filename='file_organizer.log', level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s')

def organize_files(directory):
    try:
        # List all files in the directory
        for filename in os.listdir(directory):
            file_path = os.path.join(directory, filename)
            
            # Skip directories
            if os.path.isdir(file_path):
                continue
            
            # Extract the file extension
            file_extension = os.path.splitext(filename)[1][1:]
            
            # Create a new directory for the file extension if it doesn't exist
            extension_dir = os.path.join(directory, file_extension)
            if not os.path.exists(extension_dir):
                os.makedirs(extension_dir)
                logging.info(f'Created directory: {extension_dir}')
            
            # Move the file to the new directory
            shutil.move(file_path, os.path.join(extension_dir, filename))
            logging.info(f'Moved file {filename} to {extension_dir}')
    except Exception as e:
        logging.error(f'Error organizing files: {e}')

# Get the path to the Downloads folder
downloads_path = str(Path.home() / "Downloads")

# Organize files in the Downloads folder
organize_files(downloads_path)

