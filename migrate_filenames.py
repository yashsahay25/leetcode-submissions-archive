from pathlib import Path
import re

renamed = 0

for file in Path(".").glob("*.cpp"):

    match = re.match(r"(\d+)_(.+)", file.name)

    if not match:
        continue

    problem_id = int(match.group(1))
    rest = match.group(2)

    new_name = f"{problem_id:05d}_{rest}"

    if new_name != file.name:

        file.rename(file.with_name(new_name))

        renamed += 1

        print(f"{file.name} -> {new_name}")

print(f"\nRenamed {renamed} files")