import platform
def can_run():
    return (platform.system() == 'Windows' or platform.system() == "Linux") and platform.architecture(0) == '64bit' and platform.machine() == 'AMD64'
print(1)