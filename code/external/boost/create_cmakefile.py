# %%
from pathlib import Path
from pprint import pprint
from io import StringIO

# %%
path = Path.cwd()

# %%
dirs = [d for d in path.iterdir() if d.is_dir()]

# %%
pprint([d.name for d in dirs])

# %%
def create_cmakefile(dirs=dirs):
    out = StringIO()
    for d in dirs:
        if d.name.startswith("."):
            continue
        out.write(f"add_subdirectory({d.name})\n")
    return out.getvalue()

# %%
print(create_cmakefile())

# %%
def write_cmakefile():
    with open("CMakeLists.txt", "w") as f:
        f.write(create_cmakefile())

# %%
if __name__ == "__main__":
    write_cmakefile()

# %%
