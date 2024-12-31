import winreg
import re

def _update_env_path(path):
    lower_path = path.lower()
    registry_key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, 'Environment', 0, winreg.KEY_READ)
    value, _ = winreg.QueryValueEx(registry_key, 'Path')
    winreg.CloseKey(registry_key)
    
    path_list = value.split(';')
    found = False
    for name in path_list:
        if (name.lower() == lower_path):
            found = True
            break

    if (found):
        print("  - Path <%s> has already been set." % path)
    else:
        path_list.append(path)
        registry_key = winreg.CreateKey(winreg.HKEY_CURRENT_USER, 'Environment')
        winreg.SetValueEx(registry_key, 'Path', 0, winreg.REG_EXPAND_SZ, ";".join(path_list))
        winreg.CloseKey(registry_key)
        print("  - Path <%s> is updated." % path)

def change_each_path_env(path):
    try:
        _update_env_path(path)
    except WindowsError as err:
        if (err.errno == 13):
            print("")
            print('The path "%s" cannot be set without the administrator permission.' % path)
            print('So please add "%s" into environment variable <Path> manually or run script with the administrator.' % path)
        else:
            print(str(err))

def change_path_env(paths):
    pattern = re.compile("[,;]")
    all_path = pattern.split(paths)
    for path in all_path:
        change_each_path_env(path.strip())