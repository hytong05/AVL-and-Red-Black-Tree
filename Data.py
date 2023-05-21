import os
import random

# Lấy đường dẫn của thư mục chứa file .py đang chạy
dir_path = os.path.dirname(os.path.realpath(__file__))

# Tạo file numbers.txt trước
open(os.path.join(dir_path, 'Data2.txt'), 'w').close()

# Sinh dữ liệu và ghi vào file
numbers = set()
while len(numbers) < 1000000:
    numbers.add(random.randint(0, 10000000))

with open(os.path.join(dir_path, 'Data2.txt'), 'w') as file:
    for number in numbers:
        file.write(str(number) + ' ')