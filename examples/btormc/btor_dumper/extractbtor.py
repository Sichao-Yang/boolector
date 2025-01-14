
#!/usr/bin/env python3
import sys

def extract_between_markers(text):
    start_marker = "=====StartDumping====="
    end_marker = "=====FinishDumping====="
    
    # Find start and end positions
    start_pos = text.find(start_marker) + len(start_marker)
    end_pos = text.find(end_marker)
    
    # Extract and split into lines
    if start_pos != -1 and end_pos != -1:
        extracted = text[start_pos:end_pos].strip()
        return extracted.split('\n')
    return []


filename = sys.argv[1]
with open(filename) as fp:
    text = fp.read()

lines = extract_between_markers(text)
for line in lines:
    print(line)
