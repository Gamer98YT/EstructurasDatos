import os
import xml.etree.ElementTree as ET

workspace_dir = '/Users/barrena/Documents/PracticasDatos'
sdk_path = '/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1'
sysroot_path = '/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk'

for root, dirs, files in os.walk(workspace_dir):
    for file in files:
        if file.endswith('.project'):
            filepath = os.path.join(root, file)
            try:
                tree = ET.parse(filepath)
                xml_root = tree.getroot()
                changed = False
                
                # CodeLite XML elements don't usually have namespaces, but let's be careful
                for compiler in xml_root.findall('.//Compiler'):
                    opts = compiler.get('Options', '')
                    if '-isysroot' not in opts:
                        if opts:
                            opts += ';'
                        opts += f'-isysroot {sysroot_path}'
                        compiler.set('Options', opts)
                        changed = True

                    if '-isystem' not in opts:
                        opts += f';-isystem {sdk_path}'
                        compiler.set('Options', opts)
                        changed = True

                if changed:
                    tree.write(filepath, encoding='UTF-8', xml_declaration=True)
                    print(f"Updated {filepath}")
            except Exception as e:
                print(f"Failed to process {filepath}: {e}")
