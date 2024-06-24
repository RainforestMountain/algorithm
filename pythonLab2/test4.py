import os


def list_files_larger_than(path, size):
    files_larger_than_size = []
    for file in os.listdir(path):
        file_path = os.path.join(path, file)
        if os.path.isfile(file_path) and os.path.getsize(file_path) > size:
            files_larger_than_size.append(file_path)
    return files_larger_than_size


directory_path = 'E:\\python_code\\program_code\\pythonLab2'
minimum_size = 50
larger_files = list_files_larger_than(directory_path, minimum_size)
print("Files larger than", minimum_size, "bytes:", larger_files)
